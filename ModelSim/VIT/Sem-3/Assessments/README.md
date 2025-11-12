# ModelSim Assessments

## Assessment - 1

- [Problem Statement - 01 All Gates](01%20-%20All%20Gates/)
- [Problem Statement - 02 Half Adder and Subtractor](02%20-%20Half%20Adder%20and%20Subtractor/)
- [Problem Statement - 03 Two Level Logic Circuit](03%20-%20Two%20Level%20Logic%20Circuit/)

## Assessment - 2

- [Problem Statement - 04 Half Operator](04%20-%20Half%20Operator/)
- [Problem Statement - 05 Full Adder Structural](05%20-%20Full%20Adder%20Structural/)
- [Problem Statement - 06 Full Adder Gate Level](06%20-%20Full%20Adder%20Gate%20Level/)

## Assessment - 3

- [Problem Statement - 07 4-Bit Ripple Carry Adder](07%20-%204-Bit%20Ripple%20Carry%20Adder/)
- [Problem Statement - 08 Full Subtractor](08%20-%20Full%20Subtractor/)
- [Problem Statement - 09 2-Bit Magnitude Comparator](09%20-%202-Bit%20Magnitude%20Comparator/)
- [Problem Statement - 10 8-to-1 Multiplexer](10%20-%208-to-1%20Multiplexer/)

## Assessment - 4

- [Problem Statement - 11 1-to-8 Demultiplexer](11%20-%201-to-8%20Demultiplexer/)
- [Problem Statement - 12 8-to-3 Encoder](12%20-%208-to-3%20Encoder/)
- [Problem Statement - 13 3-to-8 Decoder](13%20-%203-to-8%20Decoder/)
- [Problem Statement - 14 JK Flip-Flop](14%20-%20JK%20Flip-Flop/)

## Assessment - 5

- [Problem Statement - 15 D Flip-Flop](15%20-%20D%20Flip-Flop/)
- [Problem Statement - 16 T Flip-Flop](16%20-%20T%20Flip-Flop/)
- [Problem Statement - 17 SISO Register](17%20-%20SISO%20Register/)
- [Problem Statement - 18 SIPO Register](18%20-%20SIPO%20Register/)
- [Problem Statement - 19 PIPO Register](19%20-%20PIPO%20Register/)

## Assessment - 6

- [Problem Statement - 20 2-Bit Upcounter](20%20-%202-Bit%20Upcounter/)
- [Problem Statement - 21 3-bit Random Counter with JK](21%20-%203-bit%20Random%20Counter%20with%20JK/)
- [Problem Statement - 22 Moore Sequence Detector](22%20-%20Moore%20Sequence%20Detector/)

# ModelSim Assessments — concise formulas & notes

This file collects compact formulas and ultra‑short notes for experiments 01–22. Use this as a quick reference while simulating or reading the top.v files in each experiment folder.

Conventions:

- Inputs/outputs: A, B, Cin, Cout, S (sum), D (data), Q (current state), Q+ (next state), J/K/T as usual.
- `+` denotes next-state (Q+). `⊕` denotes XOR.

---

01 — All Gates

- Basic gates: NOT: Y = ¬A. AND: Y = A·B. OR: Y = A + B. NAND, NOR, XNOR (Y = A ⊙ B = ¬(A ⊕ B)).
- Use De Morgan: ¬(A·B) = ¬A + ¬B ; ¬(A + B) = ¬A·¬B.

02 — Half Adder

- Sum = A ⊕ B.
- Carry = A·B.
- Note: used to add two single bits (no carry-in).

02 — Half Subtractor

- Difference = A ⊕ B.
- Borrow = ¬A · B.

03 — Two-Level Logic Circuit

- Two-level SOP form: F = Σ minterms = OR of AND terms.
- Implement with AND plane followed by OR plane; minimize using K-map for fewer product terms.

04 — Half Operator

- (Usually a small combinational operator) Follow SOP/POS simplification; verify with truth table.

