# Single File Programming Question

## Problem Statement

Sneha is planning a trip and needs to book a hotel for her stay. She is looking for a simple program that helps her calculate the total cost of her stay based on the room type, number of nights, and additional services like meals and other amenities.

Implement a Hotel Booking System that allows Sneha to input her preferences and get the total cost of her stay.

Functions specifications

double calculateRoomCharges - To calculate the room charges based on room type and the number of nights.

double calculateMealExpenses - To calculate meal expenses based on whether meals are included.

double calculateServiceCosts - To calculate service costs based on whether services are included.

Note:

Room Charges per night

1. Standard Room = Rs. 100.0

1. Deluxe Room = Rs. 150.0

1. Suite = Rs. 250.0

Include Meal Yes = 30.0, No = 0.0

include Service Yes = 50.0, No = 0.0

### Input format :

The input consists of four lines of integers:

Room type (1: Standard, 2: Deluxe, 3: Suite)
Number of nights he plans to stay
Whether he wants to include meals (1: Yes, 0: No)
Whether he wants to include services (1: Yes, 0: No)

### Output format :

The output should display the double values, representing the total cost of stay at the hotel, calculated by considering room charges, meal expenses, and optional services, rounded off two decimal points.

If Room type > 3, it prints "No rooms".

Refer to the sample outputs for the formatting specifications.

### Code constraints :

The given test cases fall under the following constraints:

1 ≤ roomType ≤ 3

0 ≤ nights ≤ 365

0 ≤ includeMeals ≤ 1

0 ≤ includeService ≤ 1

### Sample test cases :

#### Input 1 :

1
2
1
1

#### Output 1 :

Total cost of stay: Rs. 280.00

#### Input 2 :

2
5
0
1

#### Output 2 :

Total cost of stay: Rs. 800.00

#### Input 3 :

3
7
1
0

#### Output 3 :

Total cost of stay: Rs. 1780.00

#### Input 4 :

4
0
0
0

#### Output 4 :

No rooms
Total cost of stay: Rs. 0.00
