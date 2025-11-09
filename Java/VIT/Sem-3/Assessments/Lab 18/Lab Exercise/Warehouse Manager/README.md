# Warehouse Manager

## Single File Programming Question

## Problem Statement

Sarah, a warehouse manager, is managing a list of product names in her store’s inventory system. She needs to perform basic operations like adding (inserting) new products, removing products that are sold out or discontinued, displaying all the products in stock, and searching for a specific product in the inventory list.

Sarah’s goal is to manage the inventory using a list of product names (strings). The system allows her to perform the following operations using ArrayList:

Insert a Product: Sarah adds a new product to the inventory.
Delete a Product: Sarah removes a product from the inventory when it’s sold or discontinued.
Display the Inventory: Sarah checks all the products currently available in the inventory.
Search for a Product: Sarah searches for a specific product in the inventory to check if it’s available.
#### Input:

```
format :
```

The input consists of multiple space-separated values representing different operations on a product list. Each operation follows a specific format:

1 <product_name> - Adds <product_name> to the product list.

2 <product_name> - Removes <product_name> from the product list if it exists.

3 - Print all products currently on the list.

4 <product_name> - Checks if <product_name> exists in the list.

#### Output:

```
format :
```

The output displays,

For (choice 1) prints, " <item> has been added to the list."

For (choice 2) prints, " <item> has been removed from the list."

For (choice 3) prints, "Items in the list:" followed by each item in the list on a new line, or "The list is empty." if the list is empty.

For (choice 4) prints," <item> is found in the list." or " <item> not found in the list."

Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ Choice ≤ 4

1 ≤ string length ≤ 100

Sample test cases :
#### Input 1:

```
1 apple 1 banana 2 apple 3 4 apple
Output 1 :
apple has been added to the list.
banana has been added to the list.
apple has been removed from the list.
Items in the list:
banana
apple not found in the list.
Input 2 :
1 car 1 bike 1 bus 2 bike 3 2 car 3 4 bus
Output 2 :
car has been added to the list.
bike has been added to the list.
bus has been added to the list.
bike has been removed from the list.
Items in the list:
car
bus
car has been removed from the list.
Items in the list:
bus
bus is found in the list.
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
image
Header Snippet
12
import java.util.ArrayList;import java.util.Scanner;
Whitelist
Set 1:
ArrayList
Fill your code here
Java (11)
theme
instruction
```

123456789101112131415161718192021222324252627282930313233343536
class StringListOperations { public static void insertItem(ArrayList<String> list, String item) { list.add(item); System.out.println(item + " has been added to the list."); } public static void deleteItem(ArrayList<String> list, String item) { if (list.remove(item)) { System.out.println(item + " has been removed from the list."); } } public static void displayItems(ArrayList<String> list) { if (list.isEmpty()) { System.out.println("The list is empty."); } else { System.out.println("Items in the list:"); for (String item : list) { System.out.println(item); } } } public static void searchItem(ArrayList<String> list, String item) { if (list.contains(item)) { System.out.println(item + " is found in the list."); } else { System.out.println(item + " not found in the list."); } } public static void main(String[] args) { Scanner scanner = new Scanner(System.in); String inputLine = scanner.nextLine(); String[] commands = inputLine.split(" "); ArrayList<String> list = new ArrayList<>();
Footer Snippet
12345678910
public class Main { public static void main(String[] args) { Scanner sc = new Scanner(System.in); ArrayList<String> list = new ArrayList<>(); String input = sc.nextLine(); String[] commands = input.split(" "); int i = 0; while (i < commands.length) {
Provide Custom Input
Result
0/2 Sample testcase passed
Compiler Message
Main.java:107: error: cannot find symbol
StringListOperations.displayList(list);
^
symbol: method displayList(ArrayList<String>)
location: class StringListOperations
1 error
Sample Testcase
Testcase 1 - Failed
Expected Output
apple has been added to the list.
banana has been added to the list.
apple has been removed from the list.
Items in the list:
banana
apple not found in the list.
#### Output:

Testcase 2 - Failed
Expected Output
car has been added to the list.
bike has been added to the list.
bus has been added to the list.
bike has been removed from the list.
Items in the list:
car
bus
car has been removed from the list.
Items in the list:
bus
bus is found in the list.
#### Output:
