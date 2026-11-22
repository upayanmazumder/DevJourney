# CAT-2 algorithm notes

FAT preparation also uses these algorithms.
See [EXPLANATIONS.md](../FAT/EXPLANATIONS.md) for the additional downloaded topics.
See [README.md](../README.md) for differences between these programs and downloaded variants.

Each program reads whitespace-separated tokens and prints one result without a prompt.
The numeric domain in each section is the range the program supports exactly.
Products and sums are not allowed to wrap silently; the programs below use 64-bit or
arbitrary-precision arithmetic where the input range requires it.
Literal examples show the complete input followed by the expected output.

## 1. Booth's algorithm

**Summary:** Multiplies signed binary integers efficiently by examining adjacent multiplier bits and reducing repeated additions through arithmetic shifts.

**Numeric domain:** `m` and `q` are signed 32-bit integers. The exact signed 64-bit product
is printed for every pair, including `-2147483648 * -2147483648`. The accumulator occupies
33 bits and is held in a `long`, so a `MIN_VALUE` multiplicand cannot overflow it.

### Algorithm

1. Initialize accumulator A, multiplier Q, multiplicand M, and previous bit Q-1 to zero.
2. For 32 iterations, inspect Q0 and Q-1.
3. 10: subtract M. 01: add M. 00/11: do nothing.
4. Arithmetic-right-shift the combined A,Q,Q-1.
5. Output the combined signed result.

**Example**

```text
Input:  6 -7
Output: -42
```

Extreme case: `-2147483648 -2147483648` prints `4611686018427387904`.

## 2. Euclid's algorithm

**Summary:** Repeatedly replaces two numbers with divisor and remainder until the remainder becomes zero; the divisor is their greatest common divisor.

**Numeric domain:** `a` and `b` are signed 64-bit integers. The result is the exact
nonnegative gcd. Because `Long.MIN_VALUE` has absolute value `2^63`, the input is widened to
`BigInteger`; `-9223372036854775808 0` prints `9223372036854775808`. `0 0` prints `0`.

### Algorithm

1. Take the absolute value of both numbers as arbitrary-precision integers.
2. While b is nonzero, replace (a,b) with (b,a mod b).
3. Print a.

**Example**

```text
Input:  48 18
Output: 6
```

## 3. Karatsuba algorithm

**Summary:** Recursively multiplies large integers using three products instead of four, reducing work compared with schoolbook multiplication.

**Numeric domain:** `x` and `y` are signed 64-bit integers. Negative inputs are multiplied by
magnitude and the sign is applied afterwards. The product is computed with `BigInteger`, so it
is exact even when it exceeds 64 bits.

### Algorithm

1. Split each magnitude into high and low halves at a power of ten.
2. Compute ac, bd, and (a+b)(c+d).
3. Derive cross term as (a+b)(c+d)-ac-bd.
4. Combine using powers of ten.
5. Recurse until one factor is a single digit.

**Example**

```text
Input:  1234 5678
Output: 7006652
```

Negative input: `-12 34` prints `-408`.
Beyond 64 bits: `9223372036854775807 2` prints
`18446744073709551614`.

## 4. Longest sequence of 1 after flipping a bit

**Summary:** Finds the longest run of ones obtainable by changing at most one zero bit into one using a single bit scan.

**Numeric domain:** One signed 32-bit integer, interpreted as its 32-bit two's-complement bit
pattern. The answer is in `0..32`; all 32 bits set (`-1`) prints `32` because at most one bit
may be flipped and no flip is needed. All zero bits (`0`) prints `1`.

### Algorithm

1. Read the integer and inspect its 32 bits from least significant to most significant.
2. Track the current run and the run before the latest zero.
3. Treat one zero as flipped and combine adjacent runs.
4. Keep the maximum, capped at 32.

**Example**

```text
Input:  5
Output: 3
```

Binary `101` becomes `111` after one flip. Input `-1` prints `32`.

## 5. Swap two nibbles in a byte

**Summary:** Exchanges the upper and lower four-bit halves of one byte using masking, shifting, and bitwise OR operations.

**Numeric domain:** The input is read as a signed 32-bit integer, but only its low eight bits
participate. Thus both signed byte values (`-128..127`) and unsigned byte values (`0..255`) are
accepted, and the output is always in `0..255`. Larger inputs use their low byte; this is
documented masking, not silent truncation of a valid byte.

### Algorithm

1. Mask the lower nibble and shift it left four positions.
2. Mask the upper nibble and shift it right four positions.
3. OR both results.

**Examples**

```text
Input:  171
Output: 186
```

`0xAB` becomes `0xBA`.

```text
Input:  255
Output: 255
```

## 6. Block swap algorithm

**Summary:** Rotates an array by repeatedly swapping the smaller of two adjacent blocks with part of the larger block.

**Numeric domain:** `n >= 0` and `d` is any signed 32-bit integer. Rotation is to the left;
`d` is reduced with `Math.floorMod`, so a negative `d` rotates right. `n = 0` reads `d` but
prints nothing, and multiples of `n` leave the array unchanged. Array elements are signed
32-bit integers. Each output element is followed by a space.

### Algorithm

1. Read n, d, and the n elements.
2. If n is zero, stop. Otherwise reduce d modulo n into `0..n-1`.
3. Compare the sizes of the two remaining blocks.
4. Swap the smaller block with the adjacent part of the larger block and shrink the larger
   block.
5. When the blocks are equal, swap them once more. Time O(n), extra space O(1).

**Examples**

```text
Input:  5 2
        1 2 3 4 5
Output: 3 4 5 1 2
```

```text
Input:  5 -1
        1 2 3 4 5
Output: 5 1 2 3 4
```

Input `0 7` prints no output.

## 7. Max product subarray

