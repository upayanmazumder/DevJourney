# Job Selection (Branch & Bound)

Problem
- Given jobs with deadlines (unit time) and profits, schedule jobs to maximize total profit. This implementation uses a branch-and-bound search with a simple upper bound (remaining profits) for pruning.

Algorithm
- Sort jobs by profit descending. Use backtracking to try assigning jobs to latest available slot ≤ deadline. Prune branches where current profit + remaining profits <= best found.

Time complexity: exponential worst-case, pruning often helps for moderate n
Space complexity: O(maxDeadline)

Input format (example):
```
4
1 4 20   # id deadline profit
2 1 10
3 2 40
4 2 30
```

Code: [main.cpp](main.cpp)
