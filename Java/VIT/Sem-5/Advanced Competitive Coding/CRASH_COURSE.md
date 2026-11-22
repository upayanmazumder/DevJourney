# ACC in three hours: recognize, build, check

**Goal:** recognize the 35 repository programs and reconstruct their main logic from a few reusable patterns.
You do not need to memorize 35 complete files.
Three hours cannot guarantee mastery of every variation or hidden test.
Use the statement, constraints, and required algorithm together. A sample alone does not identify the problem.

This sheet covers [CAT-2](CAT-2/README.md) and [FAT](FAT/README.md).
The downloaded syllabus also lists incremental sieve, weighted substring, and Hamiltonian cycle.
Those three have no imported source here. This sheet does not claim complete syllabus coverage.
The downloaded syllabus lists 30 MCQs and two coding questions for FAT, with a 90-minute duration.
That is the supplied document's pattern, not confirmation of tomorrow's format.

## 1. Your 180-minute route

Priorities below reflect learning cost and reuse, not predicted exam frequency.
Set a timer. Write code during each block instead of only reading.

| Minutes | Learn and do                                                             | Exit test                                              |
| ------- | ------------------------------------------------------------------------ | ------------------------------------------------------ |
| 0–25    | Java scaffold, input, loops, arrays, methods, output                     | Type the array program below without copying           |
| 25–50   | Array scans: leaders, majority, equilibrium, maximum product, hourglass  | Explain each stored variable before writing its update |
| 50–70   | GCD, sieve, phi, switches, apple perimeter, Josephus                     | Trace GCD and one sieve by hand                        |
| 70–90   | Binary operators, palindrome, nibble swap, bit flip, rotation            | Solve nibble swap and a three-element rotation         |
| 90–115  | Character counts, palindrome construction, hyphens, sorting, comparators | Distinguish three palindrome questions and two sorts   |
| 115–140 | Recursion, combinations, permutations, grid DP, maze, queens             | Trace one choose → recurse → undo sequence             |
| 140–160 | Booth, Karatsuba, CRT, Manacher, Warnsdorff                              | Recall each method's essential rule and limitation     |
| 160–180 | Closed-sheet retrieval test in section 8                                 | Repair errors using one failing example, then rewrite  |

If you fall behind, complete the scaffold and scan patterns first.
Read every recognition card once before spending the whole session on one difficult algorithm.
On your first pass, read each cue, recipe, and trap. Save detailed traces for the difficult-method block.
Use the linked complete source when a compact recipe is insufficient.

## 2. Translate a question before coding

Write these six answers on scratch paper:

1. **Input shape:** one number, two numbers, an array, a matrix, a token, or a full line?
2. **Task:** check one object, construct one answer, count answers, or print every answer?
3. **Restrictions:** signed values, large products, allowed moves, duplicates, and required ordering?
4. **Required method:** does the statement explicitly require Booth, Karatsuba, block swap, or Manacher?
5. **State:** which values must survive between iterations or recursive calls?
6. **Output contract:** value versus index, zero-based versus one-based, and exact failure wording?

An array is not enough evidence for majority versus leaders versus maximum product.
Read the property that the question requests.
For example, `3 3` could mean grid dimensions, GCD inputs, or something else.
Never choose an algorithm from input shape alone.

**Named algorithm rule:** `a * b`, `Arrays.sort`, and center expansion can produce correct outputs for some tasks.
They do not demonstrate Booth, Karatsuba, quicksort, selection sort, or Manacher when the question requires that method.

## 3. Java survival kit

### 3.1 One executable scaffold

This complete example reads an array and prints its sum.
Replace the calculation with the requested algorithm. Keep the input order from the exam statement.

```java
import java.util.*;
import java.math.BigInteger;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] a = new int[n];
    long sum = 0;
    for (int i = 0; i < n; i++) {
      a[i] = sc.nextInt();
      sum += a[i];
    }
    System.out.println(sum);
  }
}
```

Input `4 2 -1 5 0` produces `6`.
`import` makes library classes available. It does not execute them.
`Main` is the class name expected by many judges. Follow your judge's instructions.
`main` is the entry point. `static` lets a method run without constructing an object.
Statements usually end with `;`. Curly braces group statements.
Java is case-sensitive: `Scanner`, `String`, and `System` require capitals.

### 3.2 Read the correct thing

| Expression                  | Meaning                                 | Example                                |
| --------------------------- | --------------------------------------- | -------------------------------------- |
| `sc.nextInt()`              | Read one signed 32-bit integer          | An array length or an ordinary element |
| `sc.nextLong()`             | Read one signed 64-bit integer          | A large step count                     |
| `sc.next()`                 | Read one whitespace-separated token     | `aabb` or `69`                         |
| `sc.nextLine()`             | Read the rest of the current line       | A string containing spaces             |
| `new BigInteger(sc.next())` | Read an exact integer of arbitrary size | A huge modulus or product input        |

Whitespace separates tokens, so numbers can span lines.
Do not read an initial test count unless the question specifies one.
If it specifies `T` cases, surround the per-case calculation with `while (t-- > 0)`.
Reset all per-case state inside that loop.

**The newline trap:** after `nextInt()`, the current line's newline usually remains unread.
When the next value starts on the next full line, consume the remainder first:

```java
int n = sc.nextInt();
sc.nextLine();
String text = sc.nextLine();
```

Do not insert that extra consumption when the question puts the string on the same line.
For a line-only question, use `String text = sc.nextLine()` directly.

### 3.3 Variables, arrays, conditions, and loops

| Syntax                                   | Read it as                                      |
| ---------------------------------------- | ----------------------------------------------- |
| `int x = 3;`                             | Store an integer named x                        |
| `long x = 3L;`                           | Store a wider integer                           |
| `boolean found = false;`                 | Store a true/false flag                         |
| `char c = 'a';` versus `String s = "a";` | One character versus a string                   |
| `int[] a = new int[n];`                  | Create n zero-valued integer elements           |
| `int[][] grid = new int[r][c];`          | Create r rows and c columns                     |
| `a[i]`                                   | Element at index i, beginning at zero           |
| `a.length` versus `s.length()`           | Array length versus string length               |
| `if (x == 0) ... else ...`               | Choose a branch                                 |
| `for (int i = 0; i < n; i++)`            | Visit indices 0 through n−1                     |
| `for (int x : a)`                        | Visit values without an index                   |
| `while (b != 0)`                         | Repeat until the condition becomes false        |
| `break` versus `continue`                | Stop the loop versus skip the current iteration |
| `return value;`                          | End this method and give its caller a result    |

Use `==` for primitive equality. Use `s.equals("abc")` for string contents.
`=` assigns a value. It does not compare values.
`&&` means AND. `||` means OR. `!` means NOT.
`&&` stops after a false left condition, which helps protect array bounds.

