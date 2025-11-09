Single File Programming Question
Character Frequency

Your English literature friend is very happy with the code you gave him. Now for his research, he used your application to find character frequency in many novels. For larger novels, the application takes a lot of time for computation. So he called you on a fine Sunday to discuss this with you. He wanted to know whether you can improve the speed of the application.

You decided to modify the application by using multiple threads to reduce the computation time. For this, accept the number of counters or threads at the beginning of the problem and get the string for each counter or thread. Create a thread by extending the Thread class and take the user entered the string as input. Each thread calculates the character frequency for the word assigned to that thread. All the counts are stored locally in the thread and once all the threads are completed print the character frequency for each of the thread.

Ignore output line order.

Question Instructions:

The solution code should have its driver class named as CharacterFrequency which should extends Thread Class
The solution logic should be written in the CharacterFrequency class
Input format :
The first input consists of the number of String (N)

The second input consists of the N number of Strings in each line

Output format :
The output displays the Frequency of characters

Refer to the sample input and output for format specifications.

Sample test cases :
Input 1 :
2
welcome
java
Output 1 :
w1
e2
l1
c1
o1
m1
j1
a2
v1
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
