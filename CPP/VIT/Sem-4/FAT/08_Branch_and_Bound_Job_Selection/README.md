# Branch and Bound - Job Selection

## Problem Modeled

Job sequencing with deadline and profit.
Each job takes one unit time. A job gives profit only if finished by its deadline.
Goal: maximize total profit.

## Idea of Branch and Bound

Build decision tree level by level (include/exclude each job).
Use an upper bound (optimistic profit) to prune nodes that cannot beat current best.

## How this code works

1. Sort jobs by profit descending.
2. Each node stores:
   - current level (job index considered)
   - current profit
   - chosen jobs
   - occupied time slots
   - bound
3. For next job, create two branches:
   - Include branch: schedule job in latest free slot before deadline
   - Exclude branch: skip job
4. Compute bound by greedily filling remaining slots with remaining jobs.
5. Expand only nodes with `bound > bestProfit`.

## Why Branch and Bound helps

Without pruning, decision tree is \(2^n\).
Bound-based pruning avoids exploring many useless branches.

## Complexity

- Worst case still exponential.
- Practical performance is better due to pruning.
