#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils.h"

void free_resources_function(matrix *p, int index)
{
	if(index) {
		for(int i = 0; i < index; i++)
			free_resources(p[i]);
		free(p);
	}
}