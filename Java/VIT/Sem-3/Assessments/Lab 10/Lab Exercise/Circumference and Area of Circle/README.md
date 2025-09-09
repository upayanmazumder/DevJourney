Single File Programming Question
Problem Statement



Bob has been tasked with creating a program using CircleUtils class to calculate and display the circumference and area of the circle.



The program should allow Bob to input the radius of a circle as both an integer and a double and compute both the circumference and area of the circle using separate overloaded methods:

calculateCircumference- To calculate the circumference using the formula 2 * 3.14 * radius
calculateArea- To calculate the area 3.14 * radius * radius


Write a program to help Bob.

Input format :
The first line of input consists of an integer m, representing the radius of the circle as a whole number.

The second line consists of a double value n, representing the radius of the circle as a decimal number.

Output format :
The first line of output displays two space-separated double values, rounded to two decimal places, representing the circumference of the circle with the integer radius and the double radius, respectively.

The second line displays two space-separated double values, rounded to two decimal places, representing the area of the circle with the integer radius and the double radius, respectively.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1 ≤ m ≤ 100

1.00 ≤ n ≤ 100.00

Sample test cases :
Input 1 :
5
3.50
Output 1 :
31.40 21.98
78.50 38.47
Input 2 :
1
1.00
Output 2 :
6.28 6.28
3.14 3.14
Input 3 :
100
100.00
Output 3 :
628.00 628.00
31400.00 31400.00