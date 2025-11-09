Single File Programming Question
Problem Statement

Amit, a college administrator, is developing a system to manage student exam scores efficiently. The system should allow him to input student's roll numbers along with their marks in three subjects and then generate useful insights. The program must calculate and display the total marks for each student, identify the highest scorer in each subject, and determine the student with the highest overall total. Help Amit build this system by implementing a class-based solution to process and display student data accurately.

Create a class called Student with the following attributes:

int rno,
int mark1,
int mark2,
int mark3.

Create an array of objects for the above class.

Input format :
The first line of input consists of an integer (n), representing the number of students.

The next n lines each contain four space-separated integers:

The roll number (rno) of the student.
The marks in subject 1 (mark1).
The marks in subject 2 (mark2).
The marks in subject 3 (mark3).
Output format :
The output prints the Total marks for each student, printed on separate lines in the order of input.

The roll number and highest mark for each subject, are printed in the order of subjects.

The roll number and total marks of the student with the highest total marks.

Refer to the output for format specifications.

Code constraints :
1 ≤ n ≤ 100

1 ≤ rno, mark1, mark2, mark3 ≤ 100

Sample test cases :
Input 1 :
5
1 98 85 76
2 85 74 65
3 85 96 75
4 52 65 79
5 52 75 65
Output 1 :
259
224
256
196
192
1 98
3 96
4 79
1 259
Input 2 :
3
1 83 85 76
2 58 74 65
3 66 96 75
Output 2 :
244
197
237
1 83
3 96
1 76
1 244
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
