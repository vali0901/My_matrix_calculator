#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/utils.h"

matrix *scale_matrix_function(matrix *p, int index)
{
	int scale_index;
	scanf("%d", &scale_index);

	if(scale_index < 0 || scale_index >= index) {
		printf("Invalid index: index out of bounds.\n");
	}
	
	float scalar;
	scanf("%f", &scalar);

	for(int i = 0; i < p[scale_index].nr_rows; i++)
		for(int j = 0; j < p[scale_index].nr_columns; j++)
			for(int q = 0; q < p[scale_index].mat[i][j].nr_elem_of_exp; q++)
				p[scale_index].mat[i][j].exp[q].coef *= scalar;
	return p;
}