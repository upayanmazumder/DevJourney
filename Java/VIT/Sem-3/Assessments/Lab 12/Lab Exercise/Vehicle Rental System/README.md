# Vehicle Rental System

## Single File Programming Question

## Problem Statement

Develop a vehicle rental system that calculates the rental cost for different types of vehicles: Car, Bike, and Truck. Each vehicle type has its own rental rate. The system should be able to calculate the total rental cost based on the type of vehicle selected and the number of rental days.

To implement this system, create the following classes:

Vehicle: An abstract class that provides the structure for different types of vehicles. It contains attributes for the rental rate and abstract methods calculateRentalCost(int days) for calculating the rental cost.

Car: A concrete subclass of Vehicle that represents a car. It implements the rental cost calculation specific to cars.
Bike: A concrete subclass of Vehicle that represents a bike. It implements the rental cost calculation specific to bikes.
Truck: A concrete subclass of Vehicle that represents a truck. It implements the rental cost calculation specific to trucks.

Your system will allow users to input the rental rates for each type of vehicle and the number of rental days. Then, it will display the rental rate for the selected vehicle type and calculate and display the total rental cost based on the rental rate and the number of rental days.

#### Input:

```
format :
```

The first line of input contains an integer, carRate, representing the rental rate for a car.

The second line contains an integer, bikeRate, representing the rental rate for a bike.

The third line contains an integer, truckRate, representing the rental rate for a truck.

The fourth line contains an integer, rentalDays, representing the number of days for rental.

#### Output:

```
format :
```

For each type of vehicle, the program should display two lines:

The first line should include "Rental Rate: rate per day," where rate is the rental rate for the vehicle.

The second line should include "Total Rental Cost for Vehicle Type: totalCost," where Vehicle Type is the type of vehicle (Car, Bike, or Truck), and totalCost is the total rental cost based on the rental rate and the number of days.

Refer to the sample output for the formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ rate ≤ 10000

1 ≤ days ≤ 365

Sample test cases :
#### Input 1:

```
1000
150
750
7
Output 1 :
Rental Rate: 1000 per day
Total Rental Cost for Car: 7000
Rental Rate: 150 per day
Total Rental Cost for Bike: 1050
Rental Rate: 750 per day
Total Rental Cost for Truck: 5250
Input 2 :
1200
175
650
6
Output 2 :
Rental Rate: 1200 per day
Total Rental Cost for Car: 7200
Rental Rate: 175 per day
Total Rental Cost for Bike: 1050
Rental Rate: 650 per day
Total Rental Cost for Truck: 3900
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
```
