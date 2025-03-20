# Single File Programming Question

## Problem Statement

John wants to create a program using a class called Weather to compare historical and current weather data. Predict if it's getting warmer, colder, or staying the same based on temperature comparisons and forecast changes in weather conditions. Implement the code by passing an object as a function argument.

If current temperature > historical temperature, output: "Warmer"
If current temperature < historical temperature, output: "Colder"
If current temperature = historical temperature, output: "Same temperature"
If current weather conditions = historical conditions, output: "Same conditions: " followed by the weather conditions.
If current weather conditions differ from historical conditions, output: "Conditions changing to: " followed by the current weather condition.

### Input format :

The first line contains a float value - the historical temperature.

The second line contains a string - the historical weather conditions.

The third line contains a float value - the current temperature.

The fourth line contains a string - the current weather conditions.

### Output format :

The first line displays one of the following:

If current temperature > historical temperature, output: "Warmer".
If current temperature < historical temperature, output: "Colder".
If the current temperature = historical temperature, output: "Same temperature".

The second line displays one of the following:

If current weather conditions = historical conditions, output: "Same conditions: " followed by the weather conditions.
If current weather conditions differ from historical conditions, output: "Conditions changing to: " followed by the current weather condition.

### Sample test cases :

#### Input 1 :

20.5
Sunny
25.0
Sunny

#### Output 1 :

Warmer
Same conditions: Sunny

#### Input 2 :

15.0
Rainy
10.0
Sunny

#### Output 2 :

Colder
Conditions changing to: Sunny

#### Input 3 :

12.5
Snowy
12.5
Snowy

#### Output 3 :

Same temperature
Same conditions: Snowy
