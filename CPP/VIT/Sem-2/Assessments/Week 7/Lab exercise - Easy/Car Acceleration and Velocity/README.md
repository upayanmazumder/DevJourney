# Single File Programming Question

## Problem Statement

John is driving a car with an initial velocity (in m/s) that suddenly accelerates at a constant rate (in m/s2) for a certain time (in seconds). He wants to write a program that calculates and displays the final velocity of the car.

Help John calculate the final velocity by overloading the * operator in the Acceleration class.

Formula: Final velocity = Initial velocity + (Acceleration * time)

### Input format :

The input consists of three space-separated float values:

Initial velocity (in m/s)
Acceleration (in m/s2)
Time (in s)

### Output format :

The output displays a float value representing the final velocity followed by " m/s", rounded off to one decimal place.

Refer to the sample output for formatting specifications.

### Code constraints :

In this scenario, the test cases fall under the following constraints:

1.0 ≤ Initial velocity ≤ 500.0

1.0 ≤ Acceleration ≤ 50.0

1.0 ≤ Time ≤ 50.0

### Sample test cases :

#### Input 1 :

10.3 5.0 2.1

#### Output 1 :

20.8 m/s

#### Input 2 :

410.2 9.8 4.5

#### Output 2 :

454.3 m/s
