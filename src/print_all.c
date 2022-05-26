#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/utils.h"
#include "../include/functions.h"

void print_all_matrix(matrix *p, int index)
{
	if(index == 0)
		printf("there are no matrixes to be printed\n");
	for(int i = 0; i < index; i++) {
		printf("Matrix %d\n", i);
		print_matrix(p[i]);
		printf("\n");
	}
}