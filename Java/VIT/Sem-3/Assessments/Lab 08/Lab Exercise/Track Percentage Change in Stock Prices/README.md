# Track Percentage Change in Stock Prices

## Single File Programming Question

## Problem Statement

Meera, a talented developer, is working on a project to help stock traders track the percentage change in stock prices. She needs to create a Java class called Stock that records a stock's current and previous prices and calculates the percentage change between them.

Formula:

Percentage change = ((currentPrice - previousPrice) / previousPrice) * 100

Class Definition

Create a Java class called Stock with the following methods and attributes:

Stock(String symbol, double currentPrice): A constructor that initializes a stock with the given symbol (a string) and currentPrice (a double).

void recordPreviousPrice(double previousPrice): A method that records the previous price of the stock.

double calculatePercentageChange(): A method that calculates and returns the percentage change between the current and previous prices.

#### Input:

```
format :
```

The input consists of the following values:

The constructor Stock takes two arguments on the first two lines:

The symbol (a string)

The currentPrice (a double).

The third line contains a boolean value 'yes' or 'no':

If yes in the fourth line: The method recordPreviousPrice takes one argument, which is the previousPrice (a double).

#### Output:

```
format :
```

If the previousPrice is recorded: The output should print the calculated percentage change as a double value.

If the previousPrice is not recorded: The output should print the "Previous price is not recorded hence cannot calculate percentage change" and then print the percentage change value.

The percentage change value is rounded off to two decimal places.

Refer to the sample output for the formatting specifications.

Code constraints :

The given test cases fall under the following constraints:

1 ≤ N ≤ 106

The symbol will be a string of alphanumeric characters with a maximum length of 10 characters.

The currentPrice and previousPrice will be double values (positive or negative) with at most two decimal places.

Sample test cases :

#### Input 1:

AAPL 150.50 no

#### Output 1:

Previous price is not recorded hence cannot calculate percentage change 0.00%

#### Input 2:

GOOGL 2500.00 yes 2400.00

#### Output 2:

4.17%
