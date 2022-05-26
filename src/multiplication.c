#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/utils.h"
#include "../include/save_elements.h"

matrix_element exp_multiplication(matrix_element first_el, matrix_element second_el)
{
	matrix_element new_el;
	new_el.exp = malloc(sizeof(expression) * (first_el.nr_elem_of_exp * second_el.nr_elem_of_exp));

	int k = 0;
	for(int i = 0; i < first_el.nr_elem_of_exp; i++)
		for(int j = 0; j < second_el.nr_elem_of_exp; j++) {
			char curr_var[32];
			strcpy(curr_var, first_el.exp[i].var);
			strcat(curr_var, second_el.exp[j].var);
			for(int q = 0; q < strlen(curr_var); q++)
				if(curr_var[q] == '-') {
					strcpy(curr_var + q, curr_var + q + 1);
					q--;
				}
			if(strlen(curr_var) == 0)
				strcpy(curr_var, "-");
			new_el.exp[k].var = strdup(curr_var);

			float curr_coef = first_el.exp[i].coef * second_el.exp[j].coef;
			new_el.exp[k++].coef = curr_coef;
		}
	new_el.nr_elem_of_exp = k;
	return new_el;
}

matrix *multiplication_matrix_function(matrix *p, int *index)
{
	int multiplication_index[2];
	scanf("%d%d", multiplication_index, multiplication_index + 1);
	
	if(multiplication_index[0] > *index || multiplication_index[0] < 0 || multiplication_index[1] > *index || multiplication_index[1] < 0) {
		printf("Invalid index\n");
		return p;
	}
	if(p[multiplication_index[0]].nr_columns != p[multiplication_index[1]].nr_rows)
	{
		printf("Invalid nr_rows/nr_columns\n");
		return p;
	}

	matrix_element **new_matrix = alloc(p[multiplication_index[0]].nr_rows, p[multiplication_index[1]].nr_columns);
	for(int i = 0; i < p[multiplication_index[0]].nr_rows; i++)
		for(int j = 0; j < p[multiplication_index[1]].nr_rows; j++) {
			new_matrix[i][j].nr_elem_of_exp = 0;
			for(int k = 0; k < p[multiplication_index[0]].nr_columns; k++) {
				matrix_element tmp = exp_multiplication(p[multiplication_index[0]].mat[i][k], p[multiplication_index[1]].mat[k][j]);
				
				if(new_matrix[i][j].nr_elem_of_exp == 0) {
					new_matrix[i][j].exp = malloc(sizeof(expression) * tmp.nr_elem_of_exp);
					new_matrix[i][j].nr_elem_of_exp = tmp.nr_elem_of_exp;
				} else {
					expression *aux = realloc(new_matrix[i][j].exp, (new_matrix[i][j].nr_elem_of_exp + tmp.nr_elem_of_exp) * sizeof(expression));
					if(!aux) {
						fprintf(stderr, "eroare alocare realloc\n");
						return p;
					}
					new_matrix[i][j].exp = aux;
					new_matrix[i][j].nr_elem_of_exp += tmp.nr_elem_of_exp;
				}
				memcpy(new_matrix[i][j].exp + new_matrix[i][j].nr_elem_of_exp - tmp.nr_elem_of_exp, tmp.exp, tmp.nr_elem_of_exp * sizeof(expression));
				// for(int q = 0; q < tmp.nr_elem_of_exp; q++)
				// 	free(tmp.exp[q].var);
				free(tmp.exp);
			}
			new_matrix[i][j] = process_exp(new_matrix[i][j]);
		}
	matrix *aux = realloc(p, ++*index * sizeof(matrix));
	if(!aux) {
		fprintf(stderr, "eroare alocare realloc\n");
		*index = 0;
		return NULL;
	}
	p = aux;
	p[*index - 1].nr_rows = p[multiplication_index[0]].nr_rows;
	p[*index - 1].nr_columns = p[multiplication_index[1]].nr_columns;
	p[*index - 1].mat = new_matrix;
	return p;
}