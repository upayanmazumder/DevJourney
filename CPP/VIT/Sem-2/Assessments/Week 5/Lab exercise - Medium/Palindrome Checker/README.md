# Single File Programming Question

## Problem Statement

Rathi wants to determine whether a given string is a palindrome or not. To assist her, you are tasked with creating a program that checks if a string is a palindrome.

You are required to define a PalindromeChecker class with the following properties and methods:

A constructor that initializes the object with a string.
A method named isPalindrome that checks if the input string is a palindrome.
A destructor that displays a message when an object is destroyed.

### Input format :

The input consists of a single line containing a string.

### Output format :

If the input string is a palindrome, prints "The input string is a palindrome."

If the input string is not a palindrome, prints "The input string is not a palindrome."

When the PalindromeChecker object is destroyed (either at the end of the program or due to scope), prints "Destructor called. Object destroyed."

### Code constraints :

1 ≤ length of string ≤ 100

The input string contains printable ASCII characters

### Sample test cases :

#### Input 1 :

madam

#### Output 1 :

The input string is a palindrome.
Destructor called. Object destroyed.

#### Input 2 :

always

#### Output 2 :

The input string is not a palindrome.
Destructor called. Object destroyed.

#### Input 3 :

Radar

#### Output 3 :

The input string is not a palindrome.
Destructor called. Object destroyed.
