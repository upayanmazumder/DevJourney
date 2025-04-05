Single File Programming Question
Problem Statement



Audi, a luxury car manufacturer, offers customers the opportunity to book test drives for their latest car models. To streamline the test drive booking process, Audi wants to implement a custom function that takes customer details and preferred test drive dates as input. 



The function should check for the availability of test drive slots on the given date and book the test drive for the customer if a slot is available. 



It should also handle any clashes or boundary conditions during the booking process. 

Input format :
The input starts with a single integer N, representing the number of test drive slots.

Then, there are N lines, each containing a date in the format "yyyy-mm-dd" followed by a space and a binary value (0 or 1), representing the availability status of the test drive slot.

Output format :
The output will be either "Test Drive Booked Successfully for {customerName} on {preferredDate}" if the test drive slot is available and booked successfully, or "Test Drive Slot not available for {customerName} on {preferredDate}" if the slot is not available. The {customerName} and {preferredDate} will be replaced with actual values based on the inputs provided during runtime.

Code constraints :
The code should handle up to 10^5 test drive slots efficiently.
The date string should be limited to a practical length (e.g., 10 characters for "YYYY-MM-DD" format).
The boolean isAvailable can have two possible values: 0 (false) or 1 (true).
Sample test cases :
Input 1 :
3
2023-07-25 1
2023-07-26 1
2023-07-27 0
2023-07-27 
Output 1 :
Test Drive Slot not available on 2023-07-27
Input 2 :
3
2023-07-25 1
2023-07-26 1
2023-07-27 1
2023-07-27 
Output 2 :
Test Drive Booked Successfully on 2023-07-27