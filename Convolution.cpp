#include "Papka1/Convolution.h"

Convolution::Convolution(const Matrix& input1, const Matrix& input2) : Matrix(input1.rows - input2.rows + 1, input1.cols - input2.cols + 1) {
    performConvolution(input1, input2);
}

void Convolution::performConvolution(const Matrix& input1, const Matrix& input2) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = calculateConvolutionElement(input1, input2, i, j);
        }
    }
}

int Convolution::calculateConvolutionElement(const Matrix& input1, const Matrix& input2, int row, int col) {
    int sum = 0;
    for (int i = 0; i < input2.rows; i++) {
        for (int j = 0; j < input2.cols; j++) {
            sum += input1.data[row + i][col + j] * input2.data[i][j];
        }
    }
    return sum;
}
