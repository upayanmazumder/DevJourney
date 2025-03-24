Single File Programming Question
Problem Statement



Arun is tasked with developing a program to calculate the GDP per capita of a country. The program should take as input the total population of the country and its GDP (Gross Domestic Product). Based on this information, it should calculate the GDP per capita, which is the GDP divided by the total population.



Your task is to assist Arun in implementing the program using multiple inheritance. 



Specifically, you should create a Country class that inherits from two base classes: Population and GDP. The Population class stores the total population of the country, while the GDP class stores the GDP value. The Country class should have a method to calculate the GDP per capita and another method to display this value.



Finally, the program should take input for the total population and GDP of the country, create an instance of the Country class with this information, and calculate and display the GDP per capita. The GDP per capita should be displayed with precision up to two decimal places.



Your implementation should follow the provided structure and adhere to the given specifications.

Input format :
The first line of input consists of a long integer, representing the total population of the country.

The second line consists of a double value, representing the GDP of the country.

Output format :
The output prints "GDP: " followed by the GDP per capita for the country, rounded off to two decimal places.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ population ≤ 1010

Sample test cases :
Input 1 :
331000
2143.50
Output 1 :
GDP: 0.01
Input 2 :
93318
11431253.75
Output 2 :
GDP: 122.50
Input 3 :
4567
15423.25
Output 3 :
GDP: 3.38

Whitelist
Set 1:
class Population
Set 2:
class GDP
Set 3:
class Country