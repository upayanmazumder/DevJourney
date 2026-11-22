ADVANCED COMPETITIVE CODING - SEMESTER 5

Course materials: BSTS301P / USTS301P / STS4021.

DIRECTORIES
CAT-2/ contains the existing 12 assessment programs.
FAT/ contains corrected programs for additional topics from the downloaded FAT materials.
FAT preparation includes both directories. Duplicate downloaded examples reuse CAT-2 programs.
Each directory contains README.txt input formats and EXPLANATIONS.txt algorithm notes.

RUN ONE PROGRAM
Each numbered source contains an independent public class Main.
Do not compile all sources together because they use the same class name.
Use a temporary directory to avoid class files in this repository:

work=$(mktemp -d)
cp 'FAT/02_SegmentedSieve.java' "$work/Main.java"
javac -d "$work" "$work/Main.java"
printf '1 20\n' | java -cp "$work" Main

Expected output:
2 3 5 7 11 13 17 19

Run these commands from this directory. Use a JDK with javac and java.
Inputs use whitespace-separated tokens unless a program explicitly accepts full lines.
Programs do not print input prompts.

IMPORT SCOPE
The import consolidates duplicate source variants into one runnable program per behavior.
It corrects syntax errors, hardcoded examples, numeric overflow risks, and algorithm errors.
Slides, spreadsheets, and Word documents remain in Downloads. They are not Java source files.
Simple sieve is included because the downloaded syllabus and sieve slides cover it.
The syllabus also lists incremental sieve, weighted substring, and Hamiltonian cycle.
These topics have no standalone source in this download and are not part of this source import.

Existing CAT-2 programs retain their original behavior and input formats.
In particular, CAT-2/06 uses array reversal for rotation rather than literal block swapping.
CAT-2/09 compares sums strictly before and after an index, excluding the indexed element.
CAT-2/10 treats equal values as leaders. Some downloaded examples use strict comparisons.
