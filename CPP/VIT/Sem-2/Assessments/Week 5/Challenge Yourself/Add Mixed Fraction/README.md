Single File Programming Question
Problem Statement



Arjun is creating a recipe management system that needs to handle fractional quantities of ingredients. To simplify the calculations, he decides to create a Fraction class with private attributes numerator, and denominator to represent fractions. Arjun also needs a friend function, addMixedFraction(const Fraction&, const Fraction&), to add two fractions, where one or both may be mixed fractions (numerator > denominator). The result should be returned as a reduced Fraction object.



Write a program to input the numerators and denominators of two fractions, create Fraction objects using these values, add them using addMixedFraction, and display the result.



Example 1

Input:

4 7

8 7

Output:

12/7

Explanation:

The denominators of both fractions are the same (7), so the function directly adds the numerators and places the sum over the common denominator. Mathematically, 4/7 + 8/7 = (4 + 8) / 7 = 12 / 7.



Example 2

Input:

7 4

6 5

Output:

59/20

Explanation:

The denominators are different (4 and 5), so a common denominator is found by multiplying them (20). The numerators are calculated by cross-multiplying and adding: (7 * 5) + (6 * 4) = 35 + 24 = 59. So, 59/20 is printed.

Input format :
The first line of input consists of the numerator and denominator of the first fraction separated by space.

The second line of input consists of the numerator and denominator of the second fraction separated by space.

Output format :
The program prints the sum of the mixed fractions.



Refer to the sample output for formatting specifications.



Code constraints :
The given test cases fall under the following constraints:

1 ≤ numerator, denominator ≤ 20

All input values are positive integers.

Sample test cases :
Input 1 :
4 7
8 7
Output 1 :
12/7
Input 2 :
3 5
6 7
Output 2 :
51/35
Input 3 :
7 4
6 5
Output 3 :
59/20