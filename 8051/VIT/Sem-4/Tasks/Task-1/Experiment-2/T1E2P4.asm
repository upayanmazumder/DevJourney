; T1E2P4.asm - Add sequence and count carries
; Adds 92H,23H,66H,87H,F5H to A, increments R7 when a carry occurs
ORG 0000H
	MOV A, #92H
	MOV R0, #23H
	ADD A, R0
	JNC L1
	INC R7
L1: 	MOV R1, #66H
	ADD A, R1
	JNC L2
	INC R7
L2: 	MOV R2, #87H
	ADD A, R2
	JNC L3
	INC R7
L3: 	MOV R3, #0F5H
	ADD A, R3
	JNC L4
	INC R7
L4:
	END