# Payroll System

## Single File Programming Question

## Problem Statement

Sharon is tasked with developing a payroll system for a company. The company has employees of two categories: Managers and Substaff. Managers receive earnings based on their basic salary, while Substaff receive earnings, deductions, and a bonus based on their basic salary.

Your task is to assist Sharon define an interface named Employee with the following methods:

double earnings(double basicSalary)
double deductions(double basicSalary)
double bonus(double basicSalary)

Create an abstract class called Manager that implements the Employee interface.

In the Manager class:

Implement the earnings(double basicSalary) method to calculate earnings as basic salary + 80% of basic salary (DA) + 15% of basic salary (HRA).
Implement the deductions(double basicSalary) method to calculate deductions as 12% of basic salary.

Create another class called Substaff that extends the Manager class and implements the bonus(double basicSalary) method.

In the Substaff class:

Implement the bonus(double basicSalary) method to calculate the bonus as 50% of the basic salary.
#### Input:

```
format :
```

The input consists of a double value representing the basic salary of the employee.

#### Output:

```
format :
```

The first line of output prints "Earnings: " followed by a double value, representing the earnings, rounded off to two decimal places.

The second line prints "Deductions: " followed by a double value, representing the deductions, rounded off to two decimal places.

The third line prints "Bonus: " followed by a double value, representing the bonus, rounded off to two decimal places.

Refer to the sample output for formatting specifications.

Code constraints :
1000.00 ≤ Basic Salary ≤ 100000.00

Sample test cases :
#### Input 1:

```
25677.98
Output 1 :
Earnings: 50072.06
Deductions: 3081.36
Bonus: 12838.99
Input 2 :
50000.00
Output 2 :
Earnings: 97500.00
Deductions: 6000.00
Bonus: 25000.00
```
