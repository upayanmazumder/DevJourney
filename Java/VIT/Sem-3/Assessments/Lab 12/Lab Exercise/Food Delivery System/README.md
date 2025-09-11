Single File Programming Question
Problem Statement



Anika is developing the delivery charge calculator for Zomato, a food delivery app. The base interface Delivery defines a method to get a base delivery fee. The extended interface ChargeCalculator adds methods to calculate the total delivery fee considering various factors. The class ZomatoDelivery implements both interfaces and provides the logic for calculating delivery charges based on distance tiers and weight surcharges.



Distance charge tiers:

For distance ≤ 5 km: Rs.3 per km
For distance > 5 km and ≤ 15 km: Rs.2 per km for the first 5 km, then Rs.1.5 per km for the remaining distance
For distance > 15 km: Rs.2 per km for first 5 km, Rs.1.5 per km for next 10 km, and Rs.1 per km beyond 15 km


Weight surcharge:

No surcharge for orders ≤ 5 kg
Rs.4 for above 5 kg
Input format :
The first line of input contains an integer representing the distance in km.

The second line of input contains an integer representing the weight in kg.

The third line of input contains an integer representing the base delivery fee.

Output format :
The output prints "Base Delivery Fee: " followed by a double value representing the base delivery fee rounded to one decimal place.

The output prints "Distance Charge: " followed by a double value representing the distance charge rounded to one decimal place.

The output prints "Weight Surcharge: " followed by a double value representing the weight surcharge rounded to one decimal place.

The output prints "Total Delivery Charge: " followed by a double value representing the total delivery charge rounded to one decimal place.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ distance ≤ 100 (distance in kilometers)

1 ≤ weight ≤ 50 (weight in kilograms)

1 ≤ base delivery fee ≤ 100 (base delivery fee in Rs.)

Sample test cases :
Input 1 :
3
4
10
Output 1 :
Base Delivery Fee: 10.0
Distance Charge: 9.0
Weight Surcharge: 0.0
Total Delivery Charge: 19.0
Input 2 :
10
8
15
Output 2 :
Base Delivery Fee: 15.0
Distance Charge: 17.5
Weight Surcharge: 4.0
Total Delivery Charge: 36.5
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0