X					RN 0			
A					RN 1			
C					RN 2			
N					RN 3
M					RN 4			
CNT					RN 5
TMP					RN 6
					AREA MY_CODE,CODE,READONLY
nextElementLCG 		PROC
					EXPORT nextElementLCG 
					PUSH{R4-R8,LR}
					LDR R4, [SP, #24]
					MUL TMP,A,X
					ADD TMP,C
					EOR	TMP,N
					UDIV A,TMP,M
					MUL  C,A,M
					SUB  X,TMP,C
					POP{R4-R8,PC}
					ENDP
					END