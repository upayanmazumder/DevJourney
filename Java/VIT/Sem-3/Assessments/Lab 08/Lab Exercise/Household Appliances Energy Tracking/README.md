Single File Programming Question
Problem Statement



Arun wants to create a Java class named Appliance to track the energy consumption of household appliances. Implement methods to input the wattage and daily usage hours, and calculate both daily and monthly energy consumption. Use the main method to create an object of Appliance, gather input from the user, and display the energy consumption, rounded off to 2 decimal places.



Your task is to guide him in the program.



Note: Daily Consumption = (wattage * hours used) / 1000. Assume there are 30 days in a month.

Input format :
The first line of input consists of a double value, representing the wattage.

The second line consists of a double value, representing the hours used per day.

Output format :
The first line of output prints "Daily Consumption: X kWh" where X is a double value, rounded off to two decimal places.

The second line prints "Monthly Consumption: Y kWh" where Y is a double value, rounded off to two decimal places.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1.0 ≤ wattage ≤ 5000.0

1.0 ≤ hours ≤ 24.0

Sample test cases :
Input 1 :
1000.50
2.5
Output 1 :
Daily Consumption: 2.50 kWh
Monthly Consumption: 75.04 kWh
Input 2 :
500.75
4.0
Output 2 :
Daily Consumption: 2.00 kWh
Monthly Consumption: 60.09 kWh