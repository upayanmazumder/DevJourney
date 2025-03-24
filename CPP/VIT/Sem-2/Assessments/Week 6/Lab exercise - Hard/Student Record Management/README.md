Single File Programming Question
Problem Statement



Helen wants to create a program for student record management with a class hierarchy. 



Help her write a program that utilizes hybrid inheritance using the below information.

A base class: Person holds attributes name and ID. 
Another base class: Score contains the student's score. 
Two derived classes: UndergraduateStudent and PostgraduateStudent, inherit from both Person and Score classes, calculate and display the grade and results respectively. 


For Undergraduate Students, Grade is calculated as:

If the score is 90 or above, the grade is 'A'.
If the score is 80 to 89, the grade is 'B'.
If the score is 70 to 79, the grade is 'C'.
If the score is 60 to 69, the grade is 'D'.
If the score is below 60, the grade is 'F'.


For Postgraduate Students, Result is calculated as:

If the score is 60 or above, the result is 'Pass'.
If the score is below 60, the result is 'Fail'.
Input format :
The first line of input consists of a string, representing the UG student's name.

The second line consists of a string, representing the UG student's ID.

The third line consists of a double value, representing the UG student's score.

The fourth line consists of a string, representing the PG student's name.

The fifth line consists of a string, representing the PG student's ID.

The sixth line consists of a double value, representing the PG student's score.

Output format :
The first line of output prints the grade of UG student in the format: "Student [UG Student's Name] with ID [UG Student's ID] received grade [UG Student's Grade]."

The second line prints the result of the PG student in the format: "Student [PG Student's Name] with ID [PG Student'S ID] [Pass/Fail] the course."



Refer to the sample outputs for formatting specifications.

Code constraints :
10.0 ≤ score ≤ 100.0

Sample test cases :
Input 1 :
John
CS101
75.5
Alice
ECE111
55.0
Output 1 :
Student John with ID CS101 received grade C.
Student Alice with ID ECE111 Fail the course.
Input 2 :
Mary
EEE65
85.0
David
CSE13
92.5
Output 2 :
Student Mary with ID EEE65 received grade B.
Student David with ID CSE13 Pass the course.
Input 3 :
Ella
ECE20
45.5
George
Mech101
30.8
Output 3 :
Student Ella with ID ECE20 received grade F.
Student George with ID Mech101 Fail the course.