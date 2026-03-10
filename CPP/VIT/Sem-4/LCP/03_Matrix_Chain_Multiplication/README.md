# Matrix Chain Multiplication (Dynamic Programming)

Problem
- Given a sequence of matrices A1, A2, ..., An with dimensions p0 x p1, p1 x p2, ..., p(n-1) x pn, find the parenthesization that minimizes the total number of scalar multiplications.

Key idea (intuition)
- The order of multiplication affects cost (matrix multiplication is associative but not commutative). Use DP over chain lengths: cost for (i..j) depends on choosing a split k between i and j.

DP formulation
- Let `m[i][j]` be the minimum cost (scalar multiplications) to compute the product A_i..A_j. For i == j, `m[i][i] = 0`.
- For i < j:
	`m[i][j] = min_{i <= k < j} ( m[i][k] + m[k+1][j] + p_{i-1} * p_k * p_j )`
- Keep a `s[i][j]` table storing the split k that gives minimum cost to reconstruct optimal parenthesization.

Complexity
- Time: O(n^3) due to the triple loop (length, i, k).
- Space: O(n^2) for `m` and `s` tables.

Worked example
Dimensions: `p = [10, 20, 30, 40]` (three matrices: 10x20, 20x30, 30x40)
- Options:
	- ((A1 A2) A3): cost = (10*20*30) + (10*30*40) = 600 + 12000 = 12600
	- (A1 (A2 A3)): cost = (20*30*40) + (10*20*40) = 24000 + 8000 = 32000
- Best: `((A1 A2) A3)` with cost 12600.

Reconstruction
- Use `s[i][j]` to recursively print parenthesization.

Notes
- This DP is a classic example of optimal substructure + overlapping subproblems.

Code: `main.cpp` — fills `m` and `s`, prints minimum cost and optimal parenthesization.
