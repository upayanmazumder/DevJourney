# Emma - Computer Vision Enthusiast

## Single File Programming Question

## Problem Statement

Emma, a budding computer vision enthusiast, is working on a challenging image processing project. She has a square image represented as a 2D matrix of integers. As part of a special filter operation, she needs to rotate the image by 90 degrees clockwise, but there's a twist — she must perform the rotation in-place, using no extra space.

This means Emma has to rotate the matrix without creating a new one. Your task is to help her implement a Java program that takes this square matrix as input and rotates it within the same structure.

Can you help Emma efficiently rotate the image so that her project can move to the next stage?

#### Input:

```
format :
```

The first line of input contains a single integer n, representing the number of rows and columns of the square matrix (i.e., the matrix is of size n x n).

The next n lines each contain n space-separated integers, representing the elements of each row of the 2D array.

#### Output:

```
format :
```

The first line of output prints "Rotated 2D Array:"

The next n lines of output print the rotated matrix.

Each line contains n space-separated integers representing a row of the rotated matrix.

Refer to the sample output for format specification.

Code constraints :

1 ≤ n ≤ 50

-500 ≤ mat[n][n] ≤ 500

You must write a program that rotates the 2D array by 90 degrees in-place.

You are not allowed to create a new array to store the rotated matrix.

Sample test cases :

#### Input 1:

3 1 2 3 4 5 6 7 8 9

#### Output 1:

Rotated 2D Array: 7 4 1 8 5 2 9 6 3

#### Input 2:

4 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

#### Output 2:

Rotated 2D Array: 13 9 5 1 14 10 6 2 15 11 7 3 16 12 8 4
