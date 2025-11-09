# Boeing 747 Total Revenue

## Single File Programming Question

## Problem Statement

Teena is launching a new airline, Boeing747, and needs to calculate the total revenue generated from ticket sales based on the ticket cost and seat availability. Teena's airline offers two types of seats: regular and premium. The ticket cost and seat availability for both types of seats need to be considered for revenue calculation.

To help with this, Teena wants to implement a system using multilevel inheritance with three classes:

Airline: This class will have the ticket cost as an attribute.
Indigo: This class will extend Airline and add the seat availability attribute.
Boeing747: This class will extend Indigo and include a method to calculate the total revenue based on the ticket cost and seat availability.

Teena needs to calculate the total revenue using the formula:

Total Revenue = ticket cost * seat availability

Help Teena implement this system for calculating the revenue of her airline.

#### Input:

```
format :
```

The first line of input consists of a double value, representing the flight's ticket cost.

The second line consists of an integer, representing seat availability.

#### Output:

```
format :
```

The first line of output prints "Ticket Cost: Rs. " followed by a double value representing the ticket cost rounded to one decimal place.

The second line of output prints "Seat Availability: X seats" where X is an integer value representing the seat availability.

The third line of output prints "Total Revenue: Rs. " followed by a double value representing the total revenue rounded to one decimal place.

Refer to the sample output for the exact text and format.

Code constraints :
The given test cases fall under the following constraints:

1000.0 ≤ ticket price ≤ 50,000.0

10 ≤ seat availability ≤ 300

Sample test cases :
#### Input 1:

```
1000.0
100
Output 1 :
Ticket Cost: Rs. 1000.0
Seat Availability: 100 seats
Total Revenue: Rs. 100000.0
Input 2 :
22000.0
300
Output 2 :
Ticket Cost: Rs. 22000.0
Seat Availability: 300 seats
Total Revenue: Rs. 6600000.0
Input 3 :
50000.0
30
Output 3 :
Ticket Cost: Rs. 50000.0
Seat Availability: 30 seats
Total Revenue: Rs. 1500000.0
```
