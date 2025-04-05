Single File Programming Question
Problem Statement



Arsh is working on managing two different types of data: integers and floating-point numbers. He needs a system using the class StackDerived to handle stack operations such as pushing and popping elements for both data types. 



Implement a class template that allows Arsh to input a series of numbers, display the stack contents, and perform a pop operation to remove the top element. The program should show the stack elements before and after the pop operation for both integer and double stacks.

Input format :
The first line consists of an integer n representing the number of elements to be pushed onto the integer stack.

The second line consists of n space-separated integers to be pushed into the integer stack.

The third line consists of an integer m representing the number of elements to be pushed onto the double stack.

The fourth line consists of m space-separated double values to be pushed into the double stack.

Output format :
Display "Stack elements: " followed by the elements in the stack from top to bottom for the integer stack.

After the first pop operation, display "Stack elements: " followed by the updated stack contents for the integer stack.

Display "Stack elements: " followed by the elements in the double stack from top to bottom.

After the pop operation on the double stack, display "Stack elements: " followed by the updated stack contents for the double stack.

If a pop operation is attempted on an empty stack, output "Stack underflow!" followed by "Stack elements: " (with no elements).



Refer to the sample output for the formatting specifications.

Code constraints :
0 ≤ n, m ≤ 10

1 ≤ x ≤ 100

1.0 ≤ y ≤ 100.0

Sample test cases :
Input 1 :
5
1 2 3 4 5
2
2.5 3.5
Output 1 :
Stack elements: 5 4 3 2 1 
Stack elements: 4 3 2 1 
Stack elements: 3.5 2.5 
Stack elements: 2.5 
Input 2 :
3
10 20 30
0
Output 2 :
Stack elements: 30 20 10 
Stack elements: 20 10 
Stack elements: 
Stack underflow!
Stack elements: 