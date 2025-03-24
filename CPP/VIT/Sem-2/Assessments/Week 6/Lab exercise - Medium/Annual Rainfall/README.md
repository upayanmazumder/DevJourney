# Single File Programming Question

## Problem Statement

Reema, an environmental enthusiast, is conducting research on forest ecosystems. She needs a program to calculate the annual rainfall for different forest areas.

Write a program that can determine the annual rainfall for square and rectangular forests based on the provided dimensions (side length, length, and width) and the average annual rainfall in millimeters (mm)

Create a class Forest and utilize constructor overloading in the Forest class to handle two types of forests:

For Square Forest: annual rainfall = sideLength * sideLength * rainfallinmm
For Rectangular Forest: annual rainfall = length * width * rainfallinmm

### Input format :

The first input line of input contains the side length and average annual rainfall (in mm) for a square forest as double-point numbers.

The second input line includes the length, width, and average annual rainfall (in mm) for a rectangular forest as double-point numbers.

### Output format :

For each forest, the output displays the calculated annual rainfall in millimeters (mm) as a floating-point number with two decimal places, followed by "mm" (e.g., "7500.50 mm").

Refer to the sample output for formatting specifications.

### Code constraints :

0.01 ≤ length, width, or side length ≤ 1000.0

0.01 ≤ rainfallinmm ≤ 1000.0

### Sample test cases :

#### Input 1 :

2.9 3.4
1.9 3.7 4.9

#### Output 1 :

28.59 mm
34.45 mm

#### Input 2 :

3.5 6.7
21.4 12.5 23.6

#### Output 2 :

82.08 mm
6313.00 mm
