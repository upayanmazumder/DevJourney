# 0-1 Knapsack (Dynamic Programming)

Problem
- Given `n` items, each with weight `w[i]` and value `v[i]`, and a knapsack capacity `W`, select a subset of items (each at most once) to maximize total value without exceeding capacity.

Key idea
- Use DP where `dp[i][c]` is the maximum value achievable using the first `i` items with capacity `c`. The decision for item `i` is to take it (if it fits) or skip it.

Recurrence
- `dp[0][*] = 0`
- For i from 1..n and capacity c from 0..W:
	- if `w[i] > c`: `dp[i][c] = dp[i-1][c]`
	- else: `dp[i][c] = max(dp[i-1][c], dp[i-1][c-w[i]] + v[i])`

Space optimization
- You can reduce space to a 1D array `dp[c]` iterating items and capacities in descending order (to avoid reuse within the same item).

Complexity
- Time: O(n * W)
- Space: O(n * W) or O(W) with the optimized 1D DP (but reconstructing chosen items needs extra bookkeeping).

Worked example
```
n = 4, W = 7
weights = [1,3,4,5]
values  = [1,4,5,7]
```
- Optimal: items with weights 3 and 4 (value 4 + 5 = 9) fit exactly into capacity 7.

Notes
- DP is pseudo-polynomial because it depends on `W`. For large `W` consider approximation or meet-in-the-middle for moderate `n`.

Code: `main.cpp` — implements the DP and prints maximum value and chosen items.
