Single File Programming Question
Problem Statement



Design a program for a transport system operation. Create a base class Transport with a pure virtual function named operate. Implement two derived classes, TransportA and TransportB, which calculate and display the time taken to move between locations based on the transport type.



The program takes input for the number of transport systems and their operations, then outputs the time taken in seconds for each operation.



For TransportA: Time Taken = abs(start location - destination) * 2

For TransportB: Time Taken = abs(start location - destination) * 3

Input format :
The first line of input consists of an integer N, representing the number of transport operations.

Each of the next N lines consists of three space-separated values:

A character - Transport type ('P/p' for TransportA or 'F/f' for TransportB)
An integer - Starting location
An integer - Destination
Output format :
For each transport operation, the output prints the time taken in seconds in the following format:

"Time taken: X seconds" where X is the time taken in seconds.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1 ≤ N ≤ 10

0 ≤ Starting location and Destination ≤ 10

Sample test cases :
Input 1 :
2
P 1 5
F 3 10
Output 1 :
Time taken: 8 seconds
Time taken: 21 seconds
Input 2 :
1
p 3 7
Output 2 :
Time taken: 8 seconds
Input 3 :
3
F 5 3
P 2 8
f 7 2
Output 3 :
Time taken: 6 seconds
Time taken: 12 seconds
Time taken: 15 seconds

Whitelist
Set 1:
virtual