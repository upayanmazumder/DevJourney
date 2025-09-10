Single File Programming Question
Problem Statement
Rohan wants to build a simple banking system that calculates the yearly interest for different types of bank accounts. The program should allow the user to enter the initial balance and specify the account type (Savings, Checking, or Other). Based on the account type, the program should compute and display the yearly interest.
The interest rates are as follows:
Savings Account: 5% annual interest
Checking Account: 2% annual interest
Other Account Types: 1% annual interest
The program should use the BankAccount class to initialize the balance and account type using a constructor and determine the applicable interest rate. The calculated interest should be displayed with one decimal precision.
Input format :
The first line contains a double representing the initial balance.
The second line contains a string representing the account type (Savings, Checking, or Other).
Output format :
The first line of output prints "Yearly Interest: Rs. " followed by a double value representing the calculated yearly interest rounded to one decimal place.
Refer to the sample output for the formatting specifications.
Code constraints :
The given test cases fall under the following constraints:
1.0 ≤ Initial Balance ≤ 100000.0
Account Type will be one of: Savings, Checking, Other (case-sensitive)
Sample test cases :
Input 1 :
1000.00 Savings
Output 1 :
Yearly Interest: Rs.50.0
Input 2 :
500.00 Checking
Output 2 :
Yearly Interest: Rs.10.0
Input 3 :
200.00 Other
Output 3 :
Yearly Interest: Rs.2.0
Footer Snippet
1
2
3
4
5
6
7
8
9
10
