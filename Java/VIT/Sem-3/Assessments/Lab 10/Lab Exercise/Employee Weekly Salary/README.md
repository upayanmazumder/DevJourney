Single File Programming Question
Problem Statement



Adams has a reputation company with a great number of employees. He must calculate the salary weekly according to the hourly rate and working hours. Create a program to define a class Employee with attributes name and hourly rate. Create a subclass HourlyEmployee that calculates the weekly salary based on the number of hours worked.



(The first 40 hours are based on the regular hour rate. If the work hours are greater than 40 then the work wage is 1.5 times the hourly rate)



Example

Input:

Chris

10

45



Output:

Weekly Salary: Rs.475.00



Explanation:

Calculation:

The first 40 hours are paid normally: 40 × 10 = 400.00
The extra 5 hours are paid at 1.5 times the hourly rate: 5 × (10×1.5) = 5 × 15 = 75.00
Total salary: 400.00 + 75.00 = 475.00
Input format :
The first line of input consists of a string that represents the name of the employee.

The second line consists of a double value that represents the rate for an hour.

The last line consists of an integer that represents the total hours worked.

Output format :
The output displays the total salary of the employee, where salary is rounded to two decimal places in the format: "Weekly Salary: Rs.<double value>".



Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ hourly_rate ≤ 1000

1 ≤ total_hours ≤ 168 (Maximum working hours in a week: 7 days × 24 hours = 168)

The name of the employee should be a non-empty string.

Sample test cases :
Input 1 :
Dave
10.0
40
Output 1 :
Weekly Salary: Rs.400.00
Input 2 :
Chris
10.0
45
Output 2 :
Weekly Salary: Rs.475.00