#include "matrix.h"

matrix matrix_create(int rows, int cols) // creates matrix using the struct
{
	matrix m;
	m.noofrows = rows;
	m.noofcols = cols;
	
	m.elements = (float *)calloc(rows * cols, sizeof(float)); //allocates memory for the elements
	
	if (m.elements == NULL)
	{
		printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	
	return m;
}

matrix identity(int rows, int cols) //return identity matrix of given dimensions
{
	matrix m;
	m.noofrows = rows;
	m.noofcols = cols;
	
	m.elements = (float *)calloc(rows * cols, sizeof(float)); //allocates memory for the elements
	
	if (m.elements == NULL)
	{
		printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	
	for (int i = 0; i < rows; i++)
	{
		enter_element(&m, i, i, 1); // makes diagnol element 1
	}
	
	return m;
}

void enter_element(matrix* m, int row, int col, float val)
{
	if (row < m->noofrows && col < m->noofcols) // checks bounds
	{
		m->elements[row * m->noofcols + col] = val; //uses the formula for row-major order to find the 1D index for the element
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
		return m->elements[row * m->noofcols + col]; //finds and return the element at given location if valid
	}
	else
	{
		printf("Index out of bounds\n");
		exit(EXIT_FAILURE);
	}
}

void matrix_print(matrix* m) // prints the elements
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

void matrix_delete(matrix* m) // IMPORTANT use this at the end of program to avoid memory leaks
{
	free(m->elements);
	m->elements = NULL;
}

matrix matrix_add(matrix* m1, matrix* m2)
{
	if (m1->noofrows != m2->noofrows || m1->noofcols != m2->noofcols) // checks if the the elements have same dimension or not
	{
		printf("Matrix dimensions do not match\n");
		exit(EXIT_FAILURE);
	}
	
	matrix result = matrix_create(m1->noofrows, m1->noofcols); //create matrix to hold result
	
	for (int i = 0; i < m1->noofrows; i++)
	{
		for (int j = 0; j < m1->noofcols; j++)
		{
			enter_element(&result, i, j, get_element(m1, i, j) + get_element(m2, i, j));
		}
	}
	
	return result;
}

matrix matrix_multiply(matrix* m1, matrix* m2)
{
	if (m1->noofcols != m2->noofrows) //requirement for marix multiplication
	{
		printf("Matrix dimensions do not match\n");
		
		exit(EXIT_FAILURE);
	}
	
	matrix result = matrix_create(m1->noofrows, m2->noofcols);
	
	for (int i = 0; i < m1->noofrows; i++)
	{
		for (int j = 0; j < m2->noofcols; j++)
		{
			for (int k = 0; k < m2->noofrows; k++)
			{
				enter_element(&result, i, j, get_element(&result, i ,j) + (get_element(m1, i, k) * get_element(m2, k, j))); 
			}
		}
	}
	
	return result;
}

void matrix_scale(matrix* m, float k) // multiplies all elements in the matrix with a given scalar
{
	for (int i = 0; i < m->noofrows; i++)
	{
		for (int j = 0; j < m->noofcols; j++)
		{
			enter_element(m, i, j, get_element(m, i, j) * k);
		}
		printf("\n");
	}
}

void multiply_row(matrix* m, float k, int r) // multiplies all elements in the given row with a given scalar
{
	for (int j = 0; j < m->noofcols; j++)
	{
		enter_element(m, r, j, k * get_element(m, r, j));
	}
}

void multiply_col(matrix* m, float k, int c)// multiplies all elements in the given column with a given scalar
{
	for (int i = 0; i < m->noofcols; i++)
	{
		enter_element(m, i, c, k * get_element(m, i, c));
	}
}

void swap_rows(matrix* m, int r1, int r2) // swaps two rows
{
	float tmp;
	
	for (int i = 0; i < m->noofcols; i++)
	{
		float val1 = get_element(m, r1, i);
		float val2 = get_element(m, r2, i);
		
		enter_element(m, r1, i, val2);
		enter_element(m, r2, i, val1);
	}
}

void swap_cols(matrix* m, int c1, int c2) // swaps two columns
{
	float tmp;
	
	for (int i = 0; i < m->noofrows; i++)
	{
		float val1 = get_element(m, i, c1);
		float val2 = get_element(m, i, c2);
		
		enter_element(m, i, c1, val2);
		enter_element(m, i, c2, val1);
	}
}

void add_rows(matrix* m, float k, int r1, int r2) // adds r1 to r2 and stores results in r2
{
	for (int i = 0; i < m->noofcols; i++)
	{
		float val = k * get_element(m, r1, i) + get_element(m, r2, i);
		
		enter_element(m, r2, i, val);
	}
		
}

void add_cols(matrix* m, float k, int c1, int c2) // add c1 to c2 and stores result in c2
{
	for (int i = 0; i < m->noofrows; i++)
	{
		float val = k * get_element(m, i, c1) + get_element(m, i, c2);
		enter_element(m, i, c2, val);
	}
}

matrix transpose(matrix* m) // return transpose of the matrix
{
	matrix result = matrix_create(m->noofcols, m->noofrows);
	
	result.noofrows = m->noofcols;
	result.noofcols = m->noofrows;
	
	float tmp;
	
	for (int i = 0; i < m->noofcols; i++)
	{
		for (int j = 0; j < m->noofrows; j++)
		{
			enter_element(&result, i, j, get_element(m, j, i));
		}
	}
	
	return result;
}

int gaussian(matrix* m) // performs gaussian elimination on the matrix, returns the number times rows were swapped for det calculation
{
	int swap = 0;
	
	for (int i = 0; i < m->noofrows; i++)
	{
		float pivot = get_element(m, i, i);
		
		if (pivot == 0)
		{
			for (int huh = i + 1; huh < m->noofrows; huh++)
			{
				float val = get_element(m, huh, i);
				if (val != 0)
				{
					swap_rows(m, huh, i);
					pivot = val; 
					swap++;
					break;
				}
			}
		}
		
		if (pivot != 0)
		{
			for (int j = i + 1; j < m->noofrows; j++)
			{
				float k = -get_element(m, j, i)/pivot;
			
				for (int l = i; l < m->noofcols; l++)
				{
					enter_element(m, j, l, get_element(m, j, l) + k * get_element(m, i, l));
				}
			}
		}
	}
	
	return swap;
}

float det(matrix* m)
{
	matrix cpy = matrix_create(m->noofrows, m->noofcols);
	
	for (int i = 0; i < m->noofrows; i++) 
	{
        for (int j = 0; j < m->noofcols; j++) 
		{
            enter_element(&cpy, i, j, get_element(m, i, j));
        }
    }
	
	int swaps = gaussian(&cpy);
	
	float det = 1.0;
	
	for (int i = 0; i < cpy.noofrows; i++)
	{
		det = det * get_element(&cpy, i, i);
	}
	
	if (swaps % 2 == 1)
	{
		det = -det;
	}
	
	matrix_delete(&cpy);
	return det;
	
}
