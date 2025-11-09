# Monitoring System

## Single File Programming Question

## Problem Statement

Bobby is tasked with processing a sequence of numbers from a monitoring system. He needs to extract a strictly increasing subsequence using an ArrayList. The program should dynamically add numbers to the ArrayList only if they are greater than the last number currently stored in the list. Bobby aims to efficiently utilize the dynamic resizing and indexing features of the ArrayList to solve this problem.

Help Bobby implement this solution.

#### Input:

```
format :
```

The first line of input consists of an integer N, representing the number of elements.

The second line consists of N space-separated integers, representing the elements.

#### Output:

```
format :
```

The output prints the list of integers in increasing sequence, ignoring out-of-order elements.

Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints

1 ≤ N ≤ 20

1 ≤ elements ≤ 100

Sample test cases :
#### Input 1:

```
7
3 5 9 1 11 7 13
Output 1 :
[3, 5, 9, 11, 13]
Input 2 :
4
11 7 5 1
Output 2 :
[11]
Input 3 :
5
12 37 12 10 39
Output 3 :
[12, 37, 39]
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
image
Header Snippet
12
import java.util.ArrayList;import java.util.Scanner;
Fill your code here
Java (17)
theme
instruction
1234
// You are using Java-17version class NumberProcessor { //type your code here}
Footer Snippet
12345678910
public class Main { public static void main(String[] args) { Scanner input = new Scanner(System.in); int number_of_elements = input.nextInt(); if (number_of_elements <= 0) { return; } ArrayList<Integer> numList = new ArrayList<>(); for (int ctr = 0; ctr < number_of_elements; ctr++) {
Provide Custom Input
```
