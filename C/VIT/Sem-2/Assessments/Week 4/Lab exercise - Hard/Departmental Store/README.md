Single File Programming Question
Problem Statement



Write a program to create a structure DEP_STORE and declare the variables as store_name,  store_address, phone_no. Create another structure STORE_ITEM and declare the variables as item_number, item_name, available_qty, item_price. 



Generate a report to display the Store Name, Store Address, and Phone number with the item name and its price. Calculate the total item value present in the store. Refer to the example below:





Input format :
The first line of input consists of a string, representing the store name.

The second line consists of a string, representing the store address.

The third line consists of a string, representing the phone number.

The fourth line consists of an integer N, representing the number of items.

For each item, the input consists of the following:

An integer, representing the item number.
A string, representing the item name.
An integer, representing the quantity.
A float value, representing the price per item.
Output format :
The first line prints "Store Name: " followed by the store name.

The second line prints "Store Address: " followed by the store address.

The third line prints "Phone Number: " followed by the phone number.



After a new line, the next line prints "Item Number" followed by a tab space, "Item Name" followed by a tab space, "Available Quantity" followed by a tab space, "Item Price".

In each of the following N lines, the output prints the item number, item name, available quantity, and the item price(a float value rounded to two decimal places) of N items, separated by a tab space.



After a new line, the next line prints "Total Item Value: Rs. " followed by a float value rounded to two decimal places representing the total item value.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ N ≤ 10

2 ≤ Length of customer name < 50

2 ≤ Length of address < 100

2 ≤ Length of phone number < 15

2 ≤ Length of item name < 50

Sample test cases :
Input 1 :
ABC Mart
Chennai
7412589635
2
101
Shoes 
5
500.00
102 
Shirts 
3 
300.50
Output 1 :
Store Name: ABC Mart
Store Address: Chennai
Phone Number: 7412589635

Item Number	Item Name	Available Quantity	Item Price
101		Shoes 		5		500.00
102		Shirts 		3		300.50

Total Item Value: Rs. 3401.50
Input 2 :
Rams Retail
Coimbatore
9874563214
4
190
TNPL A4 sheet Bundle
10
170
345
Hand Gloves
20
20
234
Milton Flask 
13
305
564
Pencil Box
20
55
Output 2 :
Store Name: Rams Retail
Store Address: Coimbatore
Phone Number: 9874563214

Item Number	Item Name	Available Quantity	Item Price
190		TNPL A4 sheet Bundle		10		170.00
345		Hand Gloves		20		20.00
234		Milton Flask 		13		305.00
564		Pencil Box		20		55.00

Total Item Value: Rs. 7165.00
Whitelist
Set 1:
struct DEP_STORE
Set 2:
struct STORE_ITEM