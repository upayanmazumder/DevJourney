# Emerson - Cyclic Rotations

## Single File Programming Question

## Problem Statement

Emerson is working on a project to determine if a number and all of its cyclic rotations are prime numbers. A cyclic rotation involves shifting the digits of a number to the right and bringing the last digit to the front.

Your task is to implement a program that checks whether all cyclic rotations of a given number are prime numbers. If all rotations are prime, the output is "true"; otherwise, the output is "false".

## Example

#### Input:

197

#### Output:

197

719

971

true

### Explanation

For input 197:

Iteration 1: The rotated number is 197, it's prime. The next rotation gives 719.
Iteration 2: The rotated number is 719, it's prime. The next rotation gives 971.
Iteration 3: The rotated number is 971, it's prime. The next rotation gives 197.
All rotated numbers (197, 719, 971) are prime, so the result is true.

#### Input:

```
format :
```

The input consists of an integer n, representing the number for which cyclic rotations need to be checked.

#### Output:

```
format :
```

The output prints the cyclic rotated numbers in each line, followed by a string "true" if all rotations are prime, or "false" otherwise.

Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ n ≤ 1000

Sample test cases :
#### Input 1:

```
23
Output 1 :
23
32
false
Input 2 :
197
Output 2 :
197
719
971
true
```
