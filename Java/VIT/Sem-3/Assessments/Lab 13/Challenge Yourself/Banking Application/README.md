# Banking Application

## Single File Programming Question

## Problem Statement

Jamie is developing a banking application that manages loan repayments and account balances with specific rules and constraints. The application must ensure proper validation and handle various custom exceptions related to loan repayments:

Loan Overdue: If the loan is overdue by more than 60 days, throw LoanOverdueException with the message:

"Loan is overdue by more than 60 days. Immediate payment required."

Negative Repayment Amount: If the loan repayment amount is negative, throw NegativeLoanRepaymentAmountException with the message:

"Loan repayment amount cannot be negative."

Insufficient Funds: If the remaining balance after withdrawal is less than the minimum loan repayment amount, throw InsufficientFundsForLoanRepaymentException with the message:

"Insufficient funds to cover loan repayment after withdrawal."

The logic used for the withdrawal is:

Step 1: remainingBalance = balance − amount

Step 2: If remainingBalance < minLoanRepayment, throw exception.

Step 3: Else, update:

balance = balance − amount − minLoanRepayment

loanAmount = loanAmount − minLoanRepayment

#### Input:

```
format :
```

The first line of input consists of a double value b, representing the initial balance of the bank account.

The second line consists of a double value o, representing the outstanding loan amount.

The third line consists of a double value m, representing the minimum loan repayment amount.

The fourth line consists of an integer n, representing the number of days the loan is overdue.

The fifth line consists of a double value w, representing the amount to withdraw from the bank account.

#### Output:

```
format :
```

Successful Withdrawal and Repayment:

The first line of output prints: "Remaining Balance: " followed by the balance (rounded to two decimal places)

The second line of output prints: "Remaining Loan Amount: " followed by loanAmount (rounded to two decimal places)

Loan Overdue by More Than 60 Days:

The only line of output prints: "Loan is overdue by more than 60 days. Immediate payment required."

Negative Withdrawal Amount:

The only line of output prints: "Loan repayment amount cannot be negative."

Insufficient Funds for Loan Repayment After Withdrawal:

The only line of output prints: "Insufficient funds to cover loan repayment after withdrawal."

Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ balance ≤ 1,000,000 (Initial bank balance must be at least 1)

0 ≤ loanAmount ≤ 1,000,000 (Loan amount can be zero or more)

1 ≤ minLoanRepayment ≤ loanAmount (Minimum loan repayment must be at least 1 and not exceed the loan amount)

0 ≤ daysOverdue ≤ 365 (Overdue days range from 0 to 365)

0 ≤ amount ≤ balance (Withdrawal amount must be non-negative and not exceed the available balance)

Sample test cases :
#### Input 1:

```
5000
2000
300
30
1500
Output 1 :
Remaining Balance: 3200.00
Remaining Loan Amount: 1700.00
Input 2 :
4000
1500
600
10
3500
Output 2 :
Insufficient funds to cover loan repayment after withdrawal.
Input 3 :
6000
2500
500
20
-200
Output 3 :
Loan repayment amount cannot be negative.
Input 4 :
7000
3000
700
65
1500
Output 4 :
Loan is overdue by more than 60 days. Immediate payment required.
```
