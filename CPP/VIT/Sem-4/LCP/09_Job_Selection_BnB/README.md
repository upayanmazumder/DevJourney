# Job Selection (Branch & Bound)

Problem
- Given a set of jobs where each job takes unit time, each job has a deadline and profit. Schedule jobs (at most one per time slot) to maximize total profit while respecting deadlines.

Common greedy baseline
- A common greedy solution (for unit-time jobs) is to sort jobs by profit and, for each job, schedule it at the latest free slot before its deadline. That is often sufficient, but exploring alternatives or learning BnB is useful for study.

Branch & Bound idea
- Explore assignments with backtracking; keep an upper bound on the best achievable profit from remaining jobs to prune branches that cannot beat the current best.

Complexity
- Worst-case exponential, but pruning often makes it feasible for `n` up to a few dozens depending on deadlines.

Worked example
```
n = 4
jobs: (id, deadline, profit)
1 4 20
2 1 10
3 2 40
4 2 30
```
- The greedy method schedules highest-profit jobs first at latest possible slot. The BnB version explores candidate schedules and prunes subtrees whose optimistic bound ≤ current best.

Notes
- Useful to compare greedy vs branch-and-bound on small instances to see when pruning helps.

Code: `main.cpp` — branch-and-bound implementation; prints best schedule and profit.
