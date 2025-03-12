# Single File Programming Question

## Problem Statement

Develop a program to analyze the weather forecast for two days. Create a union named WeatherForecast to manage weather data that has the temperature and precipitation as attributes. Read inputs for two weather models, calculate and print the average temperature, average precipitation, and predicted weather type based on specific conditions.

The predicted weather type calculation is as follows:

"Sunny" if the average temperature is 25 degrees Celsius or higher and the average precipitation is less than 10 mm.
"Rainy" if the average precipitation is 10 mm or more.
"Cloudy" otherwise.

### Input format :

The first line of input consists of two space-separated double values for the first weather model: temperature (in °C) and precipitation (in mm).

The second line consists of two space-separated double values for the second weather model: temperature (in °C) and precipitation (in mm).

### Output format :

The first line of output prints "X degree celsius" where X is a double value, rounded off to two decimal places, representing the average temperature.

The second line prints "Y mm" where Y is a double value, rounded off to two decimal places, representing the average precipitation.

The third line prints either "Rainy", "Sunny" or "Cloudy" representing the predicted weather type.

Refer to the sample outputs for formatting specifications.

### Code constraints :

The given test cases fall under the following constraints:

1.0 ≤ Temperature ≤ 50.0°C

0.0 mm ≤ Precipitation ≤ 25.0 mm

### Sample test cases :

#### Input 1 :

28.2 2.0
30.3 5.0

#### Output 1 :

29.25 degree celsius
3.50 mm
Sunny

#### Input 2 :

13.9 23.6
17.5 23.9

#### Output 2 :

15.70 degree celsius
23.75 mm
Rainy

#### Input 3 :

13.0 4.0
14.8 5.8

#### Output 3 :

13.90 degree celsius
4.90 mm
Cloudy
Whitelist
Set 1:
union
