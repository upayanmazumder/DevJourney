ORG 0000H

MAIN:
    MOV TMOD, #10H      ; Timer 1 Mode 1
    
AGAIN:
    MOV TH1, #0FFH
    MOV TL1, #09CH
    
    SETB TR1

WAIT:
    JNB TF1, WAIT

    CLR TR1
    CLR TF1

    CPL P2.6

    SJMP AGAIN

END