# ACC: one-hour crash sheet

**Use this sheet instead of the longer guide when only one hour remains.**
Learn the input scaffold first. Then study the state each algorithm needs.
The tables cover all 35 repository programs. CAT-2/06 and FAT/23 share one algorithm.
One hour cannot guarantee mastery of every question or hidden test.

## Your 60 minutes

| Minutes | Action                                       |
| ------- | -------------------------------------------- |
| 0–10    | Type the complete Java program below         |
| 10–20   | Learn the library table and GCD helper       |
| 20–35   | Read the number, bit, and array recipes      |
| 35–45   | Read the string, sorting, and search recipes |
| 45–50   | Review the five difficult methods            |
| 50–60   | Complete the closed-sheet test               |

Choose priorities by reuse, not guessed exam frequency.
Read the statement before choosing a method. The same input shape can describe different problems.

## 1. One complete program to understand

This program reads an array and prints its majority element.
A majority occurs **more than n/2 times**. If none exists, this version prints `-1`.

```java
import java.util.*;
import java.math.BigInteger;

public class Main {
  static int majority(int[] a) {
    int candidate = 0, votes = 0;
    for (int x : a) {
      if (votes == 0) candidate = x;
      votes += x == candidate ? 1 : -1;
    }
    int count = 0;
    for (int x : a) {
      if (x == candidate) count++;
    }
    return count > a.length / 2 ? candidate : -1;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = sc.nextInt();
    }
    System.out.println(majority(a));
  }
}
```

Input `5 2 2 1 1 2` produces `2`.
Replace `majority` and its call when the question asks for another array algorithm.

- `main` starts the program. Helpers belong inside `Main`, but outside `main`.
- `static` lets `main` call a helper without creating an object.
- `int[] a` is an integer array. Its indices start at zero.
- `a.length` is the number of elements. Valid indices end at `a.length-1`.
- `for (int x : a)` visits values. An indexed loop also gives their positions.
- `condition ? first : second` selects first when true and second when false.
- `return` ends a helper. `System.out.println` prints a result.
- Use `==` for primitive equality. Use `.equals()` for string or `BigInteger` contents.

**Why two passes?** Voting selects a candidate. The second pass proves that it is a majority.
For `1 2 3`, voting still selects a candidate, but no majority exists.

## 2. Input, libraries, and arithmetic

| Need                                           | Java spelling                                            |
| ---------------------------------------------- | -------------------------------------------------------- |
| Ordinary integer / wider integer               | `sc.nextInt()` / `sc.nextLong()`                         |
| One token / complete line                      | `sc.next()` / `sc.nextLine()`                            |
| After a numeric token, read the next full line | Consume the current remainder with `sc.nextLine()` first |
| Array / matrix                                 | `new int[n]` / `new int[rows][cols]`                     |
| String character / length                      | `s.charAt(i)` / `s.length()`                             |
| Mutable characters                             | `s.toCharArray()`                                        |
| Slice with excluded end index                  | `s.substring(start, end)`                                |
| Ordinary ascending sort                        | `Arrays.sort(a)`                                         |
| Fill an array                                  | `Arrays.fill(a, value)`                                  |
| Output buffer                                  | `StringBuilder out = new StringBuilder();`               |
| Append / reverse / convert buffer              | `out.append(x)` / `out.reverse()` / `out.toString()`     |
| Larger / smaller                               | `Math.max(a,b)` / `Math.min(a,b)`                        |
| Safe integer comparison                        | `Integer.compare(a,b)`, not `a-b`                        |
| Character counts in sorted order               | `TreeMap<Integer,Integer>`                               |
| Increment a map count                          | `map.put(key, map.getOrDefault(key,0)+1)`                |
| Append a Unicode code point                    | `out.appendCodePoint(cp)`                                |
| Custom ordering                                | `Comparator.comparing(...).thenComparingInt(...)`        |
| Largest possible negative starting maximum     | `Long.MIN_VALUE` or the first element                    |

`java.util.*` supplies Scanner, Arrays, maps, lists, and Comparator.
`String`, `StringBuilder`, and `Math` need no import.
Do not use an extra `nextLine()` when the requested string is on the current line.
Do not read an initial test count unless the question specifies one.

