#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/utils.h"

matrix_element **alloc(int n, int m)
{
	matrix_element **mat;
	
	matrix_element **tmp = (matrix_element **)malloc(n * sizeof(matrix_element *));
	if (!tmp) {
		fprintf(stderr, "eroare alocare malloc\n");
		return NULL;
	}
	
	for (int i = 0; i < n; i++) {
		tmp[i] = (matrix_element *)malloc(m * sizeof(matrix_element));
		if (!tmp[i]) {
			fprintf(stderr, "eroare alocare malloc\n");
			return NULL;
			for (int j = 0; j < i; j++)
				free(tmp[i]);
		}
	}
	mat = tmp;
	
	return mat;
}

void print_matrix(matrix x)
{
	for(int i = 0; i < x.nr_rows; i++) {
		for(int j = 0; j < x.nr_columns; j++) {
			// printf("%d\n", p[0].mat[i][j].nr_elem_of_exp);
			for(int q = 0; q < x.mat[i][j].nr_elem_of_exp; q++) {
				if(x.mat[i][j].exp[q].coef > 0 && q != 0)
					printf("+");
				if(x.mat[i][j].exp[q].coef == -1 && strcmp(x.mat[i][j].exp[q].var, "-"))
					printf("-");
				if((strcmp(x.mat[i][j].exp[q].var, "-") && x.mat[i][j].exp[q].coef != 1 && x.mat[i][j].exp[q].coef != -1)
					|| (!strcmp(x.mat[i][j].exp[q].var, "-")))
					printf("%.2f", x.mat[i][j].exp[q].coef);
				if(strcmp(x.mat[i][j].exp[q].var, "-"))
					printf("%s", x.mat[i][j].exp[q].var);
			}
			printf(" ");
		}
		printf("\n");
	}
}

void free_resources(matrix p)
{
	for (int i = 0; i < p.nr_rows; i++) {
		for(int j = 0; j < p.nr_columns; j++) {
			for(int q = 0; q < p.mat[i][j].nr_elem_of_exp; q++)
				free(p.mat[i][j].exp[q].var);
			free(p.mat[i][j].exp);
		}
		free(p.mat[i]);
	}
	free(p.mat);
	//return p;
}

matrix copy_matrix(matrix x, matrix y)
{
	x.nr_rows = y.nr_rows;
	x.nr_columns = y.nr_columns;
	x.mat = alloc(x.nr_rows, x.nr_columns);
	for(int i = 0; i < x.nr_rows; i++)
		for(int j = 0; j < x.nr_columns; j++) {
			x.mat[i][j].nr_elem_of_exp = y.mat[i][j].nr_elem_of_exp;
			x.mat[i][j].exp = malloc(x.mat[i][j].nr_elem_of_exp * sizeof(expression));
			for(int q = 0; q < x.mat[i][j].nr_elem_of_exp; q++) {
				x.mat[i][j].exp[q].coef = y.mat[i][j].exp[q].coef;
				x.mat[i][j].exp[q].var = strdup(y.mat[i][j].exp[q].var);
			}
		}
	return x;
}