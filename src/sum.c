#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/utils.h"
#include "../include/save_elements.h"

matrix_element sum_matrix_elements(matrix_element first_el, matrix_element second_el)
{
	matrix_element new_el;
	new_el.nr_elem_of_exp = first_el.nr_elem_of_exp + second_el.nr_elem_of_exp;
	new_el.exp = malloc(sizeof(expression) * (new_el.nr_elem_of_exp));

	for(int i = 0; i < first_el.nr_elem_of_exp; i++)
	{
		new_el.exp[i].var = strdup(first_el.exp[i].var);
		new_el.exp[i].coef = first_el.exp[i].coef;
	}
	
	int k = first_el.nr_elem_of_exp;

	for(int i = 0; i < second_el.nr_elem_of_exp; i++)
	{
		new_el.exp[k + i].var = strdup(second_el.exp[i].var);
		new_el.exp[k + i].coef = second_el.exp[i].coef;
	}

	return new_el;
}

matrix *sum_matrix_function(matrix *p, int *index)
{
	int sum_index[2];
	scanf("%d%d", sum_index, sum_index + 1);

	if(sum_index[0] > *index || sum_index[0] < 0 || sum_index[1] > *index || sum_index[1] < 0) {
		printf("Invalid index, matrix does not exist.\n");
		return p;
	}

	if(p[sum_index[0]].nr_columns != p[sum_index[1]].nr_columns || p[sum_index[0]].nr_rows != p[sum_index[1]].nr_rows) {
		printf("Invalid index, different matrix sizes.\n");
		return p;
	}

	matrix_element **new_matrix = alloc(p[sum_index[0]].nr_rows, p[sum_index[0]].nr_columns);

	for(int i = 0; i < p[sum_index[0]].nr_rows; i++)
		for(int j = 0; j < p[sum_index[1]].nr_columns; j++) {
			new_matrix[i][j] = sum_matrix_elements(p[sum_index[0]].mat[i][j], p[sum_index[1]].mat[i][j]);
			new_matrix[i][j] = process_exp(new_matrix[i][j]);
		}

	matrix *aux = realloc(p, ++*index * sizeof(matrix));
	if(!aux) {
		fprintf(stderr, "eroare alocare realloc\n");
		*index = 0;
		return NULL;
	}

	p = aux;
	p[*index - 1].nr_rows = p[sum_index[0]].nr_rows;
	p[*index - 1].nr_columns = p[sum_index[0]].nr_columns;
	p[*index - 1].mat = new_matrix;
	return p;
}