**Output:** print exactly the requested values. Avoid prompts, labels, brackets, and commas unless required.
`System.out.println(a)` does not print an integer array's elements.

### Numeric rules

- `int` holds about ±2.1 billion. `long` holds about ±9.22 quintillion.
- `long result = 1L*a*b` widens before multiplying two `int` values.
- `long result = a*b` can overflow before assignment.
- Integer division discards the fractional part. `%` calculates the remainder.
- `Math.floorMod(d,n)` normalizes a rotation distance. Handle n zero first.
- Repeated products and large path counts may exceed `long`. Use `BigInteger` then.

| Ordinary operation                 | Exact `BigInteger` operation                                     |
| ---------------------------------- | ---------------------------------------------------------------- |
| Read / constants                   | `new BigInteger(sc.next())`, `BigInteger.ZERO`, `BigInteger.ONE` |
| Convert a long                     | `BigInteger.valueOf(x)`                                          |
| Add / subtract / multiply          | `a.add(b)` / `a.subtract(b)` / `a.multiply(b)`                   |
| Divide / remainder                 | `a.divide(b)` / `a.remainder(b)`                                 |
| Compare / equality                 | `a.compareTo(b)` / `a.equals(b)`                                 |
| Minimum / maximum / absolute value | `a.min(b)` / `a.max(b)` / `a.abs()`                              |
| Positive modulus / inverse         | `a.mod(m)` / `a.modInverse(m)`                                   |

Save arithmetic results: `a = a.add(b)`. `BigInteger` does not change a automatically.
`modInverse` requires positive m and `gcd(a,m) == 1`.

### Reusable GCD helper

Place this helper beside `majority`, not inside `main`.
It assumes nonnegative `long` inputs.
Use the repository's `BigInteger` version for signed minimum values.

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

`gcd(48,18)` follows `48,18 → 18,12 → 12,6 → 6,0`. The answer is `6`.

## 3. Number and bit recipes

**Notation:** n is a count or bound. a is an array. lo and hi are interval bounds.
Recipes use mathematical shorthand. Translate arithmetic into methods when using `BigInteger`.
Coprime numbers have GCD one. A nibble contains four bits.

