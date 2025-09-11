Single File Programming Question
Problem Statement



A developer aims to create a budget management system using two interfaces, ExpenseRecorder for recording expenses and BudgetCalculator for calculating remaining budgets.



The ExpenseTracker class implements these interfaces, allowing users to input an initial budget and record expenses iteratively until entering 0.0 as a sentinel value.



The program then computes and displays the remaining budget or notifies of budget exceedance.



Example



Input

100.0

20.0 30.0 10.0 0.0

Output

Remaining budget: Rs. 40.00



Explanation

The initial budget is 100.0. Expenses of 20.0, 30.0, and 10.0 are recorded.

Remaining budget is calculated (100.0 - 20.0 - 30.0 - 10.0 = 40.0).

Input format :
The first line of input is the initial budget as a double-point number (double type). The budget is a positive number.

The second line of input consists of individual expenses as double-point numbers. Each expense is separated by space.

To end the input, an expense of 0.0 is used.

Output format :
The output displays the remaining budget, formatted to two decimal places, in the following format:



If the remaining budget (double type) is non-negative, it prints "Remaining budget: Rs. [remainingBudget]".

If the remaining budget is negative, it prints "No remaining budget, You've exceeded your budget!".



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, The test cases will fall under the following constraints:

0.1 ≤ budget ≤ 5000.0

Sample test cases :
Input 1 :
100.0
20.0 30.0 10.0 0.0
Output 1 :
Remaining budget: Rs. 40.00
Input 2 :
1000.0
300.0 400.0 200.0 50.0 150.0 0.0
Output 2 :
No remaining budget, You've exceeded your budget!
Input 3 :
5000.00
1000.89 1500.76 1500.30 500.89
0.0
Output 3 :
Remaining budget: Rs. 497.16
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0