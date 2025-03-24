# Single File Programming Question

## Problem Statement

Mohit wants a financial calculator program for Fixed Deposits and Simple Interest. He needs a program that uses multi-level inheritance. The program should have three classes:

class Investment - Holds the principal, interest rate, and time period as attributes.
class FixedDeposit - Derived from the Investment class, calculates the maturity amount using a method called calculateMaturityAmount().
class SimpleInterest - Derived from FixedDeposit class, prints the maturity amount using a method called printFD(). It then computes the simple interest and prints it using a method called calculateSimpleInterest().

Formulas used:

Maturity Amount = P * (1 + (R/100)) ^ T where the power value is calculated using pow() function from the math library.
Simple Interest = P * N * R/100

where P - principal, R - interest rate, and N - time period in years.

### Input format :

The first line consists of three double-point numbers separated by a space representing the principal amount, interest rate, and time period in years to calculate Fixed Deposit and Simple Interest.

### Output format :

The first line displays "Maturity Amount: " followed by a double value which is the calculated Maturity amount rounded to two decimal places.

The second line displays "Simple Interest: " followed by a double value which is the calculated Simple interest rounded to two decimal places.

Refer to the sample outputs for the formatting specifications.

### Code constraints :

In this scenario, the test cases fall under the following constraints:

1 ≤ Principal amount ≤ 106

0.1 ≤ Interest rate ≤ 10

0.1 ≤ Time period ≤ 10

### Sample test cases :

#### Input 1 :

1000.0 5.0 2

#### Output 1 :

Maturity Amount: 1102.50
Simple Interest: 100.00

#### Input 2 :

1500.0 4.5 4

#### Output 2 :

Maturity Amount: 1788.78
Simple Interest: 270.00

#### Input 3 :

3000.0 6.0 3

#### Output 3 :

Maturity Amount: 3573.05
Simple Interest: 540.00
