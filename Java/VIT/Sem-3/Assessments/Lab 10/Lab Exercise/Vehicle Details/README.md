# Vehicle Details

## Single File Programming Question

## Problem Statement

Design a Java program to model a basic vehicle system using inheritance. Implement a base class Vehicle with attributes for distance and time. Then, create a derived class Car that includes a brand name, calculates speed using the formula Speed = Distance / Time, and adds extra utility.

In the Car class, implement:

A method calc() to calculate the speed.
A final method display() to print the brand and speed of the car (rounded to 2 decimal places) and categorize it as Slow (speed < 20), Average (20–60), or Fast (> 60).
An additional method predictDistance(double newTime) to calculate how much distance the car would cover in a different given time.
An additional method predictTime(double newDistance) to estimate how much time the car would take to cover a new distance at the current speed.

The brand name attribute in the Car class should be declared with the final keyword to prevent modification after initialization.

#### Input:

```
format :
```

The first line of input contains two double values separated by a space representing the Original distance and Original time (for calculating the initial speed).

The second line contains one double value representing the New time (for predicting distance covered).

The third line contains one double value representing the New distance (for predicting time taken).

#### Output:

```
format :
```

The first line of output prints "Brand: " followed by a string representing the brand name of the car.

The second line of output prints the speed of the car rounded to two decimal places, followed by the speed category in parentheses. The format is: Speed: <value> km/hr (Slow/Average/Fast) where the category is "Slow" if speed < 20, "Average" if speed is between 20 and 60 (inclusive), and "Fast" if speed > 60.

The third line of output prints the distance the car is predicted to cover in the given new time, rounded to two decimal places, in the format: Distance covered in <newTime> hours: <distance> km

The fourth line of output prints the estimated time the car will take to cover the specified new distance, rounded to two decimal places, in the format: Time taken to cover <newDistance> km: <time> hours

Refer to the sample output for formatting specifications.

Code constraints :
Original distance: 1.0 ≤ distance ≤ 500.0

Original time: 1.0 ≤ time ≤ 500.0

New time (for predicting distance): 1.0 ≤ newTime ≤ 500.0

New distance (for predicting time): 1.0 ≤ newDistance ≤ 500.0

Sample test cases :
#### Input 1:

```
50.0 10.0
5.0
100.0
Output 1 :
Brand: Toyota
Speed: 5.00 km/hr (Slow)
Distance covered in 5.0 hours: 25.00 km
Time taken to cover 100.0 km: 20.00 hours
Input 2 :
100.0 5.0
10.0
200.0
Output 2 :
Brand: Toyota
Speed: 20.00 km/hr (Average)
Distance covered in 10.0 hours: 200.00 km
Time taken to cover 200.0 km: 10.00 hours
```
