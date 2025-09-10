Single File Programming Question
Problem Statement



Raghav is working on a university payroll system that categorizes employees into four types: Programmer, Assistant Professor, Associate Professor, and Professor. Each employee has basic details, including name, ID, address, email ID, and mobile number. All four roles inherit these details from the base class Employee.



Each employee has a Basic Pay (BP), and the salary components are calculated as follows:



DA (Dearness Allowance): 97% of Basic Pay
HRA (House Rent Allowance): 10% of Basic Pay
PF (Provident Fund): 12% of Basic Pay
Staff Club Fund: 0.1% of Basic Pay
Gross Salary = BP + DA + HRA
Net Salary = Gross Salary - (PF + Staff Club Fund)


Help Raghav implement the class hierarchy and generate a payslip that displays the employee details and salary information.

Input format :
The first line of the input conists of an Employee Type (Programmer, AssistantProfessor, AssociateProfessor, or Professor).

The next lines (in order) contains the following one per line:

Employee Name (String)
Employee ID (String)
Address (String)
Mail ID (String)
Mobile Number (String)
Basic Pay (double)
Output format :
The output prints the payslip if the employee type is valid in the following format:

Employee Type: <Type>

Name: <Name>

ID: <ID>

Address: <Address>

Email: <Mail_id>

Mobile: <Mobile_no>

Basic Pay: <BP>

DA: <DA>

HRA: <HRA>

PF: <PF>

Staff Club Fund: <Fund>

Gross Salary: <Gross>

Net Salary: <Net>

where the BP, DA, HRA, PF, Fund, Gross salary, and Net Salary should be rounded off to one decimal place.



If the employee type is not valid, then print: "Invalid employee type"



﻿Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

0 < Basic Pay ≤ 1,00,000

Mobile number should be 10 digits

Employee type must match one of the four valid types

Sample test cases :
Input 1 :
Programmer
Ravi
E101
Chennai
ravi@mail.com
9876543210
30000
Output 1 :
Employee Type: Programmer
Name: Ravi
ID: E101
Address: Chennai
Email: ravi@mail.com
Mobile: 9876543210
Basic Pay: 30000.0
DA: 29100.0
HRA: 3000.0
PF: 3600.0
Staff Club Fund: 30.0
Gross Salary: 62100.0
Net Salary: 58470.0
Input 2 :
AssistantProfessor
Meera
E102
Bangalore
meera@mail.com
9123456789
40000
Output 2 :
Employee Type: AssistantProfessor
Name: Meera
ID: E102
Address: Bangalore
Email: meera@mail.com
Mobile: 9123456789
Basic Pay: 40000.0
DA: 38800.0
HRA: 4000.0
PF: 4800.0
Staff Club Fund: 40.0
Gross Salary: 82800.0
Net Salary: 77960.0
Input 3 :
AssociateProfessor
John
E103
Delhi
john.d@mail.com
9012345678
50000
Output 3 :
Employee Type: AssociateProfessor
Name: John
ID: E103
Address: Delhi
Email: john.d@mail.com
Mobile: 9012345678
Basic Pay: 50000.0
DA: 48500.0
HRA: 5000.0
PF: 6000.0
Staff Club Fund: 50.0
Gross Salary: 103500.0
Net Salary: 97450.0
Input 4 :
Professor
Latha
E104
Hyderabad
latha@uni.com
9988776655
60000
Output 4 :
Employee Type: Professor
Name: Latha
ID: E104
Address: Hyderabad
Email: latha@uni.com
Mobile: 9988776655
Basic Pay: 60000.0
DA: 58200.0
HRA: 6000.0
PF: 7200.0
Staff Club Fund: 60.0
Gross Salary: 124200.0
Net Salary: 116940.0
Input 5 :
Developer
Mohan
E109
Trichy
mohan@work.com
9998887776
100000
Output 5 :
Invalid employee type