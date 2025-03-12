Single File Programming Question
Problem Statement



Imagine Alex is working on a project where he needs to adjust the values in an array based on their contribution to the total product of the array. 



He was given an array of integers, and his goal is to modify each element in such a way that it represents the result of dividing the total product of the array by its original value using pointers.



Example



Input:

3

2 3 4

Output:

12 8 6 

Explanation:

Total Product = 2 * 3 * 4 = 24

Modify each element in the array by dividing the total product by its original value.

For the first element (2), the new value will be 24 / 2 = 12.

For the second element (3), the new value will be 24 / 3 = 8.

For the third element (4), the new value will be 24 / 4 = 6.

So, the modified array becomes {12, 8, 6}.

Input format :
The first line of input consists of an integer N, representing the size of an array.

The second line consists of N space-separated integers, representing the array elements.

Output format :
The output prints the modified array.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1 ≤ N ≤ 10

1 ≤ elements ≤ 10

Sample test cases :
Input 1 :
3
2 3 4
Output 1 :
12 8 6 
Input 2 :
6
1 4 5 2 3 6
Output 2 :
720 180 144 360 240 120 