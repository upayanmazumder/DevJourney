Single File Programming Question
Problem Statement



You have been assigned the responsibility of implementing the Area class for the construction company's software application.



You have declared the following inline functions within the Area class: get(), squareArea(), rectangleArea(), circleArea(), and parallelogramArea(). These functions are used to calculate the area of different geometric shapes.



Include the necessary code for the class definition and method implementations. Then, create an object of the Area class in the main method and demonstrate how the methods can be called to calculate the areas of squares, rectangles, circles, and parallelograms. Provide the complete code solution, including the class definition, method implementations, and the main method where the object is created and the methods are called.



Note: This is a sample question asked in a HCL interview.



Formula:

Area of the square = side*side

Area of the rectangle = length*breadth 

Area of the circle =3.14*radius*radius 

Area of the parallelogram = base*height

Input format :
The first value is an integer value for the side of a square. 

The next two values are integer values for the length and breadth of a rectangle, respectively. 

The fourth value is a floating-point value for the radius of a circle.

The last two values are floating-point values for the base and height of a parallelogram, respectively.

Output format :
The program should output the areas of the square, rectangle, circle, and parallelogram in separate lines with the corresponding labels.

The output should be rounded off to two decimal places for the area of the circle.



Refer to the sample output for formatting specifications.

Code constraints :
Inputs > 0

Take pi = 3.14

Sample test cases :
Input 1 :
4
5 4
6.5
6.2 4.5
Output 1 :
Area of the square: 16
Area of the rectangle: 20
Area of the circle: 132.66
Area of the parallelogram: 27.90
Input 2 :
6
10 12
8.0
15.2 18.7
Output 2 :
Area of the square: 36
Area of the rectangle: 120
Area of the circle: 200.96
Area of the parallelogram: 284.24
Whitelist
Set 1:
void get();
void squareArea();
void rectangleArea();
void circleArea();
void parallelogramArea();
inline