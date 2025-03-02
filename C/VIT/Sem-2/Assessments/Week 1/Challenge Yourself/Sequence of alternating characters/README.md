# Single File Programming Question

## Problem Statement

Jonas, a teacher aiming to engage his students visually, requires a program to create a sequence of characters. The sequence should alternate between two given characters, `char1` and `char2`, for a specified number, `N`.

Help Jonas with a program that prints the required sequence.

## Example

**Input:**

```
char1 = A
char2 = B
N = 4
```

**Output:**

```
A BB AAA BBBB
```

**Explanation:**

The output follows a pattern where 'A' is printed once, followed by 'B' printed twice, then 'AAA', and finally 'BBBB'.

## Input format

- The first line of input consists of a character, representing the value of `char1`.
- The second line of input consists of a character, representing the value of `char2`.
- The third line of input consists of an integer `N`, representing the numbers in the pattern.

## Output format

The output displays the generated sequence of characters, with each character sequence separated by a space.

Refer to the sample output for the formatting specifications.

## Code constraints

In this scenario, the test cases fall under the following constraints:

- `1 ≤ N ≤ 10`
- Valid ASCII characters must be given as input.

## Sample test cases

**Input 1:**

```
A
B
4
```

**Output 1:**

```
A BB AAA BBBB
```

**Input 2:**

```
T
G
2
```

**Output 2:**

```
T GG
```

**Input 3:**

```
#
$
10
```

**Output 3:**

```
# $$ ### $$$$ ##### $$$$$$ ####### $$$$$$$$ ######### $$$$$$$$$$
```
