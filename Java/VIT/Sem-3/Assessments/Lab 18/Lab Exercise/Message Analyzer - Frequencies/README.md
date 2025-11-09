# Message Analyzer - Frequencies

## Single File Programming Question

## Problem Statement

Priya is analyzing encrypted messages in a research project. She wants to analyze the frequency of each character in a given paragraph. The characters should be stored in a TreeMap so that the output is sorted in ascending order of characters automatically.

You are required to build a Java program that:

Uses a TreeMap<Character, Integer> to count how many times each character appears in the message.
Ignores spaces and considers only alphabets (case-sensitive).
#### Output:

```
s the frequencies of characters in sorted order.
```

You must use a TreeMap in the class named MessageAnalyzer.

#### Input:

```
format :
```

The first line of input contains an integer n, the number of lines in the message.

The next n lines each contain a string (the encrypted message line).

#### Output:

```
format :
```

The first line of output prints: "Character Frequency:"

Then print each character and its frequency in the format: "<character>: <count>"

Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ n ≤ 50

HH:MM will always be a valid 24-hour time

Descriptions do not contain spaces

Sample test cases :
#### Input 1:

```
2
Hello World
Java
Output 1 :
Character Frequency:
H: 1
J: 1
W: 1
a: 2
d: 1
e: 1
l: 3
o: 2
r: 1
v: 1
Input 2 :
1
abc ABC
Output 2 :
Character Frequency:
A: 1
B: 1
C: 1
a: 1
b: 1
c: 1
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
image
Header Snippet
1
import java.util.\*;
Whitelist
Set 1:
TreeMap
Fill your code here
Java (11)
theme
instruction
1234
// You are using Javaclass MessageAnalyzer { //Type your code here}
Footer Snippet
12345678910
public class Main { public static void main(String[] args) { Scanner sc = new Scanner(System.in); int n = Integer.parseInt(sc.nextLine()); List<String> lines = new ArrayList<>(); for (int i = 0; i < n; i++) { lines.add(sc.nextLine()); } MessageAnalyzer analyzer = new MessageAnalyzer();
Provide Custom Input
```
