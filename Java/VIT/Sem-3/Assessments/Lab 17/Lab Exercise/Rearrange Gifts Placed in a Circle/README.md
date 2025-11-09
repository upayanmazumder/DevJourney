# Rearrange Gifts Placed in a Circle

## Single File Programming Question

## Problem Statement

During a festive gathering, participants have placed their gifts in a circle, each labeled with a unique ID. To add excitement, Alex wants to rearrange the gifts by swapping two presents positioned at indices a and b to create a thrilling surprise.

Write a program to perform this gift exchange using the generics concept.

#### Input:

```
format :
```

The first line consists of an integer indicating the size of the array (n).

The second line consists of n space-separated integers representing the elements of the array.

The third line consists of an integer denoting the first index a and second index b to swap

#### Output:

```
format :
```

The first line of the output displays the original array as: "Original Array: [x, x, x]". where x, x, x are array elements.

The second line displays the array after swapping elements at the denoted indices as: "Array after swapping elements at indices a and b: [x, x, x]".

If the indices to swap are not valid, the output prints "Invalid indices. Swap operation aborted." in the second line.

Refer to the sample output for the formatting specifications.

Code constraints :
2 ≤ n ≤ 100

Valid indices to swap - 0 ≤ a, b < n

Sample test cases :
#### Input 1:

```
5
10 20 30 40 50
2 4
Output 1 :
Original Array: [10, 20, 30, 40, 50]
Array after swapping elements at indices 2 and 4: [10, 20, 50, 40, 30]
Input 2 :
2
100 200
1 3
Output 2 :
Original Array: [100, 200]
Invalid indices. Swap operation aborted.
```
