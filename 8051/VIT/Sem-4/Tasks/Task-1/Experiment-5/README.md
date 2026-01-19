# Experiment 5 — Hex-to-Decimal-to-ASCII Conversion

Task:
Write a program to read a byte from port `P1`, convert the hex byte to its decimal digits, convert those digits to ASCII, and store the ASCII bytes in RAM starting at `40H`.

Example:
- If `P1 = 0FBH` (decimal 251), the stored ASCII bytes at `40H`.. will be `32H`, `35H`, `31H` (characters `2`, `5`, `1`).

Program:
- `T1E5P1.asm` implements the conversion and writes ASCII bytes starting at RAM location `40H`.

Usage:
1. Set `P1` in the simulator to the desired input value (e.g., `0FBH`).
2. Assemble and single-step `T1E5P1.asm` and inspect RAM starting at `40H`.