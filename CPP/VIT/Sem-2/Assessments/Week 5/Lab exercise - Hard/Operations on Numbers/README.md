# Single File Programming Question

## Problem Statement

Venu is learning about basic arithmetic operations and wants to practice them with a simple program.

Write a program that has a class called Operation that takes two integers: a and b as public attributes. In the main function, it performs the following operations on a and b: Addition, Subtraction, Multiplication, Division, and Modulus.

### Input format :

The input consists of two space-separated integers, a and b, where a and b are the two numbers for which the operations should be performed.

### Output format :

The first line displays "Addition: " followed by the sum of a and b.

The second line displays "Difference: " followed by the difference between a and b.

The third line displays "Product: " followed by the product of a and b.

If b = 0; the fourth line displays "Division by zero not possible" and terminates.

Otherwise:

The fourth line displays "Division: " followed by the result of dividing a by b.

The fifth line displays "Modulus: " followed by the result of the modulus of a with b.

Note: All outputs are integers.

### Code constraints :

0 \<= a, b \<= 1000

b \<= a

### Sample test cases :

#### Input 1 :

50 8

#### Output 1 :

Addition: 58
Difference: 42
Product: 400
Division: 6
Modulus: 2

#### Input 2 :

10 0

#### Output 2 :

Addition: 10
Difference: 10
Product: 0
Division by zero not possible

#### Input 3 :

30 28

#### Output 3 :

Addition: 58
Difference: 2
Product: 840
Division: 1
Modulus: 2
Whitelist
Set 1:
class
Operation