05 — Full Adder (Structural) & 06 — Full Adder (Gate-level)

- Sum = A ⊕ B ⊕ Cin.
- Cout = A·B + B·Cin + A·Cin = majority(A,B,Cin).
- Structural: build from two half-adders + OR for carry.

07 — 4‑Bit Ripple Carry Adder

- Chain 4 full adders: for i=0..3: Si, Ci+1 = FA(Ai,Bi,Ci).
- Worst-case delay ≈ n·t_FA (propagation of carry through chain).

08 — Full Subtractor

- Difference = A ⊕ B ⊕ Bin.
- Borrow_out = (¬A·B) + (B·Bin) + (¬A·Bin).

09 — 2‑Bit Magnitude Comparator

- For A = A1A0 and B = B1B0:
- A>B = A1·¬B1 + (A1==B1)·A0·¬B0.
- A==B = (A1⊙B1)' · (A0⊙B0)'.
- A<B similar by symmetry.

10 — 8‑to‑1 Multiplexer

- Y = Σ (Si · Ii) where Si = decoder of select lines (S2,S1,S0).
- Implement with 3‑to‑8 decoder + ANDs + OR.

11 — 1‑to‑8 Demultiplexer

- Route input D to one of 8 outputs based on select lines: Oi = D · Si.

12 — 8‑to‑3 Encoder

- Binary encoder: outputs = binary index of active input (if only one input asserted).
- Priority encoder: if multiple inputs, highest-priority index is output; include valid bit.

13 — 3‑to‑8 Decoder

- Outputs: O = one-hot vector: O[2^in] = 1 for input combination.
- Implement as Oi = ∏(literal) for each minterm.

14 — JK Flip‑Flop

- Characteristic: Q+ = J·¬Q + ¬K·Q.
- Excitation: J=K=1 → toggle (Q+ = ¬Q). J=1,K=0 → set. J=0,K=1 → reset. J=K=0 → hold.
- Avoid level-sensitive race in master‑slave or use edge‑triggered FF.

15 — D Flip‑Flop

- Characteristic: Q+ = D.
- Use for edge-triggered registers; combine to make shift registers and counters.

16 — T Flip‑Flop

- Characteristic: Q+ = T ⊕ Q.
- T=1 toggles, T=0 holds.

17 — SISO Register (Serial-In Serial-Out)

- Shift each clock: Q[i+1] <= Q[i]; serial data shifts through chain.

18 — SIPO Register (Serial-In Parallel-Out)

- Load serial data; after n clocks outputs show n-bit word in parallel.

19 — PIPO Register (Parallel-In Parallel-Out)

- On load clock, parallel inputs are stored to outputs; used for synchronous load.

20 — 2‑Bit Upcounter

- Sequence: 00 → 01 → 10 → 11 → 00.
- Use toggling flip-flops: least significant bit toggles each clock; next bit toggles when LSB = 1 on rising edge (or use ripple/cascaded toggles).

21 — 3‑bit Random Counter with JK

- Implement using JK flip‑flops with feedback to produce pseudo‑random sequences (simple LFSR-like behavior) or asynchronous toggles.
- Key: design feedback taps to avoid short cycles; ensure not stuck in all‑zeros if using XOR taps for LFSR.

22 — Moore Sequence Detector

- Moore: output depends only on current state (not directly on input).
- Design steps: draw FSM for target sequence, assign states, derive next‑state and output equations.
- For overlapping sequences, ensure state machine retains necessary bits of history.

---

Quick verification tips

- Simulate each module with exhaustive input vectors for small widths; run waveform to confirm timing and glitches.
- For sequential circuits, reset and step several clocks; check state transitions and asynchronous hazards.
- Use testbenches with both edge and level stimuli to confirm edge-triggered behavior.

References

- Standard boolean identities, K‑map minimization, and flip‑flop characteristic equations above.

Files: each experiment folder contains a `top.v` (or Verilog source) — open that file when you need signal names or port order.
