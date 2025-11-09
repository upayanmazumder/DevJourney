# User ID Management System

## Single File Programming Question

## Problem Statement

Anna is creating a user ID management system that handles a list of user IDs for a given number of entries. The system allows users to view and update a specific user ID based on its index in the list. The program needs to manage various types of errors:

Validates List Size: The number of user IDs must be between 1 and 500. If the size is out of this range, it throws an IllegalArgumentException with: "Error: Number of user IDs must be between 1 and 500".
Handles Invalid Index: When accessing or updating a user ID, if the index is out of bounds, it throws an ArrayIndexOutOfBoundsException with: "Error: Invalid index. Please select a valid index from the list".
Handles Non-Numeric Inputs: If any non-integer value is entered for user IDs or index, it catches a NumberFormatException with: "Error: Please enter valid integer values for user IDs".

Help Anna complete her task efficiently.

#### Input:

```
format :
```

The first line consists of an integer n, representing the number of user IDs.

The following n lines each contain an integer representing a user ID.

The next line contains an integer i, representing the position in the array for which the user ID should be accessed and updated (0-based indexing)

The final line contains an integer s, representing the new user ID to set at the specified position.

#### Output:

```
format :
```

If the index is valid (i.e., between 0 and size - 1):

The first line of output should display the current user ID at the specified index.
The second line of output should display the updated user ID at that index.
If the index is invalid (i.e., less than 0 or greater than or equal to size), print: "Error: Invalid index. Please select a valid index from the list"

If the number of user IDs is less than 1 or greater than 500, print: "Error: Number of user IDs must be between 1 and 500"

If any input is not a valid integer, print: "Error: Please enter valid integer values for user IDs"

Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ n ≤ 500

1 ≤ userID ≤ 10000

0 ≤ i < n

1 ≤ s ≤ 10000

Sample test cases :
#### Input 1:

```
5
394
945
723
925
274
1
946
Output 1 :
945
946
Input 2 :
4
647
932
745
558
8
596
Output 2 :
Error: Invalid index. Please select a valid index from the list
Input 3 :
0
Output 3 :
Error: Number of user IDs must be between 1 and 500
Input 4 :
3
835
twenty
375
1
946
Output 4 :
Error: Please enter valid integer values for user IDs
```
