#include "Papka1/Matrix.h"
#include "Papka1/Convolution.h"
#include "Papka1/Subsample.h"
#include <iostream>

int main() {
    srand(time(NULL));
    // Создание матриц
    Matrix matrix_0;
    Matrix matrix_1(4, 4);
    Matrix matrix_2(4, 4);

    // Использование операторов
    Matrix matrix_3 = matrix_1 + matrix_2;
    Matrix matrix_4 = matrix_1 - matrix_2;
    Matrix matrix_5 = matrix_1 * 7;
    Matrix matrix_6 = matrix_1 * matrix_2;
    Matrix matrix_7 = matrix_1;
    

    // Вывод матриц
    std::cout << "Матрица 0: \n" << matrix_0 << std::endl;
    std::cout << "Матрица 1:\n" << matrix_1 << std::endl;
    std::cout << "Матрица 2:\n" << matrix_2 << std::endl;
    std::cout << "Матрица 3 (сумма двух матриц):\n" << matrix_3 << std::endl;
    std::cout << "Матрица 4 (разность двух матриц):\n" << matrix_4 << std::endl;
    std::cout << "Матрица 5 (умножение матрицы на число):\n" << matrix_5 << std::endl;
    std::cout << "Матрица 6 (умножение двух матриц):\n" << matrix_6 << std::endl;
    std::cout << "Проверка равенства матриц " << (matrix_1 == matrix_2 ? "true" : "false") << std::endl;
    std::cout << "Максимальное число матрицы (1) " << matrix_1.getMaxValue() << std::endl;
    std::cout << "Максимальное число матрицы (2) " << matrix_2.getMaxValue() << std::endl;
    std::cout << "Матрица 7: \n" << matrix_7 << std::endl;
    std::cout << "Равенство матриц" << (matrix_1 == matrix_7 ? "true" : "false") << std::endl;

    Matrix matrix_8(3, 3);
    std::cout << "Введите элементы матрицы m8: " << std::endl;
    std::cin >> matrix_8;

    // Вывод матрицы
    std::cout << "Матрица m8: \n" << matrix_8 << std::endl;

    // Создание матриц
    Matrix input1(5, 5);
    Matrix input2(3, 3);
    std::cout << "input1:\n" << input1 << std::endl;
    std::cout << "input2:\n" << input2 << std::endl;
    
    Convolution conv(input1, input2);

    // вывод результата
    std::cout << "Результат свёртки:\n" << conv << std::endl;


    Matrix input(5, 5);
    std::cout << "input:\n" << input << std::endl;
    std::cout << "max input:\n" << input.getMaxValue() << std::endl;
    SubsamplingMatrix subsamplingMatrix(input);
    Matrix maxValuesMatrix = subsamplingMatrix.getMaxValuesMatrix();
    std::cout << "Результат подвыборки:\n";
    for (int i = 0; i < maxValuesMatrix.rows; i++) {
        for (int j = 0; j < maxValuesMatrix.cols; j++) {
            std::cout << maxValuesMatrix.data[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
