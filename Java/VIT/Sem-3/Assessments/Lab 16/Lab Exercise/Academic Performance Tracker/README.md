Single File Programming Question
Problem Statement

A dedicated student, Emily is keen on tracking her academic performance in various subjects. She wants to create a program that stores information about her grades and categorizes them based on performance. To achieve this, Emily has implemented a serialization program to store and retrieve grade information.

Design a program to create an object of the Grade class with the provided subject and score. Serialize the created object to a file named grades.ser. Deserialize the Grade object from the grades.ser file. Display the performance category determined by the program after deserialization.

Note:

"Excellent" for scores of 90 or above
"Good" for scores above 70
"Needs Improvement" for scores below 70.
Input format :
The input consists of a string value 's', containing a subject and a score separated by a space.

Output format :
The output displays the performance category after deserialization.

Refer to the sample output for the formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

The string s contains uppercase, lowercase, numbers, and spaces with at most 30 characters.

0 ≤ Score ≤ 100

Sample test cases :
Input 1 :
Math 95
Output 1 :
Excellent
Input 2 :
History 80
Output 2 :
Good
Input 3 :
English 60
Output 3 :
Needs Improvement
