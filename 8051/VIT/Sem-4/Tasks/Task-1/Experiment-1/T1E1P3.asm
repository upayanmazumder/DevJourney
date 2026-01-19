; T1E1P3.asm - Multiplication example
; A <- 05H, B <- 05H, then MUL AB (A*B -> B:A)
ORG 0000H
MOV A, #05H
MOV B, #05H
MUL AB
H: SJMP H
END