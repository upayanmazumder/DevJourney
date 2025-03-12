# Single File Programming Question

## Problem Statement

Rajinder is hosting a concert and needs a program to determine the total ticket cost based on specific criteria.

Write a program that utilizes two structures: Visit, which captures attendance details such as the member count and student count, and Loyal, designed for loyal customer discounts.

The base ticket price is set at Rs. 900.00, with a 5% student discount (0.05), and a 10% group discount (0.10) for gatherings exceeding 5 members. If less than 6 members then there is no discount. The ticket cost is calculated considering the number of attendees, student status, and potential group discount.

Example

Input:

100

1

Output:

Rs. 76950.00

Explanation:

100 members, with students among them (as 1 indicates students).

Discounts Applied: 5% student discount and 10% group discount (since members > 5).

Calculation: Individual price with discounts = 900 * (1 - 0.05) * (1 - 0.10) = Rs. 769.5.

Total Ticket Cost: Multiply individual price by the number of members (100 * 769.5) = Rs. 76950.00.

Input:

6

0

Output:

Rs. 4860.00

Explanation:

6 members since the status is 0, 10% discount only applies, thus

Discounts Applied: 10% group discount (since members > 5).

Calculation: Individual price with discounts = 900 * (1 - 0.10) = Rs. 810.0

Total Ticket Cost: Multiply individual price by the number of members (6\* 810.0) = Rs. 4860.00.

### Input format :

The first line of input consists of an integer N, representing the number of members attending the concert.

The second line consists of an integer (0 or 1), 1 if there are students; and 0 otherwise.

### Output format :

The output displays "Rs. X" where X is a double value, representing the total ticket cost, rounded off to two decimal places.

Refer to the sample output for formatting specifications.

### Code constraints :

1 ≤ N ≤ 100

If the attending members are students: yes - 1, no - 0

### Sample test cases :

#### Input 1 :

18
1

#### Output 1 :

Rs. 13851.00

#### Input 2 :

6
0

#### Output 2 :

Rs. 4860.00

#### Input 3 :

100
1

#### Output 3 :

Rs. 76950.00
Whitelist
Set 1:
struct Visit
Set 2:
struct Loyal
