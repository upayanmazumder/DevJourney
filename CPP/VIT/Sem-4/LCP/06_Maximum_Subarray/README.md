# Maximum Subarray (Divide & Conquer / Kadane)

Problem
- Given an array of numbers (which may include negatives), find the contiguous subarray with the largest sum.

Two common approaches
- Divide & Conquer: recursively compute maximum in left half, right half, and the best subarray crossing the middle. (Often O(n log n).)
- Kadane's algorithm: a linear-time O(n) DP that keeps a running local maximum and a global maximum (recommended for most uses).

This folder's implementation: the provided `main.cpp` uses the divide & conquer approach (good for learning recursion and problem decomposition). For production, Kadane's algorithm is simpler and faster.

Kadane (idea)
- Maintain `current_max` = max subarray ending at current index, and `global_max` = max seen so far.

Complexity
- Divide & Conquer: O(n log n) time, O(log n) recursion space.
- Kadane: O(n) time, O(1) extra space.

Worked example
```
array = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
```
- Maximum subarray is `[4, -1, 2, 1]` with sum 6.

Notes
- Try both implementations to see differences in recursion vs in-place DP reasoning.

Code: `main.cpp` — divide & conquer implementation; replace with Kadane easily if preferred.
