# Array Operations

## Single File Programming Question

## Problem Statement

Karan is developing a program that lets the user enter the size of an array, followed by the array elements. After that, the user provides an index, and the program displays the element at that position.

To make the program reliable, Karan wants to handle cases where the user might enter an invalid index (either too large or negative).

Use a try-catch block to catch and handle ArrayIndexOutOfBoundsException if the given index is outside the valid range. Show an appropriate error message to guide the user when such an exception occurs.

#### Input:

```
format :
```

The first line of the input consists of an integer N, representing the number of elements in the array.

The second line consists of N space-separated integers, representing the array elements.

The third line consists of an integer M, representing the index(0-indexed).

#### Output:

```
format :
```

The output prints "Element at index {index}: ", followed by the element at the specified index.

If an exception occurs, print the error message "Error: Array index out of bounds".

Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ N ≤ 10

1 ≤ array elements ≤ 100

Sample test cases :
#### Input 1:

```
5
16 25 45 56 86
4
Output 1 :
Element at index 4: 86
Input 2 :
3
45 85 67
0
Output 2 :
Element at index 0: 45
Input 3 :
6
42 56 93 73 61 55
9
Output 3 :
Error: Array index out of bounds
Input 4 :
6
34 78 52 98 61 79
-5
Output 4 :
Error: Array index out of bounds
```
