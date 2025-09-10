Single File Programming Question
Problem Statement



Michael, a computer science student, is working on a project to develop a GPA calculator. He wants to create a program that accepts grades for multiple subjects and calculates the Grade Point Average (GPA) for a student.



Additionally, he wants to implement a scholarship eligibility check, where a student qualifies for a scholarship if their GPA is 3.5 or higher and they have taken at least 5 subjects.



To achieve this, create a GPACalculator class that encapsulates the logic for GPA calculation and scholarship eligibility. The Main class should handle user input and output. Ensure that the program utilizes this keyword and constructor for proper object-oriented design.

Input format :
The first line of input consists of an integer N (the number of subjects).

The second line consists of N double values, representing the grade for each subject, each separated by space.

Output format :
The first line of output prints the calculated average GPA for the student, as a decimal number rounded to two decimal places.

The second line prints the eligibility status for a scholarship.

If the student's GPA is 3.5 or higher and they've taken at least 5 subjects, the program should output "Eligible for a scholarship"
Otherwise, it should output "Not eligible for a scholarship"


Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ N ≤ 10

0.0 ≤ grade ≤ 5.0

Sample test cases :
Input 1 :
3
3.5 4.0 3.0
Output 1 :
GPA: 3.50
Not eligible for a scholarship
Input 2 :
5
3.9 3.9 4.0 4.0 4.0
Output 2 :
GPA: 3.96
Eligible for a scholarship