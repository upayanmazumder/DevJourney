# String Concatenation Operations

## Single File Programming Question

## Problem Statement

Maria, a software developer at a bustling book publishing company, is working on a text-processing utility to assist the editorial team. As part of the utility, Maria has been tasked with developing a program that manipulates strings in various ways. The program should support two types of string concatenation operations:

Simple String Concatenation: Combine two strings as they are.
String Concatenation with Reversal (Excluding Spaces): First, concatenate the two strings, remove all spaces, and then reverse the resulting string.

To achieve this, Maria needs to overload the concatenate method in the StringManipulator class to handle both cases. Specifically:

The first method should perform simple string concatenation (concatenate two strings directly).
The second method should perform string concatenation with reversal (concatenate the strings, remove spaces, and return the reversed result).
#### Input:

```
format :
```

The first line of input consists of an integer T, representing the number of test cases.

For each test case:

The first line consists of an integer choice (1 or 2):

1 for simple string concatenation.
2 for string concatenation with reversal (excluding spaces).
The second line consists of a string S1 (maximum 20 characters, may include uppercase, lowercase, and spaces).

The third line consists of a string S2 (maximum 20 characters, may include uppercase, lowercase, and spaces).

#### Output:

```
format :
```

For each test case, the program should output the result of the selected operation.

If the operation is 1, it should print the concatenated result of S1 and S2.
If the operation is 2, it should print the concatenated result of S1 and S2 (without spaces) followed by the reversed string.

﻿Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1 ≤ no_of_testcases ≤ 100

The String may be uppercase or lowercase and consists of a maximum of 20 characters.

Sample test cases :
#### Input 1:

```
1
1
Hello
World
Output 1 :
HelloWorld
Input 2 :
1
2
Hello
How are you?
Output 2 :
?uoyerawoHolleH
Input 3 :
3
1
Coding
FUn
1
abc def
ghi jkl
2
XYZ
ABC
Output 3 :
CodingFUn
abc defghi jkl
CBAZYX
```