```java
if (r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 1) {
  System.out.println("Open cell");
}
```

### 3.4 Methods and recursion

A parameter is an input to a method. A return value is its answer.
Place helper methods inside `Main`, but outside `main`.

```java
static long gcd(long a, long b) {
  while (b != 0) {
    long remainder = a % b;
    a = b;
    b = remainder;
  }
  return a;
}
```

This compact helper assumes nonnegative `long` inputs.
Call it inside `main`: `System.out.println(gcd(48, 18));`, which prints `6`.
Use the linked repository version when signed minimum values must work.

Recursion means a method calls itself on a smaller problem.
A **base case** returns immediately when the problem is complete.
A **recursive step** must approach that base case.
For combinations, depth increases. For Karatsuba, number size decreases.
Backtracking adds a third action: undo the choice after the recursive call.

### 3.5 Arithmetic that commonly loses marks

- Integer division discards the fractional part: `7 / 2` is `3`.
- `%` gives the remainder: `17 % 5` is `2`.
- For positive n, `Math.floorMod(d, n)` normalizes a negative rotation distance.
- Check `n == 0` before applying modulo n.
- `int` is about ±2.1 billion. `long` is about ±9.22 quintillion.
- Write `1L * a * b` to widen before multiplying two `int` values.
- Writing `long answer = a * b` does not prevent an earlier `int` overflow.
- Even `long` can overflow repeated products or large path counts.
- `Math.abs(Long.MIN_VALUE)` is still negative. Use `BigInteger` when that case matters.
- Initialize maximums correctly for negative inputs. Zero is not a universal starting maximum.

**Bit operations:** these act on binary digits, not decimal digits.

| Operator   | Meaning                           | Example                         |
| ---------- | --------------------------------- | ------------------------------- |
| `x & 1`    | Read the lowest bit               | `5 & 1` is `1`                  |
| `x & mask` | Keep selected bits                | `x & 15` keeps the lowest four  |
| `a \| b`   | Set bits present in either value  | Used to combine nibbles         |
| `a ^ b`    | Set bits where the values differ  | XOR, not exponentiation         |
| `x << k`   | Shift bits left                   | `3 << 2` is `12`                |
| `x >> k`   | Shift right and preserve the sign | Used in signed Booth arithmetic |
| `x >>> k`  | Shift right and fill with zeros   | Used to scan all 32 bits        |

A negative number can remain negative forever with `>>` in a `while (x != 0)` scan.
Use a fixed 32-iteration scan for a signed `int` bit pattern.

## 4. Libraries and functions worth remembering

These are reference fragments. They belong inside the scaffold or in its helper methods.
All use standard Java libraries. You need no external dependency.

| Import                 | What you actually need                                                         |
| ---------------------- | ------------------------------------------------------------------------------ |
| `java.util.*`          | `Scanner`, `Arrays`, `ArrayList`, `Collections`, `Comparator`, `TreeMap`       |
| `java.math.BigInteger` | Exact large integers                                                           |
| `java.io.*`            | `BufferedReader` and `InputStreamReader`, if you choose line-based input       |
| None for `java.lang`   | `Math`, `String`, `StringBuilder`, `Integer`, and `Long` are already available |

### 4.1 Arrays, strings, lists, and ordering

| Expression                                          | Effect or result                                             |
| --------------------------------------------------- | ------------------------------------------------------------ |
| `Arrays.sort(a)`                                    | Sort an array in ascending order, modifying it               |
| `Arrays.fill(used, false)`                          | Fill an array with one value                                 |
| `s.charAt(i)`                                       | Character at index i                                         |
| `s.toCharArray()`                                   | Mutable character array                                      |
| `s.substring(start, end)`                           | Start included, end excluded                                 |
| `s.compareTo(t)`                                    | Negative, zero, or positive according to lexicographic order |
| `String.valueOf(chars)`                             | Convert a character array to a string                        |
| `new StringBuilder()`                               | Create a mutable output buffer                               |
| `out.append(x).append(' ')`                         | Append a value and a space                                   |
| `out.reverse()`                                     | Reverse the buffer in place                                  |
| `out.toString()`                                    | Convert the buffer to a string                               |
| `List<Integer> values = new ArrayList<>();`         | Create a resizable list of boxed integers                    |
| `values.add(x)` / `values.get(i)` / `values.size()` | Append, access, or count list elements                       |
| `Collections.reverse(values)`                       | Reverse a list in place                                      |
| `Math.max(a, b)` / `Math.min(a, b)`                 | Select the larger or smaller value                           |

Arrays use `a.length`. Lists use `values.size()`. Strings use `s.length()`.
Use `System.out.println(answer)` for one result.
Use a loop for array elements. `System.out.println(a)` does not print an integer array's contents.
`Arrays.toString(a)` adds brackets and commas, which may violate the required output format.

Lexicographic order compares characters, so `file10` precedes `file2`.
Numeric-aware natural sorting must compare whole digit runs instead.
A comparator returns a negative value for "a before b", zero for equality, and a positive value for "a after b".
Use `Integer.compare(a, b)` rather than `a - b`, which can overflow.

### 4.2 Character frequencies

For lowercase English letters only:

```java
int[] frequency = new int[26];
for (char c : text.toCharArray()) {
  frequency[c - 'a']++;
}
```

`'c' - 'a'` is `2`, so it selects the third counter.
Do not use this version for uppercase letters, spaces, or arbitrary Unicode.
The repository palindrome constructor uses code points and a `TreeMap` for that broader domain.

For ordered integer keys:

```java
TreeMap<Integer, Integer> frequency = new TreeMap<>();
for (int cp : text.codePoints().toArray()) {
  frequency.put(cp, frequency.getOrDefault(cp, 0) + 1);
}
for (Map.Entry<Integer, Integer> entry : frequency.entrySet()) {
  int cp = entry.getKey();
  int count = entry.getValue();
  System.out.println(cp + " " + count);
}
```

A map stores key/value pairs. `TreeMap` visits its keys in sorted order.
`getOrDefault(key, 0)` returns zero when the key is absent.
Use `appendCodePoint(cp)` to append a full Unicode code point.
Most other string programs here operate on Java `char` values instead.

### 4.3 BigInteger: same arithmetic, different spelling

`BigInteger` values are immutable. Save the result of every arithmetic operation.
`a.add(b)` alone does not change a.

