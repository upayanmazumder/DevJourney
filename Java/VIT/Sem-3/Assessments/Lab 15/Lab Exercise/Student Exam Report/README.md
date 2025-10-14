Single File Programming Question
Problem Statement



﻿Sita is developing a program to manage student exam results. The program should allow users to input a student's name, marks in three subjects, and then calculate the average marks. It must store all this information in a file named result_source.txt.



After storing the data, the program should copy the content from result_source.txt to another file named result_destination.txt and display the copied content to the user.



Your task is to help Sita implement this functionality using character stream classes.

Input format :
The first line of input contains a string representing the student's name.

The second line of input contains three space-separated integers representing the marks obtained in three subjects (each out of 100).

Output format :
The first line of output prints "Student Exam Report:"

The second line of output prints "Name: " followed by a string representing the student's name

The third line of output prints "Subject 1: " followed by an integer representing the mark in first subject.

The fourth line of output prints "Subject 2: " followed by an integer representing the mark in second subject.

The fifth line of output prints "Subject 3: " followed by an integer representing the mark in third subject.

The sixth line prints of output prints "Average Marks: " followed by a double value representing the average of the three marks rounded to 2 decimal places.



Refer to the sample output for formatting specifications.

Code constraints :
The given testcases fall under the following constraints:

1 ≤ Length of name ≤ 50

0 ≤ Each subject mark ≤ 100

Sample test cases :
Input 1 :
Amit Verma
85 90 95
Output 1 :
Student Exam Report:
Name: Amit Verma
Subject 1: 85
Subject 2: 90
Subject 3: 95
Average Marks: 90.00
Input 2 :
Riya Sen
78 82 84
Output 2 :
Student Exam Report:
Name: Riya Sen
Subject 1: 78
Subject 2: 82
Subject 3: 84
Average Marks: 81.33