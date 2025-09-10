Single File Programming Question
Problem Statement



Aditya runs an electronics shop where he manages multiple gadgets for inventory. Each gadget has a specific name, unit price, quantity in stock, and handling cost. Aditya needs to calculate the total inventory value for all gadgets, including applicable discounts and surcharges. The Gadget[] array will hold multiple gadgets for which Aditya wants to calculate the total inventory value.



Create a class named Gadget with a parameterized constructor to initialize the name, unit price, quantity, and handling cost. Implement the following formula: Total value for a gadget = (unit price * quantity) + (handling cost * quantity)



Note: Compute the total value for each gadget using the formula and sum the total values of all the gadgets.

 

If total value > 1000.00, apply a 25% discount.
If total value > 500.00, apply a 15% discount.
If the total quantity exceeds 100 units, apply an additional 10% discount.
If the average unit price is less than 20.00, apply a 5% surcharge.
Input format :
The first line of input consists of an integer n, representing the number of gadgets.

For each gadget, the following input must be provided:

A string representing the name of the gadget.
A double value, representing the unit price of the gadget.
An integer representing the quantity in stock.
A double value, representing the handling cost for the gadget.
Output format :
The output displays the total inventory value, rounded to two decimal places.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n ≤ 100

Sample test cases :
Input 1 :
4
USB
10.00
5
2.00
Mouse
20.00
5
5.00
Cable
30.00
5
3.00
Band
40.00
5
10.00
Output 1 :
510.00
Input 2 :
2
PhoneCase
12.50
3
1.00
Protector
20.00
2
2.50
Output 2 :
89.78