| Ordinary operation                  | BigInteger equivalent                                    |
| ----------------------------------- | -------------------------------------------------------- |
| Read an integer                     | `BigInteger a = new BigInteger(sc.next());`              |
| Constants zero / one                | `BigInteger.ZERO` / `BigInteger.ONE`                     |
| Convert a long                      | `BigInteger.valueOf(x)`                                  |
| `a + b`, `a - b`, `a * b`           | `a.add(b)`, `a.subtract(b)`, `a.multiply(b)`             |
| Integer division                    | `a.divide(b)`                                            |
| Positive-modulus reduction          | `a.mod(m)` with `m > 0`                                  |
| Remainder, including signed results | `a.remainder(b)`                                         |
| `a == b`                            | `a.equals(b)`                                            |
| `a < b` / `a > b`                   | `a.compareTo(b) < 0` / `a.compareTo(b) > 0`              |
| Absolute value / GCD                | `a.abs()` / `a.gcd(b)`                                   |
| Negative / zero / positive sign     | `a.signum()` returns `-1`, `0`, or `1`                   |
| Smaller / larger                    | `a.min(b)` / `a.max(b)`                                  |
| Modular inverse                     | `a.modInverse(m)`, requiring `m > 0` and `gcd(a,m) == 1` |
| Decimal power                       | `BigInteger.TEN.pow(k)`                                  |

For example, `BigInteger.valueOf(12).multiply(BigInteger.valueOf(13))` represents `156`.
Library multiplication does not demonstrate Karatsuba when the question requires your own Karatsuba recursion.

## 5. Seven reusable thinking patterns

| Pattern                   | State to remember                       | Programs that reuse it                                        |
| ------------------------- | --------------------------------------- | ------------------------------------------------------------- |
| Running scan              | Best answer plus current state          | Leaders, majority, longest ones, maximum product              |
| Prefix/suffix bookkeeping | Left sum and remaining right sum        | Equilibrium                                                   |
| Two pointers              | A left index and a right index          | Binary palindrome, strobogrammatic check, reversing           |
| Marking / counting        | A boolean or frequency array            | Sieve, character counts, queen constraints                    |
| Sort then compare         | A comparison rule or sorted characters  | Natural sort, students, permutations, palindrome construction |
| Dynamic programming       | Answers to smaller repeated subproblems | Grid paths                                                    |
| Choose → recurse → undo   | Current partial answer and constraints  | Combinations, maze, queens                                    |

**Trace before typing:** for maximum product on `[-2, 3, -4]`, the negative product ending at `3` is `-6`.
Multiplying it by `-4` gives the answer `24`.
That is why remembering only the largest positive product fails.

For equilibrium, test `[1, 2, 3]`.
The middle index is not balanced because left is `1` and right is `3`.
Do not include the middle element unless the question explicitly uses that definition.

For recursive search, draw just two levels.
Write the base case, allowed choices, constraint check, recursive call, and undo action in that order.
A method that returns the first solution is different from one that prints all solutions.

## 6. Number, bit, and rotation recognition cards

The examples below use repository input conventions.
Follow the actual exam statement if its order, indexing, or failure wording differs.
Recipes use mathematical shorthand, not always literal Java.
For `BigInteger`, translate `+`, `*`, and equality through the API table in section 4.3.
`lo` and `hi` mean lower and upper bounds. `floor` means round down.
`ceil` means round up. `gcd(a,b)` means greatest common divisor.
Two numbers are **coprime** when their GCD is one.
`x ≡ a (mod m)` means x leaves remainder a when divided by positive m.
A **modular inverse** of a is b such that `a * b mod m == 1`.
For example, the inverse of 3 modulo 7 is 5.
`g ∤ difference` means the difference is not divisible by g.
**Contiguous** means consecutive positions without skipping.
**Lexicographic** means character-by-character order, not numeric order of digit runs.

### CAT-2/01 — Booth's algorithm

**Cue:** signed 32-bit `m q`. Exact 64-bit Booth product.

**Steps**

1. Use a signed 33-bit accumulator A.
2. Store the multiplicand in M and the 32-bit multiplier pattern in Q.
3. Set the previous multiplier bit q1 to zero.
4. Repeat 32 rounds.
5. For `(Q0,q1) = (0,1)`, add M to A.
6. For `(Q0,q1) = (1,0)`, subtract M from A.
7. For matching bits, leave A unchanged.
8. Copy Q0 into q1.
9. Shift Q right logically, placing A's lowest bit in Q's highest position.
10. Shift A right arithmetically.

**Trap:** result `(A<<32)|(Q&0xffffffffL)`. Q must shift logically and be masked.

```java
static long booth(long m, long q) {
  long M=m, A=0, Q=q&0xffffffffL; int q1=0;
  for (int i=0;i<32;i++) {
    if ((Q&1)==1 && q1==0) A-=M; else if ((Q&1)==0 && q1==1) A+=M;
    q1=(int)(Q&1); Q=(Q>>>1)|((A&1)<<31); A>>=1;
  }
  return (A<<32)|(Q&0xffffffffL);
}
// in main, after reading m and q: System.out.println(booth(m, q));
```

```text
Input:  6 -7                 -> -42
Q starts 0xFFFFFFF9; after-shift values:
i=0 (1,0) sub: A=-3 Q=0x7FFFFFFC
i=1 (0,1) add: A= 1 Q=0xBFFFFFFE
i=2 (0,0) ---: A= 0 Q=0xDFFFFFFF
i=3 (1,0) sub: A=-3 Q=0x6FFFFFFF
... after i=31: A=-1 Q=0xFFFFFFD6
(A<<32)|Q = 0xFFFFFFFFFFFFFFD6 = -42
```

[src](CAT-2/01_BoothsAlgorithm.java)

### CAT-2/02 — Euclid's algorithm

**Cue:** gcd of signed 64-bit `a b`, including `Long.MIN_VALUE`.

```text
Input:  48 18                  Input: -9223372036854775808 0
Output: 6                      Output: 9223372036854775808
```

**Steps**

1. Convert both inputs to `BigInteger`.
2. Replace each value with its absolute value.
3. While b is nonzero, compute `r = a.remainder(b)`.
4. Replace a with b.
5. Replace b with r.
6. Print a when b reaches zero.

**Trap:** `Math.abs(Long.MIN_VALUE)` stays negative and negating it overflows, so `-2^63` needs BigInteger. `0 0` correctly prints `0`. With `BigInteger`, use `.remainder(b)`, not the Java `%` operator.

[src](CAT-2/02_EuclidsAlgorithm.java)

### CAT-2/03 — Karatsuba multiplication

**Cue:** exact product of signed 64-bit `x y` with three half-size products.

**Steps**

1. Work with absolute values first.
2. Let n be the larger decimal digit count.
3. Set `m = n/2` and `p = 10^m`.
4. Split the numbers as `x = a*p+b` and `y = c*p+e`.
5. Recursively calculate ac, be, and `(a+b)*(c+e)`.
6. Calculate `cross = third-ac-be`.
7. Return `ac*p*p + cross*p + be`.
8. Use direct multiplication when either factor has one digit.
9. Restore the result's sign.

