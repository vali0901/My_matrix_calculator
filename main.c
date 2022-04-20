#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "functions/functions.h"
// #include "functions/remove.h"
// #include "functions/transposition.h"
// #include "functions/print.h"
// #include "functions/free.h"
// #include "functions/sum.h"

int main(char argc, char const *argv[])
{
	matrix *p;
	int index = 0;
	char command;
	do {
		do {
			scanf("%c", &command);
		} while(command == '\n' || command == ' ');
		switch (command) {
		case 'L':
			p = load_matrix_function(p, &index);
		break;
		case 'R':
			p = remove_matrix_function(p, &index);
		break;
		case 'P':
			print_matrix_function(p, index);
		break;
		case 'T':
			p = matrix_transposition_function(p, index);
		break;
		case 'Q':
			free_resources_function(p, index);
		break;
		case 'S':
			p = sum_matrix_function(p, &index);
		break;
		case 'M':
			p = multiplication_matrix_function(p, &index);
		break;
		default:
			printf("Unrecognized command\n");
		break;
		}
	} while(command != 'Q');

	return 0;
}