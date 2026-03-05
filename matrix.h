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

void matrix_scale(matrix* m, float k);

void multiply_row(matrix* m, float k, int r);

void multiply_col(matrix* m, float k, int c);

void swap_rows(matrix* m, int r1, int r2);

void swap_cols(matrix* m,int c1,int c2);

void add_rows(matrix* m, float k, int r1, int r2);

void add_cols(matrix* m, float k, int c1, int c2);

matrix transpose(matrix* m);

void gaussian(matrix* m);

float det(matrix* m);

#endif
