# User Registration System

## Single File Programming Question

## Problem Statement

A company is developing a user registration system that requires users to provide valid email addresses. The development team is implementing an EmailValidator program to ensure that the entered email addresses meet certain criteria using exception handling.

The email address must contain the "@" symbol.
The email address must consist of a non-empty username(before "@" symbol) and a non-empty domain(after '"@" symbol).
The domain part of the email address must contain at least one period (".").
The email address must not contain leading or trailing spaces.

Implement a custom exception, InvalidEmailException, to fulfill the company's requirements and validate it according to the specified rules.

#### Input:

```
format :
```

The input consists of a string value 's', which represents the email address.

#### Output:

```
format :
```

The output is displayed in the following format:

If the entered email address is valid according to the specified rules, the program prints:

"Email address is valid!"

If the entered email address misses the username or domain part or misses "@" symbol or has two or more "@" symbols or misses '.' in the domain part it outputs:

"Error: Invalid email format."

Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

The string s contains uppercase, lowercase, and special characters to at most 20 characters.

Sample test cases :
#### Input 1:

```
johndoe@example.com
Output 1 :
Email address is valid!
Input 2 :
john.doe.example.com
Output 2 :
Error: Invalid email format. 
Input 3 :
@example.com
Output 3 :
Error: Invalid email format. 
Input 4 :
johndoe@
Output 4 :
Error: Invalid email format. 
Input 5 :
johnNMdoe@example.com
Output 5 :
Email address is valid!
```
