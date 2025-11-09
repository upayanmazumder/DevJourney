# Specific Patterns in Substrings

## Single File Programming Question

## Problem Statement

Saranya, a software developer at a search engine company, is tasked with finding specific patterns in a long string of text. The task is to locate all starting indices where a concatenation of words, in any permutation, appears as a substring. Using a hash map to track word frequencies, Saranya can efficiently solve this problem.

#### Input:

```
format :
```

The first line of input consists of a string s (1 ≤ s.length ≤ 104), representing the text to search for concatenated substrings.

The second line of input consists of an array of words of strings (1 ≤ words.length ≤ 5000, 1 ≤ words[i].length ≤ 30), representing the words that must be concatenated in any permutation.

#### Output:

```
format :
```

The output prints an array of integers representing the starting indices of all concatenated substrings. If no such substrings exist, return an empty array.

Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ s.length ≤ 104

1 ≤ words.length ≤ 5000

1 ≤ words[i].length ≤ 30

s and words[i] consist of lowercase English letters.

Sample test cases :
#### Input 1:

```
barfoothefoobarman
2
foo
bar
Output 1 :
Starting indices of concatenated substrings: [0, 9]
Input 2 :
wordgoodgoodgoodbestword
4
word
good
best
word
Output 2 :
Starting indices of concatenated substrings: []
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.
Marks : 10
Negative Marks : 0
```
