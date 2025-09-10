Single File Programming Question
Problem Statement



John is curious to know how many leap years he has lived through. He wants a program where he can input his birth year and the current year, and the program calculates the total number of leap years between them.



Leap Year Conditions:
A year is considered a leap year if:

It is divisible by 4, and
It is not divisible by 100 unless it is also divisible by 400.


Implement a class AgeCalculatorFunctions with a constructor AgeCalculatorFunctions(int birthYear, int currentYear) to initialize the birth year. The class should contain a method to count the number of leap years from the birth year to the current year.

Input format :
The first line contains an integer birthYear, representing Alex's birth year.

The second line contains an integer currentYear, representing the current year.

Output format :
The output displays an integer, representing the total number of leap years Alex has experienced.



Refer to the sample output for format specifications.

Code constraints :
1900 ≤ birthYear ≤ 2025

birthYear ≤ currentYear

Sample test cases :
Input 1 :
1990
2023
Output 1 :
8
Input 2 :
1985
2023
Output 2 :
9
