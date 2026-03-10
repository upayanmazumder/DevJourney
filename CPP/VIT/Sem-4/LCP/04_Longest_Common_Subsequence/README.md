# Longest Common Subsequence (Dynamic Programming)

Problem
- Given two sequences (strings or arrays), find the longest sequence that appears in both in the same relative order (not necessarily contiguous).

Key idea
- Use a DP table where `dp[i][j]` is the length of LCS of prefixes `A[0..i-1]` and `B[0..j-1]`. Fill the table using matches and choosing the best of skipping one character.

Recurrence
- If `A[i-1] == B[j-1]`: `dp[i][j] = dp[i-1][j-1] + 1`
- Else: `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`

Reconstruction
- To obtain one LCS, backtrack from `dp[m][n]` following choices (if match, include char and move diagonally; else move to the larger neighbor).

Complexity
- Time: O(m * n)
- Space: O(m * n) (can be reduced to O(min(m,n)) if only length is needed, but reconstruction needs full table or extra bookkeeping)

Worked example
```
A = ABCBDAB
B = BDCABA
```
- One LCS is `BCAB` (length 4). Trace the DP table to see how the value builds.

Notes
- Useful for sequence alignment problems and many dynamic programming patterns that use grid-shaped state spaces.

Code: `main.cpp` — builds `dp` table, prints LCS length and one LCS string.
