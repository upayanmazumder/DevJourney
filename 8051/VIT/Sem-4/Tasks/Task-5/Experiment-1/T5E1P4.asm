ORG 0000H

    SETB ACC.1        ; Input A
    SETB ACC.1        ; Input B

    MOV  C, ACC.1
    CPL  C
    ANL  C, ACC.0
    MOV  ACC.2, C     ; Output C

    MOV  C, ACC.0
    ANL  C, ACC.1
    MOV  ACC.3, C     ; Output D

H:  SJMP H

END