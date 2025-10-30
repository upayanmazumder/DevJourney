Single File Programming Question
Problem Statement



A financial analyst is reviewing a list of transaction amounts recorded in a bank's system. However, some transactions have been mistakenly duplicated. The analyst wants to remove all duplicate transaction amounts while keeping only the first occurrence of each amount.



Help the financial analyst to implement this using ArrayList.

Input format :
The first line contains an integer N, representing the number of transactions recorded.

The next N lines contain integers representing transaction amounts.

Output format :
The output consists of unique transaction amounts in the order they first appeared in the input. Each amount is printed on a new line.



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the test cases will fall under the following constraints:

1 ≤ N ≤ 20

1 ≤ Amount ≤ 100000

Sample test cases :
Input 1 :
7
500
200
500
750
200
1000
1500
Output 1 :
500
200
750
1000
1500
Input 2 :
5
100
200
300
400
500
Output 2 :
100
200
300
400
500
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
image
Header Snippet
1
import java.util.*;
Whitelist
Set 1:
ArrayList
Fill your code here
Java (11)
theme
instruction
1234
// You are using Javaclass TransactionProcessor {    //Type your code here}
Footer Snippet
12345678
public class Main {    public static void main(String[] args) {        Scanner sc = new Scanner(System.in);        int n = sc.nextInt();          TransactionProcessor.processTransactions(n, sc);        sc.close();    }}
Provide Custom Input