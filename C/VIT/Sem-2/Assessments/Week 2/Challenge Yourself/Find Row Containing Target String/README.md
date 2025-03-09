Single File Programming Question
Problem Statement



Akash is working on a program that searches for a string within an array of strings. He wants to find the row number where the given string is found. If the string is not found in any row, he wants to output "Not found".



Write a program to help Akash achieve this.

Input format :
The first line contains an integer n, the number of strings in the array.

The second line contains n strings, representing the elements of the array, separated by a space.

The last line contains a string s, which Akash wants to search for.

Output format :
If s is found in the array, output "Found in row: x", where x is the row number where the string is found (1-indexed).

If s is not found in any row, output "Not found".



Refer to the sample outputs for formatting specifications.

Code constraints :
In this scenario, the test cases will fall under the following constraints:

2 ≤ n ≤ 10

1 ≤ Length of each string ≤ 100

The strings are case-sensitive.

Sample test cases :
Input 1 :
5
English Math Science EVS General
Math
Output 1 :
Found in row: 2
Input 2 :
3
English Hindi Math
hindi
Output 2 :
Not found