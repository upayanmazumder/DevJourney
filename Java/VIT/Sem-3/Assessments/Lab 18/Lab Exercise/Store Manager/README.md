# Store Manager

## Single File Programming Question

## Problem Statement

Mesa, a store manager, needs a program to manage inventory items. Define a class ItemType with private attributes for name, deposit, and cost per day. Create an ArrayList in the Main class to store ItemType objects, allowing input and display.

Note: Use "%-20s%-20s%-20s" for formatting output in tabular format, display double values with 1 decimal place.

#### Input:

```
format :
```

The first line of input consists of an integer n, representing the number of items.

For each of the n items, there are three lines:

The name of the item (a string)
The deposit amount (a double value)
The cost per day (a double value)
#### Output:

```
format :
```

The output prints a formatted table with columns for name, deposit and cost per day.

Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n ≤ 10

Sample test cases :
#### Input 1:

```
3
Laptop
10000.0
250.0
Light
1000.0
50.0
Fan
1000.0
100.0
Output 1 :
Name Deposit Cost Per Day  
Laptop 10000.0 250.0  
Light 1000.0 50.0  
Fan 1000.0 100.0  
Input 2 :
5
Headphones
300.0
15.0
Mouse
100.0
5.0
Desk
800.0
40.0
Printer
1500.0
70.0
Speakers
1200.0
60.0
Output 2 :
Name Deposit Cost Per Day  
Headphones 300.0 15.0  
Mouse 100.0 5.0  
Desk 800.0 40.0  
Printer 1500.0 70.0  
Speakers 1200.0 60.0  
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
image
Header Snippet
123
import java.util.ArrayList;import java.util.List;import java.util.Scanner;
Fill your code here
Java (11)
theme
instruction
```

123456789101112131415161718192021222324
class ItemType { private String name; private double deposit; private double costPerDay; public ItemType(String name, double deposit, double costPerDay) { this.name = name; this.deposit = deposit; this.costPerDay = costPerDay; } public String getName() { return name; } public double getDeposit() { return deposit; } public double getCostPerDay() { return costPerDay; }}
Footer Snippet
12345678910
class ArrayListObjectMain { public static void main(String args[]) { List<ItemType> items = new ArrayList<>(); Scanner sc = new Scanner(System.in); int n = Integer.parseInt(sc.nextLine()); for (int i = 0; i < n; i++) { String name = sc.nextLine(); Double deposit = Double.parseDouble(sc.nextLine());
Provide Custom Input
Result
0/2 Sample testcase passed
Compiler Message
Compilation successful
Sample Testcase
Testcase 1 - Failed
Expected Output
Name Deposit Cost Per Day
Laptop 10000.0 250.0
Light 1000.0 50.0
Fan 1000.0 100.0
#### Output:

```
Name Deposit Cost Per Day  
ItemType@4f023edb
ItemType@3a71f4dd
ItemType@7adf9f5f
Testcase 2 - Failed
Expected Output
Name Deposit Cost Per Day  
Headphones 300.0 15.0  
Mouse 100.0 5.0  
Desk 800.0 40.0  
Printer 1500.0 70.0  
Speakers 1200.0 60.0  
Output
Name Deposit Cost Per Day  
ItemType@4f023edb
ItemType@3a71f4dd
ItemType@7adf9f5f
ItemType@85ede7b
ItemType@5674cd4d
```
