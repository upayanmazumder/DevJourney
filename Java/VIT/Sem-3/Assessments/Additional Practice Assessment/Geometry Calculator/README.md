Single File Programming Question
Problem Statement

Aditi is working on a geometry calculator to compute the areas of different shapes. She wants to create a program that calculates the area of a rectangle, a square, and a circle based on user input. Help Aditi by implementing an abstract class-based program to compute and display these values.

Create an abstract class Shape with the following methods:

abstract void rectangleArea();
abstract void squareArea();
abstract void circleArea();
Create a class Area that extends Shape and calculates and prints all the areas. Then create a Main class, get the inputs, and pass them to the methods.

Formula:

Rectangle Area: Area = length _ breadth
Square Area: Area = side _ side
Circle Area: Area = π \* radius2
For the π value, use Math.PI from the math package.

Input format :
The first line of input consists of two space-separated integers, representing the length and breadth of the rectangle.

The second line consists of an integer, representing the side of the square.

The third line consists of an integer, representing the radius of the circle.

Output format :
The first line of output prints the integer, representing the area of a rectangle.

The second line prints the integer, representing the area of a square.

The third line prints a double value, the area of the circle, rounded off to two decimal places.

Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ length and breadth ≤ 100

1 ≤ side ≤ 100

1 ≤ radius ≤ 100

Sample test cases :
Input 1 :
10 20
4
5
Output 1 :
200
16
78.54
Input 2 :
15 9
12
8
Output 2 :
135
144
201.06
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
