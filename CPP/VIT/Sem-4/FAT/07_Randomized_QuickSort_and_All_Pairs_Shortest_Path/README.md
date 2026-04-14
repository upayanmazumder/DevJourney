# Randomized Quick Sort and All-Pairs Shortest Path

## Part A: Randomized Quick Sort

### Idea

Quick Sort picks a pivot and partitions array into smaller and greater elements.
Randomized pivot helps avoid worst-case on already structured input.

### Steps in code

1. Pick random pivot index in range.
2. Move pivot to end.
3. Partition array around pivot.
4. Recursively sort left and right parts.

### Complexity

- Average: \(O(n \log n)\)
- Worst: \(O(n^2)\)

## Part B: All-Pairs Shortest Path (Floyd-Warshall)

### Idea

Floyd-Warshall tries every vertex as intermediate and relaxes all pairs `(i, j)`.

### Steps in code

1. Read adjacency matrix (`INF` for no direct edge).
2. For each intermediate `k`, update all `dist[i][j]`.
3. Print final shortest path matrix.

### Complexity

- Time: \(O(n^3)\)
- Space: \(O(n^2)\)

## Program Flow

A menu is provided:

1. Randomized Quick Sort
2. All-Pairs Shortest Path
