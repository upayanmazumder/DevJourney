# Single File Programming Question

## Problem Statement

Arun is developing a time conversion program that consists of a base class called Time and two derived classes named TimeToSeconds and TimeToMinutes.

class Time - stores hours and minutes and has a virtual function display() that prints the input time.
class TimeToSeconds - overrides the display method to convert the time to seconds.
class TimeToMinutes - overrides the display method to convert the time to minutes.

To assist Arun, we need to create a program that accepts input for hours and minutes, creates instances of the derived classes, and displays the original time, the time in seconds, and the time in minutes.

### Input format :

The input consists of two space-separated integers, which represent the hour and minutes.

### Output format :

The first line of output prints the original time in the format "Time: Xh Ym" where X represents input hours and Y represents input minutes.

The second line prints the converted time in seconds.

The third line prints the converted time in minutes.

Refer to the sample outputs for formatting specifications.

### Code constraints :

In this scenario, the test cases fall under the following constraints:

1 ≤ hour ≤ 23

1 ≤ minutes ≤ 59

### Sample test cases :

#### Input 1 :

5 59

#### Output 1 :

Time: 5h 59m
21540 seconds
359 minutes

#### Input 2 :

13 19

#### Output 2 :

Time: 13h 19m
47940 seconds
799 minutes

#### Input 3 :

20 48

#### Output 3 :

Time: 20h 48m
74880 seconds
1248 minutes

Whitelist
Set 1:
virtual
