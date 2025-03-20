Single File Programming Question
Problem Statement



Lisa loves building toy houses using blocks. She has a special set of blocks that she uses to create houses. Each block has a certain length, width, and height. Lisa is curious about the total surface area of the toy house she's building, excluding the roof. Help her with the code to calculate it.



Implement a program that has a class named House and takes the dimensions of a toy house (length, width, and height) as public attributes and calculates the total surface area (TSA) of the house without the roof.



Formula: TSA = 2 * [(Width * Height) + (Width * Height) + (Height * Length) + (Height * Length)]

Input format :
The input consists of three double values in each line: length, width, and height of the toy house.

Output format :
The output displays a double value - the total surface area of the toy house (excluding the roof) rounded off to two decimal places followed by " square units.".

Code constraints :
1 <= length, width, height <= 1000

Sample test cases :
Input 1 :
5.5
4.2
3.8
Output 1 :
147.44 square units.
Input 2 :
2.7
3.5
4.9
Output 2 :
121.52 square units.
Whitelist
Set 1:
class