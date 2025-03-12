# Single File Programming Question

## Problem Statement

The Government takes a census of animals in various locations. They want to collect data on the animal's name, count, and location. To accomplish this, a structure named Animal is created with members for the animal's name, count, and location.

The task is to read the data for N animals and store it in an array of Animal structures in which the structure is accessed through pointers. Then, the program should display the details of the animals found in the location 'India'.

### Input format :

The first line of input consists of an integer N, representing the number of animals.

The next N lines of input consist of the name as a string, count as an integer, and location as a string of each animal, separated by a space.

### Output format :

The output displays the details of each animal's name as a string, count as an integer, and location as a string, separated by a space found in the location "India"(india or INDIA is also considered valid).

If no animals are found in the location, the output displays "No animals found in India".

Refer to the sample output for formatting specifications.

### Code constraints :

In this scenario, the test cases fall under the following constraints

1 ≤ N ≤ 20

1 ≤ Length of the animal's name ≤ 50

1 ≤ Length of the location ≤ 50

### Sample test cases :

#### Input 1 :

4
Cat 1 India
Dog 2 USA
Lion 6 India
Tiger 5 UK

#### Output 1 :

Cat 1 India
Lion 6 India

#### Input 2 :

2
Dog 3 UK
Cat 5 USA

#### Output 2 :

No animals found in India

#### Input 3 :

5
Leopard 6 india
Camel 8 Africa
Parrot 4 Australia
Elephant 9 India
Lynx 2 INDIA

#### Output 3 :

Leopard 6 india
Elephant 9 India
Lynx 2 INDIA
Whitelist
Set 1:
struct
Animal
