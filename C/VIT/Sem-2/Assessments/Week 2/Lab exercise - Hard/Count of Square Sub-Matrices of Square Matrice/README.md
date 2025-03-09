Single File Programming Question
Problem Statement



Given a square matrix of size N consisting of positive integers. Find the count of all the square sub-matrices, the sum of whose elements is equal to a given number S.



Example



Input:

3

1 2 3

4 5 6

7 8 9

16

Output:

1

Explanation:

In the given matrix, the sub-matrix (0, 1) to (1, 2) with sum = 2 + 3 + 5 + 6 = 16. So, the output is the count of all the square sub-matrices, the sum of whose elements is equal to S, which is 1.

Input format :
The first line of input consists of a single integer N, denoting the size of the input matrix.

The following N lines consist of N space-separated positive integers, denoting the array's elements.

The last line consists of a single positive integer S, denoting the required sum.

Output format :
The output prints an integer denoting the count of all the square sub-matrices, the sum of whose elements is equal to S.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ N ≤ 5

Sample test cases :
Input 1 :
3
6 3 5 
1 8 2 
4 8 0
21
Output 1 :
1
Input 2 :
3
1 2 3
4 5 6
7 8 9
16
Output 2 :
1