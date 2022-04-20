#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_


void free_resources_function(matrix*, int);


matrix *load_matrix_function(matrix*, int*);


void print_matrix_function(matrix*, int);


matrix *remove_matrix_function(matrix*, int*);


matrix *sum_matrix_function(matrix*, int*);


matrix matrix_transposition(matrix);

matrix *matrix_transposition_function(matrix*, int);


matrix_element exp_multiplication(matrix_element, matrix_element);

matrix *multiplication_matrix_function(matrix*, int*);


#endif