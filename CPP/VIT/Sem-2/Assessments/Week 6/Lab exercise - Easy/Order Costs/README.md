Single File Programming Question
Problem Statement



Amar needs a program to calculate order costs with discount options for James. Help Amar to write a program that uses multi-level inheritance.  



class Order - Holds item price, quantity, and discount as attributes.
class FinalOrder - Derived from Order class which calculates the total cost for James with a given item price, quantity, and discount percentage.
class DiscountedOrder - Derived from FinalOrder class which calculates the final cost for James, considering an additional discount on top of the regular discount.


Formulas used:

Total Cost = (Item Price × Quantity) - (Item Price × Quantity × Discount / 100.0)
Final Cost = (Total Cost) - (Total Cost × Additional Discount / 100.0)
Input format :
The input consists of four space-separated values: a double value representing the price of the item, an integer representing the quantity of the item, a double value representing the discount to be applied, and a double value representing the additional discount to be applied.

Output format :
The first line displays "Total Cost: " followed by a double value representing the total cost for James's order rounded to two decimal places.

The second line displays "Final Cost: " followed by a double value representing the final cost for James's order, rounded to two decimal places.



Refer to the sample outputs for the formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

0.01 ≤ Price ≤ 1000

1 ≤ Quantity ≤ 100

0 ≤ Discount ≤ 100

0 ≤ Additional Discount Percentage ≤ 100

Sample test cases :
Input 1 :
75.00 5 15.5 5.5
Output 1 :
Total Cost: 316.88
Final Cost: 299.45
Input 2 :
45.00 7 1.5 6.7
Output 2 :
Total Cost: 310.27
Final Cost: 289.49
Input 3 :
40.00 3 20.2 10.4
Output 3 :
Total Cost: 95.76
Final Cost: 85.80