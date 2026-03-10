# Karatsuba Integer Multiplication (Divide & Conquer)

Problem
- Multiply large integers faster than O(n^2) schoolbook multiplication.

Algorithm
- Karatsuba: split numbers into high/low halves and compute three recursive products: z2 = high*high, z0 = low*low, z1 = (high+low)*(high+low) - z2 - z0. Combine with digit shifts.

Time complexity: O(n^{log2(3)}) ~ O(n^{1.585})
Space complexity: O(n)

Input format (example):
```
12345678
87654321
```

Code: [main.cpp](main.cpp)
