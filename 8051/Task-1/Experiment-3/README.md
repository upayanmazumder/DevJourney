# Experiment 3 — Data Transfer and Subroutine

Tasks:
1. Transfer the string stored in code memory at `0200H` to RAM starting at `40H`.
	- Data: `0200H: DB "VIT UNIVERSITY"`
	- See `T1E3P1.asm` for a single-pass transfer.
2. Extend the program with a subroutine to copy the transferred RAM data from `40H` to `60H`.
	- See `T1E3P2.asm` for an example that first transfers from code to `40H` then copies `40H`→`60H`.

Usage:
Assemble and single-step `T1E3P1.asm` and `T1E3P2.asm` in the simulator and inspect RAM regions `40H` and `60H`.