Single File Programming Question
Problem Statement



﻿Create a structure called cricketer that stores the cricketer's information such as name, age, number of matches, and average runs as attributes. 



Write a program that takes N cricketers in a structured array and displays the information in ascending order based on average runs scored by each person.

Input format :
The first line of input consists of an integer N, representing the number of cricketers.

In each of the following N lines, the input consists of four space-separated values:

A string (without spaces) - Cricketer's name
An integer - Cricketer's age
An integer - Cricketer's number of matches
A float value - Cricketer's average runs
Output format :
The output displays the information in ascending order based on the average runs scored by each person.



Each line consists of four space-separated values:

A string (without spaces) - Cricketer's name
An integer - Cricketer's age
An integer - Cricketer's number of matches
A float value - Cricketer's average runs rounded to two decimal places


Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ N ≤ 30

length of the name ≤ 50

Sample test cases :
Input 1 :
2
Rahul 32 22 1234.58
David 42 55 256.8
Output 1 :
David 42 55 256.80
Rahul 32 22 1234.58
Input 2 :
5
Shakib 34 206 36.51
Martin 35 186 43.87
Kane 31 151 53.97
Babar 26 88 55.94
Quinton 29 125 45.62
Output 2 :
Shakib 34 206 36.51
Martin 35 186 43.87
Quinton 29 125 45.62
Kane 31 151 53.97
Babar 26 88 55.94
Whitelist
Set 1:
struct