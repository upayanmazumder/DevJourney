Single File Programming Question
Problem Statement



Create a function 'add'. The function add should perform the following operation.

The first argument should be the data type of the remaining arguments (str or int) (inp_type)
It should be able to get any number of arguments (inp1, inp2, inp3,....)
if the data type is 'str', it should perform string concatenation.
if the data type is 'int', it should perform an addition.


In the main program, get the user input as below:

inp_type -> type of input

inp1 -> arg1

inp2 -> arg2

inp3 -> arg3



Execute the below statements:

add(inp_type,inp1)

add(inp_type,inp1,inp2)

add(inp_type, inp1,inp2,inp3)



Note: Use the same naming convention as mentioned above.

Input format :
The first line of the input consists of the data type of the arguments (int or str) representing inp_type

The second line of the input consists of input1 representing inp1.

The third line of the input consists of input2 representing inp2.

The fourth line of the input consists of input3 representing inp3.

Output format :
The output displays the string concatenation or integer addition.



Refer to the sample output for a better understanding.

Sample test cases :
Input 1 :
int
4
5
6
Output 1 :
4
9
15
Input 2 :
str
Hello
Good
Morning
Output 2 :
Hello
HelloGood
HelloGoodMorning

Whitelist
Set 1:
add