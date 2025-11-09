# Railway Ticket Pricing System

## Single File Programming Question

## Problem Statement

Raj is a software developer tasked with creating a train ticket pricing system for a local railway company using method overriding. The system needs to consider different pricing rules for regular passengers and senior citizens. Senior citizens, aged 60 and above, are eligible for a 10% discount on the regular ticket price.

The calculatePrice method in the SeniorCitizenTicket class overrides the same method in the Ticket class to provide a different implementation for senior citizens.The method public double calculatePrice(int distance) calculates the ticket price based on the distance traveled.

Formula:

regular price = distance * 0.05

senior discounted price = regular price * 0.9

## Example

#### Input:

120 65

#### Output:

Senior Citizen Ticket Price: 5.4

### Explanation

Since the passenger's age is 65, which is greater than 60, the person is a senior citizen. The regular ticket price is calculated as 120 * 0.05 = 6.0. The discounted price is then calculated as 90% of the regular price, i.e., 6.0 * 0.9 = 5.4

#### Input:

```
format :
```

The input consists of two space-separated integers, representing the distance and age respectively.

#### Output:

```
format :
```

If the passenger is a regular passenger (age < 60), prints "Regular Passenger Ticket Price: <price>", where price is a double value formatted to one decimal places.

If the passenger is a senior citizen (age >= 60), prints "Senior Citizen Ticket Price: <price>" where price is a double value formatted to one decimal places.

Refer to the sample output for the formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ distance ≤ 300

30 ≤ age ≤ 100

Sample test cases :
#### Input 1:

```
120 65
Output 1 :
Senior Citizen Ticket Price: 5.4
Input 2 :
50 30
Output 2 :
Regular Passenger Ticket Price: 2.5
Input 3 :
300 100
Output 3 :
Senior Citizen Ticket Price: 13.5
```
