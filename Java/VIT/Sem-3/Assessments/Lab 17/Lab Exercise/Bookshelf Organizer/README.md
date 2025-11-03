Single File Programming Question
Problem Statement

Catherine is an avid reader with an extensive collection of books. Over time, she has organized her books in a specific order and labeled each with a unique identifier. Lately, she has been rearranging her bookshelves and wants to create an algorithm to efficiently search for a book using its ID in her collection.

Implement a generic program using binary search to assist Catherine in finding books by their unique IDs.

Input format :
The first line of input consists of an integer n, representing the number of books in Catherine's collection.

The second line consists of n space-separated integers denoting the unique IDs of the books, sorted in ascending order.

Output format :
The output displays the index(0-based) of the book corresponding to a given unique ID or displays a message indicating that the book with the provided ID is not in Catherine's collection in the following format: "Element found at index: <index>" or "Element not found in the array.".

Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ n ≤ 100

1 ≤ ID ≤ 100

Sample test cases :
Input 1 :
5
10 20 30 40 50
30
Output 1 :
Element found at index: 2
Input 2 :
5
10 20 30 40 50
90
Output 2 :
Element not found in the array.
