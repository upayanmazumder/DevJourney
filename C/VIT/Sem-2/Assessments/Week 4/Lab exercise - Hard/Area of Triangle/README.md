# Single File Programming Question

## Problem Statement

Shaun is a geometry enthusiast and needs a program using a structure to determine the area of a triangle based on its sides: side1, side2, and side3.

The user inputs the three side lengths, and the program checks and calculates the area if the sides form a valid triangle, else it indicates an invalid triangle.

Formulas used:

Area = √s(s - side1)(s - side2)(s - side3) where s = (a + b + c)/2
To check if a set of three side lengths forms a valid triangle: (side1+side2>side3) and (side1+side3>side2) and (side2+side3>side1)

### Input format :

The input consists of three integers in separate lines: side1, side2, and side3 representing the sides of a triangle.

### Output format :

If the sides form a valid triangle, the output displays the area of the triangle as a double value rounded to one decimal place.

If the sides don't form a valid triangle, the output displays "Invalid Triangle".

Refer to the sample output for the formatting specifications.

### Code constraints :

1 ≤ side1, side2, side3 ≤ 106

Use sqrt() function to calculate the square root.

### Sample test cases :

#### Input 1 :

5
5
5

#### Output 1 :

10.8

#### Input 2 :

1
2
3

#### Output 2 :

Invalid Triangle

#### Input 3 :

1001
1000
1000

#### Output 3 :

433301.1
