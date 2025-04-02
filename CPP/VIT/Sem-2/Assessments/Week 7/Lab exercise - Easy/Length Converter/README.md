Single File Programming Question
Problem Statement



Teju is working on a unit converter application that can convert lengths from millimetres to centimetres and kilometres. The application uses function overloading to handle the different unit types.



She wants to implement a UnitConverter class that contains two overloaded functions for conversion:

double convert(double millimetres) - If the unit type is 1, convert the value to centimetres.
double convert(int unitType, double value) - If the unit type is 2, convert the value to kilometres.


Assist Teju in completing the converter application.

Input format :
The first line of input consists of an integer unitType (1 or 2) representing the unit type.

The second line consists of a double value N, representing the value in millimetres to be converted.

Output format :
If the unit type is 1, print "X cm" where X is a double value, rounded off to two decimal places.

If the unit type is 2, print "Y km" where Y is a double value, rounded off to two decimal places.

If the unit type is not valid, print "Invalid unit type!"



Refer to the sample output for formatting specifications.

Code constraints :
1.00 ≤ N ≤ 1000000.00

Sample test cases :
Input 1 :
1 
100.00
Output 1 :
10.00 cm
Input 2 :
2
541456.00
Output 2 :
0.54 km
Input 3 :
3
Output 3 :
Invalid unit type!

Whitelist
Set 1:
convert