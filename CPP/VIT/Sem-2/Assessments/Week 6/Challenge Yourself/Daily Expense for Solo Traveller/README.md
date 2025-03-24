# Single File Programming Question

## Problem Statement

Anu is assigned with the task of creating a program to calculate the total daily expense for a solo traveller based on their trip details and budget allocations using the concept of multi-level inheritance.

Define a class TravelPlan with public attributes days and budget.
Subclass BudgetTravel inheriting from TravelPlan to calculate the base daily expense.
Subclass SoloTravel inheriting from BudgetTravel to incorporate lodging and food expenses.
Implement constructors in each class to initialize the respective data members.

Calculate and display the total daily expense for the solo traveller.

Formulas

Base daily expense = 1.2 * (budget / days)

Total expense = base expense + lodging expense + food expense

### Input format :

The first line of input consists of an integer representing the number of days of the trip.

The second line consists of three space-separated double values, representing the total budget, lodging expenses, and food expenses.

### Output format :

The output prints "Rs. X" where X is a double value, rounded off to two decimal places.

Refer to the sample output for formatting specifications.

### Code constraints :

1 ≤ number of days ≤ 50

Lodging and Food expenses ≤ Total Budget

### Sample test cases :

#### Input 1 :

5
3050.50 525.75 750.20

#### Output 1 :

Rs. 2008.07

#### Input 2 :

26
45575.50 15350.75 9500.25

#### Output 2 :

Rs. 26954.48

Whitelist
Set 1:
class TravelPlan
Set 2:
class BudgetTravel
Set 3:
class SoloTravel
