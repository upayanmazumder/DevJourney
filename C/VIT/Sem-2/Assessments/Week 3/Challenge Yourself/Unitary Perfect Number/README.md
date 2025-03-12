# Single File Programming Question

## Problem Statement

The Ideal Power Plant

Alex is an engineer working on optimizing power plants. In his research, he came across a special property that can help in identifying ideal configurations for power plants. This property involves checking if a certain configuration number meets a unique balance condition.

For a given configuration number, Alex needs to determine if it has a special property where the sum of its divisors (excluding the number itself) that are relatively prime to their complementary divisors equals the original number.

To simplify, a configuration number n is considered "ideal" if the sum of its divisors d (where each divisor d is relatively prime to

n/d) equals n.

Alex needs a program that can help him verify whether a given number meets this balance condition.

Example 1

Input:

60

Output:

60 is a unitary perfect number.

Explanation:

The number 60 is a unitary perfect number, because 1, 3, 4, 5, 12, 15, 20 are its proper unitary divisors, and 1 + 3 + 4 + 5 + 12 + 15 + 20 = 60.

Example 2

Input:

18

Output:

18 is not a unitary perfect number.

Explanation:

The number 18 is not a unitary perfect number, because 1, 2, and 9 are its proper unitary divisors, and 1 + 2 + 9 = 12, which is not equal to 18.

Company Tags: CoCubes

### Input format :

The input consists of an integer N, representing the configuration number of the power plant.

### Output format :

If N is an ideal configuration number, print "[N] is a unitary perfect number."

Otherwise, print "[N] is not a unitary perfect number."

Refer to the sample output for formatting specifications.

### Code constraints :

In this scenario, the test cases fall under the following constraints:

1 ≤ N ≤ 100

### Sample test cases :

#### Input 1 :

60

#### Output 1 :

60 is a unitary perfect number.

#### Input 2 :

18

#### Output 2 :

18 is not a unitary perfect number.
