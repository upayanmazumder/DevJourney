Single File Programming Question
Problem Statement



In a small town library, the librarian wants to track the total number of books across different categories like "Science", "Fiction", and "History". Implement a program that calculates the total number of books by passing the objects of each category as arguments to a function.



Class Definition:

Category Class: Contains an integer attribute for the number of books and a constructor to initialize it.
Function: The calculateTotalBooks function takes multiple Category objects as arguments and returns the total number of books.
Input format :
The first line contains an integer n, the number of categories.

Each of the next n lines contains an integer numBooks representing the number of books in that category.

Output format :
The output should print the total number of books across all categories.



Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ n ≤ 10

1 ≤ numBooks ≤ 1000

Sample test cases :
Input 1 :
3
100
150
200
Output 1 :
Total books: 450
Input 2 :
2
300
50
Output 2 :
Total books: 350