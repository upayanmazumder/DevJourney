# 0/1 Knapsack using Dynamic Programming

## Problem Statement

Given `n` items, each having a weight and a value, and a knapsack of capacity `W`, determine the maximum total value that can be obtained by selecting items such that the total weight does not exceed `W`. Each item can be chosen at most once.

---

## Technique Used

Dynamic Programming

---

## DP Definition

```

dp[i][w] = Maximum value obtained using first i items with knapsack capacity w

```

---

## Recurrence Relation

If the current item can be included:

```

dp[i][w] = max(
dp[i-1][w],
value[i-1] + dp[i-1]w - weight[i-1]]
)

```

If the current item cannot be included:

```

dp[i][w] = dp[i-1][w]

```

---

## Base Conditions

```

dp[0][w] = 0 // No items
dp[i][0] = 0 // Zero capacity

```

---

## Algorithm

1. Read the number of items `n` and knapsack capacity `W`.
2. Read the weights and values of the items.
3. Initialize the DP table using base conditions.
4. Fill the DP table using the recurrence relation.
5. The final answer is stored in `dp[n][W]`.

---

## Time and Space Complexity

- **Time Complexity:** `O(n × W)`
- **Space Complexity:** `O(n × W)`

---

## Output

Displays the maximum value that can be stored in the knapsack.
