Single File Programming Question
Problem Statement



Mithu, a math enthusiast, is keen to identify composite numbers from a list of integers. Write a program that first reads an integer n (1 ≤ n ≤ 15) to indicate how many integers will be inputted.



The program should then read n integers, filter out the prime numbers using the remove_copy_if function, and display the composite numbers. Ensure that at least one composite number is present in the input; otherwise, output -1. If n is outside the specified range, simply output -1. Help Mithu explore these fascinating numbers!

Input format :
The first line contains an integer n (1 ≤ n ≤ 15) which represents the number of integers to be inputted.

The second line contains n space-separated integers.

Output format :
If n is outside the range of 1 to 15, output -1.

If there are no composite numbers in the input, output -1.

If there are composite numbers, output them in the following format: "Composite numbers: [list of composite numbers]".



Refer to the sample output for the formatting specifications.

Code constraints :
The integer n must be between 1 and 15, inclusive.

1 ≤ input integers ≤ 1000

However, ensure that at least one composite number is included in the input for a valid output.

Sample test cases :
Input 1 :
9
4 5 12 65 89 57 584 52 111
Output 1 :
Composite numbers: 4 12 65 57 584 52 111 
Input 2 :
16
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
Output 2 :
-1