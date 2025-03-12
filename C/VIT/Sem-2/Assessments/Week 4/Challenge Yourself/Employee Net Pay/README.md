Single File Programming Question
Write a C program for employee bill generation using a structure for a maximum of 100 employees who belongs to ABC organization. Read the employee details as: Employee number, Name, Age, Designation, and Basic pay.



Compute the following details, and print all the details in a neat output format:
 Dearness Allowance = 50 % of Basic Pay
 House rent allowance = 20 % of Basic Pay
 City Compensation Allowance = 10 % of Basic Pay
 Provident Fund = 10 % of Basic Pay
 Life Insurance = 15 % of Basic Pay


2. Calculate Net pay

3.	Display all details of employees whose net salary is >= 50000

4.	Count the number of employees whose age is <=30

Input format :
The first line of the input consists of the value of n.

The next n line of input is the structure members: employee number, employee name, age, designation, and basic pay.

Output format :
The output prints the Dearness Allowance, house rent allowance, city compensation allowance, provident fund, and life insurance along with the net pay for each employee.
Print the details of the employee, if the basic pay is greater than or equal to 50000.
The number of employees having age less than or equal to 30.


Refer to the sample output for format specifications.

Sample test cases :
Input 1 :
2
15 bob 28 manager 60000
20 charles 35 supervisor 55500
Output 1 :
bob allowance details:
30000.00 12000.00 6000.00 6000.00 9000.00
Netpay: 123000.00
charles allowance details:
27750.00 11100.00 5550.00 5550.00 8325.00
Netpay: 113775.00
The following employees have netpay greater than 50000:
bob
charles
Number of employees whose age <=30: 1
Input 2 :
3
22 ben 26 accountant 10000
24 bobby 35 manager 50000
32 don 28 assistant manager 42500
Output 2 :
ben allowance details:
5000.00 2000.00 1000.00 1000.00 1500.00
Netpay: 20500.00
bobby allowance details:
25000.00 10000.00 5000.00 5000.00 7500.00
Netpay: 102500.00
don allowance details:
0.00 0.00 0.00 0.00 0.00
Netpay: 0.00
The following employees have netpay greater than 50000:
bobby
Number of employees whose age <=30: 2