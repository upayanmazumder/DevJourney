Single File Programming Question
Problem Statement



Ram is fascinated with perfect numbers and wants to create a program to identify whether a given integer is perfect or not. A perfect number is a positive integer that is equal to the sum of its proper divisors (excluding itself).



For example, 6 is a perfect number because its proper divisors are 1, 2, and 3, and 1 + 2 + 3 = 6.

15 is not a perfect number because its proper divisors are 1, 3, 5, and 1 + 3 + 5 = 9.



Function Signature

bool isPerfect(int n, int default_value = 1)

Input format :
The input consists of an integer N, representing the number that Ram wants to check for perfection.

Output format :
The output displays a single line indicating whether the given number is perfect or not.

If the number is perfect, it should print "N is a perfect number",

If the number is not perfect, it should print "N is not a perfect number".



Refer to the sample outputs for the formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ n ≤ 10000

Sample test cases :
Input 1 :
6
Output 1 :
6 is a perfect number
Input 2 :
15
Output 2 :
15 is not a perfect number