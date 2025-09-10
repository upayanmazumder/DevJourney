Single File Programming Question
Problem Statement
David is working on a warehouse inventory management system. He needs to create a program that manages an array of product IDs by performing the following operations:
Addition: Insert a new product ID at a specified index.
Deletion: Remove a product ID from a given index in the original array (not the newly added array).
Your task is to implement this functionality and display the product inventory after both operations.
Input format :
The first line of input contains an integer n, representing the number of product IDs in the initial array.
The second line contains n space-separated integers, representing the initial product IDs.
The third line contains an integer indexA, representing the position where a new product ID should be inserted.
The fourth line contains an integer productA, representing the new product ID to insert.
The fifth line contains an integer indexD, representing the index from which a product ID should be deleted.
Output format :
The first line of output displays n+1 space-separated integers, representing the array after the addition operation.
The second line of output displays n-1 space-separated integers, representing the array after the deletion operation (removing from the original array).
Refer to the sample output for the formatting specifications.
Code constraints :
In this scenario, the test cases will fall under the following constraints:
1 ≤ n ≤ 10
1 ≤ indexA, indexD ≤ 10
1 ≤ elements ≤ 100
index starts from 0
Sample test cases :
Input 1 :
6 10 20 30 40 50 60 2 90 3
Output 1 :
10 20 90 30 40 50 60 10 20 30 50 60
Input 2 :
10 23 45 67 100 28 34 56 1 27 76 5 99 1
Output 2 :
23 45 67 100 28 99 34 56 1 27 76 23 67 100 28 34 56 1 27 76
