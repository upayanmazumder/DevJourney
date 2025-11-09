# Financial Calculator

## Single File Programming Question

## Problem Statement

In ABC Company, Developers are tasked with developing a robust financial calculator system. The system consists of an abstract class FinancialCalculator with three key abstract methods: calculateCompoundInterest, calculateFutureValue, and calculateMonthlyLoanPayment. The system includes two subclasses, InvestmentCalculator and LoanCalculator.

Users are prompted to input the principal amount, annual interest rate, and duration. Based on their choice between 1. Investment or a 2. loan, the system performs the relevant financial calculations and displays the results.

Note:

Compound Intrest = P(1+Rate/100)n - P

Future Value = P(1+Rate/100)n

Loan/Month = (Loan Amount * Monthly Interest)/(1-(1+Monthly Interest)n

Monthly Loan Payment (EMI) = P×r / (1 − (1+r)-n)

where:

P = Principal / Loan Amount

r = Monthly Interest Rate = Annual Interest Rate / (12×100)

n = Total Number of Months = Years × 12

#### Input:

```
format :
```

The first line of input consists of a double value, representing the principal amount.

The second line of input consists of a double value, representing the interest rate.

The third line of input consists of an integer, representing the duration in years.

The fourth line of input consists of an integer(1 or 2), representing the Investment Calculator / Loan Calculator.

#### Output:

```
format :
```

If the choice is the Investment Calculator

The first line of output prints "Compound Interest: " followed by a double value representing the compound interest rounded to 2 decimal places.
The second line of output prints "Future Value: "followed by a double value representing the future value rounded to 2 decimal places.
If the choice is the Loan Calculator

The output prints "Monthly Loan Payment: " followed by a double value, representing the Monthly loan payments rounded to 2 decimal places.
If there is a choice other than 1 and 2, the output prints "Invalid choice".

Refer to the sample output for the formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ choice ≤ 2

1 ≤ Principal Amount ≤ 109

1 ≤ Rate of Interest ≤ 99

1 ≤ Duration ≤ 50﻿

Sample test cases :
#### Input 1:

```
10000.0
5.0
3
1
Output 1 :
Compound Interest: 1576.25
Future Value: 11576.25
Input 2 :
25000.9
9.7
1
2
Output 2 :
Monthly Loan Payment: 2194.49
Input 3 :
500000.0
8.7
5
3
Output 3 :
Invalid choice
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
image
Header Snippet
1
import java.util.Scanner;
Fill your code here
Java (17)
theme
instruction
123
abstract class FinancialCalculator {}
```
