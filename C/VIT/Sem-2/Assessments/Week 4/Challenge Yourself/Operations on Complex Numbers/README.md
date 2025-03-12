Single File Programming Question
Problem Statement



Develop a program using a typedef for a complex number structure. The program should take two sets of real and imaginary parts as input and perform the following operations:



Addition of 2 complex numbers
Subtraction of 2 complex numbers
Multiplication of 2 complex numbers
Modulus of a given complex numbers


Display the results of each operation.



Formulas for reference:

Addition of Complex Numbers: (a + bi) + (c + di) = (a + c) + (b + d)i 
Subtraction of Complex Numbers: (a + bi) - (c + di) = (a - c) + (b - d)i 
Multiplication of Complex Numbers: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
Modulus (Magnitude) of a Complex Number (a + bi) = √a2 + b2
Input format :
The first line consists of two space-separated float values representing the real and imaginary parts of the first complex number.

The second line consists of two space-separated float values representing the real and imaginary parts of the second complex number.

Output format :
The first line prints the addition of the two complex numbers in the format: a + bi

The second line prints the subtraction of the two complex numbers in the format: a + bi

The third line prints the multiplication of the two complex numbers in the format: a + bi

The fourth line prints a float value representing the modulus of the first complex number.

The fifth line prints a float value representing the modulus of the second complex number.



Note: Here a and b values are float values rounded to two decimal places.



Refer to the sample outputs for the formatting specifications.

Sample test cases :
Input 1 :
2.0 2.0
2.1 2.1
Output 1 :
4.10 + 4.10i
-0.10 + -0.10i
0.00 + 8.40i
2.83
2.97
Input 2 :
4.1 5.1
5.5 7.5
Output 2 :
9.60 + 12.60i
-1.40 + -2.40i
-15.70 + 58.80i
6.54
9.30
Whitelist
Set 1:
typedef
Set 2:
struct