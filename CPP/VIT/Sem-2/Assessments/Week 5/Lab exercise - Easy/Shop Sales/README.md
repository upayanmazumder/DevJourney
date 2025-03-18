Single File Programming Question
Problem Statement



Alex manages a retail store and wants to track total sales using an efficient method across multiple transactions. To achieve this, he implements a program that uses static data members and static member functions. These static elements ensure that the total sales are shared across all instances of the sales process. 



You are required to write a program that helps Alex sum up the sales amounts over a given number of days, utilizing static members for maintaining the total sales. The program should calculate and display the total sales rounded to two decimal places.

Input format :
The first line contains an integer n, representing the number of sales records.

The next n lines each contain a double, representing the sales amount for each day.

Output format :
The output prints "Total Sales: X.XX", where X.XX is the total sales rounded to two decimal places.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ n ≤ 10

1000.00 ≤ salesAmount ≤ 100000.00

Sample test cases :
Input 1 :
2
10000.50
20000.25
Output 1 :
Total Sales: 30000.75
Input 2 :
3
5000.00
2500.50
10000.75
Output 2 :
Total Sales: 17501.25
Whitelist
Set 1:
class
Shop
static