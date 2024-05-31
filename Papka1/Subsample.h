#ifndef Subsample_h
#define Subsample_h
#include "Matrix.h"

class SubsamplingMatrix {
public:
	SubsamplingMatrix(const Matrix& matrix); // Конструктор с параметром
	Matrix getMaxValuesMatrix() const; // Метод для получения матрицы с максимальными значениями
private:
	Matrix inputMatrix;
};

#endif