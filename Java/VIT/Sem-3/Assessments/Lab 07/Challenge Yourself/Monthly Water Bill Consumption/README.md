Single File Programming Question
Problem Statement
Divya has recently shifted to a new house and wants to check her monthly water bill based on consumption and her locality type. The water board calculates the bill by considering both the number of water units consumed and the area type — either Urban or Rural. A fixed service charge is always added, and if the area type is invalid, no per-unit cost is applied. A class named WaterBill is used to gather user input, compute the total bill based on the conditions, and display the final bill amount.
Help Divya determine her water bill.
Billing Rules:
Fixed Charge:
Every consumer is charged a flat ₹50 as a service fee.
Urban Area:
If units used ≤ 100: ₹2 per unit
If units used > 100: ₹3 per unit
Rural Area:
If units used ≤ 100: ₹1.5 per unit
If units used > 100: ₹2.5 per unit
Invalid Area Type:
Only the flat ₹50 service fee is charged.
Message: "Invalid area type entered." should be printed.
Input format :
The first line of input consists of a String, representing the consumer name.
The second line consists of a String, representing the area type (Urban or Rural).
The third line consists of an int, representing the number of water units used.
Output format :
If the area type is valid, output a single line containing a double representing the total bill amount.
If the area type is invalid, first print "Invalid area type entered." and then the service charge (50.0) on a new line.
Refer to the sample output for formatting specifications.
Code constraints :
The given testcases fall under the following constraints:
1 ≤ unitsUsed ≤ 1000
areaType must be "Urban" or "Rural" (case-insensitive)
Consumer name can be any non-empty string
Sample test cases :
Input 1 :
Divya
Urban
120
Output 1 :
410.0
Input 2 :
Ramesh
Rural
80
Output 2 :
170.0
Input 3 :
Anjali
City
50
Output 3 :
Invalid area type entered.
50.0
