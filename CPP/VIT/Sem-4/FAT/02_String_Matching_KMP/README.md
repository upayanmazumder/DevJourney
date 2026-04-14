# String Matching - KMP

## Idea

KMP avoids re-checking characters by using the LPS array (Longest Prefix which is also Suffix).
When mismatch occurs, pattern index jumps using LPS instead of restarting from 0.

## Input

1. Text string
2. Pattern string

## Steps in code

1. Build LPS array for pattern.
2. Traverse text and pattern together.
3. On match, move both indices.
4. On mismatch:
   - If pattern index is not zero, jump to `lps[j-1]`.
   - Else move text index.

## Time Complexity

- \(O(n + m)\)

## Space Complexity

- \(O(m)\) for LPS array
