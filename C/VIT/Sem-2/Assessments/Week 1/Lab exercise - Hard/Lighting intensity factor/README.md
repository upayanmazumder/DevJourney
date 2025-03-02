# Single File Programming Question

## Problem Statement

Jim is hosting a party and wants to set up different lighting effects to create the perfect atmosphere. He has three types of lighting modes available: disco lights, strobe lights, and laser lights. Each lighting mode has a different intensity adjustment factor.

### Conditions for Intensity Adjustment:

- **Disco Lights (Mode 1):** The intensity level is multiplied by 1.5.
- **Strobe Lights (Mode 2):** The intensity level is multiplied by 2.0.
- **Laser Lights (Mode 3):** The intensity level is multiplied by 1.8.

Write a program to help Jim adjust the intensity of the lighting based on the selected mode.

### Input Format:

- The first line of input consists of an integer `N`, representing the lighting mode.
- The second line consists of a floating-point value `M`, representing the initial intensity level.

### Output Format:

The output prints `Intensity: X` where `X` is a floating point value rounded off to two decimal places, representing the adjusted intensity level.

If invalid modes other than 1, 2, or 3 are given, print `Invalid`.

Refer to the sample output for formatting specifications.

### Code Constraints:

In this scenario, the test cases fall under the following constraints:

`0.0 ≤ M ≤ 60.0`

### Sample Test Cases:

#### Input 1:

```
1
10.0
```

#### Output 1:

```
Intensity: 15.00
```

#### Input 2:

```
2
8.0
```

#### Output 2:

```
Intensity: 16.00
```

#### Input 3:

```
3
12.5
```

#### Output 3:

```
Intensity: 22.50
```

#### Input 4:

```
5
60.0
```

#### Output 4:

```
Invalid
```
