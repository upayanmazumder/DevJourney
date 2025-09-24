Single File Programming Question
Problem Statement



Mithun is working on a program to manage a list of products in a retail store. He has created a Product class with attributes such as product name, price, and quantity in stock. 



The program should take input for two products and perform basic validations on the input data. 



Ensure that the program uses try-catch blocks to handle exceptions and prints the following error messages if validation fails:

if the length of the name > 25, throw an IllegalArgumentException - "Product name should be 25 characters or less".
if the price ≤ 0, throw an IllegalArgumentException - "Price should be a positive value".
if the quantity < 0, throw an IllegalArgumentException - "Quantity should be a non-negative integer".


Mithun needs your help to implement this error handling.

Input format :
The first line of input consists of a string, representing the name of the first product.

The second line consists of a double value, representing the price of the first product.

The third line consists of an integer, representing the quantity in stock of the first product.

Output format :
If the first product details are valid, print "Product details are valid".

Otherwise, print the corresponding error message.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ Length of the input string ≤ 50 characters

Sample test cases :
Input 1 :
Laptop
899.99
15
Output 1 :
Product details are valid
Input 2 :
Wireless Mouse
-10.50
8
Output 2 :
Price should be a positive value
Input 3 :
Office Chair
89.99
30
Output 3 :
Product details are valid
Input 4 :
Biological Research Microscope
25000.00
15
Output 4 :
Product name should be 25 characters or less