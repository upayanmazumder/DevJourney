# Library Books

## Single File Programming Question

## Problem Statement

Isha works in a library and has been tasked with managing a digital archive of books. She wants to store details of books, including their ID, title, and author, in a file for future reference. To achieve this, Isha plans to serialize an array of book objects and save them to a file. The system should also display a summary of the books stored after serialization.

Help Isha implement a program to serialize book details and store them efficiently.

#### Input:

```
format :
```

The first line contains an integer n (the number of books).

The next 3 × n lines contain details of the books:

Book ID (integer)
Title (String)
Author (String)
#### Output:

```
format :
```

The first line prints a fixed message:

"Successfully serialized " followed by an int (number_of_books) indicating how many books were serialized,
then the fixed string " books to books.dat".
The second line contains the fixed string: "Summary of Books:".

The following lines list the serialized books, each formatted as:

"<book_number>. [BookId: <book_id>] Title: <title>, Author: <author>"

Refer to the sample output for the formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ n ≤ 100

Titles and authors will have a maximum length of 100 characters.

Book IDs are unique.

Sample test cases :
#### Input 1:

```
1
1
Harry Potter
J.K. Rowling
Output 1 :
Successfully serialized 1 books to books.dat
Summary of Books:
```

1. [BookId: 1] Title: Harry Potter, Author: J.K. Rowling
#### Input 2:

```
   2
   201
   E=mc^2
   Albert Einstein
   202
   C++ Primer
   Stanley B. Lippman
   Output 2 :
   Successfully serialized 2 books to books.dat
   Summary of Books:
1. [BookId: 201] Title: E=mc^2, Author: Albert Einstein
1. [BookId: 202] Title: C++ Primer, Author: Stanley B. Lippman
```
