Single File Programming Question
Problem Statement



Dev is a bank assistant who needs to calculate the simple interest for various customers. He wants to develop a simple program that calculates the simple interest based on the principal amount, interest rate, and time provided by the customers.



Assist him by creating a program that uses a class SimpleInterest and constructor overloading.



Constructor overloading Specifications:

SimpleInterest(): Default constructor that initializes principal, rate, time, and simpleInterest to zero.
SimpleInterest(double p, double r, int t): Parameterized constructor that takes the principal amount (p), interest rate (r), and time (t) as arguments.
Input format :
The first line of input consists of a double-point number, representing the principal amount.

The second line consists of a double-point number, representing the interest rate.

The third line consists of an integer, representing the time period in years.

Output format :
The output prints a double-point number, representing the calculated simple interest, rounded off to two decimal places.



Refer to the sample output for formatting specifications.

Code constraints :
0.01 ≤ principal ≤ 10000.00

1.00 ≤ rate ≤ 10.00

1 ≤ time in years ≤ 10

Sample test cases :
Input 1 :
1000.00
9.00
2
Output 1 :
180.00
Input 2 :
4565.75
4.67
3
Output 2 :
639.66