# Single File Programming Question

## Problem Statement

Bakya works as a medical records assistant in a small clinic. She is tasked with managing and analyzing patient data, specifically focusing on the gender distribution and age of patients. Each patient record includes an ID, name, gender (1 for male and 0 for female), and age. Bakya's job is to count the number of male and female patients and identify if there are any patients older than 40. If patients older than 40 exist, she must list their names; otherwise, she will return '0'.

Help Bakya by creating a system that processes this patient data using the struct patient and two functions: print_gender() to count males and females, and print_age() to display names of patients above 40 years old.

### Input format :

The first line consists of an integer n, representing the number of patients.

In each of the following n lines, the input consists of four space-separated values:

An integer - Patient's ID
A string (without spaces) - Patient's name
An integer - Patient's gender(1- Male, 2- Female)
An integer - Patient's age

### Output format :

The first line prints "Count: " followed by two space-separated integers representing the number of males and females in the patient data.

The second line prints "Above 40: " followed by the names of patients whose age is greater than 40 separated by a space.

Refer to the sample output for the formatting specifications.

### Code constraints :

1 ≤ n ≤ 10

Length of the name ≤ 30

The name should not contain any spaces.

There is at least one patient over the age of 40.

### Sample test cases :

#### Input 1 :

5
100 Gokul 1 40
101 Ashok 1 35
231 Banu 2 45
211 Akaash 1 60
109 Chiranjeevi 1 44

#### Output 1 :

Count: 4 1
Above 40: Banu Akaash Chiranjeevi

#### Input 2 :

2
100 Shyam 1 23
101 Jeeva 1 25

#### Output 2 :

Count: 2 0
Above 40: 0
Whitelist
Set 1:
struct
