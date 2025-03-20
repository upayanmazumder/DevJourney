# Single File Programming Question

## Problem Statement

Tom needs to calculate properties of multiple circles for his geometry project. For each circle, he will set its radius and compute the area and circumference. Additionally, he wants to keep track of how many circles have been created.

Write a program using a class named Circle with the following:

static int circleCount: Counts the total number of Circle objects created.
static int getCircleCount(): Returns the total number of circles created.
void setRadius(double r): Sets the circle's radius.
double calculateArea(): Returns the area of the circle.
double calculateCircumference(): Returns the circumference of the circle.
void displayDetails(): Displays the circle's radius, area, and circumference.

Formula:

Area = 3.14159 * radius * radius

Circumference = 2 * 3.14159 * radius

### Input format :

The first line contains an integer n, representing the number of circles.

The next n lines each contain a double value representing the radius of each circle.

### Output format :

The first line prints the total number of circles created.

For each circle, print three lines:

The first line prints the radius formatted to two decimal places.
The second line prints the area of the circle formatted to two decimal places.
The third line prints the circumference of the circle formatted to two decimal places.

Refer to the sample output for the formatting specifications.

### Code constraints :

1 ≤ n ≤ 5

0.0 ≤ radius ≤ 25.0

pi=3.14159

### Sample test cases :

#### Input 1 :

1
1.0

#### Output 1 :

1
Radius: 1.00
Area: 3.14
Circumference: 6.28

#### Input 2 :

2
2.5
3.0

#### Output 2 :

2
Radius: 2.50
Area: 19.63
Circumference: 15.71
Radius: 3.00
Area: 28.27
Circumference: 18.85
