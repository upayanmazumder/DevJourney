# Customer Loyalty Program

## Single File Programming Question

## Problem Statement

In a customer loyalty program, reward points are logged in a sorted array as customers make transactions. Occasionally, due to system errors, duplicate entries for the same transaction may appear. To ensure accurate reward calculations, it's crucial to remove these duplicates from the list.
Write a program to process the array of reward points, removing any duplicates while preserving the order of unique entries. The program should then display the cleaned list of unique reward points and the total count of these unique points.
#### Input:

```
format :
```

The first line of input consists of an integer N, representing the number of reward points.
The second line consists of N space-separated integers, representing the reward points in sorted order.
#### Output:

```
format :
```

The first line of output prints the cleaned list of unique reward points separated by a space.
The second line of output prints an integer representing the total count of unique reward points.
Refer to the sample output for the formatting specifications.
Code constraints :
haThe given test cases fall under the following constraints:
1 ≤ N ≤ 12
1 ≤ reward points ≤ 500
Sample test cases :
#### Input 1:

```
3 100 100 200
Output 1 :
100 200 2
Input 2 :
5 10 10 20 20 30
Output 2 :
10 20 30 3
```
