# Grading Automation System

## Single File Programming Question

## Problem Statement

Maria, a software developer, is building a grading automation system for Computer Science students. The program calculates the Grade Point Average (GPA) and determines class standing based on the number of credits completed.

The GPA is calculated using the formula:

GPA = 4.0 × (creditsCompleted / 120.0)
Where 120 credits are required for graduation, and the maximum possible GPA is 4.0.

The class standing is determined as follows:

Freshman: 0-29 credits
Sophomore: 30-59 credits
Junior: 60-89 credits
Senior: 90 or more credits

The program consists of three classes:

Student – Stores the student's name and age, and has a method displayInfo() to print these details.
Undergraduate – Inherits from Student, adds creditsCompleted, and includes calculateGPA() to compute the GPA and getClassStanding() to determine class standing.
ComputerScienceMajor – Extends Undergraduate, representing a Computer Science major without adding extra functionality.

Help Maria implement this system to calculate the GPA and class standing for Computer Science students.

#### Input:

```
format :
```

The first line contains the name of the student as a string (at most 20 characters).

The second line contains the age of the student as an integer.

The third line contains the number of credits completed by the student as a double.

#### Output:

```
format :
```

The first line of output prints: "Name: " followed by student_name (the name of the student).

The second line of output prints: "Age: " followed by student_age (the student's age).

The third line of output prints: "Credits Completed: " followed by credits_completed (the number of credits completed rounded to one decimal place).

The fourth line of output prints: "GPA: " followed by calculated_GPA (the GPA rounded to one decimal place).

The fifth line of output prints: "Class Standing: " followed by class_standing (the determined class standing based on credits completed).

Refer to the sample output for formatting specifications.

Code constraints :
The length of the student's name will be at most 20 characters.

The name can contain lowercase or uppercase letters.

Sample test cases :
#### Input 1:

```
John Doe
20
15.0
Output 1 :
Name: John Doe
Age: 20
Credits Completed: 15.0
GPA: 0.5
Class Standing: Freshman
Input 2 :
Jane Smith
22
40
Output 2 :
Name: Jane Smith
Age: 22
Credits Completed: 40.0
GPA: 1.3
Class Standing: Sophomore
Input 3 :
James Brown
21
60
Output 3 :
Name: James Brown
Age: 21
Credits Completed: 60.0
GPA: 2.0
Class Standing: Junior
Input 4 :
Emily Wilson
22
120
Output 4 :
Name: Emily Wilson
Age: 22
Credits Completed: 120.0
GPA: 4.0
Class Standing: Senior
```
