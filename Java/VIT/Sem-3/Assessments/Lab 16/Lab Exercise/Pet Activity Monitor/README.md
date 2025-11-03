Single File Programming Question
Problem Statement

Xavier, a pet owner, is passionate about keeping track of his pet's activities and wants to create a program to monitor and record these activities.

Design a program to create an object of the PetActivity class with the provided activity name and initial duration. Apply a modification to the activity duration by adding 30 minutes. Serialize the modified object to a file named pet_activity.ser. Deserialize the PetActivity object from the pet_activity.ser file. Display the total duration of the pet activity after deserialization.

Input format :
The input consists of a string value 's', containing the pet activity name and its initial duration in hours, separated by a space.

Output format :
The output displays the total duration of the pet activity in hours, after deserialization, presented in hours.

Refer to the sample output for the formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

The string s contains uppercase, lowercase, numbers, and space with at most 20 characters.

Sample test cases :
Input 1 :
Walking 2.0
Output 1 :
2.5 hours
Input 2 :
Playing 0.75
Output 2 :
1.25 hours
