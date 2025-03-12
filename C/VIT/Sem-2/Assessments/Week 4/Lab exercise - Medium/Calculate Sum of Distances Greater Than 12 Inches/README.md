Single File Programming Question
Problem Statement



Ezhil wants to create a program to add N distances given in the inch-feet system using typedef in a structure. He needs to develop a program that allows the user to input N distances, each consisting of inches and feet ensuring that if the inch sum is greater than or equal to 12 it is appropriately converted to feet and then calculate the total sum of these distances.



Can you help Ezhil by developing the required program to fulfill these requirements?



Example



Input:

3

10 3.7

10 5.5

6 8.0



Output:

27

5.20



Explanation:

The sum of the feet is 10+10+6 = 26

The sum of the inch is 3.7+5.5+8.0 = 17.2



1 feet = 12 inches.

17.2 is greater than 12.

So 17.2 - 12 = 5.2.

The result is 27 feet and 5.20 inches.

Input format :
The first line of input contains an integer N, representing the number of distances.

The next N lines each contain two space-separated values: the feet value and the inch value of each distance, separated by space.



Note:

feet - integer

inch - float

Output format :
The first line of output displays the sum of the feet values as an integer.

The second line of output displays the sum of the inch values, rounded to two decimal places, as a float value.



Refer to the sample output for formatting specifications.﻿

Sample test cases :
Input 1 :
3
10 3.7
10 5.5
6 8.0
Output 1 :
27
5.20
Input 2 :
2
5 6.8
2 10.2
Output 2 :
8
5.00
Input 3 :
3
1 1.7 
1 1.5 
6 8.0
Output 3 :
8
11.20
Whitelist
Set 1:
struct
Set 2:
typedef