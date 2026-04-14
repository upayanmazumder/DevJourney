# Finding Convex Hull - Graham Scan

## Idea

Graham Scan sorts points by polar angle around the lowest point, then uses a stack concept to keep only left turns.
Right turn or collinear backtracking points are removed.

## Input

1. Number of points
2. Points as `(x, y)`

## Steps in code

1. Find the bottom-most (and left-most tie breaker) point `p0`.
2. Sort all other points by polar angle around `p0`.
3. Start hull with first two points.
4. For each next point, pop while turn is not counterclockwise.
5. Push current point.
6. Final stack is convex hull.

## Time Complexity

- Sorting dominates: \(O(n^2)\) in this code due to bubble sort
- With efficient sort, standard Graham Scan is \(O(n \log n)\)

## Space Complexity

- \(O(n)\)
