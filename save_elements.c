#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

char *number_extraction(char *word, int i)
{
	char number[30]="";
	int k = 0;
	number[k++] = word[i];
	//printf("%c\n", number[0]);
	while((word[i+k] >= '0' && word[i+k] <='9') || word[i+k] == '.' )
	{
		number[k] = word[i+k];
		++k;
	}
	if(strlen(number) == 1 && number[0] == '-') {
	//	printf("a intrat\n");
		strcpy(number, "-1");
	}
	else if (strcmp(number, "+") == 0)
		strcpy(number, "1");
	char *aux = strdup(number);
	//printf("%s\n", aux);
	return aux;
}

char *var_extraction(char *word, int i)
{
	char var[10]="";
	int k = 0;
	while((word[i + k] >= 'a' && word[i + k] <='z') || (word[i + k] >= 'A' && word[i + k] <='Z')) {
		var[k] = word[i + k];
		++k;
	}
	//printf("%s\n", var);
	char *aux = strdup(var);
	return aux;
}

matrix_element save_element(matrix_element x, char *word)
{	
	expression *tmp = malloc(sizeof(expression));
	if (!tmp)
	{
		fprintf(stderr, "eroare alocare malloc\n");
		x.nr_elem_of_exp = 0;
		x.exp = NULL;
		return x;
	}
	int nr_elem_of_exp = 1;
	
	for(int i = 0; i < strlen(word); i++)
	{
		if((word[i] == '+' || word[i] == '-') && i != 0) {
			expression *aux = realloc(tmp, (nr_elem_of_exp + 1) * sizeof(expression));
			if(!aux) {
				fprintf(stderr, "eroare alocare realloc\n");
				x.nr_elem_of_exp = 0;
				x.exp = NULL;
				return x;
			}
			nr_elem_of_exp += 1;
			tmp = aux;
			//tmp[nr_elem_of_exp - 1].sign = word[i];
		} 
		if((word[i] >= '0' && word[i] <='9') || (word[i] == '+' || word[i] == '-')) {
			char *number = number_extraction(word, i);
			if(word[i] != '-' || (word[i+1] >= '0' && word[i+1] <='9'))
				i+=strlen(number) - 1;

			tmp[nr_elem_of_exp - 1].coef = atof(number);
			if(word[i + 1] == '+' || word[i + 1] == '-' || word[i+1] == '\0')
				tmp[nr_elem_of_exp - 1].var = strdup("-");
			
			free(number);
		} else if((word[i] >= 'a' && word[i] <='z') || (word[i] >= 'A' && word[i] <='Z')) {
			//printf("ok\n");
			char *var_string = var_extraction(word, i);
			tmp[nr_elem_of_exp - 1].var = var_string;
			if(i == 0)
				tmp[nr_elem_of_exp - 1].coef = 1;
			i+=strlen(var_string) - 1;
		}
	}
	x.exp = tmp;
	x.nr_elem_of_exp = nr_elem_of_exp;
	return x;
}

matrix_element simplify_exp(matrix_element x)
{
	for(int i = 0; i < x.nr_elem_of_exp - 1; i++) 
		for(int j = i + 1; j < x.nr_elem_of_exp; j++)
			if(strcmp(x.exp[i].var, x.exp[j].var) == 0) { 
				x.exp[i].coef += x.exp[j].coef;
				for(int q = j; q < x.nr_elem_of_exp - 1; q++) {
					x.exp[q].coef = x.exp[q + 1].coef;
					free(x.exp[q].var);
					x.exp[q].var = strdup(x.exp[q+1].var);
				}
				free(x.exp[--x.nr_elem_of_exp].var);
				expression *aux = realloc(x.exp, (x.nr_elem_of_exp) * sizeof(expression));
				if(!aux) {
					fprintf(stderr, "eroare alocare realloc\n");
					x.nr_elem_of_exp = 0;
					x.exp = NULL;
					return x;
				}
				x.exp = aux;
				j--;
			}
	return x;
}

