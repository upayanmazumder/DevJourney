ORG 0000H

MAIN:
    MOV TMOD, #06H      ; Timer0 Mode2 (8-bit auto reload)

    MOV TH0, #00H
    MOV TL0, #00H

    SETB TR0

AGAIN:
    MOV A, TL0
    MOV P0, A           ; Display on 8 LEDs connected to Port 0
    SJMP AGAIN

END