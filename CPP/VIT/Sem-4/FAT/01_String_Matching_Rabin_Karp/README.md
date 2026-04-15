# String Matching - Rabin Karp

## Algorithm

1. Read text and pattern.
2. Compute hash of pattern.
3. Compute hash of first window of text (window size = pattern length).
4. Compare both hashes.
5. If hashes are equal, compare characters one by one to confirm match.
6. Slide window by 1 position using rolling hash.
7. Repeat until all windows are checked.

## Time Complexity

- Average: O(n + m)
- Worst: O(nm)

## Space Complexity

- O(1)