**Trap:** split at the larger decimal digit count. Use BigInteger. Bit-splitting is another variant.

```text
Input: 1234 5678
1234=12*100+34, 5678=56*100+78
ac=672  bd=2652  (12+34)(56+78)=46*134=6164
cross=6164-672-2652=2840
672*10000 + 2840*100 + 2652 = 7006652
```

[src](CAT-2/03_KaratsubaAlgorithm.java)

### CAT-2/04 — Longest ones after one bit flip

**Cue:** one signed 32-bit pattern. Longest 1-run after flipping at most one 0.

**Steps**

1. Set cur, prev, and best to zero.
2. Inspect exactly 32 bits.
3. For a one bit, increase cur.
4. For a zero bit, copy cur into prev.
5. Then reset cur to zero.
6. Update `best = max(best, prev+cur+1)`.
7. Shift x with `x >>>= 1`.
8. Print `min(best,32)`.

**Trap:** The extra one represents the proposed flip. Cap the answer at 32 when every bit is already one.

```text
Input: 5 (101) -> 3        Input: -1 -> 32        Input: 0 -> 1
```

[src](CAT-2/04_LongestOnesAfterFlippingBit.java)

### CAT-2/05 — Swap nibbles in a byte

**Cue:** exchange the low and high four-bit halves of one byte.

```text
Input:  171 (0xAB)      Input: 255
Output: 186 (0xBA)      Output: 255
```

**Steps**

1. Keep the lowest byte with `x &= 255`.
2. Calculate the low nibble as `x & 15`.
3. Shift that nibble left by four positions.
4. Calculate the high nibble as `x & 240`.
5. Shift that nibble right by four positions.
6. Combine both values with bitwise OR.

**Trap:** Keep both nibble masks. Shifting an unmasked negative value can preserve sign bits. Output is `0..255`.

[src](CAT-2/05_SwapNibbles.java)

### CAT-2/06 + FAT/23 — Block swap rotation (one algorithm, two IDs)

**Cue:** rotate left by `d` via equal-size block swaps. `O(n)` time, `O(1)` space. Negative `d` rotates right.

**Steps**

1. Return immediately if n is zero.
2. Normalize the distance with `Math.floorMod(d,n)`.
3. Return if the normalized distance is zero.
4. Track the lengths of the two unfinished blocks.
5. Swap the smaller block with an equal-sized piece of the larger block.
6. Reduce the larger unfinished length.
7. Repeat until both lengths match.
8. Swap those final equal blocks.

```text
if (n==0) return;
d = floorMod(d,n); if (d==0) return;
i=d; j=n-d;                  // left length i at d-i, right length j at d
while (i != j) {
  if (i < j) { swap(d-i, d+j-i, i); j -= i; }
  else       { swap(d-i, d,     j); i -= j; }
}
swap(d-i, d, i);             // equal final blocks
```

```text
[1 2 3 4 5], d=2 -> i=2, j=3
swap [1,2] with [4,5] -> 4 5 3 1 2, j=1
swap [4]   with [3]   -> 3 5 4 1 2, i=1
i=j=1 final swap [5] with [4] -> 3 4 5 1 2
```

```text
CAT-2/06:  5 2 / 1 2 3 4 5  -> "3 4 5 1 2 "   (trailing space, no newline)
FAT/23:    7 2 1 2 3 4 5 6 7 -> 3 4 5 6 7 1 2
```

**Trap:** CAT-2/06 prints trailing spaces without a newline. FAT/23 prints a newline. For n zero, only FAT/23 prints an empty line.

[src](CAT-2/06_BlockSwapAlgorithm.java) · [src](FAT/23_BlockSwapRotation.java)

### FAT/01 — Sieve of Eratosthenes

**Cue:** every prime in `[2,n]` via the named Sieve of Eratosthenes.

**Steps**

1. Create `boolean[n+1]` to mark composite numbers.
2. Try each p from 2 while `(long)p*p <= n`.
3. Skip p if a smaller prime already marked it.
4. Otherwise mark every multiple from p*p through n.
5. Use a long counter for those multiples.
6. Print the unmarked numbers from 2 through n.

**Trap:** starting at `p*p` avoids work already performed by smaller primes. `n<2` prints an empty line. The array needs `n<=Integer.MAX_VALUE-1`.

```text
Input: 30 -> 2 3 5 7 11 13 17 19 23 29
Input: 1  -> (empty line)
```

[src](FAT/01_SieveOfEratosthenes.java)

### FAT/02 — Segmented sieve

**Cue:** all primes in `[l,h]` without a boolean array of size `h+1`.

**Steps**

1. Print an empty line if `h < 2` or `l > h`.
2. Raise l to 2 when necessary.
3. Generate base primes through `floor(sqrt(h))`.
4. Process the interval in blocks of at most `2^20` values.
5. For each base prime p, calculate `start = max(p*p, ceil(lo/p)*p)`.
6. Mark multiples of p from start through the block's upper bound.
7. Store each mark at index `value-lo`.
8. Print the unmarked values.

**Trap:** start at `max(p^2, first multiple >= lo)`, not `p^2` alone. Use `long` multiples. Block index is `(int)(j-lo)`.

```text
10 30 -> 11 13 17 19 23 29      -5 10 -> 2 3 5 7      8 10 -> (empty line)
```

[src](FAT/02_SegmentedSieve.java)

### FAT/03 — Euler's totient (phi)

**Cue:** count integers in `[1,n]` coprime to `n`.

**Steps**

1. Set result to n.
2. Try p from 2 while `(long)p*p <= n`.
3. When p divides n, divide n by p until no factor p remains.
4. Subtract `result/p` from result once.
5. After the loop, check whether `n > 1`.
6. If so, subtract `result/n` for that final prime factor.
7. Print result.
8. For `n <= 0`, print zero instead.

**Trap:** subtract once per distinct prime after stripping powers. Handle the leftover after the loop. 48: `p=2` gives 24 and `n=3`. Leftover gives 16.

```text
48 -> 16      13 -> 12      1 -> 1      0 -> 0
```

[src](FAT/03_EulerPhi.java)

### FAT/04 — Generalized Chinese Remainder Theorem

**Cue:** solve `x≡a (mod m)`, `k` pairs. Moduli may share factors. Input is **modulus then remainder**.

**Steps**

1. Start with the combined condition `x = A mod M`, using `A=0` and `M=1`.
2. Read each pair as modulus m, then remainder a.
3. Reduce a modulo m.
4. Calculate `g = gcd(M,m)` and `difference = a-A`.
5. If g does not divide difference, print `No solution`.
6. Set `reducedModulus = m/g`.
7. If reducedModulus is one, set t to zero.
8. Otherwise calculate the inverse of `M/g` modulo reducedModulus.
9. Set `t = ((difference/g) * inverse) mod reducedModulus`.
10. Save the old M.
11. Replace M with `M * reducedModulus`.
12. Replace A with `(A + oldM*t) mod M`.
13. Print A after all pairs.

