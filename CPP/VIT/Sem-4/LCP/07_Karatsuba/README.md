# Karatsuba Integer Multiplication (Divide & Conquer)

Problem
- Multiply two large integers faster than the naive O(n^2) schoolbook algorithm.

Key idea (intuition)
- Split each n-digit number into high and low halves. Instead of four multiplications of halves, compute only three recursive multiplications using the identity:
	- `z2 = high1 * high2`
	- `z0 = low1 * low2`
	- `z1 = (high1 + low1) * (high2 + low2) - z2 - z0`
	Combine with appropriate digit shifts to form the full product. This reduces multiplicative work.

Complexity
- Time: O(n^{log2(3)}) ≈ O(n^{1.585})
- Space: O(n) (depending on representation and recursion depth)

Worked example
```
1234 * 5678 = 7006652
```
The implementation uses string-based splitting and recursive multiplication; it is primarily educational to show divide-and-conquer speedup.

Notes
- For very large numbers and production code, use FFT-based multiplication (Schönhage–Strassen) or big-integer libraries.

Code: `main.cpp` — recursive Karatsuba implementation.
