#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/utils.h"

matrix *remove_matrix_function(matrix *p, int *index) 
{
	int  remove_index;
	scanf("%d", &remove_index);
	if(remove_index >= *index || remove_index < 0) {
		printf("Invalid index: out of bounds\n");
		return p;
	}

	free_resources(p[remove_index]);
	
	for(int i = remove_index; i < *index - 1; i++)
		p[i] = p[i+1];
	matrix *aux = realloc(p, --*index * sizeof(matrix));
	if(!aux && *index)
	{
		fprintf(stderr, "Eroare alocare realloc\n");
		return NULL;
	}
	p = aux;
	return p;
}