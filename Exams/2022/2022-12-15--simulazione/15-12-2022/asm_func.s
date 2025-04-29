						AREA	myASMcode,CODE,READONLY
addFPpositiveNumbers 	PROC
						EXPORT addFPpositiveNumbers
						PUSH {R4-R11,LR}
						LDR R4,=0X007FFFFF
						AND R5,R4,R0
						AND R6,R4,R1
						LDR R4,=1
						LSL	R4,#23
						ORR	R5,R4	;PART1,2 MANTISA OF R0
						ORR R6,R4	;PART1,2 MANTISA OF R1
						LDR R4,=0X7F800000
						AND R7,R0,R4
						AND R8,R1,R4
						LSR R7,#23	;EXPONENT 1 PART3
						LSR R8,#23	;EXPONENT 2 PART3
						CMP R7,R8
						BHS GREATER
						MOV R2,R8
						B NOT_GREATER
GREATER					MOV R2,R7	;EXPONENT1 WAS RESULT
NOT_GREATER				CMP R2,R7  
						BEQ L1
						MOV R3,R8
						SUB R3,R7
						LSR R5,R3
						B L2
L1						MOV R3,R7
						SUB R3,R8
						LSR R6,R3    
L2						
						ADD R6,R5
						MOV R5,#1
						TST R6,R5, LSL #24
						BEQ NOT_1
						LSR R6,#1	;MANTISA RESULT
						ADD R2,#1	;EXPONENT RESULT
						LSL R2,#23
NOT_1					LDR R3,=1
						LSL	R3,#23
						BIC R6,R3	;MANTISA WITH 23TH BIT ZERO
						ORR R2,R6
						MOV R0,R2	
						POP	{R4-R11,PC}
						ENDP