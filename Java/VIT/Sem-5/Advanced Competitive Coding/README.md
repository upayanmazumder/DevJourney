# Advanced Competitive Coding — Semester 5

Course materials: BSTS301P / USTS301P / STS4021.

## Programs and explanations

| Assessment | Programs and input formats                | Algorithm notes                             |
| ---------- | ----------------------------------------- | ------------------------------------------- |
| CAT-2      | [12 assessment programs](CAT-2/README.md) | [CAT-2 explanations](CAT-2/EXPLANATIONS.md) |
| FAT        | [23 additional programs](FAT/README.md)   | [FAT explanations](FAT/EXPLANATIONS.md)     |

FAT preparation includes both directories. Duplicate downloaded examples reuse CAT-2 programs.

## Run one program

Each numbered source contains an independent public class `Main`.
Do not compile all sources together because they use the same class name.
Use a temporary directory to avoid class files in this repository.
Run these commands from this directory with a JDK that provides `javac` and `java`:

```bash
work=$(mktemp -d)
cp 'FAT/02_SegmentedSieve.java' "$work/Main.java"
javac -d "$work" "$work/Main.java"
printf '1 20\n' | java -cp "$work" Main
```

Expected output:

```text
2 3 5 7 11 13 17 19
```

Inputs use whitespace-separated tokens unless a program explicitly accepts full lines.
Programs do not print input prompts.

## Import scope

The import consolidates duplicate source variants into one runnable program per behavior.
It corrects syntax errors, hardcoded examples, numeric overflow risks, and algorithm errors.
Slides, spreadsheets, and Word documents remain in Downloads. They are not Java source files.
Simple sieve is included because the downloaded syllabus and sieve slides cover it.
The syllabus also lists incremental sieve, weighted substring, and Hamiltonian cycle.
These topics have no standalone source in this download and are not part of this source import.

## Algorithm conventions

- [CAT-2/06](CAT-2/06_BlockSwapAlgorithm.java) and [FAT/23](FAT/23_BlockSwapRotation.java) use literal block swaps for array rotation.
- [CAT-2/09](CAT-2/09_MaxEquilibriumSum.java) compares sums strictly before and after an index, excluding the indexed element.
- [CAT-2/10](CAT-2/10_LeadersInArray.java) treats equal values as leaders. Some downloaded examples use strict comparisons.

Each assessment README defines its input types, output conventions, and valid domains.
The explanations describe the corresponding implementation, not alternate downloaded variants.

## Verify the programs

Run the regression checks from the repository root with Node.js and a JDK:

```bash
node 'Java/VIT/Sem-5/Advanced Competitive Coding/verify.mjs'
```

The checks compile each of the 35 programs separately in a temporary directory.
They compare outputs with independent reference calculations and the [example fixtures](examples.json).
Keep these fixtures consistent with the inputs and outputs in the explanations.
The checks also validate N-Queens boards and every move in five sample knight tours.
Temporary class files are removed after the run, including failed runs.
