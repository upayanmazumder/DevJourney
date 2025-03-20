# Single File Programming Question

## Problem Statement

Implement a Matrix class that represents a two-dimensional matrix of integers. The class should have methods to create a matrix, set its elements, and print the matrix. Additionally, implement a function to calculate the transpose of a matrix. The program should prompt the user to enter the dimensions of the matrix and its elements, display the original matrix, and then display the transposed matrix.

Function Signature: Matrix Transpose(const Matrix& matrix);

### Input format :

The first line contains two integers, numRows and numCols, representing the number of rows and columns of the matrix.

The next numRows lines each contain numCols integers separated by spaces, representing the elements of the matrix.

### Output format :

The output prints the following details:

First print the following for the Original Matrix:

"Original Matrix:"

Followed by the matrix elements, row by row, separated by spaces.

Finally, print the following for the Transposed Matrix:

"Transposed Matrix:"

Followed by the transposed matrix elements, row by row, separated by spaces.

Refer to the sample output for formatting specifications.

### Code constraints :

The given test cases fall under the following constraints:

1 ≤ numRows, numCols ≤ 10

−10 ≤ Matrix Elements ≤ 10

### Sample test cases :

#### Input 1 :

2 2
1 2
3 4

#### Output 1 :

Original Matrix:
1 2
3 4
Transposed Matrix:
1 3
2 4

#### Input 2 :

3 3
5 6 7
8 9 10
11 12 13

#### Output 2 :

Original Matrix:
5 6 7
8 9 10
11 12 13
Transposed Matrix:
5 8 11
6 9 12
7 10 13

#### Input 3 :

3 1
9
8
7

#### Output 3 :

Original Matrix:
9
8
7
Transposed Matrix:
9 8 7
