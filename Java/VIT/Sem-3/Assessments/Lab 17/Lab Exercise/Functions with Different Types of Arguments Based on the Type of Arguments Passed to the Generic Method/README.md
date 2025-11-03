Single File Programming Question
Problem statement

Write generic functions that can be called with different types of arguments based on the type of arguments passed to the generic method; the compiler handles each method. Obtain an integer and a double value and pass them to the function.

Function Header: static <T> void genericDisplay (T element)

Input format :
The input consists of an integer and a double value, separated by a space.

Output format :
The output prints both the type and value of the input using the format: <classname> = <value>

Refer to the sample output for the formatting specifications.

Code constraints :
1 <= integer and double value <= 107

Sample test cases :
Input 1 :
1 20.25
Output 1 :
java.lang.Integer = 1
java.lang.Double = 20.25
Input 2 :
12 23.5
Output 2 :
java.lang.Integer = 12
java.lang.Double = 23.5
