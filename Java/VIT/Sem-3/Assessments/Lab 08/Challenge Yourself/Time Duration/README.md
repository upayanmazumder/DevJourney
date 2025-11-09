# Time Duration

## Single File Programming Question

## Problem Statement

Arun needs a program to calculate the sum of two-time durations using classes and objects. Guide him in creating a TimeDuration class to represent time and a TimeAdder class to add two TimeDuration objects.

The program should:

Take the input for hours, minutes, and seconds for two-time durations.
Use TimeAdder class to compute the sum of these durations.
Display the resulting time duration.

## Example

#### Input:

1 hour, 30 minutes and 45 seconds

2 hours, 15 minutes and 30 seconds

#### Output:

Time: 3 hours, 46 minutes, 15 seconds

### Explanation

First, add the hours: 1 hour + 2 hours = 3 hours.

Next, add the minutes: 30 minutes + 15 minutes = 45 minutes.

Finally, add the seconds: 45 seconds + 30 seconds = 75 seconds.

Now, adjust the values:

75 seconds can be split into 1 minute (60 seconds) and 15 seconds.

So, the total duration is 3 hours, 46 minutes and 15 seconds.

#### Input:

```
format :
```

The input consists of two lines, each representing a time duration.

For each duration, it consists of three space-separated integers: hours, minutes, and seconds.

#### Output:

```
format :
```

The output prints the sum of the time durations in the format: "Time: [hours] hours, [minutes] minutes, [seconds] seconds".

Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

0 ≤ hours ≤ 24

0 ≤ minutes ≤ 59

0 ≤ seconds ≤ 59

Sample test cases :
#### Input 1:

```
1 30 45
2 15 30
Output 1 :
Time: 3 hours, 46 minutes, 15 seconds
Input 2 :
15 45 30
3 10 15
Output 2 :
Time: 18 hours, 55 minutes, 45 seconds
```
