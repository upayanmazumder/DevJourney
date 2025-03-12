Single File Programming Question
Problem Statement



Xavier is exploring a unified approach to analyze the motion of objects. He wants to calculate the force in Newton and wants to know the status of the object.



Help Xavier to create a union named ObjectProperties that includes two parameters: mass (in kilograms) and force (in newtons). Calculate the force and determine the type of motion based on the given acceleration:

If acceleration is greater than 0, print "Constant acceleration".
If acceleration is less than 0, print "Decelerating".
If acceleration is equal to 0, print "At rest".


Note: Force = mass x acceleration

Input format :
The first line of input consists of a double value M, representing the mass of the object.

The second line consists of a double value A, representing the acceleration of the object.

Output format :
The first line of output prints the calculated force value in Newton, rounded off to two decimal places.

The second line prints either "Constant acceleration" or "Decelerating" or "At rest" based on the given acceleration.



Refer to the sample outputs for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

150.0 ≤ M ≤ 150.0

-150.0 ≤ A ≤ 150.0

Sample test cases :
Input 1 :
23.5
36.2 
Output 1 :
The force is: 850.70 N
Constant acceleration
Input 2 :
2.5   
-2.75
Output 2 :
The force is: -6.88 N
Decelerating
Input 3 :
149.5
0.0
Output 3 :
The force is: 0.00 N
At rest
Whitelist
Set 1:
union
Set 2:
ObjectProperties