Single File Programming Question
Problem Statement



Sharon is working on a population growth analysis program. She is studying how populations change over time. 



She wants to write a program that calculates the growth rate of a population based on its initial and final sizes.



Help Sharon write a program that includes a base class Popul and a derived class Birth. Popul has a virtual function calcRate() to initialize the initial and final sizes. Class Birth inherits from Popul, overriding calcRate() to calculate the growth rate based on births.



Note: Growth Rate = (1000 * (final polulation - initial population) / initial population)

Input format :
The first line of input consists of an integer N, representing the initial population.

The second line consists of an integer P, representing the final population.

Output format :
The output prints a double value, representing the population growth rate, rounded off to two decimal places.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

10 ≤ N ≤ 107

10 ≤ P ≤ 107

Sample test cases :
Input 1 :
100
1000
Output 1 :
9000.00
Input 2 :
456
768
Output 2 :
684.21

Whitelist
Set 1:
virtual