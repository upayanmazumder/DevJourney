Single File Programming Question
Problem Statement



Create a program using a structure called Employee to manage employee information. Input the employee's name, salary, and hours worked. Implement a salary increase based on hours worked, and calculate the final salary along with the total salary over 30 days. Display the results in the console.



Salary increase criteria:

If hours worked >= 12, the increase is $150.00.
If hours worked >= 10, but less than 12, the increase is $100.00.
If hours worked >= 8, but less than 10, the increase is $50.00.
If hours worked < 8, there is no increase, so the return value is $0.00.
Input format :
The input consists of the following inputs in each line:

Employee's name (a string without spaces)
Employee's current salary (a positive double-point number)
Number of hours worked by the employee (an integer)
Output format :
The first line displays "Final Salary: $" followed by a double value representing the final salary after applying the appropriate increase rounded to two decimal places.

The second line displays "Total Salary: $" followed by a double value representing the total salary for 30 days rounded to two decimal places.



Refer to the sample outputs for the formatting specifications.

Code constraints :
1 ≤ hours worked ≤ 20

Salary ≤ 10000

Sample test cases :
Input 1 :
Akil
3000.00
6
Output 1 :
Final Salary: $3000.00
Total Salary: $90000.00
Input 2 :
Yogi
575.00
9
Output 2 :
Final Salary: $625.00
Total Salary: $18750.00
Input 3 :
Uma
800.00
13
Output 3 :
Final Salary: $950.00
Total Salary: $28500.00
Input 4 :
Ragu
300.00
11
Output 4 :
Final Salary: $400.00
Total Salary: $12000.00
Whitelist
Set 1:
struct