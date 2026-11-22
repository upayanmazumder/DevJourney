# FAT algorithm notes

See [EXPLANATIONS.md](../CAT-2/EXPLANATIONS.md) for the twelve reused CAT-2 topics.
Counts and lengths must fit available memory. Enumeration can produce exponential output.
String algorithms operate on Java `char` values (UTF-16 code units), not Unicode code
points.
Space bounds below count working memory only. A program that buffers its answer in a
StringBuilder also needs memory proportional to the printed output; that buffer is added
on top of the stated working-space bound unless the note says otherwise.

## 1. Sieve of eratosthenes

[Source](01_SieveOfEratosthenes.java)

**Summary:** Marks multiples of each prime starting at its square, leaving all primes up to n in one compact boolean array.

**Input:** n (int).

**Output:** all primes in [2, n], space-separated on one line. empty line if n < 2.

**Example:** `input "30" -> output "2 3 5 7 11 13 17 19 23 29"`

**Example:** `input "1" -> empty line`

### Algorithm

1. If n < 2, print an empty line.
2. Allocate a boolean composite array of size n+1.
3. For p from 2 while `p * p <= n`: if p is unmarked, mark `p * p`, `p * p + p`, ...
   as composite. The multiple counter is a `long`, so it cannot overflow an int near the
   top of the range.
4. Print every unmarked index from 2 to n.

**Complexity:** `O(n log log n)` time and `O(n)` working space, plus the buffered output.

**Supported domain:** 2 <= n <= Integer.MAX_VALUE - 1 (the boolean array has n + 1
elements), subject to available heap. About 10^7 (roughly 10 MB for the array) is a
comfortable practical limit; use the segmented sieve for larger n when heap is tight.

## 2. Segmented sieve

[Source](02_SegmentedSieve.java)

**Summary:** Sieves the interval in fixed blocks using base primes up to sqrt(h), so large ranges avoid one huge boolean array.

**Input:** l h (ints).

**Output:** all primes in [l, h], space-separated. empty line if h < 2, l > h, or the
interval contains no primes.

**Example:** `input "10 30" -> "11 13 17 19 23 29"`

**Example:** `input "-5 10" -> "2 3 5 7"`

**Example:** `input "1 1" -> empty line`

**Example:** `input "8 10" -> empty line (no primes in the interval)`

### Algorithm

1. Clamp the lower bound to 2 (so l <= 1 is handled). reject h < 2 or l > h.
2. Build base primes up to floor(sqrt(h)) with a simple sieve.
3. Split [l, h] into blocks of 2^20 numbers.
4. For each base prime p, start at `max(p * p, ceil(lo / p) * p)` and mark multiples in
   the block.
5. Print every unmarked number in the block.

**Complexity:** `O((h-l+1) log log h)` time for the blocks plus `O(sqrt(h) log log h)` for
the base sieve. `O(sqrt(h) + block size)` working space, plus the buffered output.

**Supported domain:** 0 <= h <= Integer.MAX_VALUE, l <= h, any int l. practical limit is output/time for very wide ranges.

## 3. Euler's totient function

[Source](03_EulerPhi.java)

**Summary:** Factors n, multiplying the result by (1 - 1/p) for each distinct prime factor to count coprime integers below n.

**Input:** n (int).

**Output:** phi(n) (int). prints 0 for n <= 0.

**Example:** `input "48" -> "16"`

**Example:** `input "1" -> "1"`

**Example:** `input "13" -> "12"`

### Algorithm

1. Initialize result = n and a trial divisor p = 2.
2. While `p * p <= n`: if p divides n, divide out every factor p and apply
   result -= result / p.
3. If the remaining n > 1, it is a final prime factor. apply result -= result / n.
4. Print result.

**Complexity:** `O(sqrt(n)) time, O(1) space.`

**Supported domain:** 1 <= n <= Integer.MAX_VALUE.

## 4. Chinese remainder theorem, generalized

[Source](04_ChineseRemainderTheorem.java)

**Summary:** Merges congruences pairwise with gcd checks and modular inverses, so moduli may share factors and inconsistency is detected.

**Input:** k, then k lines/pairs "modulus remainder" (BigInteger values).

**Output:** least nonnegative solution x (BigInteger), or "No solution". `k <= 0` prints 0,
and a nonpositive modulus prints "No solution".

**Example (coprime) input:**

```text
3
3 2
4 3
5 1
```

Expected output: `11`.

**Example (non-coprime) input:**

```text
2
4 2
6 4
```

Expected output: `10`.

**Example (inconsistent) input:**