**Summary:** Tracks maximum and minimum products because negative values can exchange their roles and create the largest final product.

**Numeric domain:** `n >= 0` and every element is a signed 64-bit integer. Products are
computed with `BigInteger`, so the answer is exact even when it exceeds 64 bits. For `n = 0`
the program prints `0` because there is no nonempty subarray.

### Algorithm

1. Maintain maximum and minimum products ending at the current position.
2. If current value is negative, swap maximum and minimum.
3. Update both using current value and multiplication.
4. Track the global maximum.

**Examples**

```text
Input:  3
        -2 -3 4
Output: 24
```

The whole array `-2 * -3 * 4` is the maximum product.

Input `0` prints `0`.

Beyond 64 bits:

```text
Input:  3
        2147483647 2147483647 2147483647
Output: 9903520300447984150353281023
```

## 8. Maximum sum of hourglass in matrix

**Summary:** Checks every 3x3 matrix window, sums its seven hourglass cells, and returns the largest sum found.

**Numeric domain:** Exactly 36 signed 32-bit integers in row-major order. Each seven-cell sum
and the answer are computed in 64-bit `long`, so the largest possible sum
`7 * 2147483647 = 15032385529` is exact.

### Algorithm

1. Read the 6x6 matrix.
2. Visit every possible top-left position from 0 to 3.
3. Add the seven hourglass elements.
4. Keep the maximum sum.

**Example**

```text
Input:  1 1 1 0 0 0
        0 1 0 0 0 0
        1 1 1 0 0 0
        0 0 0 0 0 0
        0 0 0 0 0 0
        0 0 0 0 0 0
Output: 7
```

All 36 cells zero prints `0`.

Maximum 32-bit cells:

```text
Input:  2147483647 2147483647 2147483647 0 0 0
        0 2147483647 0 0 0 0
        2147483647 2147483647 2147483647 0 0 0
        0 0 0 0 0 0
        0 0 0 0 0 0
        0 0 0 0 0 0
Output: 15032385529
```

## 9. Max equilibrium sum

**Summary:** Finds the largest sum where elements strictly left and right of one position have equal totals.

**Numeric domain:** `n >= 0` and every element is a signed 64-bit integer. Prefix and suffix
sums are computed with `BigInteger`, so they cannot overflow. A valid equilibrium sum equal to
`Long.MIN_VALUE` is printed exactly rather than being confused with the no-result marker.
Output ambiguity remains by design: when no equilibrium index exists, the program prints `0`,
which is also a valid equilibrium sum. An empty array (`n = 0`) prints `0`.

### Algorithm

1. Compute total array sum.
2. Scan each element and remove it from the right sum.
3. Compare left and right sums.
4. If equal, update the maximum equilibrium sum.
5. Add the current element to the left sum.

**Examples**

```text
Input:  3
        1 3 1
Output: 1
```

```text
Input:  1
        0
Output: 0
```

The second output is ambiguous: `0` is both a valid equilibrium sum and the no-result marker.

A valid `Long.MIN_VALUE` sum is preserved:

```text
Input:  3
        -9223372036854775808 0 -9223372036854775808
Output: -9223372036854775808
```

## 10. Leaders in array

**Summary:** An element is a leader when no element to its right is greater; scan backwards while tracking the maximum.

**Numeric domain:** `n >= 0` and every element is a signed 32-bit integer. Comparison uses
`>=`, so equal values to the right are not greater and can all be leaders. Output is in
original order, each element followed by a space; `n = 0` prints no output.

### Algorithm

1. Start from the last element.
2. Track the maximum seen from the right.
3. Store an element when it is at least that maximum.
4. Reverse stored leaders for original order.

**Examples**

```text
Input:  6
        16 17 4 3 5 2
Output: 17 5 2
```

```text
Input:  3
        5 5 5
Output: 5 5 5
```

## 11. Majority element

**Summary:** Boyer-Moore voting finds a candidate, then verifies its frequency to ensure it actually exceeds half the array.

**Numeric domain:** `n >= 0` and every element is a signed 32-bit integer. The candidate is
printed only when its frequency is strictly greater than `n/2`; otherwise the program prints
`-1`. Output ambiguity remains by design: `-1` is also a valid element value, so an actual
majority of `-1` produces the same output as no majority. `n = 0` prints `-1`.

### Algorithm

1. Maintain a candidate and vote count.
2. Reset candidate when count becomes zero.
3. Increase votes for matches and decrease them otherwise.
4. Count the candidate again.
5. Print it only when its frequency exceeds n/2; otherwise print -1.

**Examples**

```text
Input:  5
        2 2 1 1 2
Output: 2
```

```text
Input:  3
        1 2 3
Output: -1
```

```text
Input:  3
        -1 -1 -1
Output: -1
```

The last two outputs are indistinguishable: no majority and a real majority of `-1`.

## 12. Lexicographically first palindromic string

**Summary:** Counts Unicode code points, builds the smallest possible first half, places one odd character centrally, then mirrors it.

**Numeric domain:** One nonempty whitespace-free token. The program counts Unicode code
points, not UTF-16 code units, so characters outside the Basic Multilingual Plane (including
emoji) are handled correctly and cannot index past a 256-entry table. Output is the
lexicographically first palindrome by code point, or `Not possible` when more than one code
point has odd frequency.

### Algorithm

1. Count every Unicode code point.
2. If more than one code point has odd frequency, a palindrome is impossible.
3. Append each code point half its frequency in ascending code-point order.
4. Place the only odd code point in the middle.
5. Append the reverse of the first half, reversing by code point.

**Examples**

```text
Input:  aabb
Output: abba
```

```text
Input:  abc
Output: Not possible
```

```text
Input:  ééa
Output: éaé
```

Supplementary characters work too: `😀😀a` prints `😀a😀`.
