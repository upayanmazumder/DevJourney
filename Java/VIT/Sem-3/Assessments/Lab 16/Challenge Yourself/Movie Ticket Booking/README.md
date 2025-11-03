Single File Programming Question
Problem Statement

Alex runs a movie ticket booking system that allows users to book tickets for different movies. Alex needs to keep track of the tickets booked, including movie name, seat number, and price, and later check how many tickets are booked for a specific movie. Your task is to help Alex serialize the ticket data and provide a way to count the tickets for any given movie.

Help Alex implement this system to efficiently store and retrieve ticket data.

Input format :
The first line consists of an integer n, representing the number of tickets booked (1 ≤ n ≤ 100).

The next n lines contain the ticket details: each line contains an integer ticketId, a string movieName, a string seatNumber, and a double price.

The last line contains a string searchMovie, which is the movie name for which Alex wants to check the number of tickets booked.

Output format :
The output prints an integer representing the number of tickets booked for the specified movie.

If no tickets are booked for the movie, the output should be: "No tickets booked for this movie".

Refer to the sample output for the formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ n ≤ 10

100 ≤ ticketId ≤ 4000

1 ≤ length of movieName ≤ 50

Seat number is a string of format "RowColumn" (e.g., A5, B10, C3)

100.0 ≤ price ≤ 1000.0

Sample test cases :
Input 1 :
5
1001 Avatar A5 250.5
1002 Inception B10 300.0
1003 Avatar C3 275.0
1004 Titanic D7 200.0
1005 Avatar E2 260.0
Avatar
Output 1 :
3
Input 2 :
4
2001 Joker A1 150.0
2002 Interstellar B2 180.0
2003 Joker C3 200.0
2004 Tenet D5 220.0
Inception
Output 2 :
No tickets booked for this movie
