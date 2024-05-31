#include "Papka1/Subsample.h"

SubsamplingMatrix::SubsamplingMatrix(const Matrix& matrix) : inputMatrix(matrix) {}
Matrix SubsamplingMatrix::getMaxValuesMatrix() const {
	int newRows = inputMatrix.rows / 2;
	int newCols = inputMatrix.cols / 2;
	Matrix maxValuesMatrix(newRows, newCols);
	for (int i = 0; i < newRows; i++) {
		for (int j = 0; j < newCols; j++) {
			int maxVal = 0;
			for (int x = 0; x < 2; x++) {
				for (int y = 0; y < 2; y++) {
					if (inputMatrix.data[2 * i + x][2 * j + y] > maxVal) {
						maxVal = inputMatrix.data[2 * i + x][2 * j + y];
					}
				}
			}
			maxValuesMatrix.data[i][j] = maxVal;
		}
	}
	return maxValuesMatrix;
}

