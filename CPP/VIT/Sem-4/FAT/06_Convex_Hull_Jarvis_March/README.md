# Finding Convex Hull - Jarvis March

## Algorithm

1. Find the leftmost point. This is the starting hull point.
2. Add current point to hull.
3. Assume any other point as next point.
4. Check every point:
 - if it is more counterclockwise, update next point
 - if collinear, keep the farthest one
5. Move to next point and repeat.
6. Stop when you return to starting point.

## Time Complexity

- O(nh), where h is number of hull points

## Space Complexity

- O(h)
