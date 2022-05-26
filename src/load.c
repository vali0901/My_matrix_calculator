#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/utils.h"
#include "../include/save_elements.h"

matrix *load_matrix_function(matrix *p, int *index)
{
	if(*index == 0) {
		p = malloc(++*index * sizeof(matrix));
	} else {
		matrix *aux = realloc(p, ++*index * sizeof(matrix));
		if(!aux) {
			fprintf(stderr, "eroare alocare realloc\n");
			*index = 0;
			return NULL;
		}
		p = aux;
	}
	p[*index - 1] = read_matrix();
	return p;
}