#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

// free
void free_resources_function(matrix*, int);

// load
matrix *load_matrix_function(matrix*, int*);

// print
void print_matrix_function(matrix*, int);

// remove
matrix *remove_matrix_function(matrix*, int*);

// sum
matrix *sum_matrix_function(matrix*, int*);

// transposition
matrix matrix_transposition(matrix);

matrix *matrix_transposition_function(matrix*, int);

// multiplication
matrix_element exp_multiplication(matrix_element, matrix_element);

matrix *multiplication_matrix_function(matrix*, int*);

// print_all
void print_all_matrix(matrix*, int);

// scale
matrix *scale_matrix_function(matrix*, int);

#endif