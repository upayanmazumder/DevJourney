# Mason - Replace every element in an array with the next greatest element to its right

## Single File Programming Question

## Problem Statement

Mason is participating in a coding challenge where he must manipulate an integer array. His task is to replace every element in the array with the next greatest element to its right. The last element of the array remains unchanged, as there is no element to its right.
Your job is to help Mason write a program that performs this transformation and outputs the modified array.
#### Input:

```
format :
```

The first line of input contains an integer n representing the number of elements in the array.
The second line of input contains n space-separated integers representing the elements of the array.
#### Output:

```
format :
```

The output prints the modified array of n integers, where each element (except the last one) is replaced by the maximum element to its right, and the last element remains unchanged.
Refer to the sample output for formatting specifications.
Code constraints :
The given testcases fall under the following constraints:
1 ≤ n ≤ 100
−10⁹ ≤ arr[i] ≤ 10⁹
Sample test cases :
#### Input 1:

```
6 12 3 91 15 12 14
Output 1 :
91 91 15 14 14 14
Input 2 :
5 10 3 7 2 6
Output 2 :
7 7 6 6 6
Input 3 :
3 1 2 3
Output 3 :
3 3 3
```
