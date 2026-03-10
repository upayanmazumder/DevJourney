# Fractional Knapsack (Greedy)

Problem
- Given `n` items each with weight `w[i]` and value `v[i]`, and a knapsack capacity `W`, you may take fractional amounts of items. Choose quantities to maximize total value without exceeding `W`.

Key idea (intuition)
- Since fractions are allowed, the optimal strategy is greedy: always take as much as possible of the item with the highest value-per-weight ratio `v[i]/w[i]`.

Algorithm
1. Compute ratio `r[i] = v[i] / w[i]` for each item.
2. Sort items in descending order of `r[i]`.
3. Greedily take full items until the next item cannot be fully added; take the remaining capacity as a fraction of that item.

Complexity
- Time: O(n log n) due to sorting.
- Space: O(n).

Worked example
```
n = 3, W = 50
(w, v): (10, 60), (20, 100), (30, 120)
ratios: 6.0, 5.0, 4.0
```
- Take item1 (10,60) => capacity 40, value 60
- Take item2 (20,100) => capacity 20, value 160
- Take 20/30 of item3 => added value 20/30 * 120 = 80, final value = 240

Notes
- Fractional knapsack is solvable optimally by greedy. For the 0-1 variant (no fractions), use DP (knapsack problem).

Code: `main.cpp` — sorts by ratio and returns maximum achievable value (allowing fractions).
