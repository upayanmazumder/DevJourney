# Salary Reader

## Single File Programming Question

## Problem Statement

Ravi is developing a program to manage employee salary details. The program should allow users to input the employee’s name, basic salary, and bonus amount. It must then calculate the total salary and store all this information in a file named salary_source.txt.

After storing the data, the program should copy the content from salary_source.txt to another file named salary_destination.txt and display the copied content to the user.

Your task is to help Ravi implement this functionality using character stream.

#### Input:

```
format :
```

The first line of input consists of a string representing the employee's name.

The second line consists of an integer representing the basic salary.

The third line consists of an integer representing the bonus amount.

#### Output:

```
format :
```

The first line of output prints "Employee Salary Details:"

The second line of output prints "Name: " followed by a string representing the employee's name.

The third line of output prints "Basic Salary: " followed by an integer representing the basic salary.

The fourth line of output prints "Bonus: " followed by an integer representing the bonus amount.

The fifth line of output prints "Total Salary: " followed by an integer representing the total salary (basic salary + bonus).

Refer to the sample output for formatting specifications.

Code constraints :
The given testcases fall under the following constraints:

1 ≤ Length of the name ≤ 50

1 ≤ Salary, Bonus ≤ 100000

Sample test cases :
#### Input 1:

```
Ravi Kumar
50000
8000
Output 1 :
Employee Salary Details:
Name: Ravi Kumar
Basic Salary: 50000
Bonus: 8000
Total Salary: 58000
Input 2 :
Anjali Sharma
40000
5000
Output 2 :
Employee Salary Details:
Name: Anjali Sharma
Basic Salary: 40000
Bonus: 5000
Total Salary: 45000
```
