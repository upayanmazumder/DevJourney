Single File Programming Question
Problem Statement



Zaara is working on her Maths assignment. The assignment is to convert a number to a Roman numeral.



Seven different symbols represent Roman numerals: I, V, X, L, C, D, and M.



Example

Two is written as II a Roman numeral, just two ones added together.
Twelve is written as, XIIwhich is simply X + II.
The number twenty-seven is written as XXVII, which is XX + V + II.


Roman numerals are usually written from largest to smallest from left to right.



However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five, we subtract it, making four.



The same principle applies to the number nine, which is registered as IX.



There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.


Given an integer, convert it to a Roman numeral to help Zaara solve her assignment.

Input format :
The input consists of an integer N.

Output format :
The output prints the corresponding Roman numeral of the given integer.

If the input number is less than or equal to zero, display "Invalid".



Refer to the sample output for formatting specifications.

Code constraints :
N < 106

Sample test cases :
Input 1 :
40
Output 1 :
XL
Input 2 :
1000
Output 2 :
M
Input 3 :
0
Output 3 :
Invalid
Input 4 :
-70
Output 4 :
Invalid
Input 5 :
27
Output 5 :
XXVII