# Finding Convex Hull - Graham Scan

## Algorithm

1. Find the point with smallest y (if tie, smallest x). Call it p0.
2. Sort all other points by polar angle with respect to p0.
3. Put first two sorted points into hull stack.
4. For each next point:
 - while top two points and current point do not make a left turn, pop stack
 - push current point
5. Remaining stack points are convex hull points.

## Time Complexity

- In this code: O(n^2) due to bubble sort
- Standard Graham Scan with fast sort: O(n log n)

## Space Complexity

- O(n)