```text
2
2 1
4 2
```

Expected output: `No solution`.

### Algorithm

1. Maintain one congruence x = A (mod M), starting with A = 0, M = 1.
2. For each (m, a): reject m <= 0. normalize a mod m. compute g = gcd(M, m).
3. If (a - A) is not divisible by g, no solution exists.
4. Otherwise set m' = m/g and solve `(M / g) * t = (a - A) / g` (mod m') with a
   modular inverse (t = 0 when m' = 1).
5. Update `A = A + M * t` and `M = M * m'`, reducing A modulo the new M.
6. After all pairs, print A mod M.

**Complexity:** `O(k)` BigInteger merge steps, with cost set by the BigInteger
multiplication and inverse algorithms. `O(1)` BigInteger variables (each `O(log M)` bits).

**Supported domain:** k >= 1. 1 <= modulus. any BigInteger remainder (normalized mod m). Moduli need not be pairwise coprime.

## 5. Strobogrammatic number check

[Source](05_StrobogrammaticCheck.java)

**Summary:** Compares paired digits from both ends under the 180-degree rotation map 0,1,8 self and 6<->9.

**Input:** one non-empty digit string.

**Output:** true or false (lowercase).

**Example:** `input "69" -> "true"`

**Example:** `input "18081" -> "true"`

**Example:** `input "962" -> "false"`

### Algorithm

1. Point i at the first digit and j at the last.
2. While i <= j, accept only the pairs (0,0), (1,1), (8,8), (6,9), (9,6).
3. Move inward. any other pair or character fails immediately.
4. If all pairs pass, the string is strobogrammatic.

**Complexity:** `O(len) time, O(1) extra space.`

**Supported domain:** any non-empty digit string (leading zeros are treated as ordinary digits. this is a string test, not a canonical-number test).

## 6. Strobogrammatic number generation

[Source](06_StrobogrammaticGenerate.java)

**Summary:** Builds numbers from the outside inward using rotation pairs, skipping a leading zero at the outermost position.

**Input:** n, the required length (int).

**Output:** all strobogrammatic numbers of length n, space-separated. empty line if n <= 0.

**Example:** `input "1" -> "0 1 8"`

**Example:** `input "2" -> "11 69 88 96"`

**Example:** `input "3" -> "101 111 181 609 619 689 808 818 888 906 916 986"`

### Algorithm

1. Allocate a char array of length n.
2. Recursively fill position i and its mirror n-1-i.
3. At the center (i == j) use 0, 1 or 8. when i > j emit the completed number.
4. At outer positions try pairs (0,0), (1,1), (6,9), (8,8), (9,6), but skip
   (0,0) at position 0 so no number except the single-digit "0" starts with 0.
5. Join emitted numbers with spaces.

**Complexity:** `O(n * 5^(n/2))` time and output size. `O(n)` recursion/array working space,
plus the buffered output.

**Supported domain:** 1 <= n <= 8 recommended (output grows exponentially. n = 8 produces 500 numbers).

## 7. Binary palindrome

[Source](07_BinaryPalindrome.java)

**Summary:** Finds the highest set bit and compares mirrored bit pairs, testing the binary representation without building a string.

**Input:** n (nonnegative long).

**Output:** true or false.

**Example:** `input "9" -> "true"   (1001)`

**Example:** `input "10" -> "false" (1010)`

**Example:** `input "0" -> "true"`

### Algorithm

1. If n < 0, return false.
2. Let hi be the index of the highest set bit (63 - leading zeros). n = 0 has
   no set bit and is the palindrome "0".
3. For lo from 0 while lo < hi, compare bit lo with bit hi. return false on a
   mismatch and move both indices inward.
4. Return true if every mirrored pair matches.

**Complexity:** `O(log n)` time, at most 31 mirrored bit comparisons for a nonnegative long, `O(1)` space.

**Supported domain:** 0 <= n <= Long.MAX_VALUE.

## 8. Toggle the switch

[Source](08_ToggleSwitch.java)

**Summary:** After all passes only perfect-square positions are toggled an odd number of times, so count them with exact integer square root.

**Input:** n (nonnegative long), the number of switches/passes.

**Output:** count of switches left on, equal to floor(sqrt(n)).

**Example:** `input "3" -> "1"`

**Example:** `input "9" -> "3"`

**Example:** `input "0" -> "0"`

**Example:** `input "9223372036854775807" -> "3037000499"`

### Algorithm

1. Switch i is toggled once per divisor of i, hence an odd number of times
   exactly when i is a perfect square.
2. Count perfect squares in [1, n] as floor(sqrt(n)).
3. Compute it by binary search on [1, 3037000499], testing mid <= n/mid to
   avoid overflow (no floating point).

**Complexity:** `O(log n) time, O(1) space.`

**Supported domain:** 0 <= n <= Long.MAX_VALUE (exact. no double rounding).

## 9. Alice apple tree

[Source](09_AliceAppleTree.java)

**Summary:** Binary-searches the smallest ring radius whose cumulative apple count reaches the target, then prints eight times that radius.

**Input:** neededApples (nonnegative long).

**Output:** minimum perimeter (BigInteger).

**Example:** `input "1" -> "8"`

**Example:** `input "13" -> "16"`

**Example:** `input "1000000000" -> "5040"`

**Example:** `input "0" -> "0"`

### Algorithm

1. Ring r contributes `12 * r^2` apples, so rings 1..r total
   `2 * r * (r + 1) * (2 * r + 1)`.
2. Double an upper bound r until its apple total reaches neededApples.
3. Binary-search the smallest r whose total is >= neededApples.
4. Print `8 * r` (the side length times four) using BigInteger.

**Complexity:** `O(log r)` iterations with `O(1)` BigInteger values (each `O(log r)` bits).
`r <= 1321123` for any nonnegative long input. `O(1)` extra working space, plus the
BigInteger values.

**Supported domain:** 0 <= neededApples <= Long.MAX_VALUE. Apple totals and the perimeter use BigInteger, so intermediate arithmetic cannot overflow.

## 10. Numeric-aware natural string sorting

[Source](10_NaturalSort.java)

**Input:** n, then n lines (each line is one string. spaces and empty lines are kept).

**Output:** The n strings in natural order, one per line.

### Example input

```text
5
file10
file2
file1
file02
file2a
```

### Example output

```text
file1
file2
file2a
file02
file10
```

### Algorithm

1. Read n and then exactly n lines into a list.
2. Compare two strings left to right.
3. When both current characters are digits, consume the whole digit run in
   each string.
4. Strip leading zeros (keeping one digit) and compare run lengths, then the
   digits lexicographically. This compares numeric values without parsing,
   so arbitrarily long runs cannot overflow.
5. Equal numeric values are ordered by fewer leading zeros first, then the
   scan continues. This makes the ordering deterministic for runs such as
   "2" and "02".
6. Otherwise compare the two characters directly. If one string ends first,
   the shorter remaining suffix sorts first.
7. Sort with this comparator and print each line.

**Complexity:** `O(n log n * L) time for n strings of maximum length L. O(total input characters + n) space.`

**Notes:** Comparison is case-sensitive and stable. n = 0 prints nothing.

## 11. Comparator demo with student records

[Source](11_StudentComparator.java)

**Input:** n, then n triples: roll name age.

**Output:** The same records sorted by name, then age, then roll (final tie-break only for determinism), one record per line as "roll name age".

### Example input

```text
3
101 Ram 18
102 Shyam 22
103 Mohan 19
```

### Example output

```text
103 Mohan 19
101 Ram 18
102 Shyam 22
```

### Algorithm

1. Read each student into a record.
2. Build a chained Comparator: name ascending, then age ascending, then roll
   ascending.
3. Sort and print roll, name, age.

**Complexity:** `O(n log n)` time. `O(n)` working space, plus the buffered output.
`n = 0` prints nothing.

## 12. Quicksort (Lomuto partition)

[Source](12_Quicksort.java)

**Input:** n, then n integers.

**Output:** The integers in nondecreasing order, space separated on one line.

### Example input

```text
6
10 80 30 90 40 50
```

### Example output

```text
10 30 40 50 80 90
```

### Algorithm

1. Read the array.
2. Choose the last element as pivot.
3. Partition so smaller elements move left of the pivot.
4. Recurse into the smaller partition and loop on the larger one. This preserves
   Lomuto partitioning while keeping the stack depth logarithmic even for sorted input.
5. Print the sorted array.

**Complexity:** `O(n log n)` average and `O(n^2)` worst-case time. The bounded recursion
uses `O(log n)` stack space in the worst case (previously `O(n)`). `O(1)` extra working
space otherwise, plus the buffered output. `n = 0` prints an empty line.

## 13. Selection sort

[Source](13_SelectionSort.java)

**Input:** n, then n integers.

**Output:** The integers in nondecreasing order, space separated on one line.

### Example input

```text
5
64 25 12 22 11
```

### Example output

```text
11 12 22 25 64
```

### Algorithm

1. For each position i, scan the unsorted suffix for its minimum.
2. Swap that minimum into position i.
3. Repeat until the array is sorted.

**Complexity:** `O(n^2)` time in all cases. `O(1)` extra working space, plus the buffered
output. `n = 0` prints an empty line.

## 14. Move all hyphens to the front of a line

[Source](14_MoveHyphens.java)

**Input:** One full line (may contain spaces and hyphens. may be empty).

**Output:** One line with all '-' characters first, followed by the other characters in their original relative order.

### Example input

```text
FACE-PREP
```

### Example output

```text
-FACEPREP
```

### Algorithm

1. Read the entire line.
2. Count hyphens and collect every non-hyphen character in order.
3. Emit that many hyphens, then the collected characters.

**Complexity:** `O(L) time and O(L) space for line length L.`

**Notes:** The transformation is stable: non-hyphen characters keep their order.

## 15. Manacher's algorithm for the longest palindromic substring

[Source](15_ManacherLongestPalindrome.java)

**Input:** One full line (the string. may be empty).

**Output:** The longest palindromic substring, or an empty line for empty input. When several longest palindromes exist, the leftmost one is printed.

### Example input

```text
abcababacs
```

### Example output

```text
cababac
```

### Example input

```text
abba
```

### Example output

```text
abba
```

### Algorithm

1. Build an integer transformed array with a separator between characters
   and distinct integer sentinels at both ends. The separators and sentinels
   are negative values, so they cannot collide with any UTF-16 code unit.
2. For each transformed center, reuse the mirrored palindrome radius when it
   lies inside the current rightmost palindrome.
3. Expand directly only beyond that boundary, then update the rightmost
   palindrome.
4. Take the largest radius. convert its center and radius back to the start
   and length in the original string.
5. Print that substring. Empty input prints an empty line.

**Complexity:** `O(L) time and O(L) space for string length L.`

## 16. All distinct permutations in sorted lexicographic order

[Source](16_SortedUniquePermutations.java)

**Input:** One full line (characters are permuted, including spaces).

**Output:** Every unique permutation on its own line, in ascending lexicographic order. Empty input prints one empty line.

### Example input

```text
baba
```

### Example output

```text
aabb
abab
abba
baab
baba
bbaa
```

### Algorithm

1. Convert the line to a char array and sort it. this is the first
   permutation.
2. Print the current permutation.
3. Find the rightmost ascent, swap its pivot with the smallest larger
   character to its right, then reverse the suffix.
4. Repeat until no ascent remains.

**Complexity:** `O(k * L)` time for k distinct permutations of length L, plus output size.
`O(L)` working space, plus the buffered output.

## 17. Positional combinations nCr

[Source](17_Combinations.java)

**Input:** n, then n integers, then r.

**Output:** Every r-element combination chosen by position, preserving input order, one
combination per line, values space separated. `r = 0` prints one empty line. `r < 0` or
`r > n` prints nothing.

### Example input

```text
5
1 2 3 4 5
3
```

### Example output

```text
1 2 3
1 2 4
1 2 5
1 3 4
1 3 5
1 4 5
2 3 4
2 3 5
2 4 5
3 4 5
```

### Algorithm

1. Read the values and r.
2. Recursively choose an index for each output position. after choosing index
   i, only indices greater than i may follow.
3. At depth r, print the chosen values.
4. Bound the loop so enough elements always remain to finish the combination.

**Complexity:** `O(C(n,r) * r) time. O(n + r) extra space (excluding output).`

## 18. Josephus survivor

[Source](18_Josephus.java)

**Input:** positive `int` n and positive `long` k.

**Output:** The 1-based position of the survivor.

### Example input

```text
14 2
```

### Example output

```text
13
```

### Algorithm

1. Track the 0-based survivor for a circle of size 1, initially 0.
2. For each size from 2 to n, update survivor = (survivor + k mod size) mod size.
   Reducing k first keeps the addition below `2 * size`, so k can be any long.
3. Print survivor + 1.

**Complexity:** `O(n) time. O(1) space. k is read as long, so large steps do not overflow during the modular arithmetic.`

## 19. Number of down/right paths in a rows x cols grid (BigInteger DP)

[Source](19_ManeuveringPaths.java)

**Input:** positive rows and cols.

**Output:** The exact number of paths from the top-left to the bottom-right cell. If rows
or cols is nonpositive, prints nothing.

### Example input

```text
3 3
```

### Example output

```text
6
```

### Example input

```text
30 30
```

### Example output

```text
30067266499541040
```

### Algorithm

1. Keep one DP row of BigInteger values, all initialized to 1 for the first
   row.
2. For every later row and column, add the value from the left to the value
   from above: dp[c] = dp[c] + dp[c-1].
3. Print the final cell.

**Complexity:** `O(rows * cols) BigInteger additions. O(cols) space. BigInteger keeps results exact for large grids.`

## 20. Rat in a maze, down/right moves only

[Source](20_RatMaze.java)

**Input:** n, then `n * n` values (0 = blocked, 1 = open), row by row.

**Output:** One solution as an `n x n` grid of 0/1 cells, where 1 marks the path, or
exactly "No solution". The start cell must be open.

### Example input

```text
4
1 0 0 1
1 0 1 0
1 1 1 1
0 1 0 1
```

### Example output

```text
1 0 0 0
1 0 0 0
1 1 1 1
0 0 0 1
```

### Example (blocked start)

```text
1
0
```

### Example output

```text
No solution
```

### Algorithm

1. Start at (0,0). Reject out-of-grid, blocked, or already-used cells.
2. Mark the cell as part of the path.
3. If it is the bottom-right cell, the path is complete.
4. Otherwise try down, then right.
5. If neither works, unmark the cell and backtrack.

**Complexity:** `O(C(2n-2, n-1))` time in the worst case (the number of down/right paths),
which is exponential in n. `O(n^2)` space. Only down and right moves are considered, so
the search cannot cycle.

## 21. All N-Queens solutions as 0/1 boards

[Source](21_NQueens.java)

**Input:** positive n.

**Output:** Every solution as an `n x n` board of 0/1 rows (1 = queen), boards separated
by one blank line, in ascending queen-column search order. If there are none, print
exactly "No solution". `n <= 0` also prints "No solution".

### Example input

```text
4
```

### Example output

```text
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0

0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0
```

### Example input

```text
2
```

### Example output

```text
No solution
```

### Algorithm

1. Place one queen per row, trying columns left to right.
2. Reject a column already used, or a used row+col diagonal, or a used
   row-col+n-1 diagonal.
3. Mark the three constraints, recurse to the next row, then unmark them.
4. At row n, print the board.

**Complexity:** `O(n * n! + S * n^2) time including S printed solutions, O(n) extra space plus output. n = 1 produces the single board "1".`

## 22. Knight's tour using Warnsdorff's heuristic

[Source](22_WarnsdorffKnightTour.java)

**Input:** n startRow startCol, with zero-based coordinates. The valid domain is `n >= 1`
and `0 <= startRow, startCol < n`.

**Output:** An `n x n` board numbered `1..n*n` in move order, or exactly "No tour found".
The starting square is always marked 1. If `n <= 0` or the start is outside the board,
prints exactly "No tour found".

### Example input

```text
8 0 0
```

**Output:** a full 8 x 8 numbered tour beginning with 1 at the top-left corner (the exact board is deterministic because ties use the fixed move order).

### Example input

```text
1 0 0
```

### Example output

```text
1
```

### Algorithm

1. Validate the start and mark it as move 1.
2. For each next move, inspect the up to eight legal unvisited knight
   destinations.
3. For each candidate, count its onward unvisited destinations.
4. Move to the candidate with the smallest onward count. ties use the fixed
   move order (2,1), (1,2), (-1,2), (-2,1), (-2,-1), (-1,-2), (1,-2), (2,-1).
5. Continue until `n * n` squares are numbered, or until no candidate remains.
6. Print the numbered board, or "No tour found".

**Complexity:** `O(n^2)` time (each step inspects 8 candidates, each with 8 onward
checks). `O(n^2)` space.

**Notes:** Warnsdorff's rule is a heuristic, not a proof. "No tour found" means this greedy run got stuck and does NOT assert that no tour exists. The start square is explicitly assigned 1, so it is never left as an unmarked 0.

## 23. Block swap rotation

[Source](23_BlockSwapRotation.java)

**Input:** n d, followed by n integers. n must be nonnegative. d may be negative or
larger than n, because it is reduced modulo n.

**Output:** The array rotated left by d positions, on one line. `n = 0` prints an empty
line.

**Example:** `"7 2 1 2 3 4 5 6 7" -> "3 4 5 6 7 1 2"`

### Algorithm

1. Normalize d modulo n. An empty array needs no rotation.
2. Divide the array into left and right blocks at d.
3. Swap the smaller block with an equal-sized part of the larger block.
4. Reduce the unfinished block until both lengths match.
5. Swap the final equal blocks.

**Complexity:** `O(n)` time and `O(1)` extra space. Negative d rotates right. Multiples of
n leave the array unchanged.
