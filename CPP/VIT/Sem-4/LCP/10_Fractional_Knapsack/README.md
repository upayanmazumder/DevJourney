# Fractional Knapsack (Greedy)

Problem
- Given weights and values for items and a capacity W, choose fractions of items to maximize total value.

Algorithm
- Greedy: sort items by value/weight ratio and take as much as possible from highest ratio.

Time complexity: O(n log n)
Space complexity: O(n)

Input format (example):
```
3 50    # n capacity
10 60
20 100
30 120
```

Code: [10_fractional_knapsack.cpp](10_fractional_knapsack.cpp)
