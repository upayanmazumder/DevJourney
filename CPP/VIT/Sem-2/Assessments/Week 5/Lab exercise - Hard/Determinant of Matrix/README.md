# Single File Programming Question

## Problem Statement

﻿Write a program that calculates the determinant of a square matrix. The program should take the size of the square matrix as input, followed by the elements of the matrix. It should then display the matrix and calculate the determinant. Finally, it should output the determinant value.

The Matrix class has the following member functions:

Matrix(int n): Constructor that takes an integer n as a parameter to initialize a square matrix of size n by dynamically allocating memory.

void readMatrix(): Reads the elements of the matrix from the standard input.

void displayMatrix(): Displays the matrix on the standard output.

int determinant(): Calculates and returns the determinant of the matrix using a recursive approach.

int determinantOfSubMatrix(int\*\* subMatrix, int subSize): Helper function used by determinant() to calculate the determinant of a submatrix.

### Input format :

The first line contains an integer n represents the size of the square matrix.

The next n lines contain n integers each, representing the elements of the matrix.

### Output format :

The program should display the matrix in a square format.

It should output a single line with the determinant value.

Refer to the sample output for format specifications.

### Sample test cases :

#### Input 1 :

4
2 4 1 7
3 2 5 1
1 2 3 4
5 6 7 8

#### Output 1 :

Matrix:
2 4 1 7
3 2 5 1
1 2 3 4
5 6 7 8
Determinant: 4

#### Input 2 :

3
1 2 3
4 5 6
7 8 9

#### Output 2 :

Matrix:
1 2 3
4 5 6
7 8 9
Determinant: 0

#### Input 3 :

2
5 -2
3 1

#### Output 3 :

Matrix:
5 -2
3 1
Determinant: 11
