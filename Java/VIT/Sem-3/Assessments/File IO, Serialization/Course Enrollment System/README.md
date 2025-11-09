# Course Enrollment System

## Single File Programming Question

## Problem Statement

Riya is developing a student course enrollment system for her university. She wants to store each student’s details—including their name, student ID, and the list of courses they have enrolled in—safely using Java serialization. Your task is to create a program that:

Reads student details from the user.
Validates the inputs.
Serializes and deserializes the student information.
Prints the student’s details in the specified format.
#### Input:

```
format :
```

he first line contains a string representing the Student’s Name.

The second line contains a string representing the Student’s ID.

The third line contains a comma-separated list of enrolled courses.

#### Output:

```
format :
```

If all the details are valid, output the following:

Name: <name>
Student ID: <id>
Enrolled Courses: <courses>
If the student ID is invalid (i.e., not a positive integer), output: Invalid student ID! Must be a positive integer.

Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

Student Name: Any non-empty string.

Student ID: Must be a positive integer.

Enrolled Courses: A non-empty list of comma-separated courses.

Sample test cases :
#### Input 1:

```
Jane Smith
67890
Computer Science, Programming
Output 1 :
Name: Jane Smith
Student ID: 67890
Enrolled Courses: Computer Science, Programming
Input 2 :
Sarah Lee
12345
Math, Chemistry, Biology
Output 2 :
Name: Sarah Lee
Student ID: 12345
Enrolled Courses: Math, Chemistry, Biology
Input 3 :
Lucas Green
-12345
Math, History
Output 3 :
Invalid student ID! Must be a positive integer.
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
```
