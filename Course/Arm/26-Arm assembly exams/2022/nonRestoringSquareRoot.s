X				RN	0
K				RN	1
R				RN	2
P				RN	3
Q				RN	4
I				RN	5
TMP				RN	6
TMP2			RN	7
						AREA MY_CODE,CODE,READONLY
nonRestoringSquareRoot	PROC
						EXPORT nonRestoringSquareRoot
						PUSH{R4-R8,LR}
						MOV R,X
						LDR P,=0
						LDR Q,=0
						LDR I,=1

WHILE											
						CMP I,K
						BHI	RETURN
						CMP R,#0
						BEQ RETURN
						
						CMP R,#0	;IF
						BLE ELSE
						LSL R,R,#1
						SUB TMP,P,Q
						LSL TMP,#1
						SUB R,TMP
						LDR TMP,=1
						SUB TMP2,K,I
						LSL TMP,TMP2
						SUB R,TMP
						ADD P,TMP
						B IPLUS
ELSE				
						LSL R,#1
						SUB TMP2,P,Q
						LSL TMP2,#1
						ADD R,TMP2
						LDR TMP,=1
						SUB TMP2,K,I
						LSL TMP,TMP2						
						SUB R,TMP
						ADD Q,TMP
					
IPLUS					ADD I,#1					
					
						B WHILE
RETURN					
						SUB R0,P,Q
						POP{R4-R8,PC}
						ENDP
						END