# Inventory Manager

## Single File Programming Question

## Problem Statement

A store manager keeps track of product inventory in a file named inventory.txt. Each line in this file contains a product's name, its unit price (as a decimal number), and the available stock quantity (as an integer).

The manager wants to:

Calculate the stock value for each product by multiplying the unit price with the stock quantity.
Determine the total stock value of all products.
Save these results to a file called stock_value.txt.
Display each product's name with its stock value, as well as the total stock value, on the console — all rounded to one decimal place.

Your task is to write a program that performs these tasks.

#### Input:

```
format :
```

First line: integer n (number of products)

Next n lines: product name (string), unit price (double), stock quantity (int)

#### Output:

```
format :
```

For each product: "ProductName: Rs.StockValue"

Last line: "Total Stock Value: Rs.TotalValue"

All values rounded to 1 decimal place

Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n ≤ 10

Unit price: 0.0 ≤ price ≤ 100000.0

Stock quantity: 0 ≤ quantity ≤ 1000

Sample test cases :
#### Input 1:

```
3
Laptop 45000.0 5
Mouse 800.0 15
Keyboard 1200.0 10
Output 1 :
Laptop: Rs.225000.0
Mouse: Rs.12000.0
Keyboard: Rs.12000.0
Total Stock Value: Rs.249000.0
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
```
