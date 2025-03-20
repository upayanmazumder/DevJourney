# Single File Programming Question

## Problem Statement

Regina is working on a greeting program to welcome and say hello to users. She wants to create a flexible program that allows users to input their name and receive a personalized welcome and greeting. Regina also wants to provide default greetings in case the user doesn't input their name.

Implement a program that takes a user's name as input and displays both a welcome message and a hello message using functions with default arguments.

Functions Specifications

void displayWelcome(const string& name = "")

If name is provided, it includes the name in the message.

void displayHello(const string& name = "")

If name is provided, it includes the name in the message.

### Input format :

The input consists of the name as a string.

### Output format :

The output displays the welcome and hello messages using the provided functions.

The output should be in the following format:

If name is given then print:

"Welcome <name>

Hello <name>"

If name is not given the print:

"Welcome

Hello "

Refer to the sample output for the formatting specifications.

### Code constraints :

The given test cases fall under the following constraints:

1 ≤ Length of the string ≤ 100

### Sample test cases :

#### Input 1 :

John

#### Output 1 :

Welcome John
Hello John

#### Input 2 :

#### Output 2 :

Welcome
Hello
