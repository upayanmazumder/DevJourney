# Single File Programming Question

## Problem Statement

Rita, a fitness enthusiast and gym trainer, is developing a personalized exercise calorie calculator for her clients. The program should calculate the approximate calories burned based on exercise type, duration, weight, and intensity.

For different exercise types, the calories burned per minute are as follows:

Running: 9.8 calories per minute (intensity factor applied)
Cycling: 6.7 calories per minute (intensity factor applied)
Swimming: 7.2 calories per minute (intensity factor applied)
Other exercises: 5.0 calories per minute (intensity factor applied)

The program should take the following inputs:

Exercise type (running, cycling, swimming, or other)
Exercise duration (in minutes)
Client's weight (in kilograms)
Exercise intensity (optional, default value is 1.0)
Calculate and display the approximate number of calories burned during the exercise session.

Function specification

calculateCaloriesBurned - This will have an optional parameter intensity with a default value of 1.0.

### Input format :

The first line inputs a string representing the exercise type (running, cycling, swimming, or other exercises).

The second line inputs a positive double-point number representing the exercise duration (in minutes).

The third line inputs a positive double-point number representing the client's weight (in kilograms).

The fourth line inputs a positive double-point number representing the exercise intensity (optional, default value 1.0).

### Output format :

The output displays a message indicating the approximate number of calories burned during the exercise session.

Refer to the sample output for formatting specifications.

### Code constraints :

The given test cases fall under the following constraints:

Exercise type will be one of the following: "running", "cycling", "swimming", "other".

Duration and weight will be positive floating-point numbers.

Exercise intensity (optional) will be a positive floating-point number.

The program should handle both lower and upper case input for exercise type.

### Sample test cases :

#### Input 1 :

running
30.0
65.0
1.0

#### Output 1 :

You burned approximately 19110 calories.

#### Input 2 :

cycling
60.0
75.5
2.0

#### Output 2 :

You burned approximately 60702 calories.

#### Input 3 :

swimming
45.5
50.0

#### Output 3 :

You burned approximately 16380 calories.

#### Input 4 :

other
20.0
60.0

#### Output 4 :

You burned approximately 6000 calories.
