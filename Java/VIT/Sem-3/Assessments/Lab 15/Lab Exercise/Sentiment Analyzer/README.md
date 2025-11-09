# Sentiment Analyzer

## Single File Programming Question

## Problem Statement

Mr. Styles is working on a sentiment analysis program to understand the sentiments conveyed in various sentences.

He needs your assistance in developing a program that analyzes the sentiment of a given sentence and classifies it as positive, negative, or neutral.

positive keywords = happy, good, excellent, positive.
negative keywords = sad, bad, terrible, negative.
Anything else is Neutral.

Create a file named input.txt, the input is written into the file input.txt. The program then reads the sentence from input.txt and sentiment analysis is performed based on predefined positive and negative keywords.

The classified sentiment (positive, negative, or neutral) is written to a new file named output.txt and displayed.

Note :

﻿The program should use input and output streams (FileInputStream, FileOutputStream, DataInputStream, DataOutputStream) to handle file operations.

#### Input:

```
format :
```

The input consists of a string, representing the entered statement.

#### Output:

```
format :
```

The output displays a string representing the evaluated sentiment.

Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ string length ≤ 50

Sample test cases :
#### Input 1:

```
I am feeling happy today.
Output 1 :
Positive
Input 2 :
The movie was terrible.
Output 2 :
Negative
Input 3 :
The movie was not great.
Output 3 :
Neutral
```
