Single File Programming Question

Problem Statement


Rina is managing the inventory for a library, where each row of a 2D matrix represents the number of different genres of books available on each shelf.


She wants to perform the following operations:


Transformation: Replace each element in a row with the sum of all elements in that row.

Merging: After transformation, Rina will provide one additional matrix, and specify whether to merge the transformed matrix with this new matrix row-wise or column-wise.


Input format :

The first line contains two integers R and C, representing the number of rows and columns of the initial matrix.

The next R lines contain C space-separated integers, representing the book counts in the library.

The next line contains two integers MR and MC, representing the dimensions of the second matrix (to be merged).

The next MR lines contain MC space-separated integers, representing the second matrix.

The last line contains an integer mergeType:

0 → Row-wise merging (append the second matrix below the transformed matrix).

1 → Column-wise merging (append the second matrix to the right of the transformed matrix).

Output format :

The output prints "Transformed matrix: "followed by the transformed 2D matrix where each element in a row is replaced with the sum of the elements in that row.

The output prints "Final merged matrix: ", followed by the merging based on mergeType.


Refer to the sample output for formatting specifications.

Code constraints :

The given test cases fall under the following constraints:

1 ≤ T ≤ 10

1 ≤ R, C, MR, MC ≤ 10

0 ≤ books count ≤ 100

Sample test cases :

Input 1 :

3 4 8 2 4 9 4 5 6 1 7 8 9 3 2 4 3 5 7 2 6 1 4 9 0

Output 1 :

Transformed matrix: 23 23 23 23 16 16 16 16 27 27 27 27 Final merged matrix: 23 23 23 23 16 16 16 16 27 27 27 27 3 5 7 2 6 1 4 9 

Input 2 :

2 3 1 2 3 4 5 6 2 3 7 8 9 3 2 1 1

Output 2 :

Transformed matrix: 6 6 6 15 15 15 Final merged matrix: 6 6 6 7 8 9 15 15 15 3 2 1

