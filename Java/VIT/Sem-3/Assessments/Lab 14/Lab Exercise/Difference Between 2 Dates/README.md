# Difference Between 2 Dates

## Single File Programming Question

## Problem Statement

Rohit is given the task of developing a program that calculates the difference between two dates using the java.time class. The program should input two dates in the format "yyyy-mm-dd" and display the calculated difference in days.

The program makes use of the java.time.LocalDate class for date manipulation, java.time.format.DateTimeFormatter for parsing the input dates, and java.util.Scanner for reading the user input.

Implement a program to help Rohit that inputs two dates in the format "yyyy-mm-dd", and displays the calculated difference in days.

#### Input:

```
format :
```

The first line of input consists of the start date as a string, in the format 'yyyy-mm-dd'.

The second line of input consists of the end date as string, in the format 'yyyy-mm-dd'.

#### Output:

```
format :
```

The output prints "X days", where X represents the calculated difference between the given two dates.

Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1000 ≤ year (yyyy) ≤ 9999

01 ≤ month (mm) ≤ 12

01 ≤ day (dd) ≤ 31 (depending on the respective month and whether it's a leap year):

February: 01 ≤ day ≤ 28 (in a common year) or 01 ≤ day ≤ 29 (in a leap year)

April, June, September, November: 01 ≤ day ≤ 30

January, March, May, July, August, October, December: 01 ≤ day ≤ 31

start and end date should not be included in calculation.

Sample test cases :
#### Input 1:

```
2024-12-02
2000-12-02
Output 1 :
8766 days
Input 2 :
1995-08-12
1997-09-01
Output 2 :
751 days
```