**Trap:** normalize negative remainders. Special-case `m'=1`. Use BigInteger.

```text
3 / 3 2 / 4 3 / 5 1 -> 11
2 / 4 2 / 6 4       -> 10
2 / 2 1 / 4 2       -> No solution
Merge 4,2 then 6,4: first A=2,M=4; g=2, diff=2, m'=3, inv(2 mod 3)=2
t=(2/2)*2 mod 3=2; M=12; A=2+4*2=10
```

[src](FAT/04_ChineseRemainderTheorem.java)

### FAT/05 — Strobogrammatic check

**Cue:** is a digit string unchanged by a 180-degree rotation?

**Steps**

1. Place one pointer at each end of the string.
2. Accept only `(0,0)`, `(1,1)`, `(8,8)`, `(6,9)`, and `(9,6)`.
3. Return false when a pair fails.
4. Move both pointers inward.
5. Continue while the left pointer does not pass the right pointer.
6. Return true when every pair passes.

**Trap:** The center digit must match its own rotation. Only 0, 1, and 8 qualify. This string check permits leading zeros.

```text
"69" -> true      "18081" -> true      "962" -> false      "6" -> false
```

[src](FAT/05_StrobogrammaticCheck.java)

### FAT/06 — Strobogrammatic generation

**Cue:** print every strobogrammatic number of exact length `n`, built from mirror pairs.

**Steps**

1. Create a character array of length n.
2. Fill mirrored positions recursively.
3. If the pointers cross, print the completed array.
4. At a single center position, try 0, 1, and 8.
5. Otherwise try the five valid rotation pairs.
6. Skip the outer `(0,0)` pair to prevent a leading zero.
7. Print an empty line for `n <= 0`.

**Trap:** the center branch runs first so `n=1` emits `0`. The leading-zero skip applies only to two-ended pairs.

```text
1 -> 0 1 8
2 -> 11 69 88 96
3 -> 101 111 181 609 619 689 808 818 888 906 916 986
```

[src](FAT/06_StrobogrammaticGenerate.java)

### FAT/07 — Binary palindrome

**Cue:** is the binary form of nonnegative `long n` a palindrome?

**Steps**

1. Return false for a negative input.
2. Set `hi = 63-Long.numberOfLeadingZeros(n)`.
3. Set lo to zero.
4. While `lo < hi`, compare bits lo and hi.
5. Extract a bit with `(n >>> position) & 1`.
6. Return false on a mismatch.
7. Move lo upward and hi downward.
8. Return true if every pair matches.

**Trap:** stop at the highest set bit, not bit 63, or leading zeros break every number. Negative input is false. `0` has `hi=-1` and passes.

```text
9 -> true (1001)      10 -> false (1010)      0 -> true      9223372036854775807 -> true
```

[src](FAT/07_BinaryPalindrome.java)

### FAT/08 — Toggle the switch

**Cue:** `n` switches, pass `k` toggles multiples of `k`. Count switches left on.

**Steps**

1. Only perfect-square positions remain on.
2. Count them by calculating `floor(sqrt(n))`.
3. For positive n, search between 1 and 3037000499.
4. Choose `mid = lo + (hi-lo+1)/2`.
5. If `mid <= n/mid`, replace lo with mid.
6. Otherwise replace hi with `mid-1`.
7. Continue until lo equals hi.
8. Print lo, or zero for `n <= 0`.

**Trap:** `Math.sqrt` may round near the long limit. `mid<=n/mid` avoids overflow. `n<=0` prints 0.

```text
3 -> 1      9 -> 3      0 -> 0      9223372036854775807 -> 3037000499
```

[src](FAT/08_ToggleSwitch.java)

### FAT/09 — Alice apple tree

**Cue:** smallest square-garden radius `r` reaching `needed`. Ring `r` has `12r^2` apples. Print perimeter `8r`.

**Steps**

1. Calculate cumulative apples with `f(r) = 2*r*(r+1)*(2*r+1)`.
2. Use `BigInteger` for this calculation.
3. Double the upper radius until its apple count reaches the target.
4. Binary-search the smallest radius whose count reaches the target.
5. Print `8*r` for that radius.
6. Print zero when the target is zero.
7. For target 13, radius 1 gives 12 apples and radius 2 gives 60.
8. The corresponding answer is 16.

**Trap:** `needed=0` prints 0. `f` exceeds `Long.MAX_VALUE` near the maximum radius, so use BigInteger.

```text
1 -> 8      13 -> 16      1000000000 -> 5040      0 -> 0
```

[src](FAT/09_AliceAppleTree.java)

### FAT/18 — Josephus survivor

**Cue:** `n` people, eliminate every `k`-th. Print the 1-based survivor.

**Steps**

1. Start with zero-based survivor index zero for a one-person circle.
2. Visit circle sizes from 2 through n.
3. Update `survivor = (survivor + k%size) % size`.
4. Print `survivor+1` to obtain the one-based position.

**Trap:** reduce `k` modulo `size` before adding, or `survivor+k` overflows for huge `k`. Stay 0-based until printing.

```text
14 2 -> 13      5 2 -> 3      41 3 -> 31
5 9223372036854775807 -> 4      1 1 -> 1
```

[src](FAT/18_Josephus.java)

## 7. Array, string, sorting, and search recognition cards

Each example pair shows input first and output second. Source links contain the complete runnable program.

### CAT-2/07 · Maximum product subarray

**Recognize:** Find the largest product of consecutive array elements. Negative values require both a maximum and a minimum product.

**Example**

```text
3
-2 -3 4
```

```text
24
```

**Steps**

1. Initialize mx, mn, and answer from the first value.
2. For each later negative value, swap mx and mn first.
3. Set `mx = max(value, mx*value)`.
4. Set `mn = min(value, mn*value)`.
5. Update answer from mx.
6. Use `BigInteger` when products can exceed long.
7. For n zero, print zero.

**Trap:** Swap before updating. `int`/`long` overflow on huge products. `n = 0` prints `0`.

**Source:** [CAT-2/07_MaxProductSubarray.java](CAT-2/07_MaxProductSubarray.java)

---

### CAT-2/08 · Maximum hourglass sum

**Recognize:** fixed 6×6 matrix. The hourglass is 3 top + 1 middle + 3 bottom = **7 cells**, not nine.

**Example**

```text
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
```

```text
7
```

**Steps**

1. Read the 6-by-6 matrix.
2. Visit top-left indices i and j from 0 through 3.
3. Add the three top cells.
4. Add the middle cell `a[i+1][j+1]`.
5. Add the three bottom cells.
6. Keep the largest seven-cell sum.
7. Use long arithmetic from the first addition.

