# Experiment 4 — Summation (Binary and BCD)

This experiment shows two approaches to summing a sequence of 10 bytes stored in code memory at `0200H`.

Tasks:
1. Sum 10 binary bytes and store the 16-bit result in `R3:R2` (high:low). Data at `0200H`:
	- `DB 22H, 43H, 23H, 34H, 31H, 77H, 91H, 33H, 43H, 07H`
	- See `T1E4P1.asm`.
2. Sum 10 BCD bytes and store the result in `R3:R2` using `DA A` for decimal adjust.
	- Same data as above; see `T1E4P2.asm`.

Usage:
Assemble and step through `T1E4P1.asm` and `T1E4P2.asm` to observe the accumulation and `CY`/`AC` behavior.