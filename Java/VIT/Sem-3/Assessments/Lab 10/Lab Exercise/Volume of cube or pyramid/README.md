# Volume of cube or pyramid

## Single File Programming Question

## Problem Statement

Linda is developing a program that computes the volume of either a cube or a pyramid based on user input. The user specifies the shape (1 for a cube, 2 for a pyramid) and provides the necessary dimensions like side length for a cube and base and height for a pyramid.

Help her write the program then calculate and display the corresponding volume using the overloaded method called calculateVolume.

Formulas Used:

Volume of a cube = Side length * Side length * Side length
Volume of a pyramid = (Base * Height) / 3.0
#### Input:

```
format :
```

The first line consists of an integer representing the shape (1 for cube, 2 for pyramid).

If the choice is 1: The second line consists of a double value m, representing the side length of the cube.

If the choice is 2:

The second line consists of a double value x, representing the base of the pyramid.
The third line consists of a double value y, representing the height of the pyramid.
#### Output:

```
format :
```

If the choice is 1: The output displays "Volume of the cube: " followed by a double value representing the volume of the cube, rounded to two decimal places.

If the choice is 2: The output displays "Volume of the pyramid: " followed by a double value representing the volume of the pyramid, rounded to two decimal places.

If the choice is not 1 or 2, the output displays "Invalid".

Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1.0 ≤ m ≤ 100.0

1.0 ≤ x, y ≤ 100.0﻿

Sample test cases :
#### Input 1:

```
1
12.5
Output 1 :
Volume of the cube: 1953.13
Input 2 :
2
48.7
12.5
Output 2 :
Volume of the pyramid: 202.92
Input 3 :
4
12.5
Output 3 :
Invalid
Input 4 :
1
100.0
Output 4 :
Volume of the cube: 1000000.00
Input 5 :
2
100.0
100.0
Output 5 :
Volume of the pyramid: 3333.33
```
