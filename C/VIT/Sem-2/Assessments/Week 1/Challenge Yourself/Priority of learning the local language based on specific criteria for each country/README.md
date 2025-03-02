# Single File Programming Question

## Problem Statement

Anu is planning to travel to various countries for work and leisure. She wants to determine the priority of learning the local language based on specific criteria for each country. Write a program to assist Anu in making informed decisions about language learning priorities using a switch statement.

The following are the conditions for language learning priority:

### For France (Country Code 1):

- If the English-speaking population is below 50%, prioritize learning the local language (Priority: High).
- Otherwise, prioritize other languages (Priority: Low).

### For Japan (Country Code 2):

- If the average life expectancy is above 80 years, prioritize learning the local language (Priority: High).
- Otherwise, prioritize other languages (Priority: Low).

### For Brazil (Country Code 3):

- If the percentage of the urban population is above 80%, prioritize learning the local language (Priority: High).
- Otherwise, prioritize other languages (Priority: Low).

### Input format:

- The first line of input consists of an integer, representing the country code (1 for France, 2 for Japan, 3 for Brazil).
  - If the country code is 1, the second line consists of a floating-point value N, representing the percentage of the English-speaking population.
  - If the country code is 2, the second line consists of a floating-point value A, representing the average life expectancy in years.
  - If the country code is 3, the second line consists of a floating-point value P, representing the percentage of the urban population.

### Output format:

- The output prints the priority of learning the local language in the format: "Priority: [High] or [Low]".
- If the country code is invalid, print "Invalid".

Refer to the sample output for formatting specifications.

### Code constraints:

- In this scenario, the test cases fall under the following constraints:
  - 1.0 ≤ N, A, P ≤ 100.0

### Sample test cases:

#### Input 1:

```
1
30.0
```

#### Output 1:

```
Priority: High
```

#### Input 2:

```
2
85.0
```

#### Output 2:

```
Priority: High
```

#### Input 3:

```
3
75.0
```

#### Output 3:

```
Priority: Low
```

#### Input 4:

```
2
34.5
```

#### Output 4:

```
Priority: Low
```

#### Input 5:

```
4
```

#### Output 5:

```
Invalid
```

#### Input 6:

```
1
67.7
```

#### Output 6:

```
Priority: Low
```
