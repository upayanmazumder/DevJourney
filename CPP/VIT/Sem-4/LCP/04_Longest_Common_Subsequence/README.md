# Longest Common Subsequence (Dynamic Programming)

Problem
- Given two sequences, find the length (and one LCS) of their longest common subsequence.

Algorithm
- Standard DP table of size (m+1)*(n+1) filling based on matches / skipping.

Time complexity: O(m*n)
Space complexity: O(m*n)

Input format (example):
```
ABCBDAB
BDCABA
```

Code: [main.cpp](main.cpp)
