#include <stdio.h>
#include "matrix.c"

int main()
{
	int r1, c1, r2 ,c2;
	
	printf("Enter dimension of first matrix\n");
	scanf("%i %i", &r1, &c1);
	printf("Enter the dimensions of second matrix\n");
	scanf("%i %i", &r2, &c2);
	
	matrix m1 = matrix_create(r1, c1);
	matrix m2 = matrix_create(r2, c2);
	
	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j < c1; j++)
		{
			float n;
			scanf("%f", &n);
			enter_element(&m1, i, j, n);
		}
	}
	
	for (int i = 0; i < r2; i++)
	{
		for (int j = 0; j < c2; j++)
		{
			float n;
			scanf("%f", &n);
			enter_element(&m2, i, j, n);
		}
	}
	
	printf("First matrix is:\n");
	matrix_print(&m1);
	printf("Second matrix is:\n");
	matrix_print(&m2);
	printf("Result:\n");
	matrix res = matrix_multiply(&m1, &m2);
	
	matrix_print(&res);
	
	matrix_delete(&m1);
	matrix_delete(&m2);
	matrix_delete(&res);
	
}