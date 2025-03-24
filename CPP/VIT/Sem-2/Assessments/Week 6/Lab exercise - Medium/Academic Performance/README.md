# Single File Programming Question

## Problem Statement

Patrick, a student at ABC College, needs a program to track his academic performance.

Design a program with multiple inheritance featuring a Student class inheriting attributes from the classes: GPA, CreditHours.

class GPA - stores GPA value (double)
class CreditHours - stores credit hours value (int)

Calculate Patrick's total grade points by multiplying GPA by credit hours. If his attendance is above 80%, add 5 to his grade points.

### Input format :

The first line of input consists of a double value, representing Patrick's GPA.

The second line consists of an integer, representing Patrick's credit hours.

The third line consists of a double value, representing Patrick's attendance percentage.

### Output format :

The output prints a double value representing Patrick's total grade points, rounded off to one decimal place.

Refer to the sample output for formatting specifications.

### Code constraints :

1.0 ≤ GPA ≤ 10.0

0 ≤ credit hours ≤ 100

1.0 ≤ attendance ≤ 100.0

### Sample test cases :

#### Input 1 :

3.7
45
81.7

#### Output 1 :

171.5

#### Input 2 :

6.7
42
70.5

#### Output 2 :

281.4

#### Input 3 :

8.2
50
95.7

#### Output 3 :

415.0

#### Input 4 :

6.7
35
80.0

#### Output 4 :

234.5

Whitelist
Set 1:
class GPA
Set 2:
class CreditHours
Set 3:
class Student
