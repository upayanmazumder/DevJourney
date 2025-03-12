# Single File Programming Question

## Problem Statement

Patrick is developing a program for financial transactions. Your task is to assist him in completing the program.

You are given two arrays, each of size N. The first array contains a set of positive integers representing the transaction amount, and the second array contains binary values (0s and 1s), where 0 represents a positive sign(credit), and 1 represents a negative sign(debit).

Implement a program that negates(changes the sign) the corresponding transaction amount using pointers. After the negation operation, print the resulting array.

Example

Input:

5

100 200 120 345 667

1 0 1 0 1

Output:

-100 200 -120 345 -667

Explanation:

There are 5 financial transactions {100, 200, 120, 345, 667}. The second array indicates whether each transaction is a credit (0) or debit (1). The program changes the sign of the transaction amounts based on the corresponding binary values, resulting in the output: {-100, 200, -120, 345, -667}.

### Input format :

The first line of input consists of a positive integer N, representing the number of transactions.

The second line consists of N space-separated positive integers, representing the transaction amount.

The third line consists of N space-separated binary values (0s and 1s) representing the nature of the transaction (credit or debit).

### Output format :

The output prints N space-separated integers, along with a sign (positive/negative) representing the nature of each transaction.

Refer to the sample output for formatting specifications.

### Code constraints :

In this scenario, the test cases fall under the following constraints:

1 ≤ N ≤ 20

1 ≤ transaction amount ≤ 103

### Sample test cases :

#### Input 1 :

4
55 89 98 56
0 1 1 0

#### Output 1 :

55 -89 -98 56

#### Input 2 :

5
125 678 954 345 252
1 0 0 0 1

#### Output 2 :

-125 678 954 345 -252

#### Input 3 :

5
100 200 120 345 667
1 0 1 0 1

#### Output 3 :

-100 200 -120 345 -667
