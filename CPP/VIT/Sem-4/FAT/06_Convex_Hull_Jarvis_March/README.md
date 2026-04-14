# Finding Convex Hull - Jarvis March

## Idea

Jarvis March (Gift Wrapping) starts from leftmost point and repeatedly selects the most counterclockwise point.
It wraps around until it returns to start.

## Input

1. Number of points
2. Points as `(x, y)`

## Steps in code

1. Find leftmost point.
2. Add current hull point.
3. Choose a candidate next point.
4. Scan all points and replace candidate if a more counterclockwise point exists.
5. Handle collinear case by taking farthest point.
6. Continue until start point is reached.

## Time Complexity

- \(O(nh)\), where \(h\) is number of hull points

## Space Complexity

- \(O(h)\) for hull index list
