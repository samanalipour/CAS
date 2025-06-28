Y					RN	0
N					RN	1
T					RN	2
TMP1				RN	3
CNT					RN	4
TMP2				RN	5
TMP3				RN	6
RESULT				RN	7
					AREA ANSWER,CODE,READONLY
Maclaurin			PROC
					EXPORT Maclaurin
					PUSH {R4-R7,LR}
					LDR TMP1,=10
					MUL T,Y,TMP1		;T0
					LDR CNT,=1
					MOV RESULT,T
FOR 		
					RSB TMP1,T,#0		;NEG TMP1,T
					MUL TMP2,Y,Y	
					MUL TMP1,TMP2
					LSL TMP2,CNT,#1		;MUL TMP2,CNT,#2
					ADD TMP3,TMP2,#1
					MUL TMP2,TMP3
					LDR TMP3,=100
					MUL TMP2,TMP3
					SDIV T,TMP1,TMP2
					ADD  RESULT,T
					ADD CNT,#1
					CMP CNT,N
					BLS	FOR
					MOV R0, RESULT
					POP {R4-R7,PC}
					ENDP
					END