Single File Programming Question

Problem Statement



Renu works for a retail store that sells two types of items: wooden items and electronics. The store needs a program to calculate the total amount for a customer's purchase based on their choice of item type and the quantity or cost of the item(s).



Create a base class, ItemType, with one virtual function.

virtual double calculateAmount()



Create a class called wooden that extends ItemType with a number of items and cost as its private attributes. Obtain the data members and override the virtual function.

amount = number of items * cost



Create a class for electronics that extends ItemType with cost as its private attribute. Obtain the data member and override the virtual function.

amount = 80% of the amount (20% discount)



In the main method, obtain a choice.

If the choice is 1, create an object for the wooden class and call the method.

If the choice is 2, create an object for the electronics class and call the method.

Input format :
The first line of input consists of an integer, choice (1 for Wooden, 2 for Electronics).

If choice is 1 (Wooden), the second line consists of two values, an integer noOfItems representing the number of items

and a floating-point number cost representing the cost per item, separated by a space.

If choice is 2 (for Electronics items), a floating-point number cost is expected, representing the cost of the Electronics item.

Output format :
The program calculates the total amount for the chosen item type based on the given input. It then prints the calculated amount with exactly two decimal places.

If the input choice is not 1 or 2, the program will print "Invalid choice."



Refer to the sample output for the formatting specifications.

Code constraints :
1 <= noOfItems <= 103

0 < cost <= 105

Sample test cases :
Input 1 :
1
5 10.50
Output 1 :
52.50
Input 2 :
2
100.50
Output 2 :
80.40
Input 3 :
3
Output 3 :
Invalid choice.

Whitelist
Set 1:
virtual