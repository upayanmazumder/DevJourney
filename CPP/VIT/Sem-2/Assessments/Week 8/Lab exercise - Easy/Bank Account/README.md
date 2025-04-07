Single File Programming Question
Problem statement



John wants to create a program for calculating interest on a bank account using a template class named BankAccount. The class includes two data members: balance and interestRate.



The program provides functionality to set the balance, set the interest rate, get the current balance, get the interest rate, and calculate the interest earned after one year.



Formula:

Calculates the interest earned on the current balance after one year using the formula balance * interestRate / 100.

Input format :
The first line consists of an integer representing the initial balance of the bank account.

The second line consists of an integer representing the interest rate of the bank account.

Output format :
The first line should display the balance of the bank account after one year, considering the interest earned in the format:

"Balance after one year: <<Z>>".

The second line should display the interest earned after one year in the format:

"Interest earned after one year: <<X>>".



Refer to the sample output for formatting specifications.

Code constraints :
0 ≤ balance ≤ 10^5

0 ≤ interest rate ≤ 20

Sample test cases :
Input 1 :
1000
5
Output 1 :
Balance after one year: 1050
Interest earned after one year: 50
Input 2 :
500
2
Output 2 :
Balance after one year: 510
Interest earned after one year: 10