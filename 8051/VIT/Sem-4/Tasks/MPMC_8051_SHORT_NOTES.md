# MPMC 8051 Short Notes (Basics to Advanced)

These notes are built from your complete 8051 lab set in Task-1 to Task-5 and organized as a fast revision + teaching guide.

## 1) 8051 Core Basics

### 1.1 Architecture Snapshot
- 8-bit CPU, Harvard architecture (separate code and data spaces).
- Internal RAM: 128 bytes (00H to 7FH) in basic 8051.
- SFR space: 80H to FFH.
- Registers:
  - A (Accumulator): main ALU register.
  - B: used by MUL AB, DIV AB.
  - PSW: flags (CY, AC, OV, P, etc.).
  - SP: Stack Pointer.
  - DPTR: 16-bit data pointer for code/external memory access.
  - R0 to R7 (4 banks).

### 1.2 Important SFRs Used in Your Syllabus
- P0, P1, P2, P3: I/O ports.
- TMOD, TH0, TL0, TH1, TL1: timer/counter control and registers.
- TCON bits: TR0, TF0, TR1, TF1.
- SCON, SBUF: serial configuration and buffer.
- IE: interrupt enable.

### 1.3 Addressing Modes You Practiced
- Immediate: `MOV A, #55H`
- Register: `ADD A, R0`
- Direct: `MOV A, 30H`
- Register indirect: `MOV A, @R0`
- Code memory indexed: `MOVC A, @A+DPTR`

## 2) Arithmetic and Flag Behavior (Task-1, Exp-1)

### 2.1 Addition
```asm
MOV A, #05H
MOV R0, #05H
ADD A, R0
```
- Result in A.
- CY set if carry out of bit 7.
- AC set if carry from bit 3 to bit 4.

### 2.2 Subtraction with borrow
```asm
CLR C
MOV A, #0AH
MOV R0, #05H
SUBB A, R0
```
- Always clear carry before normal subtraction unless you intentionally chain borrows.
- Formula: `A <- A - operand - CY`

### 2.3 Multiplication
```asm
MOV A, #05H
MOV B, #05H
MUL AB
```
- 8x8 multiply.
- 16-bit result in B:A (high:low).

### 2.4 Division
```asm
MOV A, #20H
MOV B, #05H
DIV AB
```
- Quotient in A, remainder in B.
- Division by zero makes result undefined and sets OV.

## 3) Stack and Carry Counting (Task-1, Exp-2)

### 3.1 PUSH and POP rules
- `PUSH direct`:
  - SP <- SP + 1
  - RAM[SP] <- data
- `POP direct`:
  - data <- RAM[SP]
  - SP <- SP - 1

### 3.2 Register bank direct addresses
- In bank 0, `R0..R7` map to addresses `00H..07H`.
- So `PUSH 0` means push R0 (bank 0).

### 3.3 Carry counting pattern
```asm
MOV R7, #00H
MOV A, #92H
ADD A, #23H
JNC N1
INC R7
N1: ADD A, #66H
JNC N2
INC R7
N2:
```
- Useful to track overflow events across multi-byte math.

## 4) Data Transfer: Code Memory to RAM + Subroutine Thinking (Task-1, Exp-3)

### 4.1 Code memory read using MOVC
```asm
CLR A
MOVC A, @A+DPTR
```
- Reads byte from code memory at address `DPTR + A`.

### 4.2 String copy template
```asm
MOV DPTR, #0200H
MOV R0, #40H
MOV R1, #0EH
LOOP: CLR A
      MOVC A, @A+DPTR
      MOV @R0, A
      INC DPTR
      INC R0
      DJNZ R1, LOOP
```

### 4.3 Internal RAM to RAM copy
```asm
MOV R0, #40H
MOV R1, #60H
MOV R3, #0EH
L2: MOV A, @R0
    MOV @R1, A
    INC R0
    INC R1
    DJNZ R3, L2
```

## 5) Summation of Array: Binary and BCD (Task-1, Exp-4)

### 5.1 16-bit sum method
- Low byte accumulator in R2, high byte in R3.
- For each byte:
  - Add to low byte.
  - If carry, increment high byte.

```asm
; initialize first
MOV R2, #00H
MOV R3, #00H

; inside loop
MOVC A, @A+DPTR
ADD A, R2
JNC NEXT
INC R3
NEXT: MOV R2, A
```

