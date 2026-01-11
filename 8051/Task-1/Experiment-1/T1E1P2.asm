; T1E1P2.asm - Subtraction with borrow example
; A <- 0AH, R0 <- 0SH, then SUBB A,R0 (A := A - R0 - borrow)
ORG 0000H
MOV A, #0AH
MOV R0, #0SH
SUBB A, R0
H: SJMP H
END