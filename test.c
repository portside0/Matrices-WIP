#include <stdio.h>
#include "matrix.c"

int main()
{
	int r, c;
	scanf("%i %i", &r, &c);
	
	matrix m1 = create_matrix(r, c);
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			float n;
			scanf("%f", &n);
			enter_element(&m1, i, j, n);
		}
	}
	
	print_matrix(&m1);
	
	delete_matrix(&m1);
}