# Loan Management System

## Single File Programming Question

## Problem Statement

You are tasked with developing a loan management system for a financial institution. The system should include a LoanCalculator class to calculate monthly loan payments, track the total interest paid, and monitor the remaining balance for various loan accounts.

To enhance this system, you need to implement an AdvancedLoanCalculator subclass that offers additional features and benefits for loan management. For each month, it will provide monthly payments, principal payments, interest payments, and the remaining balance. At the end, the total interest paid and the monthly payment should be displayed.

Your goal is to design and implement the AdvancedLoanCalculator to extend the capabilities of the LoanCalculator in a way that provides more comprehensive insights into loan management.

Formula:

The monthly loan payment (EMI) should be calculated using the standard amortization formula:

Where:

P = Principal (loan amount)

r = Monthly interest rate (Annual rate ÷ 12 ÷ 100)

n = Loan term in months

Interest Payment for a month ( Interest Payment = Remaining Principal × r )
Principal Payment ( Principal Payment = Monthly Payment − Interest Payment )
Remaining Balance after each month ( Remaining Balance = Previous Balance − Principal Payment )
Total Interest Paid ( Total Interest Paid = ∑ Interest Payment over all months )
#### Input:

```
format :
```

The first line of the input is a double value 'a', representing the Principal amount (loan amount) with two decimal places.

The second line of the input is a double value 'b', representing the Annual interest rate as a percentage with two decimal places.

The third line of the input is an integer value 'c', representing the Loan term in months.

#### Output:

```
format :
```

For each month of the loan term, the program will display the following details:

The first line of the output displays, the "Month " and is followed by the number (e.g., "Month 1:").

The second line of the output displays, the "Monthly Payment: " and is followed by the amount (formatted to two decimal places).

The third line of the output displays, the "Principal Payment: " and is followed by the amount (formatted to two decimal places).

The fourth line of the output displays, the "Interest Payment: " amount (formatted to two decimal places).

The fifth line of the output displays, the "Remaining Balance: " (formatted to two decimal places).

(between each month a blank line should be left)

At the end of all monthly outputs, display:

The output prints "Total Interest Paid: " followed by the total interest amount paid over the loan term, formatted to two decimal places.

The last line of output prints "Monthly Payment: " repeated again with the same monthly payment value (formatted to two decimal places) for summary.

Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

Follow the method overriding concept.

1 < a < 106.

1 < b < 106.

1 < c < 10.

Sample test cases :
#### Input 1:

```
100000.00
10.00
2
Output 1 :
Month 1:
Monthly Payment: 50625.86
Principal Payment: 49792.53
Interest Payment: 833.33
Remaining Balance: 50207.47
```

Month 2:
Monthly Payment: 50625.86
Principal Payment: 50207.47
Interest Payment: 418.40
Remaining Balance: 0.00

Total Interest Paid: 1251.73
Monthly Payment: 50625.86
#### Input 2:

```
200000.00
15.00
1
Output 2 :
Month 1:
Monthly Payment: 202500.00
Principal Payment: 200000.00
Interest Payment: 2500.00
Remaining Balance: 0.00
```

Total Interest Paid: 2500.00
Monthly Payment: 202500.00
