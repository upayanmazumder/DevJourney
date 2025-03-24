Single File Programming Question
Problem Statement



You are tasked with creating a program to calculate the speed of highway drivers based on the distance travelled and the time taken.



Your program should define a class HighwayDriver with the following specifications:



The class should have two private member variables:
distance (double): representing the distance travelled in miles.
time (double): representing the time taken to travel the distance in hours.
The class should have two constructors:
HighwayDriver(double dist, double hours, double mins): Initializes the distance and time based on the given parameters. The time parameter is in hours, with an additional parameter for minutes. It should calculate the speed (distance/time) for the first driver in miles per hour and display it with two decimal places.
HighwayDriver(double dist, double hours): Initializes the distance and time based on the given parameters. The time parameter is in hours. It should calculate the speed (distance/time) for the second driver in miles per hour and display it with two decimal places.


Your task is to implement the HighwayDriver class and the main program to achieve the specified functionality.

Input format :
The first line of input consists of three space-separated double values, representing the distance travelled, hours driven and minutes driven for the first driver.

The second line consists of two space-separated double values, representing the distance travelled, and hours driven for the second driver.

Output format :
For each driver, print the driving speed in miles per hour (mph) as a double value, rounded off to two decimal places, in separate lines.



Refer to the sample output for the formatting specifications.

Code constraints :
0.01 ≤ distance ≤ 100.0

0.0 ≤ hours ≤ 12.0

0.0 ≤ minutes ≤ 59.0

Sample test cases :
Input 1 :
90.5 1.0 20.0
90.8 1.0
Output 1 :
67.88 mph
90.80 mph
Input 2 :
87.5 1.0 40.0
34.8 2.0
Output 2 :
52.50 mph
17.40 mph
Input 3 :
45.7 4.0 35.0
64.9 2.0
Output 3 :
9.97 mph
32.45 mph

Whitelist
Set 1:
class HighwayDriver
Set 2:
HighwayDriver