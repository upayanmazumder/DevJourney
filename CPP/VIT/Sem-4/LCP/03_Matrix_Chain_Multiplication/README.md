# Matrix Chain Multiplication (Dynamic Programming)

Problem
- Given dimensions of a chain of matrices, compute the minimum number of scalar multiplications needed to multiply them.

Algorithm
- DP over chain length: m[i][j] = min over k of m[i][k] + m[k+1][j] + cost of multiplying the two resulting matrices.

Time complexity: O(n^3)
Space complexity: O(n^2)

Input format (example):
```
3         # number of matrices
10 20 30 40   # dimensions p0 p1 p2 p3 (length = n+1)
```

Code: [main.cpp](main.cpp)
