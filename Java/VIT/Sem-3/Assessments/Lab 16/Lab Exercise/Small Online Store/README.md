Single File Programming Question
Problem Statement

Alex runs a small online store, and he needs to keep track of various products and their costs. To simplify the process, he decides to serialize the product details (ID, name, and cost) into a file and later retrieve them to calculate the total cost. You are tasked with implementing a program that reads a collection of Product objects from a serialized file and calculates the total cost of all the products.

However, Alex’s program is not working as expected, and you need to debug it. Help Alex by ensuring that the program correctly deserializes the product details from a file and calculates the total cost.

Input format :
The first line contains an integer n, the number of products.

The next nx3 lines contain the details of each product:

The first line contains an integer product_id.
The second line contains a string product_name.
The third line contains a double cost representing the cost of the product.
Output format :
The first line prints a fixed message:

"Successfully serialized " followed by an int (number_of_products) indicating how many products were serialized,
then the fixed string " products to products.dat".
The second line prints:

"Total cost of all products: " followed by a double (total_cost) which is the sum of the cost field of all products.

Refer to the sample output for the formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ n ≤ 10

1 ≤ product_id ≤ 1000

1 ≤ product_name length ≤ 100

1.0 ≤ cost ≤ 10000000.0

Sample test cases :
Input 1 :
1
1
TV
5000.0
Output 1 :
Successfully serialized 1 products to products.dat
Total cost of all products: 5000.0
Input 2 :
2
201
Bottle
100.0
202
Water
300.0
Output 2 :
Successfully serialized 2 products to products.dat
Total cost of all products: 400.0
