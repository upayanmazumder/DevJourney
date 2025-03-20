Single File Programming Question
Problem Statement



Ramanan is a weather enthusiast who wants a simple tool to convert temperatures between Fahrenheit and Celsius. He has requested your help to create a program that accomplishes this task.



Write a program that allows Ramanan to input temperatures in Fahrenheit and Celsius, convert them to the other scale and display the equivalent temperature of both temperatures. Use a class Temperature having the temperature as a public attribute.



Formulas:

Fahrenheit to Celsius = (F - 32) * 5/9

Celsius to Fahrenheit = (C * 9/5) + 32

Input format :
The first line of input consists of a float value representing the temperature in Fahrenheit F.

The second line consists of a float value representing the temperature in Celsius C.

Output format :
The output prints two float values in each line rounded to two decimal places.

Converted temperature (F to Celsius) followed by " degree celsius".
Converted temperature (C to Fahrenheit) followed by "degree fahrenheit"


Refer to the sample output for formatting specifications.

Code constraints :
32.0 ≤ F ≤ 212.0

-30.0 ≤ C ≤ 100.0

Sample test cases :
Input 1 :
77.0
25.0
Output 1 :
25.00 degree celsius
77.00 degree fahrenheit
Input 2 :
122.25
-10.12
Output 2 :
50.14 degree celsius
13.78 degree fahrenheit
Whitelist
Set 1:
class
Temperature