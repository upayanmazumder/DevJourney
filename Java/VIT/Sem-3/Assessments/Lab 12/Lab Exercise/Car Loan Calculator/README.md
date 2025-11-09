# Car Loan Calculator

## Single File Programming Question

## Problem Statement

John is developing a car loan calculator and has structured his program using two interfaces, Principal and InterestRate, defining methods for principal and interest rate retrieval.

The Loan class implements these interfaces, taking principal and annual interest rates as parameters. User input is solicited for these values, and the program ensures their validity before performing calculations. If input values are invalid (less than or equal to zero), an error message is displayed.

Note: Total interest = principal * interest rate * years

#### Input:

```
format :
```

The first line of input consists of a double value P, representing the principal.

The second line consists of a double value R, representing the annual interest rate.

The third line consists of an integer value N, representing the loan duration in years.

#### Output:

```
format :
```

If the input values are valid, print "Total interest paid: Rs. " followed by a double value, representing the total interest paid, rounded off to two decimal places.

If the input values are invalid (negative or zero values for principal, annual interest rate, or loan duration), print "Invalid input values!".

Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

0.00 < P < 10,00,000.00

0.01 ≤ R ≤ 0.99

0 < N < 25

Sample test cases :
#### Input 1:

```
20000.00
0.05
5
Output 1 :
Total interest paid: Rs.5000.00
Input 2 :
45000.25
0
2
Output 2 :
Invalid input values!
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
```