**Trap:** Do not add middle-left/right cells. Start at `Long.MIN_VALUE` for all-negative input.

**Source:** [CAT-2/08_MaximumHourglassSum.java](CAT-2/08_MaximumHourglassSum.java)

---

### CAT-2/09 · Max equilibrium sum

**Recognize:** Find the largest matching sum on both sides of an index. Exclude the indexed element.

**Example**

```text
3
1 3 1
```

```text
1
```

**Steps**

1. Calculate the array's total sum.
2. Start with right equal to total and left equal to zero.
3. Before testing an element x, subtract x from right.
4. If left equals right, record the larger matching left sum.
5. Then add x to left.
6. Use `BigInteger` to avoid overflow.
7. Print zero if no index qualifies.

**Trap:** The pivot belongs to neither side. Test equality, not “at least”. No equilibrium prints `0`, ambiguous with a real sum of `0`. `n = 0` prints `0`.

**Source:** [CAT-2/09_MaxEquilibriumSum.java](CAT-2/09_MaxEquilibriumSum.java)

---

### CAT-2/10 · Leaders in array

**Recognize:** a leader has no greater element to its right. Equal values also count in this source.

**Example**

```text
6
16 17 4 3 5 2
```

```text
17 5 2
```

The line ends with one space.

**Steps**

1. Start m at `Integer.MIN_VALUE`.
2. Scan indices from right to left.
3. When `a[i] >= m`, store a[i].
4. Then set m to a[i].
5. Print the stored values in reverse storage order.

**Trap:** Using `>` drops equal leaders: `5 5 5` prints all three. Output ends with a space. `n = 0` prints nothing.

**Source:** [CAT-2/10_LeadersInArray.java](CAT-2/10_LeadersInArray.java)

---

### CAT-2/11 · Majority element

**Recognize:** an element occurring strictly more than `n/2` times. A voting candidate needs verification.

**Example**

```text
5
2 2 1 1 2
```

```text
2
```

```text
3
1 2 3
```

```text
-1
```

**Steps**

1. Start count at zero.
2. When count is zero, select the current value as candidate.
3. In that branch, set count to one.
4. Otherwise increase count for a matching value.
5. Otherwise decrease count for a different value.
6. Count the candidate's actual occurrences in a second pass.
7. Print it only if its frequency exceeds n/2.
8. Otherwise print -1.

**Trap:** Skipping the recount may print a non-majority. `-1` also means a real majority of `-1`. `n = 0` prints `-1`.

**Source:** [CAT-2/11_MajorityElement.java](CAT-2/11_MajorityElement.java)

---

### CAT-2/12 · Lexicographically first palindromic string

**Recognize:** rearrange all characters into the lexicographically smallest palindrome — a permutation task, not a substring task.

**Example**

```text
aabb
```

```text
abba
```

```text
abc
```

```text
Not possible
```

**Steps**

1. Count Unicode code points.
2. Print `Not possible` if more than one count is odd.
3. Visit code points in ascending order through a `TreeMap`.
4. Append count/2 copies to the first half.
5. Place the odd character at the center, if one exists.
6. Append the first half in reverse code-point order.

**Trap:** Do not search substrings. Count code points, not UTF-16 units, for emoji. Exact spelling: `Not possible`.

**Source:** [CAT-2/12_LexicographicallyFirstPalindromicString.java](CAT-2/12_LexicographicallyFirstPalindromicString.java)

---

### FAT/10 · Natural sort (numeric-aware strings)

**Recognize:** sort so digit runs compare numerically: `file2` before `file10`, unlike lexicographic order.

**Example**

```text
5
file10
file2
file1
file02
file2a
```

```text
file1
file2
file2a
file02
file10
```

**Steps**

1. Read n strings as full lines.
2. Compare each pair from left to right.
3. When both current characters are digits, read both complete digit runs.
4. Ignore leading zeros while keeping one significant zero for an all-zero run.
5. Compare significant lengths first.
6. If lengths match, compare digits.
7. For equal numeric values, prefer fewer leading zeros.
8. For other characters, use character order.
9. When one string ends first, place it first.
10. Sort the strings with this comparison rule.

**Trap:** `Arrays.sort`/`compareTo` is lexicographic and wrong. Do not parse runs into `int`/`long`. Long runs overflow. Case-sensitive. `2` before `02`.

**Source:** [FAT/10_NaturalSort.java](FAT/10_NaturalSort.java)

---

### FAT/11 · Student comparator

**Recognize:** sort records by name, then age, then roll. The roll tie-break makes order deterministic.

**Example**

```text
3
101 Ram 18
102 Shyam 22
103 Mohan 19
```

```text
103 Mohan 19
101 Ram 18
102 Shyam 22
```

**Steps**

1. Read records in roll, name, age order.
2. Store each record.
3. Build a comparator with name as the primary key.
4. Add age as the second key.
5. Add roll as the third key.
6. Sort with that comparator.
7. Print each record in roll, name, age order.

**Trap:** Name is primary, not roll. Sort order `name→age→roll` differs from output columns `roll→name→age`. Names are one token.

**Source:** [FAT/11_StudentComparator.java](FAT/11_StudentComparator.java)

---

### FAT/12 · Quicksort (Lomuto partition)

**Recognize:** Quicksort partitions around a pivot. Its average time is `O(n log n)`. Unbalanced partitions can require `O(n²)` time.

**Example**

```text
6
10 80 30 90 40 50
```

```text
10 30 40 50 80 90
```

**Steps**

1. Choose `a[high]` as pivot.
2. Set `i = low-1`.
3. Scan j from low through high-1.
4. For each value below pivot, increase i.
5. Swap a[i] and a[j] for that value.
6. After the scan, swap a[i+1] and a[high].
7. The pivot's final index is i+1.
8. Recursively sort the smaller partition.
9. Use a loop for the larger partition to limit stack depth.

**Trap:** Do not scan `a[high]`. Partitioning is not full sorting. The loop does not remove `O(n²)` worst-case time.

**Source:** [FAT/12_Quicksort.java](FAT/12_Quicksort.java)

---

### FAT/13 · Selection sort

**Recognize:** repeatedly select the minimum of the unsorted suffix.

**Example**

```text
5
64 25 12 22 11
```

```text
11 12 22 25 64
```

**Steps**

1. Visit each position i from 0 through n-2.
2. Set min to i.
3. Scan j from i+1 through n-1.
4. When `a[j] < a[min]`, replace min with j.
5. After the scan, swap a[i] and a[min].
6. Repeat for the next position.

**Trap:** Swap only after the scan. Time is `O(n²)` always. Not stable, so equal values may reorder.

**Source:** [FAT/13_SelectionSort.java](FAT/13_SelectionSort.java)

