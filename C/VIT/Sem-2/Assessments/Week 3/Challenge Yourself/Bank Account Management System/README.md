# Single File Programming Question

## Problem Statement

Gokul wants to create a simple bank account management system. He wants to be able to deposit and withdraw money from his account and check his account balance.

You need to help him implement this system using pointer arithmetic.

### Input format :

The input consists of a series of inputs from the user in the following format:

An integer choice (1, 2, 3, or 4) represents the user's menu selection.

Deposit
Withdraw
Display Balance
Exit
If the choice is 1 (Deposit) or 2 (Withdraw), the choice is followed by an integer representing the amount to deposit or withdraw, separated by a space.

Note: Option 4 is mandatory to terminate the program.

### Output format :

The output displays the following information in separate lines:

For deposit and withdrawal operations, print "Deposit successful." or "Withdrawal successful." as appropriate.
If the user attempts to withdraw more money than the account balance, print "Insufficient balance."
When checking the account balance, print "Current Balance: " followed by the account balance (an integer).
For invalid choices, print "Invalid choice."
After choosing to exit the program, print "Exiting program."

Refer to the sample outputs for a better understanding.

### Code constraints :

1 ≤ balance ≤ 107

Withdrawal amount ≤ Account balance

The initial account balance is 0.

### Sample test cases :

#### Input 1 :

1 100
2 300
3
4

#### Output 1 :

Deposit successful.
Insufficient balance.
Current Balance: 100
Exiting program.

#### Input 2 :

1 1000
2 300
3
4

#### Output 2 :

Deposit successful.
Withdrawal successful.
Current Balance: 700
Exiting program.

#### Input 3 :

6
4

#### Output 3 :

Invalid choice.
Exiting program.

#### Input 4 :

2 300
3
4

#### Output 4 :

Insufficient balance.
Current Balance: 0
Exiting program.

#### Input 5 :

1 500
2 100
2 200
3
4

#### Output 5 :

Deposit successful.
Withdrawal successful.
Withdrawal successful.
Current Balance: 200
Exiting program.
