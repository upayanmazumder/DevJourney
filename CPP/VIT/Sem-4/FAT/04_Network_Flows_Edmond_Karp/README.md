# Network Flows - Edmond Karp

## Algorithm

1. Copy capacity matrix to residual matrix.
2. Use BFS to find path from source to sink.
3. If no path is found, stop.
4. Find bottleneck flow (minimum residual capacity on path).
5. Update residual graph:
 - reduce forward edges
 - increase backward edges
6. Add bottleneck to max flow.
7. Repeat from BFS step.

## Time Complexity

- O(VE^2)

## Space Complexity

- O(V^2)
