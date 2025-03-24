Single File Programming Question
Problem Statement



Ravi, a marathon enthusiast, requires a program to effortlessly convert distances between miles and kilometers to maintain consistent records.



The program should take a distance value and a unit indicator ('m' for miles or 'k' for kilometers) as input and employ constructor overloading within the MarathonRunner class to perform the conversion between units when needed.



This program will streamline Ravi's record-keeping process and ensure accuracy in his marathon distance tracking.



Note:

If 'm' is in miles, then 'distance' is multiplied by 1.60934.

Otherwise, if 'k' is in a different unit, 'distance' is multiplied by 1.2.

Input format :
The first line of input consists of a double-point number, distance, representing the distance recorded by Ravi.

The second line of input consists of the character unit, which can be either 'm' or 'k' and indicates the unit of the provided distance.

Output format :
The output displays the following format:



If the provided unit is valid ('m' or 'k'), the output is the converted distance as a floating-point number with two decimal places.
If the provided unit is invalid (anything other than 'm' or 'k'), the output is "Invalid input for unit."


Refer to the sample output for the formatting specifications.

Code constraints :
0.01 ≤ distance ≤ 100.0.

Sample test cases :
Input 1 :
60.0
k
Output 1 :
72.00
Input 2 :
80.45
m
Output 2 :
129.47
Input 3 :
43.2
M
Output 3 :
Invalid input for unit