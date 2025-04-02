Single File Programming Question
Problem Statement



Imagine you are creating a hotel room pricing system with a class Hotel featuring a pure virtual function calculatePrice() to calculate prices based on nights and guests. Derived classes SingleRoom and DoubleRoom implement this function.  



Base cost calculation:

For Single room - Rs. 100 per night
For Double room - Rs. 150 per night


Additional cost calculation:

If guests stay for more than 5 nights, they avail a 10% discount. 
If guests stay for 5 or fewer nights, add Rs. 15 service charge.


﻿The program takes user input for nights and guests and then calculates and displays costs for both room types.

Input format :
The first line of input consists of an integer n, representing the number of nights the guests will use the room.

The second line consists of an integer p, representing the number of guests.

Output format :
The first line of output prints "Single Room Cost: " followed by an integer representing the cost for the single room.

The second line prints "Double Room Cost: " followed by an integer representing the cost for the double room.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1 ≤ n ≤ 10

1 ≤ p ≤ 20

Sample test cases :
Input 1 :
6
3
Output 1 :
Single Room Cost: 540
Double Room Cost: 810
Input 2 :
3
7
Output 2 :
Single Room Cost: 315
Double Room Cost: 465
Input 3 :
5
12
Output 3 :
Single Room Cost: 515
Double Room Cost: 765

Whitelist
Set 1:
virtual