Single File Programming Question
Problem Statement



A painter needs to determine the cost to paint different shapes based on their surface area. The program should be designed to handle the area of a sphere and calculate the total painting cost using the following formulas:



Area of sphere: Area = 4 * pi * r² where pi = 3.14
Total painting cost: Cost = cost per square meter * area of sphere


The program will consist of three classes:

Shape class: This class should set the shape type and radius.
Area class: This class should extend Shape to calculate the area.
Cost class: This class should extend Area to calculate the total painting cost.
Input format :
The input consists of a string representing the shape type, a double value representing the radius, and another double value representing the cost per square meter on each line.

Output format :
For a valid shape type of "Sphere":

The first line prints: "Area of Sphere is: <calculated_area>" rounded to two decimal places.
The second line prints: "Cost to paint the shape is: <total_painting_cost>" rounded to two decimal places.
For any other shape types, print: "Invalid type".



Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1.0 ≤ radius ≤ 50.0

1.0 ≤ cost ≤ 10.0

Sample test cases :
Input 1 :
Sphere
3.4
5.8
Output 1 :
Area of Sphere is: 145.19
Cost to paint the shape is: 842.12
Input 2 :
Sphere
50.0
10.0
Output 2 :
Area of Sphere is: 31400.00
Cost to paint the shape is: 314000.00
Input 3 :
Triangle
3.4
2.3
Output 3 :
Invalid type
Input 4 :
sphere
34.6
4.9
Output 4 :
Invalid type