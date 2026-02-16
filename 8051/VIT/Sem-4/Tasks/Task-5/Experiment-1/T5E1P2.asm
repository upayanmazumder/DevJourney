ORG 0000H
    LJMP MAIN

ORG 0023H                  ; Serial interrupt vector table
    LJMP SERIAL

ORG 0030H                  ; After vector table space
MAIN:
    SETB P1.2              ; P1.2 made as input pin
    MOV  TMOD, #20H        ; Timer 1 mode 2
    MOV  TH1, #-3          ; Set baud rate 9600
    MOV  SCON, #50H        ; One stop bit
    MOV  IE, #10010000B    ; Serial interrupt enabled
    SETB TR1               ; Timer 1 started

BACK:
    MOV  C, P1.2
    MOV  P1.7, C
    SJMP BACK

SERIAL:
    JB   TI, TRANS
    MOV  A, SBUF
    MOV  P2, A
    CLR  RI
    RETI

TRANS:
    CLR  TI
    RETI

END