| Program and recognition cue                                                                             | State or rule to reconstruct                                                                     | Example input → output                       |
| ------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------ | -------------------------------------------- |
| [CAT-2/01 Booth](CAT-2/01_BoothsAlgorithm.java): signed multiplication                                  | Track accumulator A, multiplier Q, and previous bit. See section 6                               | `6 -7` → `-42`                               |
| [CAT-2/02 Euclid](CAT-2/02_EuclidsAlgorithm.java): greatest common divisor                              | Repeat `(a,b) = (b,a%b)` until b reaches zero                                                    | `48 18` → `6`                                |
| [CAT-2/03 Karatsuba](CAT-2/03_KaratsubaAlgorithm.java): three recursive products                        | Split numbers into halves. See section 6                                                         | `1234 5678` → `7006652`                      |
| [CAT-2/04 Longest ones](CAT-2/04_LongestOnesAfterFlippingBit.java): flip at most one zero               | Track current run and run before the latest zero. Maximize `previous+current+1`, capped at 32    | `1775` → `8`                                 |
| [CAT-2/05 Nibble swap](CAT-2/05_SwapNibbles.java): exchange four-bit halves                             | `((x & 15) << 4) \| ((x & 240) >>> 4)`                                                           | `100` → `70`                                 |
| [CAT-2/06](CAT-2/06_BlockSwapAlgorithm.java) / [FAT/23](FAT/23_BlockSwapRotation.java): left rotation   | Input is `n d`, then n values. Swap equal-sized block pieces until both unfinished lengths match | `5 2 1 2 3 4 5` → `3 4 5 1 2`                |
| [FAT/01 Sieve](FAT/01_SieveOfEratosthenes.java): list primes through n                                  | Mark each prime's multiples from p*p. Print unmarked indices from 2                              | `10` → `2 3 5 7`                             |
| [FAT/02 Segmented sieve](FAT/02_SegmentedSieve.java): primes in an interval                             | Generate base primes through sqrt(hi). Mark each block from `max(p*p,ceil(lo/p)*p)`              | `10 20` → `11 13 17 19`                      |
| [FAT/03 Phi](FAT/03_EulerPhi.java): count coprime values                                                | Start result=n. For each distinct prime factor p, apply `result -= result/p` once                | `48` → `16`                                  |
| [FAT/04 CRT](FAT/04_ChineseRemainderTheorem.java): simultaneous remainders                              | Input is k modulus/remainder pairs. Merge consistent constraints. See section 6                  | `2 4 2 6 4` → `10`                           |
| [FAT/05 Strobogrammatic check](FAT/05_StrobogrammaticCheck.java): rotated digits                        | Check mirrored pairs: 00, 11, 88, 69, 96                                                         | `69` → `true`                                |
| [FAT/06 Strobogrammatic generation](FAT/06_StrobogrammaticGenerate.java): all numbers of a given length | Fill mirrored pairs recursively. Exclude outer 00. Centers use 0, 1, 8                           | `2` → `11 69 88 96`                          |
| [FAT/07 Binary palindrome](FAT/07_BinaryPalindrome.java): same binary digits backward                   | Compare lowest and highest meaningful bits, then move inward                                     | `9` → `true` because its binary form is 1001 |
| [FAT/08 Switches](FAT/08_ToggleSwitch.java): count switches left on                                     | Only perfect-square positions remain on. Answer is exact `floor(sqrt(n))`                        | `15` → `3`                                   |
| [FAT/09 Apple tree](FAT/09_AliceAppleTree.java): minimum garden perimeter                               | Find smallest r with `2*r*(r+1)*(2*r+1) >= needed`. Print 8*r                                    | `13` → `16`                                  |
| [FAT/18 Josephus](FAT/18_Josephus.java): eliminate every k-th person                                    | Start survivor=0. For sizes 2 through n, use `(survivor+k%size)%size`. Print survivor+1          | `7 3` → `4`                                  |

**Bit syntax:** `&` masks, `|` combines, and `^` means XOR, not exponentiation.
`<<` shifts left. `>>` preserves the sign. `>>>` fills zeros from the left.
For longest ones, inspect exactly 32 bits with `>>>`. Negative input can prevent a `>>` loop from ending.
At each zero, copy current into previous. Then reset current to zero.

**Number traps:** 0 and 1 are not prime. Phi removes every power of each prime factor.
For an interval block, store the mark for value v at `v-lo`, not v.
A strobogrammatic middle can contain only 0, 1, or 8.
For large square roots, compare `mid <= n/mid` to avoid multiplication overflow.

## 4. Array recipes

A **contiguous subarray** uses consecutive positions without skipping.
For these programs, input normally starts with n and then n values.
Hourglass input is the exception: it contains 36 cells without dimensions.

| Program and recognition cue                                  | State or update rule                                                                                        | Example input → output       |
| ------------------------------------------------------------ | ----------------------------------------------------------------------------------------------------------- | ---------------------------- |
| [CAT-2/07 Maximum product](CAT-2/07_MaxProductSubarray.java) | Track maximum mx and minimum mn ending here. Swap them before a negative value. Update both from that value | `3 -2 -3 4` → `24`           |
| [CAT-2/08 Hourglass](CAT-2/08_MaximumHourglassSum.java)      | In every valid 3×3 window, add three top cells, the center, and three bottom cells                          | A 6×6 matrix of ones → `7`   |
| [CAT-2/09 Equilibrium](CAT-2/09_MaxEquilibriumSum.java)      | Start left=0, right=total. Subtract x from right. Test equality. Then add x to left                         | `3 1 3 1` → `1`              |
| [CAT-2/10 Leaders](CAT-2/10_LeadersInArray.java)             | Scan backward. Keep each value at least the current right-side maximum. Restore original output order       | `6 16 17 4 3 5 2` → `17 5 2` |
| [CAT-2/11 Majority](CAT-2/11_MajorityElement.java)           | Vote for a candidate. Recount it. Require frequency strictly above n/2                                      | `5 2 2 1 1 2` → `2`          |

