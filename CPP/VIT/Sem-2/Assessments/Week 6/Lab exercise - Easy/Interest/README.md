Single File Programming Question
Problem Statement



Harry, a recent graduate, is excited about buying his first car and considering a loan. To calculate the total interest paid, he wants to design a class structure using multiple inheritance. 



Create a class named Loan inheriting from the classes: Principal and InterestRate. This program calculates the total interest paid over the loan period, aiding Harry in understanding the financial implications. 



Principal class - stores the price as a protected attribute
InterestRate class - stores interest rate as a protected attribute
Loan class - calculates total interest


Note: Total Interest = price * interest rate * years.

Input format :
The first line of input consists of a double value, representing the car price.

The second line consists of a double value, representing the interest rate.

The third line consists of an integer, representing the loan duration in years.

Output format :
The output prints "Total interest paid: Rs.X" where X is the total interest paid over the years, rounded off to two decimal places.



Refer to the sample output for formatting specifications.

Code constraints :
0.0 ≤ Price ≤ 1000000.0

0.0 ≤ Rate ≤ 100.0

0 < years ≤ 10

Sample test cases :
Input 1 :
120575.50
0.05
5
Output 1 :
Total interest paid: Rs.30143.88
Input 2 :
224564.89
3.12
2
Output 2 :
Total interest paid: Rs.1401284.91
Input 3 :
165050.52
5.52
2
Output 3 :
Total interest paid: Rs.1822157.74

Whitelist
Set 1:
class Loan
Set 2:
class Principal
Set 3:
class InterestRate