# Assembly Line Scheduling (Dynamic Programming)

Problem
- There are two assembly lines, each with n stations. Station i on line j takes time `a_j[i]`. Products enter with times `e1`,`e2` and leave with `x1`,`x2`. If you switch lines between station i and i+1, a transfer time `t_j[i]` applies. Find the minimum total processing time and the sequence of chosen lines.

Key idea (intuition)
- The optimal way to reach station i on a line depends only on the optimal ways to reach station i-1 — a classic DP with local choices (stay or transfer).

DP recurrence
- Let `f1[i]` = best time to finish station i and be on line 1; `f2[i]` likewise for line 2.
	- Base:
		- `f1[1] = e1 + a1[1]`
		- `f2[1] = e2 + a2[1]`
	- Transition for i = 2..n:
		- `f1[i] = min(f1[i-1] + a1[i], f2[i-1] + t2[i-1] + a1[i])`
		- `f2[i] = min(f2[i-1] + a2[i], f1[i-1] + t1[i-1] + a2[i])`
	- Final answer: `ans = min(f1[n] + x1, f2[n] + x2)`

Reconstruction
- Store which previous line produced the minimum for each `f1[i]`/`f2[i]` and backtrack from the last station to retrieve the chosen line at each station.

Complexity
- Time: O(n)
- Space: O(n) for reconstruction arrays (can be reduced to O(1) if only the minimum time is needed).

Example (trace)
```
n = 4
e1 e2 = 2 4
x1 x2 = 3 2
a1 = 7 9 3 4
a2 = 8 5 6 4
t1 = 2 3 1
t2 = 2 1 2
```
- Trace the `f1` and `f2` arrays by hand using the recurrence to get the minimal time and chosen lines.

Notes
- Useful to understand simple DP formulation and path reconstruction.

Code: `main.cpp` — computes minimal time and prints the station-by-station line choices.
