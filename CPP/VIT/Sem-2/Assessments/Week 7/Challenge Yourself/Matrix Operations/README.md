Single File Programming Question
Problem Statement



Write a C++ program that defines a Matrix class capable of performing various matrix operations. The class should allow matrix multiplication, transpose, and input/output operations. 



In the main function, the program should take two matrices as input, calculate their product (if valid), and display the result. Additionally, it should compute and display the transpose of the first matrix.

Input format :
The first line of input contains two integers rows1 and cols1, representing the dimensions of the first matrix.

The next rows1 lines contain cols1 integers each, representing the elements of the first matrix.

The following line contains two integers rows2 and cols2, representing the dimensions of the second matrix.

The next rows2 lines contain cols2 integers each, representing the elements of the second matrix.

Output format :
The output displays the following:

The result of matrix multiplication with each element separated by spaces and rows separated by newlines.
The transpose of the first matrix with each element separated by spaces and rows separated by newlines.


Refer to the sample outputs for the formatting specifications.

Code constraints :
1 ≤ rows1, cols1, rows2, cols2 ≤ 10

-100 ≤ The matrix elements (integers) ≤ 100

Sample test cases :
Input 1 :
2 2
2 3
4 5
2 2
1 2
3 4
Output 1 :
Matrix product:
11 16 
19 28 
Transpose of the first matrix:
2 4 
3 5 
Input 2 :
2 2
1 2
3 4
2 2
2 3
4 5
Output 2 :
Matrix product:
10 13 
22 29 
Transpose of the first matrix:
1 3 
2 4 