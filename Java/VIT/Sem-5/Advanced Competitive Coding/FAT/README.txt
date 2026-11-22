FAT JAVA PRACTICE PROGRAMS

Use these programs together with ../CAT-2/.
Each numbered file is an independent public class Main.
Copy one selected file to Main.java before compilation.
See ../README.txt for compilation commands and import scope.
Do not compile these sources together.

INPUT FORMATS
01 Sieve of Eratosthenes: one integer n
02 Segmented sieve: two integers l h
03 Euler phi: one positive integer n
04 Chinese remainder theorem: k, followed by k modulus/remainder pairs
05 Strobogrammatic check: one digit string
06 Strobogrammatic generation: one positive length n
07 Binary palindrome: one nonnegative long n
08 Toggle the switch: one nonnegative long n
09 Alice apple tree: one nonnegative long neededApples

10 Natural sort: n, then n lines
11 Student comparator: n, then n lines of roll name age
12 Quicksort: n, then n integers
13 Selection sort: n, then n integers
14 Move hyphens: one full line
15 Manacher longest palindrome: one full line
16 Sorted unique permutations: one full line
17 Combinations: n, then n integers, then r
18 Josephus: n k
19 Maneuvering paths: rows cols
20 Rat maze: n, then n*n values (0/1)
21 N queens: n
22 Warnsdorff knight tour: n startRow startCol (zero-based)

23 Block swap rotation: n d, followed by n integers

EXPLANATIONS.txt provides algorithms, complexity, examples, and numeric domains.
Use nonnegative array counts and positive grid sizes.
Student names use one token. Natural sort consumes n full lines after its count.
Programs 14, 15, and 16 consume a full line, including spaces.
Natural sort compares digit runs numerically. Student comparison uses ordinary name order.
Josephus returns a 1-based position. Knight coordinates are zero-based.
Rat maze permits only down and right moves. N queens prints all solutions.
Warnsdorff uses a greedy heuristic. No tour found does not prove impossibility.
CRT prints the least nonnegative solution, including zero when appropriate.
Enumeration programs can produce very large outputs.

CORRECTIONS FROM THE DOWNLOAD
Removed duplicate classes, invalid prose inside code, and hardcoded driver inputs.
Corrected segmented sieve indexing for lower bounds below two.
Made Manacher separators distinct from every input character.
Generated unique permutations directly in sorted order without a deduplication map.
Marked the knight start before searching and implemented the actual Warnsdorff rule.
Added literal block swap rotation alongside the existing reversal-based CAT-2 version.
