# Experiment 2 — Stack Operations & Flag Testing

This folder contains programs that demonstrate stack push/pop operations and a multi-add sequence to observe the carry flag.

Programs:
- `T1E2P1.asm` — Load values into R0–R4 and push them onto the stack.
- `T1E2P2.asm` — Set `SP = 0DH`, write values to memory locations `08H`–`0DH`, then `POP` into R0–R4.
- `T1E2P3.asm` — Push R0–R4 onto the stack and then pop them back to the same registers.
- `T1E2P4.asm` — Add sequence `92H, 23H, 66H, 87H, F5H` into A and use `JNC/INC R7` to count carry occurrences.

Usage:
1. Assemble and single-step each program in the simulator.
2. Inspect the stack region, `SP`, and registers after each instruction.