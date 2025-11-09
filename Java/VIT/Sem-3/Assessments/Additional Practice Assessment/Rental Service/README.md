Single File Programming Question
Problem Statement

You are tasked with managing a rental service for various items. Each item has a name, deposit, and cost per day. Create a class ItemType with private attributes for name (String), deposit (double), and costPerDay (double), along with a default constructor, a parameterized constructor, getters, setters, and an overridden toString() method.

In the ArrayListObjectMain class, prompt the user for N items, gather their details, and store them in an ArrayList of ItemType objects.

Finally, display the items in a formatted table with headers: Name, Deposit, and Cost Per Day, ensuring values for deposit and cost are displayed with one decimal place.

Note: Use "%-20s%-20s%-20s" for formatting output in tabular format; display double values with 1 decimal place.

Input format :
The first line of input contains an integer N, the number of items.

The following N lines contain the details of each item in the following order: name (String), deposit (double), and costPerDay (double).

Output format :
The output should display the details in a tabular format with the headers: Name, Deposit, and Cost Per Day. The Deposit and Cost Per Day columns should display values with one decimal place and be aligned accordingly.

Each item’s details should be printed under the respective columns with the proper formatting.

Refer to the sample output for the formatting specifications

Code constraints :
1 ≤ N ≤ 1000

Sample test cases :
Input 1 :
3
Laptop
10000
250
Light
1000
50
Fan
1000
100
Output 1 :
Name Deposit Cost Per Day  
Laptop 10000.0 250.0  
Light 1000.0 50.0  
Fan 1000.0 100.0  
Input 2 :
5
smartwatch
10043
450
bag
4000
50
charger
1000
100
ironbox
5000
50
dress
100
25
Output 2 :
Name Deposit Cost Per Day  
smartwatch 10043.0 450.0  
bag 4000.0 50.0  
charger 1000.0 100.0  
ironbox 5000.0 50.0  
dress 100.0 25.0  
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
