#ifndef SAVE_ELEM
#define SAVE_ELEM

char *number_extraction(char, int);

char *var_extraction(char, int);

matrix_element save_element(matrix_element, char);

matrix_element simplify_exp(matrix_element);

matrix_element remove_null_elem(matrix_element);

char *alfanumeric_sort(char);

matrix_element sort_exp_var(matrix_element);

matrix_element sort_exp_var_alf(matrix_element);

matrix_element put_numbers_last(matrix_element);

matrix_element process_exp(matrix_element);

matrix read_matrix(void);

#endif