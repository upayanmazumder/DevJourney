# Annual Salary of Manager

## Single File Programming Question

## Problem Statement

In a company, each manager has a unique employee ID and a monthly salary. You are required to design a program that will calculate and display the annual(12 months) salary of a manager based on the input details provided by the user.

Implement the solution using a single inheritance approach.

Employee: The base class with attributes name and employeeID.

Manager: The derived class inheriting from Employee, with an additional attribute salary.

#### Input:

```
format :
```

The first line of input consists of a string name, representing the manager's name.

The second line of input consists of an integer employeeID, representing the manager's employee ID.

The third line of input consists of a double salary, representing the manager's monthly salary.

#### Output:

```
format :
```

The first line of output prints: Name: <name>

The second line of output prints: Annual Salary: Rs. <annual_salary> (rounded to two decimal places).

Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

10,000.0 ≤ monthly salary ≤ 2,00,000.0

Sample test cases :
#### Input 1:

```
Davis
234
28750.75
Output 1 :
Name: Davis
Annual Salary: Rs. 345009.00
Input 2 :
Ramya
907
37500.25
Output 2 :
Name: Ramya
Annual Salary: Rs. 450003.00
```
