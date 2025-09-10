Single File Programming Question
Problem Statement
Aarav is planning to book a movie ticket online. The theater calculates the ticket price based on the time slot, ticket type, and the age of the person to apply discounts accordingly. The booking system uses a class named Ticket to take user input, calculate the final ticket price based on rules, and print the final amount.
Help Aarav compute how much he needs to pay.
Ticket Pricing Rules:
Base Price by Time Slot:
Morning: ₹100
Evening: ₹150
If the time slot is neither "Morning" nor "Evening", the message "Invalid time slot entered." is displayed, and the final price is ₹0.
Ticket Type Surcharge:
If the ticket is "Premium" (case insensitive), add ₹50.
"Standard" ticket has no additional charge.
Age-Based Discount:
If age < 12: Apply 50% discount on total price.
If age ≥ 60: Apply a 30% discount on the total price.
Others: No discount.
Input format :
The first line of input contains a String, representing the customer's name.
The second line contains an int, representing the age of the customer.
The third line contains a String, representing the time slot (Morning or Evening).
The fourth line contains a String, representing the ticket type (Premium or Standard).
Output format :
If the time slot is valid, print a single line containing a double value of the final ticket price.
If the time slot is invalid, print "Invalid time slot entered." followed by 0.0.
Refer to the sample output for formatting specifications.
Code constraints :
The given testcases fall under the following constraints:
1 ≤ age ≤ 100
Time slot must be "Morning" or "Evening" (case-insensitive)
Ticket type must be "Premium" or "Standard" (case-insensitive)
Sample test cases :
Input 1 :
Aarav
10
Morning
Premium
Output 1 :
75.0
Input 2 :
Ravi
65
Evening
Standard
Output 2 :
105.0
Input 3 :
Sana
30
Afternoon
Premium
Output 3 :
Invalid time slot entered.
0.0
