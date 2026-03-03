#include "matrix.h"

matrix create_matrix(int rows, int cols)
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

void print_matrix(matrix* m)
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

void delete_matrix(matrix* m)
{
	free(m->elements);
	m->elements = NULL;
}
