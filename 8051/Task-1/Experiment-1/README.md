# Experiment 1 — Basic Arithmetic

This folder contains four simple 8051 assembly programs demonstrating basic arithmetic operations. Assemble and run them using Keil µVision or your preferred 8051 simulator.

Programs:
- `T1E1P1.asm` — Addition: adds `05H` and `05H`.
- `T1E1P2.asm` — Subtraction with borrow: subtracts `0SH` from `0AH` using `SUBB`.
- `T1E1P3.asm` — Multiply: multiplies `05H` by `05H` using `MUL AB`.
- `T1E1P4.asm` — Divide: divides `20H` by `05H` using `DIV AB`.

Usage:
1. Open the project in Keil µVision or load the `.asm` file in your simulator.
2. Assemble and single-step the program to observe register and flag changes.