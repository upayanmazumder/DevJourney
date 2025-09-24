Single File Programming Question
Problem Statement



Anu is developing a program that represents a book and ensures the validity of its attributes upon creation. The program should handle exceptions for invalid book details and provide informative error messages.



Implement a Book class with the following attributes: title (String), author (String), publicationYear (int).
Create a constructor for the Book class that initializes the book's attributes (title, author, publication year).
Implement private validation methods (validateTitle, validateAuthor, validatePublicationYear) to ensure that the title is not empty, the author is not empty, and the publication year is a positive integer.
Throw IllegalArgumentException with appropriate error messages if validation fails.
Implement a method addBook in the Book class that prints "Book added successfully" to the console.


Help Anu to design the program.

Input format :
The first line of input consists of a string, representing the title of the book.

The second line consists of a string, representing the author of the book.

The third line consists of an integer, representing the publication year of the book.

Output format :
If the book is added, print "Book added successfully"

If the title is an empty string, print "Invalid title: Title should not be empty"

If the author is an empty string, print "Invalid author: Author should not be empty"

If the publication year is not a positive integer, print "Invalid publication year: Publication year should be a positive integer".



Refer to the sample output for formatting specifications.

Code constraints :
length of the input string ≤ 100 characters

Sample test cases :
Input 1 :
The Great Gatsby
F. Scott Fitzgerald
1925
Output 1 :
Book added successfully
Input 2 :

F. Scott Fitzgerald
1925
Output 2 :
Invalid title: Title should not be empty
Input 3 :
Harry Potter and the Sorcerer's Stone
J.K. Rowling
-1997
Output 3 :
Invalid publication year: Publication year should be a positive integer
Input 4 :
Ambedkar: A Life

2022
Output 4 :
Invalid author: Author should not be empty