### 5.2 BCD sum with DA A
- After `ADD`, use `DA A` for packed BCD correction.
- `DA A` adjusts A to valid BCD digits depending on AC/CY and nibble values.

```asm
ADD A, R2
DA A
JNC NEXT
INC R3
```

## 6) Hex to Decimal to ASCII Conversion (Task-1, Exp-5)

Goal: Convert 8-bit value (0 to 255) to ASCII decimal digits.

### 6.1 Core math
For number N:
- Hundreds = `N / 100`
- Tens = `(N % 100) / 10`
- Ones = `N % 10`
- ASCII digit = digit + 30H

### 6.2 Division-based extraction idea
- 8051 `DIV AB` gives quotient in A and remainder in B.
- Repeated divide by 10 can extract decimal digits.

### 6.3 Reliable fixed-width 3-digit version
```asm
; Input in A (0..255), output ASCII at 40H,41H,42H
MOV R0, #40H
MOV B, #100
DIV AB            ; A=hundreds, B=remainder
ADD A, #30H
MOV @R0, A
INC R0

MOV A, B
MOV B, #10
DIV AB            ; A=tens, B=ones
ADD A, #30H
MOV @R0, A
INC R0

MOV A, B
ADD A, #30H
MOV @R0, A
```

## 7) Port Interfacing (Task-2)

### 7.1 Alternating pattern output
- `55H = 01010101b`, `AAH = 10101010b`
- Used to test LEDs/data bus lines.

```asm
MOV P0, #55H
ACALL DELAY
MOV P0, #0AAH
ACALL DELAY
```

### 7.2 Port mirroring
```asm
MOV A, P1
MOV P2, A
```
- Reads external status from one port and forwards to another.

## 8) Timers: Theory and Formulas (Task-3 + Task-5)

### 8.1 Machine cycle
For classic 8051:
- 1 machine cycle = 12 oscillator periods.
- Timer tick frequency:

$$
 f_{tick} = \frac{f_{osc}}{12}
$$

- Tick period:

$$
 T_{tick} = \frac{12}{f_{osc}}
$$

For `f_osc = 11.0592 MHz`:

$$
 T_{tick} \approx 1.085 \ \mu s
$$

### 8.2 Mode overview
- Mode 1: 16-bit timer.
- Mode 2: 8-bit auto-reload.

### 8.3 16-bit preload formula (Mode 1)
If delay needed is `Tdelay`:

$$
 counts = \frac{T_{delay}}{T_{tick}}
$$

$$
 preload = 65536 - counts
$$

Then:
- `THx = high byte(preload)`
- `TLx = low byte(preload)`

### 8.4 8-bit auto-reload formula (Mode 2)

$$
 preload = 256 - counts
$$

Load `THx = preload`; TLx is reloaded automatically after overflow.

### 8.5 Timer polling pattern
```asm
SETB TR0
WAIT: JNB TF0, WAIT
CLR TR0
CLR TF0
```

### 8.6 Square-wave toggle pattern
```asm
CPL P1.0
; wait timer overflow
```
- One overflow gives half-period if you toggle once each overflow.

## 9) Serial Communication (Task-4 and Task-5)

### 9.1 UART mode used
`SCON = 50H`
- Mode 1 (8-bit UART, variable baud).
- REN enabled.

### 9.2 Baud rate using Timer1 Mode2
Common setup:
```asm
MOV TMOD, #20H
MOV TH1, #-3
MOV SCON, #50H
SETB TR1
```

### 9.3 Baud formula (SMOD=0)

$$
 Baud = \frac{f_{osc}}{12 \times 32 \times (256 - TH1)}
$$

At `11.0592 MHz`:
- `TH1 = FDH (-3)` gives 9600 bps.

### 9.4 TX sequence
```asm
MOV SBUF, A
WAIT: JNB TI, WAIT
CLR TI
```

### 9.5 RX sequence
```asm
WAIT: JNB RI, WAIT
MOV A, SBUF
CLR RI
```

### 9.6 String transmit from code memory
```asm
MOV DPTR, #MSG
NEXT: CLR A
      MOVC A, @A+DPTR
      JZ DONE
      MOV SBUF, A
W1:   JNB TI, W1
      CLR TI
      INC DPTR
      SJMP NEXT
DONE:
```

## 10) Interrupts (Task-5 + To Be Decided)

