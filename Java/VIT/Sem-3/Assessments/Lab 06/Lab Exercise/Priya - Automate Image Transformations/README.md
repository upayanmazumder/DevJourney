# Priya - Automate Image Transformations

## Single File Programming Question

## Problem Statement

Priya is building a system to automate image transformations using matrix operations. To do this, she needs to multiply two matrices representing pixel data and transformation rules.

Help Priya perform matrix multiplication and print the resulting matrix if the operation is valid.

#### Input:

```
format :
```

The first line of input consists of two int values, representing the number of rows R1 and columns C1 of the first matrix.

The next R1 × C1 integers represent the elements of the first matrix.

The next line consists of two int values, representing the number of rows R2 and columns C2 of the second matrix.

The next R2 × C2 integers represent the elements of the second matrix.

#### Output:

```
format :
```

If matrix multiplication is possible, print R1 lines, each containing C2 space-separated int values representing the resulting matrix.

Otherwise, print "Matrix multiplication not possible".

Refer to the sample output for formatting specifications.

Code constraints :

The given test cases fall under the following constraints:

1 ≤ R1, C1, R2, C2 ≤ 10

0 ≤ Matrix Elements ≤ 10000

Sample test cases :

#### Input 1:

2 3 1 2 3 4 5 6 3 2 7 8 9 10 11 12

#### Output 1:

58 64 139 154

#### Input 2:

1 1 5 1 1 4

#### Output 2:

20
