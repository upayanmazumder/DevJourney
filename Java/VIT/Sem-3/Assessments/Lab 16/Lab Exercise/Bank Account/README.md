# Bank Account

## Single File Programming Question

## Problem Statement

Sam is managing his bank account and wants to perform various transactions using a program. He wants to deposit and withdraw funds and then save the account details using serialization. Upon restarting the program, he wants to be able to load the serialized data and continue with his banking transactions.

Write a program to assist Sam in managing his bank account, create a BankAccount class, and Serialize the BankAccount object to a file named bankAccount.ser after the transactions. Deserialize the BankAccount object from the file when the program restarts.

Display the final balance after the transactions in a formatted manner with two decimal places.

#### Input:

```
format :
```

The first line of input consists of a double value B, representing the initial balance.

The second line consists of a double value D, representing the deposit amount.

The third line consists of a double value W, representing the withdrawal amount.

#### Output:

```
format :
```

The output displays the final balance after the transactions, with two decimal places.

Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1.0 ≤ B ≤ 50000.0

1.0 ≤ D ≤ 50000.0

1.0 ≤ W ≤ 6000.0

Sample test cases :
#### Input 1:

```
1000.7
500.5
100.6
Output 1 :
1400.60
Input 2 :
10000.5
450.7
120.2
Output 2 :
10331.00
```
