A			RN	0
LENGTH		RN	1
I			RN	2
X			RN	3
J			RN	4
TMP1		RN	5
TMP2		RN	6
			AREA MY_CODE,CODE,READONLY
				
insertionSort	PROC
				EXPORT insertionSort
				PUSH{R4-R8,LR}
				LDR I,=1
WHILE
				CMP I,LENGTH
				BHS	ENDWHILE
				LDRSB X,[A,I]
				SUB J,I,#1
WHILE2
				CMP J,#0
				BLT ENDWHILE2
				LDRSB TMP1,[A,J]
				CMP TMP1,X
				BLT ENDWHILE2
				ADD TMP2,J,#1
				STRB TMP1,[A,TMP2]
				SUB J,#1
				B WHILE2
ENDWHILE2				
				ADD TMP2,J,#1
				STRB X,[A,TMP2]
				ADD I,#1
				B WHILE
ENDWHILE
				POP{R4-R8,PC}
				ENDP

				
copyData	PROC
			EXPORT copyData
			PUSH{R4-R8,LR}
			LDR R4,=0
FOR				
;			LDRSB R3,[R0],#1
;			STRB  R3,[R1],#1
			LDRSB R3,[R0,R4]
			STRB  R3,[R1,R4]
			ADD R4,#1
			SUB R2,#1
			CMP R2,#0
			BNE	FOR
			POP{R4-R8,PC}
			ENDP

			END