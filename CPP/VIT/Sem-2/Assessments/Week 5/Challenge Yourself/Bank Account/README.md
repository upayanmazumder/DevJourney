# Single File Programming Question

## Problem Statement

Priya is working on a banking application that calculates interest for customers' accounts. She needs to create a class called BankAccount that contains a static data member to store the interest rate (initially set to 3%), which is shared by all accounts. This static interest rate can be updated using a static member function setInterestRate. The class should also include a method to calculate the interest based on the account balance and the shared interest rate.

Write a program to help Priya calculate the interest for a given balance using the updated interest rate, with the result printed to two decimal places.

### Input format :

The first line contains a float value representing the new interest rate.

The second line contains a float value representing the account balance.

### Output format :

The output prints a float value representing the calculated interest with two decimal places.

Refer to the sample output for the formatting specifications.

### Code constraints :

0.01 ≤ rate ≤ 0.10

500.00 ≤ balance ≤ 10^6

### Sample test cases :

#### Input 1 :

0.04
1000.00

#### Output 1 :

40.00

#### Input 2 :

0.03
500.50

#### Output 2 :

15.01
Whitelist
Set 1:
class
BankAccount
static
setInterestRate
