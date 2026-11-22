# CAT-2 Java assessment programs

Each source is an independent program with class `Main`.
Copy the selected source to `Main.java` if your lab IDE requires that filename.
Do not compile these sources together.
See the [course index](../README.md) for compilation commands and import scope.

## Input formats

| Number | Program                                                                                       | Input                                 |
| ------ | --------------------------------------------------------------------------------------------- | ------------------------------------- |
| 01     | [Booth](01_BoothsAlgorithm.java)                                                              | `m q`                                 |
| 02     | [Euclid](02_EuclidsAlgorithm.java)                                                            | `a b`                                 |
| 03     | [Karatsuba](03_KaratsubaAlgorithm.java)                                                       | `x y`                                 |
| 04     | [Longest ones after flipping bit](04_LongestOnesAfterFlippingBit.java)                        | one integer                           |
| 05     | [Swap nibbles](05_SwapNibbles.java)                                                           | one byte value                        |
| 06     | [Block swap](06_BlockSwapAlgorithm.java)                                                      | `n d`, followed by `n` array elements |
| 07     | [Max product subarray](07_MaxProductSubarray.java)                                            | `n`, followed by `n` elements         |
| 08     | [Maximum hourglass sum](08_MaximumHourglassSum.java)                                          | 36 integers for a 6x6 matrix          |
| 09     | [Max equilibrium sum](09_MaxEquilibriumSum.java)                                              | `n`, followed by `n` elements         |
| 10     | [Leaders](10_LeadersInArray.java)                                                             | `n`, followed by `n` elements         |
| 11     | [Majority element](11_MajorityElement.java)                                                   | `n`, followed by `n` elements         |
| 12     | [Lexicographically first palindromic string](12_LexicographicallyFirstPalindromicString.java) | one string                            |

See [EXPLANATIONS.md](EXPLANATIONS.md) for algorithm notes, exact numeric domains, and
input/output examples.

## Output and numeric domains

Every program prints one result and never prompts. These contracts are exact; the code does
not silently wrap a valid input.

| Number | Output and numeric domain                                                                                                   |
| ------ | --------------------------------------------------------------------------------------------------------------------------- |
| 01     | Signed 32-bit `m q`; prints the exact signed 64-bit product, including `MIN_VALUE * MIN_VALUE`.                             |
| 02     | Signed 64-bit `a b`; prints the exact nonnegative gcd. The gcd `2^63` prints `9223372036854775808`.                         |
| 03     | Signed 64-bit `x y`; prints the exact arbitrary-precision product, including products beyond 64 bits.                       |
| 04     | One signed 32-bit bit pattern; prints `0..32` using at most one zero-bit flip. `-1` prints `32`.                            |
| 05     | Only the low eight bits of the integer are used; output is in `0..255`.                                                     |
| 06     | `n >= 0`, any signed 32-bit `d`; left rotation, negative `d` rotates right, `n = 0` prints nothing.                         |
| 07     | `n >= 0`, signed 64-bit elements; exact arbitrary-precision product; `n = 0` prints `0`.                                    |
| 08     | 36 signed 32-bit cells; exact 64-bit hourglass sum.                                                                         |
| 09     | `n >= 0`, signed 64-bit elements; exact prefix sums. No equilibrium prints `0`, which is ambiguous with a valid sum of `0`. |
| 10     | `n >= 0`, signed 32-bit elements; equal values may all be leaders.                                                          |
| 11     | `n >= 0`, signed 32-bit elements; no majority prints `-1`, which is ambiguous when `-1` is the majority.                    |
| 12     | One nonempty Unicode token; prints the lexicographically first palindrome or `Not possible`.                                |

FAT preparation also uses these CAT-2 topics. Use these files instead of duplicate downloads.
See [FAT programs](../FAT/README.md) for the additional topics.
