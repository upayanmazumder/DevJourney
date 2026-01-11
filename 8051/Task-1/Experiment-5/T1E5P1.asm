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