---

### FAT/14 · Move hyphens to the front

**Recognize:** full line. Move every `'-'` to the front while other characters keep their order.

**Example**

```text
FACE-PREP
```

```text
-FACEPREP
```

```text
-a b-c
```

```text
--a bc
```

**Steps**

1. Read the complete line.
2. Count its hyphens.
3. Append each non-hyphen character to a buffer.
4. Preserve their original order.
5. Print the counted hyphens.
6. Print the buffer immediately afterward.

**Trap:** Do not reverse or sort the rest. This is a stable partition. Only ASCII `'-'` counts. Spaces stay. Empty line prints an empty line.

**Source:** [FAT/14_MoveHyphens.java](FAT/14_MoveHyphens.java)

---

### FAT/15 · Manacher longest palindromic substring

**Recognize:** longest contiguous palindrome in linear time. Not a permutation or subsequence.

**Example**

```text
abcababacs
```

```text
cababac
```

```text
abba
```

```text
abba
```

**Steps**

1. Build an integer array with separators between input characters.
2. Place distinct negative sentinels at both ends.
3. Keep each palindrome radius in p[i].
4. Track the current center and right boundary.
5. If `i < right`, calculate `mirror = 2*center-i`.
6. Initialize `p[i] = min(right-i, p[mirror])` in that case.
7. Expand around i while its mirrored characters match.
8. When `i+p[i] > right`, update center and right.
9. Keep the first center with each new greatest radius.
10. Use that radius as bestLen.
11. Calculate `start = (bestCenter-bestLen)/2`.
12. Return the substring from start through start+bestLen, with the final index excluded.

```java
static int grow(int[] t, int[] p, int i, int right, int center) {
  int mirror = 2 * center - i;
  if (i < right) p[i] = Math.min(right - i, p[mirror]);
  while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) p[i]++;
  return p[i];
}
```

**Trap:** `p` counts pairs, not a diameter. Sentinels must not match input. Strict `>` keeps leftmost. Expanding every centre without mirror reuse is `O(n²)`, not Manacher.

**Source:** [FAT/15_ManacherLongestPalindrome.java](FAT/15_ManacherLongestPalindrome.java)

---

### FAT/16 · Sorted unique permutations

**Recognize:** every distinct permutation in ascending lexicographic order, generated from a sorted start.

**Example**

```text
baba
```

```text
aabb
abab
abba
baab
baba
bbaa
```

**Steps**

1. Sort the characters to obtain the first permutation.
2. Print the current arrangement.
3. Find the rightmost i where `a[i] < a[i+1]`.
4. Stop if no such i exists.
5. Find the rightmost j where `a[j] > a[i]`.
6. Swap a[i] and a[j].
7. Reverse the suffix after i.
8. Repeat from the print step.

**Trap:** Keep the comparisons exactly as shown. The permutations include spaces. Empty input produces one empty line.

**Source:** [FAT/16_SortedUniquePermutations.java](FAT/16_SortedUniquePermutations.java)

---

### FAT/17 · Positional combinations nCr

**Recognize:** every `r`-element combination by index, in input order. Repeated values can give identical-looking lines.

**Example**

```text
5
1 2 3 4 5
3
```

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

**Steps**

1. Read n values and the requested size r.
2. Call `combine(start,depth)` with both arguments zero.
3. At `depth == r`, print the chosen values.
4. Otherwise try i from start through `n-(r-depth)`.
5. Store i as the chosen index for this depth.
6. Recurse with start i+1 and depth+1.
7. Continue with the next possible i after the recursive call.

**Trap:** Do not sort or deduplicate by value. Combinations are positional, not permutations. `r = 0` prints one empty line. `r < 0` or `r > n` prints nothing.

**Source:** [FAT/17_Combinations.java](FAT/17_Combinations.java)

---

### FAT/19 · Maneuvering paths (grid DP)

**Recognize:** count top-left to bottom-right paths using only down/right in a `rows × cols` grid. No obstacles.

**Example**

```text
3 3
```

```text
6
```

```text
30 30
```

```text
30067266499541040
```

**Steps**

1. Create one DP row of exact `BigInteger` values.
2. Initialize every value to one for the grid's first row.
3. For each later row, visit columns 1 through cols-1.
4. Replace dp[c] with `dp[c].add(dp[c-1])`.
5. The old dp[c] counts paths from above.
6. The updated dp[c-1] counts paths from the left.
7. Print dp[cols-1].

**Trap:** No up/left or obstacles. One row or column has one path. Nonpositive `rows`/`cols` print nothing. `long` can overflow on large grids.

**Source:** [FAT/19_ManeuveringPaths.java](FAT/19_ManeuveringPaths.java)

---

### FAT/20 · Rat in a maze (down/right)

**Recognize:** `n × n` maze of `1` open / `0` blocked. Only down and right from `(0,0)`. Print one path or `No solution`.

**Example**

```text
4
1 0 0 1
1 0 1 0
1 1 1 1
0 1 0 1
```

```text
1 0 0 0
1 0 0 0
1 1 1 1
0 0 0 1
```

**Steps**

1. Reject cells outside the grid or on a wall.
2. Reject cells that the current path already marks.
3. Mark the current cell in the solution.
4. At the bottom-right cell, return true.
5. Try the downward move first.
6. Try the rightward move if the downward move fails.
7. If both fail, remove the current mark.
8. Return false for that failed choice.
9. Print the solution grid when the search succeeds.

**Trap:** No up/left. Adding them without a visited guard cycles. `No solution` is exact. Output marks the chosen path, not all reachable cells.

**Source:** [FAT/20_RatMaze.java](FAT/20_RatMaze.java)

---

### FAT/21 · N-Queens (all boards)

**Recognize:** one queen per row, no shared column or diagonal. Print every solution.

**Example**

```text
4
```

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

**Steps**

1. Place one queen in each row.
2. Try columns from left to right.
3. Reject a used column.
4. Reject a used row+column diagonal.
5. Reject a used row-column+n-1 diagonal.
6. Mark the three constraints for an accepted choice.
7. Store the chosen column for this row.
8. Recurse into the next row.
9. Remove the three marks after that call.
10. Print a board whenever the row index reaches n.

**Trap:** `row-col` can be negative, so add `n-1` for the up index. Unmark all three. `n = 2`/`3` have none. `n <= 0` prints `No solution`. One blank line between boards.

**Source:** [FAT/21_NQueens.java](FAT/21_NQueens.java)

---

### FAT/22 · Warnsdorff knight tour

**Recognize:** greedy tour: always choose unvisited square with fewest onward moves.

**Example**

```text
5 0 0
```

```text
1 22 11 16 7
12 17 8 21 10
25 2 23 6 15
18 13 4 9 20
3 24 19 14 5
```

