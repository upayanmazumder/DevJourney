# Single File Programming Question

## Problem Statement

You are creating a shopping cart for an e-commerce website. Implement overloaded functions called calculateTotalPrice that can calculate the total price of different types of items, such as a single item, multiple items, or items with discounts. Each overloaded function should take the required parameters and return the calculated total price.

Calculate the total price for a single item without quantity or discounts.
Calculate the total price for multiple items in quantity without any discounts.
Calculate the total price for multiple items with quantity and a discount percentage.

### Input format :

The user should enter an integer corresponding to the desired option (1, 2, 3, or 4).

If the choice is 1, the input consists of the price of the item, separated by a space.

If the choice is 2, the input consists of the price of the item and the quantity, separated by a space.

If the choice is 3, the program consists of the price of the item, the quantity, and the discount percentage, separated by a space.

If the choice is 4, the program exits.

If the choice is other than 1, 2, 3, or 4, it is considered an invalid choice.

### Output format :

For the choices 1, 2, and 3, the output displays the calculated total price as a floating-point number with two decimal places.

If the choice is 4, the program exits.

If the choice is invalid, the output displays "Invalid choice".

The output will be displayed on a new line.

Refer to the sample outputs for the formatting specifications.

### Code constraints :

1 \<= choice \<= 4

0 \<= Quantity \<= 3000

0.0 \<= Price \<= 3000.0

### Sample test cases :

#### Input 1 :

1 10.5
2 102.25 3
3 100 10 10
4

#### Output 1 :

10.50
306.75
900.00

#### Input 2 :

2 150 2
5
4

#### Output 2 :

300.00
Invalid choice
