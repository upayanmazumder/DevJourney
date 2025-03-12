# Single File Programming Question

## Problem Statement

Create a structure for a customer of supermarket products. The structure should include Product number, Cost per product, Number of items, and expiry date (dd/mm/yyyy).

Populate 10 instances of a structure. Perform the following operations with suitable functions

a. Display the details of a product with the given product number

b. Display the products whose cost is above the given cost.

c. Display the products with the given expiry date.

### Input format :

The first line of the input consists of an integer n, representing the number of products.

The next n lines consist of four space-separated values in each line: product number (integer), cost per product (float value), number of items (integer), and expiry date (string) of each product.

The next input consists of the product number to be searched.
The next input consists of the product cost to be searched.
The last input consists of the expiry date to be searched.

### Output format :

The output displays the product details and the results of each search operation as shown in the sample output.

Round off the amount values to two decimal places.

Refer to sample input and output for formatting specifications.

### Code constraints :

1 ≤ n ≤ 10

1 ≤ Length of the expiry date < 25

### Sample test cases :

#### Input 1 :

5
1 150.00 10 12/10/2022
2 200.00 6 30/05/2025
3 500.00 12 20/12/2030
4 250.00 20 31/01/2035
5 350.00 25 20/20/2025
3
200.00
31/01/2035

#### Output 1 :

Product details of the searched product number
3 500.00 12 20/12/2030

Product details of the searched product cost
2 200.00 6 30/05/2025

Product with the searched expiry date
4 250.00 20 31/01/2035

#### Input 2 :

10
101 150.50 15 15/10/2022
102 200.25 8 25/05/2025
103 500.75 20 12/12/2030
104 250.80 30 28/02/2035
105 350.40 22 22/12/2025
106 180.20 18 05/06/2024
107 300.90 25 10/11/2023
108 400.60 12 15/09/2025
109 120.75 5 19/04/2026
110 450.30 28 30/08/2023
103
150.50
22/12/2025

#### Output 2 :

Product details of the searched product number
103 500.75 20 12/12/2030

Product details of the searched product cost
101 150.50 15 15/10/2022

Product with the searched expiry date
105 350.40 22 22/12/2025

#### Input 3 :

1
3 500.00 12 20/12/2030
3
500.00
20/12/2030

#### Output 3 :

Product details of the searched product number
3 500.00 12 20/12/2030

Product details of the searched product cost
3 500.00 12 20/12/2030

Product with the searched expiry date
3 500.00 12 20/12/2030
Whitelist
Set 1:
struct
