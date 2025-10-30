Single File Programming Question
Problem Statement



Define a generic interface named Min with a single method findMin() that takes an array of type T as argument and returns the minimum element in the array. Define a class MinFinder that implements the Min interface.



The findMin() method of the MinFinder class should find the minimum element in the array using the Arrays.sort() method and return it. 



﻿The program should create an array of integers and an array of doubles, call the findMin() method on each array using an object of the MinFinder class, and print the minimum element returned by the method.

Input format :
The first line of input consists of an integer n, which represents the number of elements in the array.

The second line contains n space-separated integers, which are the elements of the array

Output format :
The output prints the minimum value from the array.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n ≤ 100

−106 ≤ array elements ≤ 106

Sample test cases :
Input 1 :
3
123 321 121
Output 1 :
121
Input 2 :
6
5478 69223 4548 78787 20211 888
Output 2 :
888