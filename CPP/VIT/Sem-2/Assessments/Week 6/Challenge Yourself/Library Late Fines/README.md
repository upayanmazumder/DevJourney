# Single File Programming Question

## Problem Statement

Develop a program to calculate late fines for library items. The program should utilize a base class 'LibraryItem' with a due and return date and derive two classes 'Book' and 'DVD' to calculate and display the late fine for each type of library item.

The fine calculation for 'Book' is based on a flat rate of 1 per day for overdue items.

The fine calculation for 'DVD' is based on a flat rate of 2 per day for overdue items.

### Input format :

The input consists of two lines of input, where each line contains a date.

The first line represents the due date as a string, and the second line represents the return date as a string.

### Output format :

For each library item (Book and DVD), display the following:

Due Date: (Due Date)

Return Date: (Return Date)

Late Fine: (Late Fine)

Refer to the sample outputs for the formatting specifications.

### Code constraints :

The input dates are in the format "YYYY-MM-DD"

### Sample test cases :

#### Input 1 :

2023-11-01
2023-11-05

#### Output 1 :

Due Date: 2023-11-01
Return Date: 2023-11-05
Late Fine: 4
Due Date: 2023-11-01
Return Date: 2023-11-05
Late Fine: 8

#### Input 2 :

2023-11-15
2023-11-15

#### Output 2 :

Due Date: 2023-11-15
Return Date: 2023-11-15
Late Fine: 0
Due Date: 2023-11-15
Return Date: 2023-11-15
Late Fine: 0
