# Complete Weeks Between 2 Dates

## Single File Programming Question

## Problem Statement

Alex needs to plan a series of events and wants to determine how many complete weeks lie between two important dates. Write a program for him that calculates the number of complete weeks between two given dates, provided in the format yyyy-mm-dd.

Use java.time class to handle date parsing and calculations accurately.

#### Input:

```
format :
```

The first line of input consists of the start date as a string, in the format 'yyyy-mm-dd'.

The second line consists of the end date as a string, in the format 'yyyy-mm-dd'.

#### Output:

```
format :
```

The output prints "X weeks", where X represents the number of complete weeks between the given dates.

Refer to the sample output for formatting specifications.

Code constraints :
A complete week means a full 7-day period

start date and end date not inclusive.

1000 ≤ year (yyyy) ≤ 9999

01 ≤ month (mm) ≤ 12

01 ≤ day (dd) ≤ 31 (depending on the respective month and whether it's a leap year):

February: 01 ≤ day ≤ 28 (in a common year) or 01 ≤ day ≤ 29 (in a leap year)

April, June, September, November: 01 ≤ day ≤ 30

January, March, May, July, August, October, December: 01 ≤ day ≤ 31

Sample test cases :
#### Input 1:

```
2020-12-02
2000-12-02
Output 1 :
1043 weeks
Input 2 :
1995-08-12
1997-09-01
Output 2 :
107 weeks
```
