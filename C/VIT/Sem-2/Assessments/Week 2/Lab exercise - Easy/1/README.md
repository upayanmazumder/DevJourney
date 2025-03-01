# Single File Programming Question

## Problem Statement

Raveena is developing a program to analyze an integer array. Her task is to identify and tally the negative numbers within this array. This analysis is crucial for Raveena's dataset, as negative values might represent specific conditions or anomalies that require further investigation.

Write a program that assists Raveena in counting and displaying the number of negative elements in an integer array.

### Input format :

The first line of input consists of an integer n, representing the number of elements in the array.

The second line of input consists of n space-separated integers, representing the elements of the array.

### Output format :

If there are no negative elements in the array, the output prints "No negative elements in the array".

Otherwise, the output prints "Total negative elements in array = " followed by an integer which is the total count of negative elements in the array.

Refer to the sample output for the formatting specifications.

### Code constraints:

In this scenario, the test cases will fall under the following constraints:

3 ≤ n ≤ 10

-1000 ≤ elements ≤ 1000

### Sample test cases:

#### Input 1:

10
10 -2 5 -20 1 50 60 -50 -12 -9

#### Output 1:

Total negative elements in array = 5

#### Input 2:

5
6 3 2 1 9

#### Output 2:

No negative elements in the array

#### Input 3:

3
-1000 -99 1000

#### Output 3:

Total negative elements in array = 2