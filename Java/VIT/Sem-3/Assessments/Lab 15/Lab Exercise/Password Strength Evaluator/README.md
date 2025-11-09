# Password Strength Evaluator

## Single File Programming Question

## Problem Statement

Amelia is working on a program that evaluates the strength of passwords based on specified criteria. She needs assistance in creating a program to automate this process.

Evaluation is based on the length of the password.

If the length of the password is ≤ 3, classify it as Weak.
If the length is between 4 and 7 characters (both inclusive), classify it as Medium.
If the length is 8 characters or more, classify it as Strong.

Create a file named password.txt, the entered password is written to a file password.txt. The program then reads the stored password from password.txt to determine the password strength based on its length.

The evaluated password strength is written to a new file named evaluation.txt and displayed.

#### Input:

```
format :
```

The input consists of a string, representing the entered password.

#### Output:

```
format :
```

The output displays a string representing the evaluated strength.

Refer to the sample output for the formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ length ≤ 15

Sample test cases :
#### Input 1:

```
Sample@pass
Output 1 :
Strong
Input 2 :
pass
Output 2 :
Medium
Input 3 :
Av@
Output 3 :
Weak
```
