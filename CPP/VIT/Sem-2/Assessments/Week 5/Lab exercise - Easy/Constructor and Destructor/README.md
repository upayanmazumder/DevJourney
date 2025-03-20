# Single File Programming Question

## Problem Statement

Alex is creating a simulation to track the creation and destruction of objects in a program. Each object is represented by an instance of the man class. Every time a new object is created, a message is printed indicating its creation number. Similarly, when an object is destroyed, a message is printed indicating its destruction order.

Write a program to simulate the creation of n objects and track the order in which they are created and destroyed.

### Input format :

The input consists of a single integer n, representing the number of objects to be created.

### Output format :

For each object created prints "Created x", where x is the object's creation number.

For each object destroyed, prints "Destroyed y", where y is the current object count after destruction.

Refer to the sample output for the formatting specifications.

### Code constraints :

1 ≤ n ≤ 100

### Sample test cases :

#### Input 1 :

3

#### Output 1 :

Created 1
Created 2
Created 3
Destroyed 2
Destroyed 1
Destroyed 0

#### Input 2 :

7

#### Output 2 :

Created 1
Created 2
Created 3
Created 4
Created 5
Created 6
Created 7
Destroyed 6
Destroyed 5
Destroyed 4
Destroyed 3
Destroyed 2
Destroyed 1
Destroyed 0
