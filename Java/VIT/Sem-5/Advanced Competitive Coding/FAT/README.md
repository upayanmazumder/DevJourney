# FAT Java practice programs

Each source is an independent program with class `Main`.
Copy the selected source to `Main.java` if your lab IDE requires that filename.
Do not compile these sources together.
See the [course index](../README.md) for compilation commands and import scope.

## Input formats

| Number | Program                                                          | Input                                        |
| ------ | ---------------------------------------------------------------- | -------------------------------------------- |
| 01     | [Sieve of Eratosthenes](01_SieveOfEratosthenes.java)             | one integer `n`                              |
| 02     | [Segmented sieve](02_SegmentedSieve.java)                        | two integers `l h`                           |
| 03     | [Euler phi](03_EulerPhi.java)                                    | one positive integer `n`                     |
| 04     | [Chinese remainder theorem](04_ChineseRemainderTheorem.java)     | `k`, followed by `k` modulus/remainder pairs |
| 05     | [Strobogrammatic check](05_StrobogrammaticCheck.java)            | one digit string                             |
| 06     | [Strobogrammatic generation](06_StrobogrammaticGenerate.java)    | one positive length `n`                      |
| 07     | [Binary palindrome](07_BinaryPalindrome.java)                    | one nonnegative long `n`                     |
| 08     | [Toggle the switch](08_ToggleSwitch.java)                        | one nonnegative long `n`                     |
| 09     | [Alice apple tree](09_AliceAppleTree.java)                       | one nonnegative long `neededApples`          |
| 10     | [Natural sort](10_NaturalSort.java)                              | `n`, then `n` lines                          |
| 11     | [Student comparator](11_StudentComparator.java)                  | `n`, then `n` lines of `roll name age`       |
| 12     | [Quicksort](12_Quicksort.java)                                   | `n`, then `n` integers                       |
| 13     | [Selection sort](13_SelectionSort.java)                          | `n`, then `n` integers                       |
| 14     | [Move hyphens](14_MoveHyphens.java)                              | one full line                                |
| 15     | [Manacher longest palindrome](15_ManacherLongestPalindrome.java) | one full line                                |
| 16     | [Sorted unique permutations](16_SortedUniquePermutations.java)   | one full line                                |
| 17     | [Combinations](17_Combinations.java)                             | `n`, then `n` integers, then `r`             |
| 18     | [Josephus](18_Josephus.java)                                     | `n k`                                        |
| 19     | [Maneuvering paths](19_ManeuveringPaths.java)                    | `rows cols`                                  |
| 20     | [Rat maze](20_RatMaze.java)                                      | `n`, then `n * n` values (0/1)               |
| 21     | [N queens](21_NQueens.java)                                      | `n`                                          |
| 22     | [Warnsdorff knight tour](22_WarnsdorffKnightTour.java)           | `n startRow startCol` (zero-based)           |
| 23     | [Block swap rotation](23_BlockSwapRotation.java)                 | `n d`, followed by `n` integers              |

See [EXPLANATIONS.md](EXPLANATIONS.md) for algorithm notes.

## Input and output conventions

Use nonnegative array counts and positive grid sizes.
Student names use one token. Natural sort consumes n full lines after its count.
Programs 14, 15, and 16 consume a full line, including spaces.
Natural sort compares digit runs numerically. Student comparison uses ordinary name order.
Josephus returns a 1-based position. Knight coordinates are zero-based.
Rat maze permits only down and right moves. N queens prints all solutions.
Warnsdorff uses a greedy heuristic. No tour found does not prove impossibility.
CRT prints the least nonnegative solution, including zero when appropriate.
Enumeration programs can produce very large outputs.

## Corrections from the download

Removed duplicate classes, invalid prose inside code, and hardcoded driver inputs.
Corrected segmented sieve indexing for lower bounds below two.
Made Manacher separators distinct from every input character.
Generated unique permutations directly in sorted order without a deduplication map.
Marked the knight start before searching and implemented the actual Warnsdorff rule.
Added a literal block swap rotation program with n = 0 and negative d support.
