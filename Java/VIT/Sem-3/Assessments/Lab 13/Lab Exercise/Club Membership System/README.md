# Club Membership System

## Single File Programming Question

## Problem Statement

John is attempting to register for the club's membership system. He enters his age as part of the registration process. If John is under 18, the system should inform him that his age is not valid for registration by throwing a custom exception (AgeNotValidException). If he is eligible (18 or older), the system should confirm that he is eligible for registration.

#### Input:

```
format :
```

The first line of input contains an integer representing the age.

#### Output:

```
format :
```

The output prints if the age is greater than 18, "Age is valid! You are eligible." or "Age is less than 18. You are not eligible."

Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ age ≤ 50

Sample test cases :
#### Input 1:

```
20
Output 1 :
Age is valid! You are eligible.
Input 2 :
10
Output 2 :
Age is less than 18. You are not eligible.
```
