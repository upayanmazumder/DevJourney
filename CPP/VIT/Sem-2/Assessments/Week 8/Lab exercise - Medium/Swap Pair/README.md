# Single File Programming Question

## Problem Statement

Marton, a researcher, is working with two numerical data types: float and double. He needs a system using the class PairDerived to store these values and swap their positions when needed.

Design a class template that allows Marton to input the two numbers, display them, and swap their values. The program should show the values before and after the swap using the PairDerived class.

### Input format :

The first line consists of a float value representing the first number.

The second line consists of a double value representing the second number.

### Output format :

Display "Values before swap:" followed by:

"First: " followed by the first value.

"Second: " followed by the second value.

Display "Values after swap:" followed by:

"First: " followed by the first value after swapping.

"Second: " followed by the second value after swapping.

Refer to the sample output for the formatting specifications.

### Code constraints :

Float value: 1.0 ≤ first ≤10000.0

Double value: 1.0 ≤ second ≤ 10000.0

### Sample test cases :

#### Input 1 :

45.43
96.25

#### Output 1 :

Values before swap:
First: 45.43
Second: 96.25
Values after swap:
First: 96.25
Second: 45.43

#### Input 2 :

968.32
478.25

#### Output 2 :

Values before swap:
First: 968.32
Second: 478.25
Values after swap:
First: 478.25
Second: 968.32
