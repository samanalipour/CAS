X						RN	0
K						RN	1
R						RN  2
P						RN	3
Q						RN  4
I						RN  5
						AREA MY_FUNC,CODE,READONLY
nonRestoringSquareRoot	PROC
						EXPORT nonRestoringSquareRoot 
						PUSH	{R4-R11,LR}	
						MOV R,X
						MOV P,#0
						MOV Q,#0
						MOV I,#1
WHILE					CMP I,K
						BHI	RETURN
						CMP R,#0
						BEQ RETURN
						CMP R,#0
IF_CONDITION			BLE	ELSE_CONDITION
						LSL	R,#1
						SUB R6,P,Q
						LSL R6,#1
						MOV R7,#1
						LSL	R7,K
						LSR	R7,I
						SUB	R,R6
						SUB R,R7
						ADD P,P,R7
						B INC
ELSE_CONDITION
						LSL	R,#1
						SUB R6,P,Q
						LSL	R6,#1
						MOV R7,#1
						LSL	R7,K
						LSR	R7,I
						ADD R,R6
						SUB R,R7
						ADD Q,R7
INC						ADD	I,#1
						B WHILE
RETURN
						SUB R0,P,Q
						
						POP	    {R4-R11,PC}	
						ENDP