**Steps**

1. Mark the starting square with 1.
2. List each legal unvisited destination for the knight.
3. Count each destination's onward unvisited moves.
4. Choose the destination with the smallest count.
5. Keep the first destination on equal counts.
6. Use the fixed move order shown in the complete source.
7. Number the chosen square with the next step.
8. Repeat until every square has a number.
9. If no destination remains early, print `No tour found`.

**Trap:** `No tour found` only means this greedy run got stuck, not impossible. Start is `1`. Coordinates are zero-based. Count only unvisited squares.

**Source:** [FAT/22_WarnsdorffKnightTour.java](FAT/22_WarnsdorffKnightTour.java)

## 8. Final 20 minutes: retrieve, do not reread

### First 12 minutes

Choose two of these tasks. Write complete `Main` programs without looking at the linked source.

1. Read two nonnegative integers and print their GCD.
2. Read n and n integers. Print the majority element or `-1`.
3. Read n and print every prime from 2 through n.

Then test a normal case and a boundary case.
For majority, include a case with no majority.
For sieve, test n = 1. For GCD, test one zero input.
If you cannot write the scaffold, repeat section 3 before studying another difficult algorithm.

### Next 5 minutes

Cover the answer column. Say the algorithm and explain its state before calculating the output.

| Task and input                        | Expected result | Reason to recall                                                 |
| ------------------------------------- | --------------- | ---------------------------------------------------------------- |
| Maximum product: `4 2 -3 -2 4`        | `48`            | Keep both current maximum and minimum products                   |
| Equilibrium: `5 1 2 99 2 1`           | `3`             | Exclude the indexed element                                      |
| Nibble swap: `100`                    | `70`            | Decimal 100 is hexadecimal `0x64`, which becomes `0x46`          |
| Strobogrammatic check: `962`          | `false`         | Digit 2 has no rotation partner                                  |
| Grid paths: `3 3`                     | `6`             | Add paths from above and left                                    |
| Longest ones with one flip: `1775`    | `8`             | Merge runs separated by one zero                                 |
| Josephus: `7 3`                       | `4`             | Return the one-based survivor, not the final zero-based index    |
| Palindrome rearrangement: `baba`      | `abba`          | Count characters and construct sorted halves                     |
| Longest palindromic substring: `baba` | `bab`           | Preserve contiguous input characters and prefer the leftmost tie |

### Last 3 minutes: exam checklist

1. Check whether the input starts with a test count or an array length.
2. Check whether a string contains spaces.
3. Check whether the question requests an answer, an index, a count, or every arrangement.
4. Check numeric bounds before choosing `int`, `long`, or `BigInteger`.
5. Check the required algorithm before replacing it with a library call.
6. Test a smallest input, a negative/zero case when allowed, and a duplicate case.
7. Remove prompts, debugging output, brackets, and labels unless the output requires them.
8. Check the exact failure text, output order, and index base.

## 9. MCQ facts and traps

The downloaded syllabus includes Java basics and time/space complexity.
These facts support those topics without adding another set of programs to memorize.

| Concept                 | What to remember                                                                                                     |
| ----------------------- | -------------------------------------------------------------------------------------------------------------------- |
| `O(1)`                  | A fixed number of operations, such as nibble swapping                                                                |
| `O(log n)`              | Repeatedly halve the search interval, as in binary search                                                            |
| `O(n)`                  | Visit each item a constant number of times                                                                           |
| `O(n log n)`            | Typical efficient comparison sorting cost                                                                            |
| `O(n²)`                 | Two full nested loops, or selection sort                                                                             |
| Quicksort               | Average `O(n log n)`, worst `O(n²)`, even with bounded recursion                                                     |
| Sieve                   | `O(n log log n)` time and an `O(n)` marking array                                                                    |
| Manacher                | `O(L)` time and space for string length L                                                                            |
| Center expansion        | `O(L²)` worst-case time, not Manacher                                                                                |
| Permutations            | For distinct items, n! arrangements. Output itself can be enormous                                                   |
| Combinations            | Choose r positions without reordering. Count is n! / (r! (n-r)!)                                                     |
| Paths without obstacles | Count is C(rows+cols−2, rows−1) for down/right moves                                                                 |
| Recursion memory        | Stack frames count as auxiliary space                                                                                |
| BigInteger cost         | Arithmetic cost grows with the number of digits. It is not a fixed-time primitive operation                          |
| Java arrays             | Zero-based, fixed length, reference types, with default zero/false/null elements                                     |
| Array copying           | `b = a` shares the same array. `Arrays.copyOf(a, a.length)` makes a separate shallow copy                            |
| Method arguments        | Java passes values. The caller and method can hold references to the same array, so both can observe element changes |
| Strings                 | Immutable. `equals` compares contents. `==` compares references                                                      |
| Integer arithmetic      | Division truncates toward zero. Ordinary overflow does not automatically throw an exception                          |
| Boolean operators       | `&&` and `                                                                                                           |     | `short-circuit.`&`and` | ` also have bitwise integer meanings |
| Keywords                | `static` belongs to the class. `void` means no returned value. `new` constructs an object or array                   |
| Runtime                 | The JDK supplies tools such as `javac`. Java bytecode executes on the JVM                                            |

Do not replace the required algorithm merely because an alternative has the same complexity.
For example, next-permutation generates sorted unique arrangements directly.
Backtracking with a sorted set can produce the same output, but it stores extra answers.

## 10. What to review in the complete source

Use this only when a card is not enough to reconstruct a required algorithm.
Spend the difficult-method block on these details, rather than memorizing all imports again.

- **Booth:** adjacent-bit cases, accumulator width, and the combined arithmetic shift.
- **Karatsuba:** split/recombine powers and the three recursive calls.
- **CRT:** modulus/remainder input order and the GCD consistency test before an inverse.
- **Natural sort:** numeric-run comparison without overflow and leading-zero tie rules.
- **Manacher:** transformed indices, mirror initialization, boundary update, and substring conversion.
- **N queens:** row/column indexing and both diagonal keys.
- **Warnsdorff:** mark the starting square before choosing the next move.

For all other cards, identify the loop or recurrence first.
Then add reading and printing through the scaffold.
Do not invent output labels from the example's explanatory text.

## Java API references

The examples use longstanding Java APIs. The linked reference version is Java 21.
You do not need to read these pages during your three-hour session.

- [Scanner: tokens and complete lines](https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/util/Scanner.html)
- [Arrays: sorting, filling, and copying](https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/util/Arrays.html)
- [StringBuilder: append, reverse, and code points](https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/lang/StringBuilder.html)
- [Comparator: ordering and chained comparisons](https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/util/Comparator.html)
- [BigInteger: exact arithmetic and modular operations](https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/math/BigInteger.html)
