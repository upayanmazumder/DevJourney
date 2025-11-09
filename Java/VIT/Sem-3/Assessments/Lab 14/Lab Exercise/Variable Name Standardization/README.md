# Variable Name Standardization

## Single File Programming Question

## Problem Statement

Meera, a software developer at a startup, is working on a Java-based variable name standardization tool that integrates with their code quality checker. As part of this, she needs to convert any given sentence into a valid camelCase identifier commonly used in Java naming conventions.

The sentence can contain multiple words separated by spaces. The goal is to transform it into a single camelCase word by:

Removing all spaces,
Keeping the first word in lowercase,
Capitalizing the first letter of every subsequent word, and
Joining everything into a single string.

For example, the input "convert this sentence" should produce the output "convertThisSentence".

To achieve this, Meera must use only the classes provided in the java.lang package, including String, Character, and StringBuilder, to ensure optimal performance and cleaner string manipulation.

Help Meera implement the logic as per the requirement.

#### Input:

```
format :
```

The first line of input contains a string representing the sentence to be converted into camelCase(Words are separated by a single space).

#### Output:

```
format :
```

The output prints a single camelCase string derived from the input by:

Removing all spaces,
Keeping the first word in lowercase,
Capitalizing the first letter of each subsequent word.

Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ Length of the input string ≤ 200.

The input string contains only lowercase or uppercase alphabetic characters and spaces.

Sample test cases :
#### Input 1:

```
convert this sentence
Output 1 :
convertThisSentence
Input 2 :
hello world
Output 2 :
helloWorld
```