**Maximum product updates:** `mx=max(x,mx*x)` and `mn=min(x,mn*x)` after the optional swap.
Keep a separate best answer across positions. Initialize from the first element for nonempty input.
For `[-2,3,-4]`, keeping the minimum product allows the final answer `24`.

**Three traps:** equilibrium excludes the pivot. Equal values count as leaders here. Majority requires a second pass.
Start a maximum from the first value or a negative bound, not zero.
Use long arithmetic from the first hourglass addition.

## 5. Strings, sorting, and search

**Recursion:** define a stopping condition first. Each call must approach that condition.
**Backtracking:** choose, recurse, undo. Keep different candidate branches independent.
**Dynamic programming:** store answers to smaller repeated problems instead of recalculating them.

| Program and recognition cue                                                                              | Essential construction                                                                                          | Example input → output                              |
| -------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------- | --------------------------------------------------- |
| [CAT-2/12 First palindrome](CAT-2/12_LexicographicallyFirstPalindromicString.java): rearrange characters | Count characters. Reject more than one odd frequency. Build the sorted half, optional center, and reversed half | `aabb` → `abba`                                     |
| [FAT/10 Natural sort](FAT/10_NaturalSort.java): digit-aware ordering                                     | Compare complete digit runs numerically. Compare significant lengths before digits to avoid overflow            | Lines `file10`, `file2` → `file2`, `file10`         |
| [FAT/11 Student comparator](FAT/11_StudentComparator.java)                                               | Read roll/name/age records. Compare name, then age, then roll. Print roll/name/age                              | `2 1 Zed 18 2 Amy 20` → `2 Amy 20`, then `1 Zed 18` |
| [FAT/12 Quicksort](FAT/12_Quicksort.java)                                                                | Choose last pivot. Move smaller values left. Place pivot. Sort both partitions                                  | `3 3 1 2` → `1 2 3`                                 |
| [FAT/13 Selection sort](FAT/13_SelectionSort.java)                                                       | Find the unsorted suffix's minimum. Swap it into the next position                                              | `3 3 1 2` → `1 2 3`                                 |
| [FAT/14 Hyphens](FAT/14_MoveHyphens.java)                                                                | Count hyphens. Preserve other characters in a buffer. Print hyphens first                                       | `a-b--c` → `---abc`                                 |
| [FAT/15 Manacher](FAT/15_ManacherLongestPalindrome.java): longest contiguous palindrome                  | Reuse mirrored palindrome radii. See section 6                                                                  | `babad` → `bab`                                     |
| [FAT/16 Unique permutations](FAT/16_SortedUniquePermutations.java)                                       | Sort first. Find the next rightmost ascent. Swap with its rightmost larger value. Reverse the suffix            | `ABB` → `ABB`, `BAB`, `BBA`                         |
| [FAT/17 Combinations](FAT/17_Combinations.java)                                                          | Read n values, then r. Choose increasing indices recursively. Print when depth reaches r                        | `3 1 2 3 2` → `1 2`, `1 3`, `2 3`                   |
| [FAT/19 Grid paths](FAT/19_ManeuveringPaths.java)                                                        | Initialize one DP row to ones. For later rows, use `dp[c] = dp[c].add(dp[c-1])`                                 | `3 3` → `6`                                         |
| [FAT/20 Maze](FAT/20_RatMaze.java)                                                                       | Read n and n×n cells. Mark open cells. Try down, then right. Undo failed choices                                | `1 0` → `No solution`                               |
| [FAT/21 N queens](FAT/21_NQueens.java)                                                                   | Place one queen per row. Exclude used columns and both diagonals. Undo after recursion                          | `1` → board `1`                                     |
| [FAT/22 Warnsdorff](FAT/22_WarnsdorffKnightTour.java)                                                    | Mark start 1. Choose the unvisited destination with fewest onward moves                                         | `1 0 0` → board `1`                                 |

