# Single File Programming Question

## Problem Statement

Amit and Angel want to create a program where they are given the ages of two people, a current year, and a future year. They want to calculate the number of years until one person is twice as old as the other.

Help them in creating the program using a loop.

### Example

Given the ages of two persons (age1 = 8, age2 = 24), a current year (2024), and a future year (2036), iterate from the current year to the future year to find a year where one person's age will be twice the other's age.

After 8 years (in 2032), one person will be twice as old as the other (age1 + years = 16, age2 + years = 32), satisfying the condition, and thus the output is 8 years.

### Input format

- The first line of input consists of an integer A, representing the age of the first person.
- The second line consists of an integer B, representing the age of the second person.
- The third line consists of an integer C, representing the current year.
- The fourth line consists of an integer F, representing the future year.

### Output format

- If the condition is met, print an integer representing the year in which one person will be twice as old as the other.
- Otherwise, print "No such year found up to F", where F is an integer representing the future year.

Refer to the sample output for formatting specifications.

### Code constraints

In this scenario, the test cases fall under the following constraints:

- \(1 \leq A, B \leq 100\)
- \(1960 \leq C, F \leq 2100\)

### Sample test cases

#### Input 1
```
8
24
2024
2036
```
#### Output 1
```
8
```

#### Input 2
```
8
24
2024
2030
```
#### Output 2
```
No such year found up to 2030
```

#### Input 3
```
25
20
2022
2028
```
#### Output 3
```
No such year found up to 2028
```

#### Input 4
```
60
30
2024
2040
```
#### Output 4
```
0
```