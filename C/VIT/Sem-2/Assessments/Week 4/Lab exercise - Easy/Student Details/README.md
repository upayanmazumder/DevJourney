Single File Programming Question
Problem Statement



Maya is a class teacher who wants to maintain a record of her students' details, including their roll numbers, names, and marks. She wants to display these details in a structured format to track students' progress effectively. Using the concept of structures and pointers, write a program to help Maya display the details of her students.

Input format :
The first line consists of the number of Student details 'n'.

Next 'n' lines are the student details consisting of the order roll_no, name, and marks separated by space.

Output format :
The output displays the details of each Student.



Refer to the sample output for the formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ n ≤ 50

1 ≤ roll_no ≤ 1000

Marks are floating-point numbers between 0.0 and 100.0.

Names contain only alphabetic characters and are case-sensitive, with a maximum length of 50.



Sample test cases :
Input 1 :
3
1 john 85.5
2 jane 92.3
3 Bob 77.8
Output 1 :
Details of all students
Student 1
Roll no: 1
Name: john
Marks: 85.50
Student 2
Roll no: 2
Name: jane
Marks: 92.30
Student 3
Roll no: 3
Name: Bob
Marks: 77.80
Input 2 :
2
10 Prabhas 60
25 Vinay 28
Output 2 :
Details of all students
Student 1
Roll no: 10
Name: Prabhas
Marks: 60.00
Student 2
Roll no: 25
Name: Vinay
Marks: 28.00
Input 3 :
2
9 Alice 88.7
4 Charlie 75.4
Output 3 :
Details of all students
Student 1
Roll no: 9
Name: Alice
Marks: 88.70
Student 2
Roll no: 4
Name: Charlie
Marks: 75.40
Whitelist
Set 1:
struct Student
roll_no
name
marks