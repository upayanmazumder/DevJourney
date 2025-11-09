# Permutations Calculator

## Single File Programming Question

## Problem Statement

Develop a program that calculates the number of permutations for N elements using the formula N!. The program should accept user input for the value of N and throw an exception for negative values.

Implement a method calculatePermutations that takes N as a parameter and calculates the number of permutations. Throw an IllegalArgumentException with the message "Error: Negative value of N" if the input N is negative.

In the main method, catch and handle any IllegalArgumentException thrown by the calculatePermutations method.

#### Input:

```
format :
```

The input consists of an integer N.

#### Output:

```
format :
```

The output prints the long number representing the number of permutations of the given integer N.

If N is negative, print "Error: Negative value of N"

Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

-100 ≤ N ≤ 100

Sample test cases :
#### Input 1:

```
5
Output 1 :
120
Input 2 :
-9
Output 2 :
Error: Negative value of N
```
