Single File Programming Question
Problem Statement



Mary is managing a business and wants to analyze its profitability. She operates both a regular business model and a seasonal business model. To assess profitability, she uses a program that calculates and compares the profit margins for both models based on revenue and cost.



The program defines:

BusinessUtility class with a method calculateMargin(double revenue, double cost).
SeasonalBusinessUtility (inherits from BusinessUtility) and overrides calculateMargin(double revenue, double cost), adding a seasonal adjustment of 10% to the base margin.
ProfitabilityChecker class with a method checkProfitability(double regularMargin), which prints "Business is profitable." if the regular margin is 10% or more, otherwise prints "Business is not profitable.".


Mary inputs revenue and cost, and the program compute and display the regular and seasonal margins using:



Margin = ((Revenue − Cost) / Revenue) × 100

Seasonal Margin = Margin + 10

Input format :
The first line of input consists of a double value r, representing the revenue.

The second line consists of a double value c, representing the cost.

Output format :
The first line prints a double value, representing the regular profit margin, rounded to two decimal places, in the format: "Regular Margin: X. XX%", where X.XX denotes the calculated regular margin.

The second line prints a double value, representing the seasonal profit margin, rounded to two decimal places, in the format: "Seasonal Margin: X. XX%", where X.XX denotes the calculated seasonal margin.

The third line prints a string, indicating whether the business is profitable or not profitable, based on the regular margin.

If the regular margin is less than 10, print "Business is not profitable.". If it is 10 or greater, print "Business is profitable."



Refer to the sample output for the formatting specifications.

Code constraints :
jaIn this scenario, the test cases fall under the following constraints:

100.0 ≤ r ≤ 1000.0

50.0 ≤ c ≤ 1000.0

Sample test cases :
Input 1 :
1000.0
800.0
Output 1 :
Regular Margin: 20.00%
Seasonal Margin: 30.00%
Business is profitable.
Input 2 :
1000.0
950.0
Output 2 :
Regular Margin: 5.00%
Seasonal Margin: 15.00%
Business is not profitable.