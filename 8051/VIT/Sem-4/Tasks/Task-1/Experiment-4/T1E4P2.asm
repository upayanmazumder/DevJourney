; T1E4P2.asm - Sum 10 BCD bytes (decimal adjust) into R3:R2
ORG 0000H
    MOV DPTR, #0200H
    MOV R0, #10

LOOP: 
    CLR A
    MOVC A, @A + DPTR
    ADD A, R2
    DA A
    JNC NEXT
    INC R3

NEXT: 
    INC DPTR
    MOV R2, A
    DJNZ R0, LOOP

HERE: 
    SJMP HERE

ORG 0200H
    DB 22H, 43H, 23H, 34H, 31H, 77H, 91H, 33H, 43H, 07H

END
