#include "matrix.h"

matrix matrix_create(int rows, int cols)
{
	matrix m;
	m.noofrows = rows;
	m.noofcols = cols;
	
	m.elements = (float *)calloc(rows * cols, sizeof(float));
	
	if (m.elements == NULL)
	{
		printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	
	return m;
}

void enter_element(matrix* m, int row, int col, float val)
{
	if (row < m->noofrows && col < m->noofcols)
	{
		m->elements[row * m->noofcols + col] = val;
	}
	else
	{
		printf("Index out of bounds\n");
		exit(EXIT_FAILURE);
	}
}

float get_element(matrix* m, int row, int col)
{
	if (row < m->noofrows && col < m->noofcols)
	{
		return m->elements[row * m->noofcols + col];
	}
	else
	{
		printf("Index out of bounds\n");
		exit(EXIT_FAILURE);
	}
}

void matrix_print(matrix* m)
{	
	for (int i = 0; i < m->noofrows; i++)
	{
		for (int j = 0; j < m->noofcols; j++)
		{
			printf("%f ", get_element(m, i, j));
		}
		printf("\n");
	}
}

void matrix_delete(matrix* m)
{
	free(m->elements);
	m->elements = NULL;
}

matrix matrix_add(matrix* m1, matrix* m2)
{
	if (m1->noofrows != m2->noofrows || m1->noofcols != m2->noofcols)
	{
		printf("Matrix dimensions do not match\n");
		exit(EXIT_FAILURE);
	}
	
	matrix result = matrix_create(m1->noofrows, m1->noofcols);
	
	for (int i = 0; i < m1->noofrows; i++)
	{
		for (int j = 0; j < m1->noofcols; j++)
		{
			enter_element(&result, i, j, get_element(m1, i, j) + get_element(m2, i, j));
		}
	}
	
	return result;
}
