Single File Programming Question
Problem Statement



Teena's retail store has implemented a Loyalty Points System to reward customers based on their spending. The program calculates and displays the loyalty points based on whether the customer is a regular or a premium customer.



For regular customers (class Customer), the loyalty points are calculated as:

Loyalty points = amount spent / 10


For premium customers (class PremiumCustomer, which inherits from Customer), the loyalty points are calculated as:

Loyalty points = 2 * (amount spent / 10)


The program should use method overriding for premium customers to calculate their loyalty points. The method that needs to be overridden is calculateLoyaltyPoints in the Customer class.

Input format :
The first line of input consists of an integer representing the amount spent by the customer.

The second line consists of a string representing the premium customer status:

"yes" if the customer is a premium customer.
"no" if the customer is not a premium customer.
Output format :
The output should display the loyalty points earned based on the amount spent and the customer type.



Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ amount ≤ 103

Sample test cases :
Input 1 :
50
yes
Output 1 :
10
Input 2 :
40
no
Output 2 :
4