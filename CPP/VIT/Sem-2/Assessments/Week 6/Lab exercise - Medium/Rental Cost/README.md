Single File Programming Question
Problem Statement



Rahul is assigned with implementing a program to calculate the rental cost for a car and a motorcycle based on their daily rental rates and the number of days they are rented.



Create a base class Vehicle and derived classes Car and Motorcycle. 



The rental cost is calculated differently for each vehicle type.

Car rental cost = daily rental rate * number of days
Motorcycle rental cost = daily rental rate * number of days * 0.8 (Applying the 20% discount for motorcycles)
Input format :
The first line of input consists of a double-value, representing the daily rental rate for a car.

The second line consists of a double-value, representing the daily rental rate for a motorcycle.

The third line consists of an integer, representing the number of days to rent the car.

The fourth line consists of an integer, representing the number of days to rent the motorcycle.

Output format :
The first line of output prints "Total rental cost for the car: X" where X is a double-value, rounded off to two decimal places.

The second line prints "Total rental cost for the motorcycle: Y" where Y is a double-value, rounded off to two decimal places.



Refer to the sample outputs for formatting specifications.

Code constraints :
1 ≤ number of days ≤ 30

Sample test cases :
Input 1 :
10.2
8.3
3
2
Output 1 :
Total rental cost for the car: 30.60
Total rental cost for the motorcycle: 13.28
Input 2 :
15.75
12.25
5
3
Output 2 :
Total rental cost for the car: 78.75
Total rental cost for the motorcycle: 29.40

Whitelist
Set 1:
class Vehicle
Set 2:
class Car
Set 3:
class Motorcycle