ORG 0000H

    SETB ACC.0          ; Input A
    SETB ACC.1          ; Input B
    CLR  ACC.2          ; Input C
    SETB ACC.3          ; Input D

    MOV  C, ACC.0
    ANL  C, ACC.1
    ORL  C, ACC.2
    CPL  C
    MOV  ACC.7, C

    MOV  C, ACC.2
    CPL  C
    ANL  C, ACC.3
    CPL  C
    ANL  C, ACC.7       ; Final Output (F)

HALT:
    SJMP HALT

END
