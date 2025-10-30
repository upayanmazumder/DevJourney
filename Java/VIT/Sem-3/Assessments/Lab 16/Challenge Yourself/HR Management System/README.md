Single File Programming Question
Problem Statement

Riya is working on an HR management system that needs to store and retrieve employee records using object serialization. The system should allow storing multiple employees' details and later retrieve only those earning above a given salary threshold.

Your task is to implement a Java program that:

Takes multiple employee records as input, where each employee has:
employee_id (Integer)
name (String)
department (String)
salary (Double)
Serializes the employee records into a file named "employees.ser".
Deserializes the records from the file and prints employees' earnings above a given threshold.
Input format :
The first line consists of an integer n, representing the number of employees.

The next n lines contain the employee details: each line contains an integer employee_id, a string name, a string department, and a double salary.

The last line contains a double value X, the salary threshold.

Output format :
If an employee’s salary is greater than X, print: "employee_id name department salary"

If no employees meet the criteria, print: "No employees found above threshold"

Refer to the sample output for the formatting specifications.

Code constraints :
jaThe given test cases fall under the following constraints:

1 ≤ N ≤ 20

100 ≤ employee_id ≤ 1000

1 ≤ length(name) ≤ 20 (Alphabets only)

1 ≤ length(department) ≤ 15 (Alphabets only)

10000.00 ≤ salary ≤ 5000000.00

10000.00 ≤ X ≤ 5000000.00

Sample test cases :
Input 1 :
3
101 John HR 45000.00
102 Alice IT 60000.00
103 Bob Finance 90000.00
50000.00
Output 1 :
102 Alice IT 60000.0
103 Bob Finance 90000.0
Input 2 :
2
201 Mike HR 40000.00
202 Sara IT 38000.00
45000.00
Output 2 :
No employees found above threshold
