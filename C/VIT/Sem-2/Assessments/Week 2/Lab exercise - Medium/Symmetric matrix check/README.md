# Single File Programming Question

## Problem Statement

Lakshith and Manav, best friends, enjoy summer vacation playing games. This time, they delve into matrix manipulation. They write a program to determine if a matrix is symmetric by comparing it with its transpose.

If the matrix is symmetric, they celebrate their victory; otherwise, they continue their quest for the perfect game.

### Input format :

The first line of input consists of an integer N, representing the size of the matrix.

The next N lines consist of N space-separated integers, representing the matrix elements.

### Output format :

The first line of output prints "Original matrix:".

The next N lines print N elements in each line representing the original matrix.

The following line prints "Transpose matrix:".

The next N lines print N elements in each line representing the transpose of the original matrix.

The last line prints one of the following:

If both matrices are symmetric, print "Matrix is Symmetric!"
If both matrices are not symmetric, print "Matrix is not Symmetric!"

Refer to the sample output for formatting specifications.

### Code constraints :

1 ≤ N ≤ 10

### Sample test cases :

#### Input 1 :

3
1 7 3
7 4 5
3 5 6

#### Output 1 :

Original matrix:
1 7 3
7 4 5
3 5 6
Transpose matrix:
1 7 3
7 4 5
3 5 6
Matrix is Symmetric!

#### Input 2 :

3
1 2 3
4 5 6
1 8 7

#### Output 2 :

Original matrix:
1 2 3
4 5 6
1 8 7
Transpose matrix:
1 4 1
2 5 8
3 6 7
Matrix is not Symmetric!
