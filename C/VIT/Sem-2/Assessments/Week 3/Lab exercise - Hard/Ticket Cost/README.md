# Single File Programming Question

## Problem Statement

Kathir aims to create a program to determine the total ticket cost for an upcoming event, considering his age and the quantity of tickets he intends to buy.

The available ticket types are Basic (Rs. 150.0) and VIP (Rs. 300.0), each priced differently. The program should apply age-based discounts and utilize pointers for price calculations.

Discount Calculation:

If Kathir's age is less than 18, he will receive a 10% discount on Basic tickets.
If Kathir's age is 18 or older, he will receive a 5% discount on VIP tickets.

Formulas Used: Total Cost = Discounted Price * Number of Tickets, where Discounted Price = Original Price - (Original Price * Discount Percentage)

### Input format :

The first line of input consists of an integer representing Kathir's age.

The second line of input consists of an integer n, representing the number of tickets Kathir wants to purchase.

### Output format :

The output displays "Rs." followed by the total cost of the tickets as a double-point value, rounded to two decimal places.

Refer to the sample output for the formatting specifications.

### Code constraints :

4 ≤ age ≤ 90

1 ≤ n ≤ 100

### Sample test cases :

#### Input 1 :

5
1

#### Output 1 :

Rs.135.00

#### Input 2 :

20
3

#### Output 2 :

Rs.855.00
