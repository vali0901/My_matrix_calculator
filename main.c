#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/utils.h"
#include "include/functions.h"

int main(char argc, char const *argv[])
{
	matrix *p;
	int index = 0;
	char command[16];
	do{
		scanf("%s", command);
		if(!strcmp("LOAD", command)) {
			p = load_matrix_function(p, &index);
		} else if(!strcmp("RMV", command)) { 
			p = remove_matrix_function(p, &index);
		} else if(!strcmp("PRINT", command)) {
			print_matrix_function(p, index);
		} else if(!strcmp("PRINT_ALL", command)) {
			print_all_matrix(p, index);
		} else if(!strcmp("TRANSP", command)) {
			p = matrix_transposition_function(p, index);
		} else if(!strcmp("EXIT", command)) {
			free_resources_function(p, index);
		} else if(!strcmp("SUM", command)) {
			p = sum_matrix_function(p, &index);
		} else if(!strcmp("MUL", command)) {
			p = multiplication_matrix_function(p, &index);
		} else if(!strcmp("SCALE", command)) {
			p = scale_matrix_function(p, index);
		} else {
			printf("Unrecognized command\n");
		}
		char buff;
		do {
			scanf("%c", &buff);
		} while(buff != '\n');
	} while(strcmp("EXIT", command));

	return 0;
}