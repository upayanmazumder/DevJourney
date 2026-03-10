# N-Queens (Backtracking)

Problem
- Place N queens on an N×N board so no two queens attack each other; print all solutions or one solution.

Algorithm
- Standard backtracking: place queens row by row, pruning on column and diagonal conflicts.

Time complexity: exponential in N (backtracking)
Space complexity: O(N)

Input: single integer N

Code: [08_nqueens.cpp](08_nqueens.cpp)
