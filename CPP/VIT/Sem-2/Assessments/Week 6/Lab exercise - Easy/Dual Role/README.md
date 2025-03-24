Single File Programming Question
Problem Statement



Robin wants to create a program to manage an individual's dual roles as a student and an employee. The monthly income is calculated based on her age. As a student, a stipend of age * 100 is received, and as an employee, a salary of age * 500 is received. 



The program consists of four classes:

Person - Contains individual's name and age as attributes.
Student - Inherits from Person class and calculates the stipend using calculateStipend() method.
Employee - Inherits from Person class and calculates the salary using calculateSalary() method.
TeachingAssistant - Inherits from Student and Employee classes. It calculates and displays the individual's total monthly income by calling Student or Employee class based on role.
						

Refer to the below Class diagram:



			

Input format :
The first line consists of a string s representing the name of the individual.

The second line consists of an integer value n representing the individual's age.

The third line consists of a character c representing the type, where 'S' represents a student and 'E' represents an employee.

Output format :
The output displays the total monthly income calculated based on the type of role in the format: "X's Income: Rs. Y" where:

X - Name

Y - Total monthly income rounded to two decimal places.



If the type is neither 'S' nor 'E', the output displays "Invalid status!".



Refer to the sample outputs for the formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

18 ≤ n ≤ 80

Status: "S" or "E" (Case sensitive)

Length of the name ≤ 50

The name should not contain any spaces.

Sample test cases :
Input 1 :
Alice
25
S
Output 1 :
Alice's Income: Rs. 2500.00
Input 2 :
Charlie
35
E
Output 2 :
Charlie's Income: Rs. 17500.00
Input 3 :
Stella
19
t
Output 3 :
Invalid status!