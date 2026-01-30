A				RN	0
AT				RN	1
CNT_1			RN  2
CNT_2			RN  3
X				RN  4
TMP1			RN  5
TMP2			RN  6
				AREA MY_CODE,CODE,READONLY
transposition	PROC
				EXPORT transposition
				PUSH{R4-R6,LR}
				
				LDR CNT_1,=0
FOR_1
				LDRB X,[A,CNT_1]
				LDR CNT_2,=0
FOR_2				
				MOV TMP1,X
				LDR TMP2,=7
				SUB TMP2,CNT_2
				LSR TMP1,TMP2
				AND TMP1,#1
				LDR TMP2,=7
				SUB TMP2,CNT_1
				LSL TMP1,TMP2
				LDRB TMP2,[AT,CNT_2]
				ORR TMP2,TMP1
				STRB TMP2,[AT,CNT_2]
				ADD CNT_2,#1
				CMP CNT_2,#8
				BNE FOR_2
				ADD CNT_1,#1
				CMP CNT_1,#8
				BNE FOR_1
				
				POP{R4-R6,PC}
				ENDP
				END
					