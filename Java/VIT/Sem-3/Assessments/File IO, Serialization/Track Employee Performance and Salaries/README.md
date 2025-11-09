# Track Employee Performance and Salaries

## Single File Programming Question

## Problem Statement

Priya manages a small IT consultancy firm and wants to track her employees’ performance and salaries securely. Each employee has a unique ID, a name, and a salary. She wants to store the employee data using serialization into a .ser file and then deserialize it to ensure data integrity. After deserialization, she wants to identify the employee with the highest salary.

Your task is to implement the logic to find the employee with the highest salary.

Help Priya develop this employee management system.

#### Input:

```
format :
```

The first line of input consists of an integer which represents the Number of employees.

The Next N lines of input consist of ID Name Salary which are space separated values.

where,

id represents integer, unique employee ID
name represents Single-word string, employee name
salary represents Double, employee salary
#### Output:

```
format :
```

Print the employee with the highest salary in the following format: Highest Salary: Employee[ID=<id>, Name=<name>, Salary=<salary>]

Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ N ≤ 50

Salary is a positive number.

Sample test cases :
#### Input 1:

```
3
101 Arjun 50000
102 Sita 60000
103 Rekha 55000
Output 1 :
Highest Salary: Employee[ID=102, Name=Sita, Salary=60000.0]
Input 2 :
1
201 Rohit 45000
Output 2 :
Highest Salary: Employee[ID=201, Name=Rohit, Salary=45000.0]
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
```
