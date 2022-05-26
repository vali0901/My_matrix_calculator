#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/utils.h"

matrix matrix_transposition(matrix x)
{
	matrix tmp;
	tmp.mat = alloc(x.nr_columns, x.nr_rows);
	tmp.nr_rows = x.nr_columns;
	tmp.nr_columns = x.nr_rows;
	for(int i = 0; i < tmp.nr_rows; i++)
		for(int j = 0; j < tmp.nr_columns; j++) {
			tmp.mat[i][j].nr_elem_of_exp = x.mat[j][i].nr_elem_of_exp;
			tmp.mat[i][j].exp = malloc(tmp.mat[i][j].nr_elem_of_exp * sizeof(expression));
			for(int q = 0; q < tmp.mat[i][j].nr_elem_of_exp; q++) {
				tmp.mat[i][j].exp[q].coef = x.mat[j][i].exp[q].coef;
				tmp.mat[i][j].exp[q].var = strdup(x.mat[j][i].exp[q].var);
			}
		}
	free_resources(x);
	x.mat = tmp.mat;
	int aux = x.nr_rows;
	x.nr_rows = x.nr_columns;
	x.nr_columns = aux;
	return x;
}

matrix *matrix_transposition_function(matrix *p, int index)
{
	int transposition_index;
	scanf("%d", &transposition_index);
	if(transposition_index < index && transposition_index >= 0)
		p[transposition_index] = matrix_transposition(p[transposition_index]);
	else
		printf("Invalid index: out of bounds\n");
	return p;
}