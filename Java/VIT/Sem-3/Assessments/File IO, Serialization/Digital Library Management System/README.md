# Digital Library Management System

## Single File Programming Question

## Problem Statement

Ravi is building a digital library management system for his personal collection. He wants to store book details permanently so that they persist even if the program is closed. Your task is to append new books to the existing collection, deserialize all books from a .ser file, and perform an analysis of the collection. The analysis should:

Sort books by page count in ascending order.
Identify the book with the longest title.
Calculate the average number of pages across all books (rounded to 2 decimal places).
Help Ravi create this library management system.

#### Input:

```
format :
```

The first line contains an integer N, the number of books.

The next N lines contain details of each book in the format: Title Author Pages

Note: Title and Author are single words (without spaces).

#### Output:

```
format :
```

Display all book titles sorted by page count (ascending).

This line prints Book with Longest Title: followed by book with longest title.

Thie line prints the Average Number of Pages: average number of pages across all books (rounded to 2 decimal places).

Refer to the sample output for the formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ N ≤ 100

Title length ≤ 50 characters

Author length ≤ 30 characters

10 ≤ Pages ≤ 2000

Sample test cases :
#### Input 1:

```
3
MathBasics John 120
HistoryOfWorld Sita 340
AIResearch Arjun 250
Output 1 :
Books Sorted by Page Count:
MathBasics
AIResearch
HistoryOfWorld
```

Book with Longest Title: HistoryOfWorld

Average Number of Pages: 236.67
#### Input 2:

```
4
CProgramming Dennis 800
JavaBasics James 400
PythonGuide Guido 600
RubyBook Matz 300
Output 2 :
Books Sorted by Page Count:
RubyBook
JavaBasics
PythonGuide
CProgramming
```

Book with Longest Title: CProgramming

Average Number of Pages: 525.00
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
