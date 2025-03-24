Single File Programming Question
Problem Statement



Design a simple banking system that includes savings accounts. The system allows users to create savings accounts, deposit money, withdraw money, and calculate interest for the accounts. Each account has a unique account number and starts with an initial balance. The interest rate for each savings account is provided during its creation.



Classes:



Account: A base class for a bank account. It stores the account number and balance. It provides methods to deposit, withdraw, get the balance, and get the account number.



SavingsAccount: Inherits from the Account class. It represents a savings account with an additional interest rate. It has methods to calculate and add interest and display the account balance.

Input format :
The first line contains a character string representing the account number.

The second line contains a non-negative floating-point number representing the initial balance.

The third line contains a non-negative floating-point number representing the interest rate.

The fourth line contains a non-negative floating-point number representing the deposit amount.

The fifth line contains a non-negative floating-point number representing the withdrawal amount.

Output format :
For each deposit and withdrawal operation,

display a success message in the format: "Deposited " or "Withdrawn " followed by the respective amount with two decimal values and "successfully."

If interest is calculated, display the interest added in the format: "Interest added: " followed by the calculated interest with two decimal values.

Finally, display the savings account balance in the format: "Savings Account Balance: " followed by the current balance with two decimal values.



Refer to the sample output for the formatting specifications.

Code constraints :
1 <= The length of the account number <= 15

1 <= Initial balance for savings accounts <= 10000.0

0.0 <= Annual interest rate for the savings account <= 1.0

0.0 <= Deposit and withdrawal amounts <= 10000.0

Withdrawal amounts do not exceed the available balance.

Sample test cases :
Input 1 :
A1234567890
1000.00
5.00
200.00
300.00
Output 1 :
Deposited 200.00 successfully.
Withdrawn 300.00 successfully.
Interest added: 45.00
Savings Account Balance: 945.00
Input 2 :
B9876543210
500.00
2.50
100.00
50.00
Output 2 :
Deposited 100.00 successfully.
Withdrawn 50.00 successfully.
Interest added: 13.75
Savings Account Balance: 563.75