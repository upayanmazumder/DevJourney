; T1E1P4.asm - Division example
; A <- 20H, B <- 05H, then DIV AB (A/B -> A=quotient, B=remainder)
ORG 0000H
MOV A, #20H
MOV B, #05H
DIV AB
H: SJMP H
END