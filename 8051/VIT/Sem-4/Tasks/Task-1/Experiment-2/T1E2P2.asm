; T1E2P2.asm - Stack pointer and POP example
; Set SP = 0DH, write values to RAM 08H..0DH then POP into R0..R4
ORG 0000H
MOV SP, #0DH
MOV 08H, #10H
MOV 09H, #11H
MOV 0AH, #12H
MOV 0BH, #13H
MOV 0CH, #14H
MOV 0DH, #16H
POP 0
POP 1
POP 2
POP 3
POP 4
END