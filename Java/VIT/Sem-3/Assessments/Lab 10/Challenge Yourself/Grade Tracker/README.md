Single File Programming Question
Problem Statement



Kavi, a student, is preparing for his exams and needs to track his marks across multiple subjects. He has a method for adding marks for individual subjects and another method to add marks for two subjects at once. He also needs to calculate his average marks and includes a bonus in the calculation. Based on his marks, he wants to know his grade. Help Kavi implement a solution to track and compute his results.



Help him to implement the task.



Methods Specification:

addMarks: This method should be overloaded to support both adding a single mark for a subject (addMarks(int marks)) and adding marks for two subjects (addMarks(int marks1, int marks2)).



calculateAverage: This method should be overloaded to support calculating the average marks, both without a bonus (calculateAverage()) and with a bonus (calculateAverage(int bonus)).



calculateGrade: This method takes the marks for a subject and calculates the grade based on the following conditions:

If marks are 90 or above, return "Excellent".
If marks are between 80 and 89, return "Good".
If marks are between 70 and 79, return "Average".
If marks are between 60 and 69, return "Below Average".
If marks are below 60, return "Fail".


Formulas:

Average:

average = totalMarks / subjects

Bonus Average:

bonusAverage = (totalMarks + bonus) / subjects

Input format :
The first line of input consists of a String name, representing the name of the student (in this case, Kavi).

The second line of input consists of an Integer marks1, representing the marks for the first subject.

The third line of input consists of an Integer marks2, representing the marks for the second subject.

The fourth line of input consists of an Integer marks3, representing the marks for the third subject.

The fifth line of input consists of an Integer bonus, representing the bonus marks to be added to the total marks for calculating the bonus average.

Output format :
The first line of output prints: "Basic Average: " followed by the value of average1 (average without bonus).

The second line of output prints: "Bonus Average: " followed by the value of average2 (average with bonus).

The third line of output prints: "Word Grade: " followed by the grade for marks1.



Refer to the sample output for the formatting specifications.

Code constraints :
The test cases fall under the following constraints:

1 ≤ length of name ≤ 100

1 ≤ marks ≤ 100

0 ≤ bonus ≤ 20

Sample test cases :
Input 1 :
Alice
80
85
90
5
Output 1 :
Basic Average: 85.00
Bonus Average: 86.67
Word Grade: Good
Input 2 :
Bob
30
45
20
3
Output 2 :
Basic Average: 31.67
Bonus Average: 32.67
Word Grade: Fail