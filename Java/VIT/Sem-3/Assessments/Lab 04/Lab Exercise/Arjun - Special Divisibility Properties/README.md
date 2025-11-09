# Arjun - Special Divisibility Properties

## Single File Programming Question

## Problem Statement

Arjun is fascinated by numbers with special divisibility properties. He wants to find all numbers within a given range that are divisible by the sum of their digits but are not divisible by any of their individual digits.

Help Arjun identify such numbers in the range so he can study their unique characteristics.

## Example

#### Input:

10 30

#### Output:

27

### Explanation

Sum of digits of 27 = 2 + 7 = 9; 27 is divisible by 9 (27 % 9 = 0).

Check divisibility by individual digits: 27 % 2 ≠ 0 and 27 % 7 ≠ 0 (so not divisible by any single digit).

Since 27 meets both conditions, it is printed as output.

#### Input:

```
format :
```

The input consists of two integers, representing the starting number n1 and ending number n2 of the range.

#### Output:

```
format :
```

The output prints all such numbers line by line that satisfy the condition.

If no such numbers exist, print the message "No numbers are divisible based on the given conditions.".

Refer to the sample output for the formatting specifications.

Code constraints :
10 ≤ n1, n2 ≤ 103

Sample test cases :
#### Input 1:

```
10 20
Output 1 :
No numbers are divisible based on the given conditions.
Input 2 :
10 30
Output 2 :
27
```
