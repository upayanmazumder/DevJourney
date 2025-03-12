Single File Programming Question
Problem Statement



Arun needs a program to analyze waterfalls. Your task as a programmer is to guide him in completing the program using nested structures.



Define a Waterfall structure with width, height, and depth. Create a TotalFlow structure containing a waterfall. Implement functions to calculate total volume and surface area. Input the waterfall dimensions and display the total volume and surface area of a waterfall.



Formulae:

Total Volume = Width x Height x Depth

Surface Area = 2 x (Width x height + Width x Depth + Height x Depth)

Input format :
The input consists of the three double values W, H, and D, representing the width, height, and depth of the waterfall separated by space.

Output format :
The first line prints "X cubic meters" where X is a double value, representing the total volume in cubic meters, rounded off to 2 decimal points.

The second line prints "Y square meters" where Y is a double value, representing the surface area in square meters, rounded off to 2 decimal points.



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1.0 ≤ W, H, D ≤ 100.0

Sample test cases :
Input 1 :
1.1 1.1 1.1
Output 1 :
1.33 cubic meters
7.26 square meters
Input 2 :
24.5 16.7 18.9
Output 2 :
7732.93 cubic meters
2375.66 square meters
Input 3 :
98.7 100.0 56.8
Output 3 :
560616.00 cubic meters
42312.32 square meters
Whitelist
Set 1:
struct Waterfall
Set 2:
struct TotalFlow