### 10.1 Useful vectors
- Timer0 ISR vector: 000BH
- Serial ISR vector: 0023H

### 10.2 Enable bits
- `EA` global enable.
- `ET0` timer0 interrupt enable.
- `ES` serial interrupt enable.

Example:
```asm
MOV IE, #10000010B   ; EA=1, ET0=1
```

### 10.3 ISR structure
```asm
ORG 000BH
    ; service
    RETI
```
- Keep ISR short.
- Clear relevant flag (TF0/RI/TI) inside ISR when needed.

### 10.4 Serial ISR branch pattern
```asm
JB TI, TX_PART
; else RX part
```
- Same serial interrupt vector handles both TI and RI events.

## 11) Logic Function Realization (Task-5 P3/P4)

Your files also practice implementing Boolean functions using carry-bit logic operations:
- `MOV C, bit`
- `ANL C, bit`
- `ORL C, bit`
- `CPL C`
- `MOV bit, C`

This is a compact way to implement SOP/POS expressions directly in assembly.

General approach:
1. Write truth table.
2. Derive minimized expression.
3. Map literals to bit-addressable inputs.
4. Build terms using carry logic.
5. Store output to bit/port pin.

## 12) Advanced Integration Pattern (Your main.asm)

`To Be Decided/main.asm` demonstrates integrated concepts:
- Serial receive interrupt.
- Character class check (uppercase/lowercase/other).
- State variable update (`R6`).
- Different timer-based waveform routines selected by state.

This is an important MPMC-style pattern: communication + control + timing in one firmware loop.

## 13) Common Mistakes and Fixes (Seen in Current Files)

1. Initialize accumulators/counters before loops.
- Example: set `R2`, `R3`, `R7` to 00H before using for sum/carry count.

2. Clear carry before standalone subtraction.
- Use `CLR C` before `SUBB` unless borrow chaining is intended.

3. Use valid numeric literals.
- `05H` is valid, `0SH` is a typo.

4. Verify instruction spelling.
- Example typo like `HMOV` should be `MOV`.

5. Confirm TMOD values with mode bits.
- Timer mode bits must match your intention for T0/T1.

6. Prefer deterministic loop stop conditions in conversion logic.
- Hex to decimal conversion should terminate using quotient check, not carry check.

## 14) One-Page Exam Revision Checklist

- Arithmetic: ADD, SUBB, MUL AB, DIV AB flag behavior.
- Stack: SP changes on PUSH/POP; bank0 direct addresses.
- MOVC with DPTR for code-memory tables/strings.
- 16-bit summation and carry propagation.
- BCD addition with `DA A`.
- Hex/binary to decimal ASCII conversion algorithm.
- Port input-output mirroring and test patterns.
- Timer mode1/mode2 initialization and preload calculations.
- Serial setup (`TMOD`, `TH1`, `SCON`, `TR1`, TI/RI handling).
- Interrupt vectors, IE bits, ISR design and `RETI`.
- Carry-bit based Boolean expression implementation.
- Integrated state-machine style coding with interrupts + timers.

## 15) Ready-to-Use Formula Sheet

1. Timer tick period:

$$
T_{tick} = \frac{12}{f_{osc}}
$$

2. Mode1 preload:

$$
Preload_{16} = 65536 - \frac{T_{delay}}{T_{tick}}
$$

3. Mode2 preload:

$$
Preload_{8} = 256 - \frac{T_{delay}}{T_{tick}}
$$

4. UART baud (Timer1 Mode2, SMOD=0):

$$
Baud = \frac{f_{osc}}{12 \cdot 32 \cdot (256 - TH1)}
$$

5. Hex byte to decimal digits:

$$
H = \left\lfloor\frac{N}{100}\right\rfloor,\quad
T = \left\lfloor\frac{N \bmod 100}{10}\right\rfloor,\quad
O = N \bmod 10
$$

6. ASCII digit conversion:

$$
ASCII(d) = d + 30H
$$

## 16) Suggested Study Order (Fast to Deep)

1. Arithmetic and flags.
2. Stack and memory transfer.
3. Summation (binary and BCD).
4. Number format conversion.
5. Port interfacing.
6. Timers and delay formulas.
7. Serial communication and string TX/RX.
8. Interrupt-driven programs.
9. Integrated control program (`main.asm`).

If you want, I can generate a second file with only viva questions + expected short answers from these exact experiments.