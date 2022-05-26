#ifndef UTILS
#define UTILS

typedef struct {
	//char sign;
	char *var;
	float coef;
} expression;

typedef struct {
	expression *exp;
	int nr_elem_of_exp;
} matrix_element;

typedef struct {
	int nr_rows, nr_columns;
	matrix_element **mat;
} matrix;

matrix_element **alloc(int, int);

void print_matrix(matrix);

void free_resources(matrix);

matrix copy_matrix(matrix, matrix);

#endif // UTILS.H 