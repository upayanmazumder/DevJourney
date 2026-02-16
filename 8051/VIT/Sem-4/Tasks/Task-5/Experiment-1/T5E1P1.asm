ORG 0000H
    LJMP MAIN                  ; Jump to main

ORG 000BH                      ; Timer 0 interrupt vector
    CPL P2.1                   ; Toggle P2.1 pin
    RETI                       ; Return from ISR

ORG 0030H                      ; After vector table space

MAIN:
    MOV TMOD, #02H             ; Set Timer 0 in mode 2 (8-bit auto-reload)
    MOV P0, #0FFH              ; Set P0 as input port
    MOV TH0, #-92              ; Load reload value
    MOV IE, #10000010B         ; Enable Timer 0 interrupt
    SETB TR0                   ; Start Timer 0

BACK:
    MOV A, P0                  ; Read data from P0
    MOV P1, A                  ; Move data from P0 to P1
    SJMP BACK                  ; Infinite loop (ISR handles toggle)

END
