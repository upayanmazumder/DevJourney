# Randomized Quick Sort and All-Pairs Shortest Path

## Part A: Randomized Quick Sort

### Algorithm

1. Pick a random pivot index between low and high.
2. Swap pivot with last element.
3. Partition array so smaller elements go left and larger go right.
4. Recursively sort left part.
5. Recursively sort right part.

### Complexity

- Average: O(n log n)
- Worst: O(n^2)

## Part B: All-Pairs Shortest Path (Floyd-Warshall)

### Algorithm

1. Read adjacency matrix (use INF for no direct edge).
2. For each k from 0 to n-1:
 - for each i from 0 to n-1:
 - for each j from 0 to n-1:
 - update dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
3. Final matrix gives shortest distances between all pairs.

### Complexity

- Time: O(n^3)
- Space: O(n^2)
