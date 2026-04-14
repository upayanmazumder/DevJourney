# String Matching - Rabin Karp

## Idea

Rabin Karp compares hash values instead of direct substring comparison at every shift.
If hash matches, then we verify character by character (to handle hash collisions).

## Input

1. Text string
2. Pattern string

## Steps in code

1. Compute hash of pattern and first text window of same length.
2. Slide pattern over text one position at a time.
3. If hash matches, do direct character check.
4. Use rolling hash to update text window hash in \(O(1)\).

## Time Complexity

- Average: \(O(n + m)\)
- Worst (many collisions): \(O(nm)\)

## Space Complexity

- \(O(1)\) extra (excluding input strings)
