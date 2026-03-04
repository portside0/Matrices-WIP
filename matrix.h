#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

typedef struct matrix
{
	unsigned int noofrows;
	unsigned int noofcols;
	float* elements;
}
matrix;

// Matrix utilities
matrix matrix_create(int rows, int cols);

void enter_element(matrix* m, int row, int col, float val);

float get_element(matrix* m, int row, int col);

void matrix_print(matrix* m);

void matrix_delete(matrix* m);


// Matrix operations
matrix matrix_add(matrix* m1, matrix* m2);

matrix matrix_multiply(matrix* m1, matrix* m2);
#endif