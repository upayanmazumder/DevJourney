# 0-1 Knapsack (Dynamic Programming)

Problem
- Given weights and values of n items and a capacity W, select a subset (each item at most once) maximizing total value without exceeding W.

Algorithm
- DP over items and capacities: dp[i][w] = best using first i items with capacity w.

Time complexity: O(n*W)
Space complexity: O(n*W)

Input format (example):
```
4 7      # n W
1 3 4 5  # weights
1 4 5 7  # values
```

Code: [05_knapsack.cpp](05_knapsack.cpp)
