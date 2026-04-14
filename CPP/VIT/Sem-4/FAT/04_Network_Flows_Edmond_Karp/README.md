# Network Flows - Edmond Karp

## Idea

Edmond Karp is a specific Ford Fulkerson method that uses BFS to find the shortest augmenting path in terms of edges.
This gives a polynomial time guarantee.

## Input

1. Number of vertices
2. Capacity matrix
3. Source index
4. Sink index

## Steps in code

1. Build residual graph from capacity matrix.
2. Use BFS to find augmenting path and parent array.
3. Compute bottleneck flow in that path.
4. Update residual capacities.
5. Add bottleneck to max flow.
6. Repeat until BFS cannot reach sink.

## Time Complexity

- \(O(VE^2)\)

## Space Complexity

- \(O(V^2)\) for residual matrix
