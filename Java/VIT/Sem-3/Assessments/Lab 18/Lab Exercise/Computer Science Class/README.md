# Computer Science Class

## Single File Programming Question

## Problem Statement

Raman, a computer science teacher, is responsible for registering students for his programming class. To streamline the registration process, he wants to develop a program that stores students' names and allows him to retrieve a student's name based on their index in the list.

Raman has decided to use an ArrayList to store the names of students, as it provides efficient dynamic resizing and indexing.

Write a program that enables Raman to input the names of students and fetch a student's name using the specified index. If the entered index is invalid, the program should return an appropriate message.

#### Input:

```
format :
```

The first line of input consists of an integer n, representing the number of students to register.

The next n lines of input consist of the names of each student, one by one.

The last line of input is an integer, representing the index (0-indexed) of the element to retrieve.

#### Output:

```
format :
```

If the index is valid (within the bounds of the ArrayList), print "Element at index [index]: " followed by the element (student name as string).

If the index is invalid, print "Invalid index".

Refer to the sample output for formatting specifications.﻿

Code constraints :
The given test cases fall under the following constraints:

2 ≤ n ≤ 10

3 ≤ student's name ≤ 50

0 ≤ index < n

Sample test cases :
#### Input 1:

```
5
Alice
Bob
Ankit
Alice
Prajit
2
Output 1 :
Element at index 2: Ankit
Input 2 :
2
Alice
Bob
2
Output 2 :
Invalid index
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
image
Header Snippet
12
import java.util.ArrayList;import java.util.Scanner;
Whitelist
Set 1:
ArrayList
Fill your code here
Java (11)
theme
instruction
1234
// You are using Javaclass NameManager { //Type your code here}
Footer Snippet
12345678910
public class Main { public static void main(String[] args) { Scanner sc = new Scanner(System.in); NameManager manager = new NameManager(); int n = sc.nextInt(); sc.nextLine(); // consume newline for (int i = 0; i < n; i++) { String name = sc.nextLine();
Provide Custom Input
```
