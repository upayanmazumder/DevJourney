# Single File Programming Question

## Problem Statement:

Ajay is assigned with designing a program with an ElectricityBill class that utilizes multiple inheritance, inheriting attributes from Consumption, Rate, and ConnectionType classes. This program calculates the total cost of electricity consumption based on consumed units and connection type, which can be either residential or commercial, each with its respective rate.

Note: Total Electricity Consumption Cost = Units * rate where units can be residential or commercial.

### Input format :

The first line of input consists of a double value, representing the total electricity units consumed.

The second line consists of a double value, representing the rate per unit for residential connections.

The third line consists of a double value, representing the rate per unit for commercial connections.

The fourth line consists of a string, representing the Connection type (residential or commercial).

### Output format :

The output displays the total electricity cost rounded to two decimal places.

Based on the connection type, the total cost is calculated by multiplying it with respective units.

Refer to the sample output for formatting specifications.

### Code constraints :

In this scenario, the test cases fall under the following constraints:

1.00 ≤ units ≤ 100.00

0.01 ≤ residential rate/unit ≤ 10.00

0.01 ≤ commercial rate/unit ≤ 10.00

Connection type: residential or commercial (case sensitive)

### Sample test cases :

#### Input 1 :

80.00
0.15
0.18
commercial

#### Output 1 :

14.40

#### Input 2 :

80.05
0.15
0.18
residential

#### Output 2 :

12.01

#### Input 3 :

100.00
0.70
0.80
residential

#### Output 3 :

70.00
