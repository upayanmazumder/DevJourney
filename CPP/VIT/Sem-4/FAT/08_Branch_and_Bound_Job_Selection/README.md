# Branch and Bound - Job Selection

## Algorithm

1. Read jobs (id, deadline, profit).
2. Sort jobs by profit in descending order.
3. Use recursion for decision tree:
   - include current job (if slot is available)
   - exclude current job
4. Before expanding a node, calculate upper bound (best possible profit from this point).
5. If bound is not better than current best profit, prune that branch.
6. At leaf level, update best answer if current profit is higher.
7. Print maximum profit and selected jobs.

## Why Branch and Bound

- Normal recursion checks many useless branches.
- Bound helps skip branches that cannot improve answer.

## Complexity

- Worst case: exponential
- Usually faster than plain brute force due to pruning
