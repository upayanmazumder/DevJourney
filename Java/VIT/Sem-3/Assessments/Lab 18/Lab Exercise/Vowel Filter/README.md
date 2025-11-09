# Vowel Filter

## Single File Programming Question

## Problem Statement

A teacher is filtering a list of words provided by students. Some words contain too many vowels, making them difficult for a spelling competition. The teacher decides to remove all words that contain more than two vowels.

Help the teacher to implement it using ArrayList.

#### Input:

```
format :
```

The first line contains an integer N, representing the number of words in the list.

The next N lines contain a string representing the words (one per line).

#### Output:

```
format :
```

The output consists of words that contain two or less than two vowels, printed in the same order they appeared in the input. Each word is printed on a new line.

Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the test cases will fall under the following constraints:

1 ≤ N ≤ 15

Each word consists of lowercase English letters only.

The length of each word is between 1 and 50 characters.

Sample test cases :
#### Input 1:

```
1
sri
Output 1 :
sri
Input 2 :
5
alice
bob
charlie
david
eva
Output 2 :
bob
david
eva
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
image
Header Snippet
12
import java.util.ArrayList;import java.util.Scanner;
Whitelist
Set 1:
ArrayList
Fill your code here
Java (11)
theme
instruction
1234
// You are using Javaclass VowelFilter {    //Type your code here}
Footer Snippet
123456789
public class Main {    public static void main(String[] args) {        Scanner sc = new Scanner(System.in);        int n = sc.nextInt();         sc.nextLine();         VowelFilter.filterWords(n, sc);        sc.close();    }} 
Provide Custom Input
```
