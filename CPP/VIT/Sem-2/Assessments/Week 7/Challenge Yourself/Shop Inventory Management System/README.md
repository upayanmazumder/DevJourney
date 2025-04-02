Single File Programming Question
Problem statement



You are tasked with developing a simple inventory management system for a retail shop called "Dukaan." The shop sells various items, each with a unique item ID and an associated price. Your goal is to create a program that allows the shopkeeper to set prices for items and then display the prices of all the items in the shop.



To implement this, you have been provided with a base class named Shop, which includes a pure virtual function setPrice to set the price of an item and a function displayPrice to display the prices of all the items in the shop.



Your task is to create a derived class named ConcreteShop that inherits from the Shop class. The ConcreteShop class should override the setPrice function to store the item IDs and their corresponding prices in two arrays: itemId and itemPrice.

Input format :
The first line of input consists of a single integer n, representing the number of items in the shop.

The next n lines contain two space-separated integers, representing the id and price of each item.

Output format :
The output displays n lines, each displaying the price of a product using the following format: "The Price of item with Id <itemId> is <itemPrice>".



Refer to the sample output for the formatting specifications.

Code constraints :
1≤ Number of items ≤10

1≤ Id of each item ≤103

1≤ Price of each item ≤ 103

Sample test cases :
Input 1 :
3
1 100
2 200
3 300
Output 1 :
The Price of item with Id 1 is 100
The Price of item with Id 2 is 200
The Price of item with Id 3 is 300
Input 2 :
4
11 25
22 54
33 72
44 90
Output 2 :
The Price of item with Id 11 is 25
The Price of item with Id 22 is 54
The Price of item with Id 33 is 72
The Price of item with Id 44 is 90

Whitelist
Set 1:
virtual