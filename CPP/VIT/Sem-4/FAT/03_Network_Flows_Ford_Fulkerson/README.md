# Network Flows - Ford Fulkerson

## Algorithm

1. Copy capacity matrix to residual matrix.
2. Find an augmenting path from source to sink using DFS.
3. Find minimum edge capacity on that path (bottleneck flow).
4. Subtract bottleneck from forward edges in residual graph.
5. Add bottleneck to backward edges in residual graph.
6. Add bottleneck to total max flow.
7. Repeat until no augmenting path exists.

## Time Complexity

- O(E * maxFlow) for integer capacities (common bound)

## Space Complexity

- O(V^2)
