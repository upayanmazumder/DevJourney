Single File Programming Question
Problem Statement

Olivia is a college administrator who manages student records, including each student’s name, roll number, and enrolled courses. She wants to store student records safely using Java serialization and retrieve them later using deserialization.

Your task is to:

Read student details from the user.
Validate the inputs.
Serialize the student object to a file.
Deserialize it.
Print the student information in the specified format.
Help Olivia develop this student administration system.

Input format :
The first line contains a string representing the Student’s Name.

The second line contains an integer representing the Student’s Roll Number.

The third line contains a string representing the Enrolled Courses, as a comma-separated list of course names.

Output format :
If all the details are valid, output the following:

Name: <name>
Roll Number: <roll number>
Enrolled Courses: <courses>
If the roll number is invalid (i.e., not a positive integer), output: Invalid roll number! Must be a positive integer.

Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

Student Name: Any non-empty string.

Roll Number: Must be a positive integer.

Enrolled Courses: Must be a non-empty string with at least one course.

Sample test cases :
Input 1 :
John Doe
12345
Math, Physics, Chemistry
Output 1 :
Name: John Doe
Roll Number: 12345
Enrolled Courses: Math, Physics, Chemistry
Input 2 :
Alice Green
54321
Math, Biology
Output 2 :
Name: Alice Green
Roll Number: 54321
Enrolled Courses: Math, Biology
Input 3 :
Mike Johnson
-123
Math, Computer Science
Output 3 :
Invalid roll number! Must be a positive integer.
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