For natural sort, input is n followed by n full lines. The table shows only the string portion.
Hyphens, Manacher, and permutations also accept full lines.
Use `nextLine()`, not `next()`, when spaces belong to the string.

**Do not confuse these tasks:**

- A palindrome check only answers true or false.
- Palindrome construction rearranges all characters.
- A palindromic substring preserves consecutive input characters.
- Permutations reorder all positions. Combinations select r increasing positions.
- Ordinary string sorting places `file10` before `file2`. Numeric-aware sorting reverses that pair.

For queens at row r and column c, diagonal keys are `r+c` and `r-c+n-1`.
Mark the column and both diagonals before recursion. Remove all three marks afterward.
Maze prints one path. Queens prints every valid board in this repository.
Warnsdorff is a heuristic. `No tour found` does not prove that no tour exists.

## 6. Five difficult methods: learn their decisive rules

### Booth

Inspect `(Q0, previousBit)` for 32 rounds.
For 01, add M to A. For 10, subtract M from A. For 00 or 11, do neither.
Then shift the combined state arithmetically.
The repository uses a 33-bit accumulator for signed minimum inputs.
Ordinary `m*q` does not demonstrate Booth.

### Karatsuba

Split `x=a*p+b` and `y=c*p+d`, where p is a power of ten.
Recursively compute `u=a*c`, `v=b*d`, and `w=(a+b)*(c+d)`.
Return `u*p*p + (w-u-v)*p + v`.
Handle signs separately. Stop splitting when a factor has one digit.

### Generalized CRT

Maintain `x=A mod M`, initially `A=0` and `M=1`.
For a new pair `(m,a)`, calculate `g=gcd(M,m)` and `difference=a-A`.
If g does not divide difference, no solution exists.
Otherwise set `q=m/g`.
For q one, use t zero. Otherwise calculate `t=((difference/g)*inverse(M/g)) mod q`.
The inverse uses modulus q.
Calculate `newM=M*q`, then `newA=(A+M*t) mod newM`.
Replace A and M with those new values.

### Manacher

Insert separators between characters. Use distinct sentinels at both ends.
Store each center's palindrome radius in p[i]. Track the rightmost palindrome's center and right boundary.
Inside that boundary, initialize from mirror `2*center-i`.
Use the smaller of the mirror radius and `right-i`.
Then expand while the surrounding values match.
Update the boundary when the palindrome extends farther right.
For this transformation, length is the best radius and start is `(bestCenter-bestLength)/2`.

### Literal block swap

Normalize d. Split the array into left length i=d and right length j=n-d.
When i<j, swap i elements at `d-i` with those at `d+j-i`. Reduce j by i.
When i>j, swap j elements at `d-i` with those at d. Reduce i by j.
When lengths match, swap the final equal blocks.
Here `swap(start1,start2,count)` exchanges count pairs of array elements.
Triple reversal gives a rotation, but it does not demonstrate literal block swapping.

## 7. Last ten minutes: close the sheet

**First six minutes:** write the majority program from memory.
Test a real majority and a case without one.
If the scaffold fails, correct it before studying another difficult method.

**Next three minutes:** calculate these answers without running code.

| Task             | Input          | Answer         |
| ---------------- | -------------- | -------------- |
| Maximum product  | `4 2 -3 -2 4`  | `48`           |
| Equilibrium      | `5 1 2 99 2 1` | `3`            |
| Nibble swap      | `171`          | `186`          |
| Josephus         | `7 3`          | `4`            |
| Grid paths       | `3 3`          | `6`            |
| First palindrome | `abc`          | `Not possible` |

**Final minute:** check input order, numeric types, failure text, and output order.
Check whether the question requires a named algorithm. A matching sample does not prove the method is acceptable.

**MCQ memory:** selection sort is `O(n²)`. Quicksort averages `O(n log n)` but can take `O(n²)`.
Sieve takes `O(n log log n)`. Manacher takes `O(L)` for string length L.
Printing n! permutations already requires a very large output.

For complete implementations and broader limits, use the [three-hour guide](CRASH_COURSE.md) or the linked sources.
This sheet covers the imported programs, not the three syllabus topics without imported source.
