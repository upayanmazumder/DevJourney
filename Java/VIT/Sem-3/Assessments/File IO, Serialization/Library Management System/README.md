Single File Programming Question
Problem Statement

Ananya is developing a library management system for her college. She wants to keep track of each book’s details, including the book’s title, a unique book ID, and the name of the person who borrowed it. The system should be able to store and retrieve this information efficiently.

Help Ananya by writing a program that reads the book lending details and validates the input.

Input format :
The first line consists of a string representing the Book's Title.

The second line consists of a string representing the Book's ID.

The third line consists of a string representing the Borrower's Name

Output format :
If all the details are valid, output the following:

Book Title: <title>
Book ID: <id>
Borrower's Name: <borrower_name>
If the book ID is invalid (i.e., not a positive integer), output: Invalid book ID! Must be a positive integer.

Refer to the sample output for formatting specifications.

Code constraints :
Book Title: Any non-empty string.

Book ID: Must be a positive integer.

Borrower's Name: A non-empty string.

Sample test cases :
Input 1 :
Harry Potter and the Sorcerer's Stone
12345
John Doe
Output 1 :
Book Title: Harry Potter and the Sorcerer's Stone
Book ID: 12345
Borrower's Name: John Doe
Input 2 :
Moby Dick
-12345
John Doe
Output 2 :
Invalid book ID! Must be a positive integer.
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
