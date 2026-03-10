# Huffman Coding (Greedy)

Problem
- Given a set of symbols and their frequencies, assign binary prefix codes so the total encoded length (sum frequency * code length) is minimized.

Why this works (intuition)
- Frequent symbols should get shorter codes. Huffman's greedy method builds an optimal binary tree by repeatedly merging the two least frequent nodes. The final tree depth gives the code lengths.

Algorithm (outline)
1. Put each symbol as a leaf node with weight = frequency in a min-heap.
2. While heap size > 1:
	 - Pop two smallest-weight nodes a and b.
	 - Create a new internal node with weight = a.weight + b.weight and children (a, b).
	 - Push the new node back to the heap.
3. The remaining node is the root; traverse it assigning 0 for left and 1 for right to obtain codes.

Pseudocode
```
for each symbol s:
	push (freq[s], leaf(s)) into minHeap
while minHeap.size() > 1:
	(f1,n1) = pop(minHeap)
	(f2,n2) = pop(minHeap)
	push (f1+f2, node(n1,n2)) into minHeap
root = pop(minHeap)
assign_codes(root, "")
```

Complexity
- Time: O(n log n) for n symbols (heap operations).
- Space: O(n) for tree and heap.

Worked example
Input:
```
4
A 5
B 9
C 12
D 13
```
Steps (sketch):
- Merge A(5) and B(9) -> node 14
- Merge C(12) and D(13) -> node 25
- Merge 14 and 25 -> root 39
One valid set of codes (may vary by tie-breaking):
```
A: 00
B: 01
C: 10
D: 11
```

Notes and variants
- Huffman produces optimal prefix codes when symbol cost is proportional to code length.
- For canonical Huffman codes (useful for deterministic encoding/decoding), sort by code length and assign lexicographically.

References
- D. A. Huffman, "A method for the construction of minimum-redundancy codes" (1952)
- CLRS — Greedy algorithms

Code: `main.cpp` — builds the Huffman tree and prints codes for each input symbol.
