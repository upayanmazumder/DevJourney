; T1E3P2.asm - Transfer string from code space to 40H, then copy 40H->60H
ORG 0000H
    MOV DPTR, #0200H
    MOV R0, #40H
    MOV R1, #0EH

LOOP: 
    CLR A
    MOVC A, @A + DPTR
    MOV @R0, A
    INC R0
    INC DPTR
    DJNZ R1, LOOP

    MOV R0, #40H
    MOV R1, #60H
    MOV R3, #0EH

LOOP2: 
    CLR A
    MOV A, @R0
    MOV @R1, A
    INC R0
    INC R1
    DJNZ R3, LOOP2

HERE: 
    SJMP HERE

ORG 0200H
    DB "VIT UNIVERSITY"

END
