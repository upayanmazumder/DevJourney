Single File Programming Question
Problem Statement



Rani wants to purchase n different books from a bookstore. 



Create a structure called book with the following details: book ID, book's name, author, publisher, number of copies, and price.



If the price of the book is more than 500 rupees, a 10% tax should be added. For all other cases, a 5% tax should be added. Calculate the total amount that she has to pay.

Input format :
The first line consists of an integer n, representing the number of books.

In each of the following n lines, the input consists of six space-separated values:

An integer - Book ID
A string (without spaces) - Book's name
A string (without spaces) - Author's name
A string (without spaces) - Publisher's name
An integer - Number of copies required
A float value - Price of the book
Output format :
The output prints n lines. In each of the following n lines, the output prints two space-separated values:

A string (without spaces) - Book's name.
A float value rounded to two decimal places - Final price after including appropriate tax.


Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n ≤ 10

1 ≤ Length of the book's name ≤ 50

1 ≤ Length of the author's name ≤ 25

1 ≤ Length of the publisher's name ≤ 25

Sample test cases :
Input 1 :
3
101 ToKillAMockingbird HarperLee PenguinBooks 150 450.00
102 1984 GeorgeOrwell RandomHouse 100 300.00
103 PrideAndPrejudice JaneAusten VintageBooks 120 550.00
Output 1 :
ToKillAMockingbird 472.50
1984 315.00
PrideAndPrejudice 605.00
Whitelist
Set 1:
struct
book