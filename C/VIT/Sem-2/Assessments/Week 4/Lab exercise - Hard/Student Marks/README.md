Single File Programming Question
Problem Statement



Rajesh is a teacher who wants to create a program to manage student data. Each student would have a name, age, and marks in three subjects: C, DS, and Physics. Implement a nested structure named Marks within the Student structure to encapsulate subject-wise marks.



The program should read the data for 'n' students, calculate each student's total marks, and then display the students in ascending order based on their total marks. 

Input format :
The first line of the input consists of an integer n, representing the number of students.

In each of the following n lines, the input consists of five space-separated values:

A string (without spaces) - Student's name
An integer - Student's age
Three integers - Marks in C, DS, and Physics
Output format :
The output displays the sorted list of students in ascending order based on their total marks.

For each student, the output displays the following separated by a space:

A string (without spaces) - The student's name
An integer - The student's age
An integer - The total marks obtained by the student


Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

2 ≤ n ≤ 10

19 ≤ age ≤ 26

1 ≤ Length of the name ≤ 20

1 ≤ Each mark ≤ 100

Sample test cases :
Input 1 :
2
Eva 25 92 89 94
David 23 78 82 88
Output 1 :
David 23 248
Eva 25 275
Input 2 :
5
Alice 19 89 97 87
Bob 20 91 92 93
Charles 19 87 95 89
David 20 56 58 59
Elena 19 98 99 99
Output 2 :
David 20 173
Charles 19 271
Alice 19 273
Bob 20 276
Elena 19 296
Input 3 :
10
Ava 20 88 92 90
Liam 22 78 82 88
Olivia 21 92 89 94
Ethan 23 85 78 92
Mia 24 85 90 88
Noah 25 78 82 80
Grace 25 75 80 85
Jack 24 78 82 80
Aiden 22 92 89 94
Lily 23 88 92 90
Output 3 :
Noah 25 240
Grace 25 240
Jack 24 240
Liam 22 248
Ethan 23 255
Mia 24 263
Ava 20 270
Lily 23 270
Aiden 22 275
Olivia 21 275
Whitelist
Set 1:
struct