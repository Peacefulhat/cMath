#ifndef MATRIX_H
#define MATRIX_H
#include<stdarg.h>
#include<stdio.h>
#include"cmath.h"
#include<stdlib.h>
#include<math.h>
typedef struct{
unsigned int rows;
unsigned int cols;
float **elements;
}matrix;

extern const matrix MAT_UNDEFINED;
matrix allocateMatrix(unsigned int rows, unsigned int cols);
matrix identity(unsigned int dim);
// all rows and cols zeros
matrix zeroMatrix(unsigned int rows, unsigned int cols);

matrix newMatrix(unsigned int rows, unsigned int cols,...);
matrix copy(matrix m);
matrix copyPtr(matrix *m);
void printMatrix(matrix m);
#endif // !MATRIX_H
