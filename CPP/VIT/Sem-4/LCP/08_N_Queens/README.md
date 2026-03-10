# N-Queens (Backtracking)

Problem
- Place `N` queens on an `N × N` chessboard so that no two queens attack each other (no shared row, column, or diagonal). Print all valid configurations or a single valid configuration.

Key idea (intuition)
- Place queens one row at a time. For each row try each column that is not attacked by previously placed queens. Backtrack when a conflict occurs.

Optimizations
- Use boolean arrays or bitmasks to track occupied columns, and the two diagonals, for O(1) conflict checks per candidate.

Complexity
- Time: exponential in `N` (solutions grow quickly), but pruning reduces search drastically for small N.
- Space: O(N) for the placement array and auxiliary structures.

Worked example
- For `N = 4` there are 2 solutions, commonly given as column lists `[2,4,1,3]` and `[3,1,4,2]` (1-based indexing per row).

Notes
- Useful exercise in backtracking and search pruning. Bitmask implementations are common in competitive programming for maximum speed.

Code: `main.cpp` — backtracking implementation that prints solutions.
