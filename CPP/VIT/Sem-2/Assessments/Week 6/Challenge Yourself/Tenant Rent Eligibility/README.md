# Single File Programming Question

## Problem Statement

Develop a program that consists of two classes: Tenant and RentEligibility. The Tenant class is the base class and stores the monthly income of a tenant, while the RentEligibility class calculates the rental amount based on a specified percentage. In the main function, input the tenant's monthly income and the desired rent percentage.

If the tenant's monthly income is at least Rs. 15,000, the tenant is considered eligible for rent, compute and display the rental amount. If the tenant is not eligible, print an appropriate message.

Note: Rental amount = (rent percentage / 100) * monthly income.

### Input format :

The first line of input consists of a double value, representing the tenant's monthly income.

The second line consists of a double value, representing the rent percentage.

### Output format :

If the tenant is eligible for rent,

The first line of output prints "Eligible".
The second line prints "Rent Amount: X" where X is a double-value, rounded off to two decimal places.
If the tenant is not eligible for rent, print "Not Eligible".

Refer to the sample outputs for formatting specifications.

### Code constraints :

1000.0 ≤ monthly income ≤ 100000.0

1.0 ≤ rent percentage ≤ 100.0

### Sample test cases :

#### Input 1 :

14050.57
25.0

#### Output 1 :

Not Eligible

#### Input 2 :

90750.25
57.1

#### Output 2 :

Eligible
Rent Amount: 51818.39

#### Input 3 :

15450.75
16.2

#### Output 3 :

Eligible
Rent Amount: 2503.02

Whitelist
Set 1:
class Tenant
Set 2:
class RentEligibility
