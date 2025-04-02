Single File Programming Question
Problem Statement



You are designing a traffic simulator. Implement overloaded functions called calculateSpeed that can calculate different speeds, such as the speed of a car, the speed of a train, and the speed of a plane. Each overloaded function should take the required inputs and return the calculated speed.



Formula:

speed = distance/time

speed = (distance/time) + acceleration*time



Example



Input:

100.5

10

5.5

6.6



Output:

10.05

65.05

76.05

Input format :
The first line of input consists of the distance (in meters) as a double value.

The second line of input consists of the time (in seconds) as a double value.

The third line of input consists of the acceleration (in m/s2) of the train as a double value.

The last line of input consists of the acceleration (in m/s2) of the plane as a double value.

Output format :
The first line of output prints the speed of the car (m/s) rounded off to two decimal places.

The second line of output prints the speed of the train (m/s) rounded off to two decimal places.

The last line of output prints the speed of the plane (m/s) rounded off to two decimal places.



Refer to the sample output for the formatting specifications.

Code constraints :
1.0 < distance < 2500.0

1.0 < time < 60.0

1.0 < accelerations of train and plane < 50.0

Sample test cases :
Input 1 :
100.5
10.0
5.5
6.6
Output 1 :
10.05
65.05
76.05