#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/utils.h"

void print_matrix_function(matrix *p, int index)
{
	int print_index;
	scanf("%d", &print_index);
	if(print_index < index && print_index >= 0)
		print_matrix(p[print_index]);
	else
		printf("Invalid print matrix index\n");
}