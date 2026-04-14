# Network Flows - Ford Fulkerson

## Idea

Ford Fulkerson repeatedly finds an augmenting path from source to sink in residual graph and pushes possible flow.
This implementation uses DFS for finding paths.

## Input

1. Number of vertices
2. Capacity matrix
3. Source index
4. Sink index

## Steps in code

1. Copy capacity matrix into residual graph.
2. Use DFS to find any path with positive residual capacity.
3. Find bottleneck (minimum edge capacity in that path).
4. Update forward and backward residual capacities.
5. Add bottleneck to max flow.
6. Repeat until no augmenting path exists.

## Time Complexity

- Depends on path selection and capacities.
- Common bound: \(O(E \cdot \text{maxFlow})\) for integer capacities.

## Space Complexity

- \(O(V^2)\) for residual matrix
