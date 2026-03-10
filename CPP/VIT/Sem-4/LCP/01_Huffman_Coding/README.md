# Huffman Coding (Greedy)

Problem
- Given symbols and their frequencies, build prefix-free binary codes minimizing total encoded length.

Algorithm
- Use a min-heap of nodes (frequency). Repeatedly extract two lowest-frequency nodes and merge them; the resulting tree yields binary codes by traversing left->0, right->1.

Time complexity: O(n log n)
Space complexity: O(n)

Input format (example):
```
4
A 5
B 9
C 12
D 13
```

Code: [01_huffman.cpp](01_huffman.cpp)

Sample
- Compile and run the code; it prints the code for each symbol.
