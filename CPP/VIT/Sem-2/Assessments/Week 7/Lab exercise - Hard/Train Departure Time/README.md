# Single File Programming Question

## Problem Statement

Create a class Time to represent the departure time of a train, initialized with hours and minutes. Overload the pre-increment operator ++ to advance the departure time by one minute. Display the original and updated departure times.

Note: The time is represented in 24-hour format.

### Input format :

The input consists of two space-separated integers, hours (h) and minutes (m) representing the departure time of the train.

### Output format :

The first line of output prints the original departure time and the second line prints the updated departure time.

The time is printed in the format: [hours]h [minutes]m.

Refer to the sample output for formatting specifications.

### Code constraints :

0 ≤ h ≤ 23

0 ≤ m ≤ 59

### Sample test cases :

#### Input 1 :

11 57

#### Output 1 :

11h 57m
11h 58m

#### Input 2 :

13 5

#### Output 2 :

13h 5m
13h 6m

#### Input 3 :

23 59

#### Output 3 :

23h 59m
0h 0m

#### Input 4 :

0 59

#### Output 4 :

0h 59m
1h 0m
