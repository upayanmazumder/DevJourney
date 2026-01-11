; T1E5P1.asm - Convert hex byte in P1 to decimal ASCII bytes at RAM starting 40H
; Example: P1=0FBH (251 decimal) -> store '2','5','1' (32H,35H,31H) at 40H..
ORG 0000H
    MOV P1, #0FBH
    MOV R0, #40H
    MOV A, P1

LOOP:
    MOV B, #10
    DIV AB
    XCH A, B
    ADD A, #30H
    MOV @R0, A
    XCH A, B
    INC R0
    JNC LOOP

    END
