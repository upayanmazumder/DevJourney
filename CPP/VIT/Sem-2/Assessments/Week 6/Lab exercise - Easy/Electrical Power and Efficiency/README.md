Single File Programming Question
Problem Statement



Arvind is designing a program to calculate electrical power and efficiency, and he needs your help. Create a base class P with voltage and current attributes to compute power. Implement a derived class PE with an efficiency attribute to determine useful and wasted power.



Write a program to help him accomplish the task.



Formulas

Power = Voltage * Current

Useful Power = Power * Efficiency

Wasted Power = Power * (1.0 - Efficiency)

Input format :
The input consists of three space-separated double values, representing the voltage, current, and efficiency.

Output format :
The first line of output prints the calculated electrical power in watts (W).

The second line prints the useful electrical power in watts (W) after considering efficiency.

The third line prints the wasted electrical power in watts (W) due to inefficiency.

All the values are double values that are rounded to one decimal place.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1.0 ≤ voltage ≤ 500.0

1.0 ≤ current ≤ 50.0

0.01 ≤ efficiency ≤ 0.99

Sample test cases :
Input 1 :
120.7 5.0 0.85
Output 1 :
Power: 603.5W
Useful Output Power: 513.0W
Wasted Power: 90.5W
Input 2 :
347.8 23.6 0.47
Output 2 :
Power: 8208.1W
Useful Output Power: 3857.8W
Wasted Power: 4350.3W

Whitelist
Set 1:
class P
class PE