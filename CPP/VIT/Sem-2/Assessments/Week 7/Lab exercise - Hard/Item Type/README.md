# Single File Programming Question

## Problem Statement:

Create a base class ItemType with one virtual function

double calculateAmount()

Create a class wooden that extends ItemType with a number of items and cost as its private attributes. Obtain the data members and override the virtual function.

amount = number of items\*cost

Create a class electronics that extend ItemType with cost as its private attribute. Obtain the data member and override the virtual function.

amount = 80% of the amount (20% discount)

In the main method, obtain a choice

If the choice is 1, create an object for the wooden class and call the method.

If the choice is 2, create an object for the electronics class and call the method.

### Input format :

The first line of the input consists of the choice.

If the choice is 1, enter the number of items and cost.

If the choice is 2, enter the cost.

### Output format :

The output prints the final amount.

Round off the output to two decimal places.

### Sample test cases :

#### Input 1 :

1
5 840

#### Output 1 :

4200.00

#### Input 2 :

2
1800

#### Output 2 :

1440.00
