# Single File Programming Question

## Problem Statement

In a data processing application, a developer named Sneha is responsible for creating a utility that calculates the sum of unique integers from a user-provided list. To achieve this, Sneha decides to utilize the Standard Template Library (STL) list. The utility should ensure that duplicate integers are removed before calculating the sum.

Write a program that reads a list of integers from the user, checks if the size of the list is within a specific limit, and then computes the sum of the unique integers. If the size exceeds the limit, the program should output "-1".

### Input format :

The first line contains an integer N, the number of elements in the list.

The second line contains N integers separated by spaces, which represent the elements of the list.

### Output format :

If N is greater than 15, output: "-1".

Otherwise, output:

"Sum of unique elements: <sum>"

where <sum> is the sum of all unique integers in the list.

Refer to the sample output for formatting specifications.

### Code constraints :

1 ≤ N ≤ 15

1 ≤ elements ≤ 100

### Sample test cases :

#### Input 1 :

5
1 5 4 4 1

#### Output 1 :

Sum of unique elements: 10

#### Input 2 :

20

#### Output 2 :

-1

Whitelist
Set 1:
list
