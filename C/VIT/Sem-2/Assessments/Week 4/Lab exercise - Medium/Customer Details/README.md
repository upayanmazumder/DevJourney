# Single File Programming Question

## Problem Statement

Create a structure Customer to store the customer name, account number, and account balance of N customers.

Write a program that performs the following operations:

Print the names of all the customers having a balance of less than Rs. 200.
If the customer has more than Rs. 1000 in their account, add 3% as interest to the current balance and print the updated balance.

### Input format :

The first line of input consists of an integer N, representing the number of customers.

The following N lines consist of three space-separated values: a string representing the customer name, an integer representing the account number, and a floating point value representing the account balance.

### Output format :

The first line prints "Customers with balance less than Rs.200:".

The second line prints the names of customers with a balance of less than Rs.200, separated by a space.

For the customers with more than Rs.1000 as updated balance, the output prints "Updated balance of X: Rs. Y" where X is the name and Y is the updated balance as a float value, rounded off to two decimal places.

Refer to the sample output for the formatting specifications.

### Code constraints :

1 ≤ N ≤ 10

1 < Length of customer name < 50

### Sample test cases :

#### Input 1 :

3
John 101 750.50
Alice 102 1200.75
Bob 103 180.20

#### Output 1 :

Customers with balance less than Rs.200:
Bob
Updated balance of Alice: Rs. 1236.77

#### Input 2 :

5
David 201 300.31
Eva 202 190.54
Frank 203 1850.45
Grace 204 50.75
Sam 205 1758.34

#### Output 2 :

Customers with balance less than Rs.200:
Eva Grace
Updated balance of Frank: Rs. 1905.96
Updated balance of Sam: Rs. 1811.09
Whitelist
Set 1:
struct
