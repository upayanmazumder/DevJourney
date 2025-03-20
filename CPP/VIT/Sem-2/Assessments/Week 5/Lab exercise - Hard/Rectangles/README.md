Single File Programming Question
Problem statement



Alice is working on a program to manage multiple rectangles using a class named Rectangle. This class contains a static data member count to keep track of the total number of rectangle instances created and a static member function getCount() that returns the value of count. The class also has non-static member functions: setDimensions(int l, int w) to set the length and width of each rectangle and getArea() to calculate the area of the rectangle. Whenever a new rectangle is instantiated, the static member count is incremented. 



Help Alice to retrieve the total number of rectangles created and calculate the area for each rectangle.



Formula:

Area = length * width

Input format :
The first line of input consists of an integer n, representing the number of rectangles.

The next n lines each contain two integers ? and w, representing the length and width of each rectangle.

Output format :
The first line of output prints "Total number of rectangles: " followed by an integer representing the total number of rectangles created.

The next n lines prints "Area of rectangle i: " followed by an integer representing the area of the ith rectangle.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ n ≤ 10

1 ≤ l,w ≤ 25

Sample test cases :
Input 1 :
2
5 10
3 4
Output 1 :
Total number of rectangles: 2
Area of rectangle 1: 50
Area of rectangle 2: 12
Input 2 :
1
6 7
Output 2 :
Total number of rectangles: 1
Area of rectangle 1: 42