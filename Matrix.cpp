#include "Papka1/Matrix.h"

// методы класса матрица
Matrix::Matrix() : rows(2), cols(2) {
    allocateMemory();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = 0; // Инициализация нулями
        }
    }
}

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {//заполнение матрицы случайными числами
    allocateMemory();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = rand() % 100;
        }
    }
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {//метод для нового объекта Matrix с помощью копии 
    allocateMemory();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }
}

Matrix::~Matrix() {
    deallocateMemory();//дестркутор
}

Matrix& Matrix::operator=(const Matrix& other) {//одной матрице присваиваются элементы другой 
    if (this != &other) {
        deallocateMemory();
        rows = other.rows;
        cols = other.cols;
        allocateMemory();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this;
}

bool Matrix::operator==(const Matrix& other) const {//для проверки на равность матриц 
    if (rows != other.rows || cols != other.cols) {
        return false;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }
    return true;
}

Matrix Matrix::operator+(const Matrix& other) const {//сложение двух матриц 
    if (rows != other.rows || cols != other.cols) {
        std::cout << "Сложение матриц невозможно: размеры матриц не совпадают." << std::endl;
        return Matrix(); // Возвращаем пустую матрицу
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {//вычитание двух матриц
    if (rows != other.rows || cols != other.cols) {
        std::cout << "Вычитание матриц невозможно: размеры матриц не совпадают." << std::endl;
        return Matrix(); // Возвращаем пустую матрицу
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(int scalar) const {//умножение матрицы на число 
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {//умножение двух матриц 
    if (cols != other.rows) {
        std::cout << "Умножение матриц невозможно: количество столбцов первой матрицы должно быть равно количеству строк второй матрицы." << std::endl;
        return Matrix(); // Возвращаем пустую матрицу
    }

    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            result.data[i][j] = 0; // Инициализируем элементы result нулями
            for (int k = 0; k < cols; k++) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

int Matrix::getMaxValue() const {//нахождение максимального элемепнта матрицы 
    int maxVal = data[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (data[i][j] > maxVal) {
                maxVal = data[i][j];
            }
        }
    }
    return maxVal;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {//для вывода матрицы на экран
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            os << matrix.data[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Matrix& matrix) {//для ввода элемента матрицы
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            is >> matrix.data[i][j];
        }
    }
    return is;
}

void Matrix::allocateMemory() {//выделение памяти
    data = new int*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols]();
    }
}

void Matrix::deallocateMemory() {//освободить память 
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
}
