# Insert Substring into a specific position of a text

## Single File Programming Question

## Problem Statement

Lisa needs a tool to insert a given substring into a specific position of a text. She wants to create a program using java.lang.StringBuilder to achieve this. The program should take the original text, substring, and insertion position as input and output the modified text.

Can you assist Lisa in this?

#### Input:

```
format :
```

The first line of input consists of a string representing the original text string.

The second line consists of a string representing the substring to insert.

The third line consists of an integer representing the position (0-based index) where the substring should be inserted.

#### Output:

```
format :
```

The output prints the modified text string after inserting the substring at the specified position. If the position is greater than the original text length, print "Invalid position."

Refer to the sample output for formatting specifications.

Code constraints :
The input string consists of printable ASCII characters.

Sample test cases :
#### Input 1:

```
HelloWorld
Java
5
Output 1 :
HelloJavaWorld
Input 2 :
OpenAI
GPT
3
Output 2 :
OpeGPTnAI
Input 3 :
Java
World
8
Output 3 :
Invalid position.
```
