# Single File Programming Question

## Problem Statement

Yashwanth wants a program to streamline his operations by managing plant data, applying discounts, and categorizing plant ratings. Help him with a program using hierarchical inheritance to achieve this.

You need to implement the following classes. Print the final discounted price for n plants and categorize them based on the ratings.

class Plant - Manages plant data including count, price per unit, and discount percentage for each plant.
class Discount - Inherits from Plant, calculates discounted rates for plants based on discount percentage.
class Nursery - Inherits from Plant, contains rating as an attribute, categorizes plant ratings, and displays the category.

Categorization of Rating:

"Average" if the Rating is in the range of 0.1 to 2.5.
"Excellent" if the Rating is in the range of 2.6 to 5.0.

Formulas used: Discounted Rate = (1 - (Discount Percentage / 100)) * Price Per Unit

Refer to the below class diagram:

### Input format :

The input consists of an integer n representing the count of the number of plants, a float value representing the price of each plant, a float value representing the discount percentage, and a float value representing the rating, separated by spaces.

### Output format :

The first line displays "Final Price: " followed by a float value representing the final price of n plants rounded to two decimal places.

The second line prints the category of the plants based on rating.

It prints "Average" if the Rating is in the range of 0.1 to 2.5.
It prints "Excellent" if the Rating is in the range of 2.6 to 5.0.

Refer to the sample output for the formatting specifications.

### Code constraints :

In this scenario, the test cases fall under the following constraints:

1 ≤ n ≤ 50

1 ≤ Price ≤ 1000

0.0 ≤ rating ≤ 5.0

0 ≤ Discount Percentage ≤ 100

### Sample test cases :

#### Input 1 :

2 100.50 2.5 3.6

#### Output 1 :

Final Price: 195.98
Excellent

#### Input 2 :

10 158.50 2.5 2.5

#### Output 2 :

Final Price: 1545.38
Average
