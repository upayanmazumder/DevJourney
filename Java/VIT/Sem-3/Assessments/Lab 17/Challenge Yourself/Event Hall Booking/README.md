Single File Programming Question
Problem Statement

Rajesh, the owner of "Royal Event Halls," manages a collection of event halls available for booking. Each hall has details such as the name, contact number, cost per day, and owner’s name. Rajesh wants to display the list of available halls sorted by their daily cost in a tabular format, making it easier for his clients to choose based on their budget.

Help Rajesh by implementing a program that:

Accepts hall details (name, contact number, cost per day, owner’s name), stores them in a list, and sorts them by the cost per day using the Comparable interface.
Displays the details in a tabular format with columns: Hall Name, Contact Number, Cost Per Day, and Owner Name.

You will implement the Comparable interface in the Hall class. The generic interface method names should include:

getName(), setName(String name)
getContactNumber(), setContactNumber(String contactNumber)
getCostPerDay(), setCostPerDay(double costPerDay)
getOwnerName(), setOwnerName(String ownerName)
Use the compareTo() method to sort the halls, and ensure the program displays the details correctly in tabular form.

Input format :
The first line of input consists of an integer n, representing the number of halls.

The next n × 4 lines each contain hall details:

A String, representing the hall name
A String, representing the contact number
A double, representing the cost per day
A String, representing the owner’s name
Output format :
For each hall, print the following details in a single line, separated by a single space:

Hall Name
Contact Number
Cost Per Day (displayed with one decimal place)
Owner Name
The output should display halls in ascending order based on their cost per day.

Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n ≤ 100

Sample test cases :
Input 1 :
3
SDH hall
12345
12000.0
Jane  
XUV hall
24680
15000.0
Jack  
SRT hall
13579
20000.0
John  
Output 1 :
SDH hall 12345 12000.0 Jane  
XUV hall 24680 15000.0 Jack  
SRT hall 13579 20000.0 John  
Input 2 :
2
Bliss hall
54321
18000.0
Rachel
Luxe hall
98765
22000.0
Michael
Output 2 :
Bliss hall 54321 18000.0 Rachel
Luxe hall 98765 22000.0 Michael