matrix_element remove_null_elem(matrix_element x)
{
	for(int i = 0; i < x.nr_elem_of_exp; i++)
		if(x.exp[i].coef == 0) {
			for(int q = i; q < x.nr_elem_of_exp - 1; q++) {
				x.exp[q].coef = x.exp[q + 1].coef;
				free(x.exp[q].var);
				x.exp[q].var = strdup(x.exp[q+1].var);
			}
			free(x.exp[--x.nr_elem_of_exp].var);
			if(x.nr_elem_of_exp == 0)
			{
				x.exp[0].coef = 0;
				x.exp[0].var = strdup("-");
				x.nr_elem_of_exp++;
			} else {
				expression *aux = realloc(x.exp, (x.nr_elem_of_exp) * sizeof(expression));
				if(!aux) {
					fprintf(stderr, "eroare alocare realloc\n");
					x.nr_elem_of_exp = 0;
					x.exp = NULL;
					return x;
				}
				x.exp = aux;
				i--;
			}
			
		}
	return x;
}

char *alfanumeric_sort(char *var)
{
	for(int i = 0; i < strlen(var) - 1; i++)
		for(int j = i + 1; j < strlen(var); j++)
			if(var[i] > var[j]) {
				char aux = var[i];
				var[i] = var[j];
				var[j] = aux;
			}
	return var;
}

matrix_element sort_exp_var_alf(matrix_element x)
{
	for(int i = 0; i < x.nr_elem_of_exp - 1; i++)
		for(int j = i + 1; j < x.nr_elem_of_exp; j++)
			if(strcmp(x.exp[i].var, x.exp[j].var) > 0)
			{
				expression aux = x.exp[i];
				x.exp[i] = x.exp[j];
				x.exp[j] = aux;
			}
	return x;
}

matrix_element sort_exp_var(matrix_element x) 
{
	for(int i = 0; i < x.nr_elem_of_exp; i++)
		x.exp[i].var = alfanumeric_sort(x.exp[i].var);
	x = sort_exp_var_alf(x);  //sortam variabilele alfanumeric c+a+b -> a+b+c
	for(int i = 0; i < x.nr_elem_of_exp - 1; i++)
		for(int  j = i + 1; j < x.nr_elem_of_exp; j++)
			if(strlen(x.exp[i].var) < strlen(x.exp[j].var))
			{
				expression aux = x.exp[i];
				x.exp[i] = x.exp[j];
				x.exp[j] = aux;
			}
	return x;
}

matrix_element put_numbers_last(matrix_element x)
{
	for(int i = 0; i < x.nr_elem_of_exp - 1; i++)
		for(int j = i + 1; j < x.nr_elem_of_exp; j++)
			if(strcmp(x.exp[i].var, "-") == 0)
			{
				expression aux = x.exp[i];
				x.exp[i] = x.exp[j];
				x.exp[j] = aux;
			}
	return x;
}

matrix_element process_exp(matrix_element x)
{
	x = sort_exp_var(x);  //sortam variabilele alfabetic: baac -> aabc, apoi dupa lungime
	x = put_numbers_last(x);  // punem numerele la final: 3+a -> a+3
	x = simplify_exp(x);  //adunari, scaderi
	x = remove_null_elem(x);  //scoatem orice are, in urma calculelor, coef 0  
	return x;
}

matrix read_matrix(void)
{
	matrix a;
	scanf("%d%d", &a.nr_rows, &a.nr_columns);
	
	a.mat = alloc(a.nr_rows, a.nr_columns);
	
	for (char i = 0; i < a.nr_rows; i++)
		for (char j = 0; j < a.nr_columns; j++) {
			char word[100];
			scanf("%s", word);
			a.mat[i][j] = save_element(a.mat[i][j], word);
			a.mat[i][j] = process_exp(a.mat[i][j]);
		}
	return a;
}