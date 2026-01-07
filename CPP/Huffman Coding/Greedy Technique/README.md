# Huffman Coding using Greedy Technique

## Problem Statement

Given a set of characters and their frequencies, generate prefix-free binary codes using Huffman Coding such that the total cost of encoding is minimized.

---

## Technique Used

Greedy Algorithm

---

## Data Structures Used

- Min Heap (Priority Queue)
- Binary Tree

---

## Algorithm

1. Read the number of characters `n`.
2. Read the frequencies of all characters.
3. Create a leaf node for each frequency and insert it into a min heap.
4. While more than one node exists in the heap:
   - Remove the two nodes with the smallest frequencies.
   - Create a new internal node with frequency equal to their sum.
   - Insert the new node back into the heap.
5. Traverse the Huffman tree:
   - Left child → `0`
   - Right child → `1`
6. Print the Huffman codes at each leaf node.

---

## Properties of Huffman Coding

- Huffman codes are prefix-free.
- Characters with higher frequencies get shorter codes.
- Ensures optimal data compression.

---

## Time and Space Complexity

- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(n)`

---

## Output

Displays the generated Huffman codes for the given frequencies.
