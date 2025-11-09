# Library System

## Single File Programming Question

## Problem Statement

Alex is managing a library system where book records need to be stored and retrieved efficiently. Each book has a unique ID, a title, an author, and a number of copies available. The records need to be serialized to a file so they can be retrieved later.

Alex also wants to query books based on a minimum number of copies available and retrieve only those books that have copies greater than the given threshold.

Write a program that does the following:

Reads book details (n books).
Stores them in a file using serialization.
Reads the data back from the file.
Filters and prints books with copies greater than a given threshold.
If no books meet the criteria, print "No books found above threshold".
#### Input:

```
format :
```

An integer n representing the number of books.

Next n lines contains 4 space separated inputs:

An integer book_id
A string title
A string author
An integer copies (number of copies available)
The last line contains an integer representing the minimum copies threshold.

#### Output:

```
format :
```

The output prints the books that have copies greater than the given threshold in the format:

"book_id title author copies"

If no book meets the criteria, print: "No books found above threshold"

Refer to the sample output for the formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ n ≤ 100 (Number of books)

1 ≤ book_id ≤ 1000 (Unique ID for each book)

1 ≤ length(title), length(author) ≤ 50 (Title and author names are up to 50 characters)

0 ≤ copies ≤ 100 (Books can have between 0 and 100 copies)

0 ≤ threshold ≤ 100 (Threshold for filtering books)

Sample test cases :
#### Input 1:

```
3
401 AlgorithmsAndData BobDavis 4
402 DatabaseManagement CarlaMoore 6
403 MobileDevelopment JakeBrown 3
3
Output 1 :
401 AlgorithmsAndData BobDavis 4
402 DatabaseManagement CarlaMoore 6
Input 2 :
2
201 DataScience MarkLee 2
202 WebDevelopment SusanGreen 3
5
Output 2 :
No books found above threshold
```
