Single File Programming Question
Problem Statement



Lolita wants to write a program to define a Rectangle class that represents rectangles in a 2D space. The class should have private attributes to store the coordinates of two points, (llx, lly) representing the lower-left corner and (urx, ury) representing the upper-right corner of the rectangle.



The program should allow the user to input these coordinates and then compute and display the area of the rectangle. The Rectangle class should include a constructor to initialize the coordinates, a method to calculate the area, and a destructor to display a message when a rectangle object is destroyed.



Formula: Area = Width × Height

where:

Width is the absolute difference between the x-coordinates of the upper-right and lower-left corners.

Height is the absolute difference between the y-coordinates of the upper-right and lower-left corners

Input format :
The first line of input consists of two space-separated integers, llx and lly, representing the coordinates of the lower left of a rectangle.

The second line of input consists of two space-separated integers, urx and ury, representing the coordinates of the upper-right points of a rectangle.

Output format :
The output displays the following:



When the Rectangle object is created, the output displays: "Rectangle created."

After creating the Rectangle object, the output displays "Area of the rectangle: " followed by the area of the rectangle (integer).

When the Rectangle object is destroyed, the output displays "Rectangle destroyed."

Code constraints :
1<= llx, lly, urx, and ury <= 1000

llx < urx

lly < ury

Sample test cases :
Input 1 :
60 20
70 15
Output 1 :
Rectangle created.
Area of the rectangle: 50
Rectangle destroyed.
Input 2 :
4 12
6 22
Output 2 :
Rectangle created.
Area of the rectangle: 20
Rectangle destroyed.