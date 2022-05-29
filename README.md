# MY_MATRIX_CALCULATOR
My_matrix_calculator is a project in which operations can be performed on
matrices that may contain unknown variables. Each matrix can be recognised
by an index that shows its position in the memory. The program can do several
operations:

## LOAD
-> it loads into the memory a new matrix, at the end of the matrices array

usage: 
LOAD 2 3
1 2 3
a 2 a
(this loads into memory a matrix with 2 rows and 3 columns with 
the specified values)
-------------------------------------------------------------------------------
## RMV
-> removes a matrix from memory, depending on the given index

usage:
RMV 0
(removes the first matrix in the matrices array, all the other matrices moving
with a position to the left)
----------------------------------------------------------------------------------
## PRINT
-> prints a matrix, depending on the given index

usage:
PRINT 0
(prints the first matrix, without changing anything)
----------------------------------------------------------------------------------
## PRINT_ALL
-> prints all matrices in the memory

usage:
PRINT_ALL
-----------------------------------------------------------------------------------
## TRANSP 
-> modifies the matrix with the given index with its transpose

usage:
TRANSP 0
(modifies the first matrix with its transpose, if the matrix is [1, 2, 3],
after the TRANSP command, the matrix will be [1; 2; 3])
-----------------------------------------------------------------------------------
## SUM
-> creates a new matrix which will be placed at the end of the matrices array,
and will be the result of adding two matrices with the given index

usage:
SUM 0 1
(creates a new_matrix, the result of adding the first and the second matrix)
-----------------------------------------------------------------------------------
## MUL
-> same as sum, but it is the result of multiplying two matrices

usage:
MUL 0 1
it can also be:
MUL 0 0
-----------------------------------------------------------------------------------
## SCALE
-> scales a matrix with a number

usage:
SCALE 0 2
(it scales the first matrix with 2, if the first matrix is [1, a, 4],
after this command it will be [2, 2a, 8])
-----------------------------------------------------------------------------------
## EXIT
-> closes the program and frees all the resources used

-----------------------------------------------------------------------------------
## CONSTRAINTS:
If you wish working with unknown variables, please use one-letter named variables,
otherwise the program will not work as wished.
-----------------------------------------------------------------------------------
## CONVENTIONS:
a^2 = aa
a^3 * d^2 * c * b = aaabcdd
(the variables will be sortet alphabetically)
