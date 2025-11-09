# Movie Year

## Single File Programming Question

## Problem Statement

Tim, an avid movie enthusiast, wishes to create a program to manage and store information about his favorite movies. He wants to serialize and deserialize movie data, specifically the title and release year, with a unique twist: the release year stored in the serialized file should be three years earlier than the original release year.

Design a program to create an object for the Movie class with the provided movie title and release year. Serialize the created object to a file named movie_info.ser. Deserialize the Movie object from the movie_info.ser file. Display the modified release year (three years earlier) after deserialization.

#### Input:

```
format :
```

The input consists of a string value 's', containing a movie title and release year separated by a space.

#### Output:

```
format :
```

The output displays the modified release year after deserialization.

Refer to the sample output for the formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

The string s contains uppercase, and lowercase with at most 30 characters.

Sample test cases :
#### Input 1:

```
Inception 2010
Output 1 :
2007
Input 2 :
The_Dark_Knight 2008
Output 2 :
2005
```
