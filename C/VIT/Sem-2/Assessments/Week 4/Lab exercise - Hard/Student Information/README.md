Single File Programming Question
Problem Statement



Amanpreet Singh, the school headmaster, wants to create a program to manage student information using structures and pointers. He needs your help in completing the program. He wants to store information about students using a structure and pointers.



The program should handle various tasks such as identifying students of a specific age as exactly 17, finding students with even roll numbers, and retrieving details for a specific roll number. 



Note: It is assumed that at least one student is of age 17, at least one student has an even roll number and the roll number to be searched is present in the list.

Input format :
The first line of input consists of an integer n, representing the number of students.

The next n lines of input consist of the student's roll number as an integer, name as a string without spaces, age as an integer, and address as a string without spaces, separated by a space.

The last line of input consists of an integer, representing the roll number to be searched.

Output format :
The first line of output prints the names of all the students of the age of 17, separated by a space.

The second line of output prints the names of all the students with even roll numbers, separated by space.

The third line of output prints the details (roll number, name, age, and address) of the student separated by a space whose roll number is given.



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the test cases will fall under the following constraints:

2 ≤ n ≤ 10

Length of the student's name ≤ 25

Length of the address ≤ 25

Sample test cases :
Input 1 :
5
1 Alice 17 Coimbatore
2 Ram 15 Chennai
3 Pooja 25 Karur
4 Devi 26 Erode
5 Bava 17 Salem
4
Output 1 :
Alice Bava 
Ram Devi 
4 Devi 26 Erode
Input 2 :
2
1 Shine 17 Bangalore
4 Bob 15 Mumbai
1
Output 2 :
Shine 
Bob 
1 Shine 17 Bangalore
Whitelist
Set 1:
struct