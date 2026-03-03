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

matrix create_matrix(int rows, int cols);
void enter_element(matrix* m, int row, int col, float val);
float get_element(matrix* m, int row, int col);
void print_matrix(matrix* m);
void delete_matrix(matrix* m);

#endif