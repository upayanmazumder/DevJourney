# Emma - Periodic Updates in Data Analysis

## Single File Programming Question

## Problem Statement

Emma is a data analyst working with a grid-based system where each cell contains important numerical data. The grid represents spatial data, inventory records, or structured reports that require periodic updates.

Due to system updates and new requirements, Emma needs to modify the grid in the following ways:

She wants to insert either a new row or a new column at a given position.

Later, she needs to delete either a row or a column from the modified matrix.

#### Input:

```
format :
```

The first line contains two integers rows and cols (the dimensions of the matrix).

The next rows lines contain cols space-separated integers representing the initial matrix.

The next line contains two integers insertType and insertIndex:

insertType = 0 for row insertion, 1 for column insertion.

insertIndex is the position where the new row/column should be added.

If inserting a row, the next cols integers represent the new row or If inserting a column, the next rows integers represent the new column.

The next line contains two integers deleteType and deleteIndex:

deleteType = 0 for row deletion, 1 for column deletion.

deleteIndex is the position to be deleted.

#### Output:

```
format :
```

The first line of output prints the string "After insertion" followed by the modified matrix with the inserted row or column.

Each row of the matrix is printed on a new line with space-separated integers.

The next line prints the string "After deletion" followed by the final matrix after the specified deletion operation.

Each row of the resulting matrix is printed on a new line with space-separated integers.

Refer to the sample output for formatting specifications.

Code constraints :

1 ≤ N, M ≤ 10

1 ≤ dataset elements ≤ 1000

Sample test cases :

#### Input 1:

3 3 1 2 3 4 5 6 7 8 9 0 1 10 11 12 1 2

#### Output 1:

After insertion 1 2 3 10 11 12 4 5 6 7 8 9 After deletion 1 2 10 11 4 5 7 8

#### Input 2:

2 2 5 6 7 8 1 0 1 3 0 1

#### Output 2:

After insertion 1 5 6 3 7 8 After deletion 1 5 6
