#ifndef Matrix_h
#define Matrix_h
    
#include <iostream>
#include <cstdlib>

class Matrix {
public:
    Matrix(); // Конструктор по умолчанию
    Matrix(int rows, int cols); // Конструктор с параметрами
    Matrix(const Matrix& other); // Конструктор копирования
    ~Matrix(); // Деструктор

    Matrix& operator=(const Matrix& other); // Оператор присваивания
    bool operator==(const Matrix& other) const; // Оператор сравнения на равенство
    Matrix operator+(const Matrix& other) const; // Оператор сложения
    Matrix operator-(const Matrix& other) const; // Оператор вычитания
    Matrix operator*(int scalar) const; // Оператор умножения на число
    Matrix operator*(const Matrix& other) const; // Оператор умножения матриц

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix); // Оператор вывода в консоль
    friend std::istream& operator>>(std::istream& is, Matrix& matrix); // Оператор ввода с консоли

    int getMaxValue() const; // Метод для получения максимального значения

    int rows;
    int cols;
    int** data;
private:
    

    void allocateMemory(); // Метод для выделения памяти
    void deallocateMemory(); // Метод для освобождения памяти
};

#endif
