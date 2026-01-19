; T1E1P1.asm - Addition example
; A <- 05H, R0 <- 05H, then A := A + R0
ORG 0000H
MOV A, #05H
MOV R0, #05H
ADD A, R0
H: SJMP H
END
