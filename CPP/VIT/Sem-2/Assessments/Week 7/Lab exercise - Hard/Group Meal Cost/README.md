# Single File Programming Question

## Problem Statement

Write a program to calculate the total cost of a meal for a group of people.

The program has a base class, MenuItem, with an attribute price and a pure virtual function calculatePrice().

Two derived classes, Appetizer and MainCourse, inherit from MenuItem. They implement the pure virtual function to calculate the total cost based on the price of the item and the number of persons.

For Example,

If there are 4 people in the group, and if the number of appetizer items is 3 and the number of main course items is 4.

The appetizer prices are 44.25, 53.50, 75.99.
The main course prices are 48.99, 53.25, 86.75, 92.00.
The total cost is calculated by adding all the costs and multiplying the number of people.

For appetizers: (44.25 + 53.50 + 75.99) = 173.74
For main courses: (48.99 + 53.25 + 86.75 + 92.00) = 280.99
Total cost = (173.74 + 280.99) * 4 = 454.73 * 4 = 1818.92.

### Input format :

The first line of input consists of an integer n, representing the number of persons dining.

The second line consists of two space-separated integers, N - the number of appetizer items and M - the number of main course items.

The third line consists of N space-separated floating-point numbers, representing the prices of the N appetizer items.

The fourth line consists of M space-separated floating-point numbers, representing the prices of the M main course items.

### Output format :

The output prints "Rs. X" where X is a float value, representing the the total cost of the menu items for the specified number of persons, rounded off to two decimal places.

Refer to the sample output for formatting specifications.

### Code constraints :

In this scenario, the test cases fall under the following constraints:

1 ≤ n ≤ 20

1 ≤ N, M ≤ 20

1.0 ≤ price ≤ 1000.0

### Sample test cases :

#### Input 1 :

1
1 1
72.50
81.99

#### Output 1 :

Rs. 154.49

#### Input 2 :

4
3 4
44.25 53.50 75.99
48.99 53.25 86.75 92.00

#### Output 2 :

Rs. 1818.92

#### Input 3 :

11
5 5
5.99 4.75 3.99 7.50 12.25
6.75 15.99 3.25 10.00 10.00

#### Output 3 :

Rs. 885.17

Whitelist
Set 1:
virtual
