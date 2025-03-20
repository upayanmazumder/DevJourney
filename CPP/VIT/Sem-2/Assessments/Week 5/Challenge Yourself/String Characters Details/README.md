Single File Programming Question
Problem Statement



In a bustling city, a team of detectives is working tirelessly to solve a series of mysterious messages left by an enigmatic criminal mastermind. These messages contain a mix of alphabets, numbers, and special characters. The detectives need a tool to analyze the messages and provide insights into the distribution of different characters within them.



Design a program that takes a message as input and performs the following tasks:

a) Calculate the length of the message.

b) Count the number of alphabets (both uppercase and lowercase), numbers, and special characters in the message.

c) Determine the occurrence count of each unique character in the message.



Function specifications

int length (const char* str1) -  To find the length of the string

void count (const char * str1) - To count the total number of alphabets, digits, or special characters

void occur (const char * str1) - To count all occurrences of a character

Input format :
The input consists of a string message.

Output format :
The first line of output displays the length of the message.

The next three lines display the count of alphabets (both uppercase and lowercase), numbers, and special characters.

In the following lines, for each unique character in the message, the output displays the occurrences of all characters,



Refer to the sample output for the formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

The input message consists of printable ASCII characters.

1 ≤ Length of the string ≤ 50

Sample test cases :
Input 1 :
apple?or!orange*1234
Output 1 :
Length: 20
Alphabets: 13
Numbers: 4
Special characters: 3
Occurrence of a is 2
Occurrence of p is 2
Occurrence of l is 1
Occurrence of e is 2
Occurrence of ? is 1
Occurrence of o is 2
Occurrence of r is 2
Occurrence of ! is 1
Occurrence of n is 1
Occurrence of g is 1
Occurrence of * is 1
Occurrence of 1 is 1
Occurrence of 2 is 1
Occurrence of 3 is 1
Occurrence of 4 is 1
Input 2 :
Aa2!
Output 2 :
Length: 4
Alphabets: 2
Numbers: 1
Special characters: 1
Occurrence of A is 1
Occurrence of a is 1
Occurrence of 2 is 1
Occurrence of ! is 1