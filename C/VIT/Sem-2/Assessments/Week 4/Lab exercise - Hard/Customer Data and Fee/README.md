Single File Programming Question
Problem Statement



Rashmika manages a group of customers with data plans and needs to calculate additional charges when they exceed their plan limits. Each customer has a unique ID, their data usage, and a plan limit, all stored in a struct named CustomerData. If a customer exceeds their limit, a function calculateFee calculates the additional charges at Rs. 2.00 per GB.



Your task is to write a program that processes the number of customers, and their usage data and calculates any additional charges using this function. Display each customer's ID and fee if applicable, along with the total data used and total plan limit across all customers.

Input format :
The first line consists of an integer n, representing the number of customers.

The next n lines each contain three space-separated values:

An integer customerID (the unique customer identifier).
A double value dataUsed (the amount of data used by the customer in GB).
A double value planLimit (the customer's data plan limit in GB).
Output format :
If any customer has an additional charges, print "X Y" where X is the corresponding customer ID and Y is the calculated charge rounded to two decimal places.

If no customer has additional charges, print: "No charges".



Next, print the total data used and total plan limit across all customers in the following format:

"Total Data Used: Z GB" where Z is the total data used by all customers, rounded to two decimal places.

"Total Plan Limit: A GB" where A is the total plan limit, rounded to two decimal places.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ n ≤ 10

1 ≤ customerID ≤ 105

1.0 ≤ dataUsed, planLimit ≤ 1500.00

Sample test cases :
Input 1 :
2
201 40.0 30.0
202 15.0 20.0
Output 1 :
201 20.00
Total Data Used: 55.00 GB
Total Plan Limit: 50.00 GB
Input 2 :
3
101 50.0 40.0
102 30.0 35.0
103 60.0 50.0
Output 2 :
101 20.00
103 20.00
Total Data Used: 140.00 GB
Total Plan Limit: 125.00 GB
Input 3 :
2
301 1.0 25.0
302 8.0 10.0
Output 3 :
No charges
Total Data Used: 9.00 GB
Total Plan Limit: 35.00 GB
Whitelist
Set 1:
struct