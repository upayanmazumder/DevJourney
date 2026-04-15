# String Matching - KMP

## Algorithm

1. Read text and pattern.
2. Build LPS array for pattern.
3. Start two indices: i for text, j for pattern.
4. If characters match, move both i and j.
5. If j reaches pattern length, report one match and set j = LPS[j-1].
6. On mismatch:
   - If j is not 0, set j = LPS[j-1].
   - Else move i.
7. Continue until end of text.

## Time Complexity

- O(n + m)

## Space Complexity

- O(m)
