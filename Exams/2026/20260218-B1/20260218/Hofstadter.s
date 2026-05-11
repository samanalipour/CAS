MEM				RN		0
DIM				RN		1
Q_MAX			RN		2
CNT 			RN		3
Q_N_1			RN		4
Q_N_2			RN		5
TMP1			RN		6
				AREA MY_CODE,CODE,READONLY
HofstadterQ		PROC
				EXPORT HofstadterQ
				PUSH{R3-R6,LR}
				
				LDR CNT,=0
				LDR TMP1,=1
				STR TMP1,[MEM,CNT]
				ADD CNT,#4
				STR TMP1,[MEM,CNT]
				MOV Q_MAX,TMP1
				CMP DIM,#2
				BLS EXIT
				LDR CNT,=3
FOR
				SUB TMP1,CNT,#1
				SUB TMP1,#1
				LSL TMP1,#2
				LDR Q_N_1,[MEM,TMP1]
				SUB TMP1,CNT,Q_N_1
				SUB TMP1,#1
				LSL TMP1,#2				
				LDR Q_N_1,[MEM,TMP1]
				
				SUB TMP1,CNT,#2
				SUB TMP1,#1
				LSL TMP1,#2
				LDR Q_N_2,[MEM,TMP1]
				SUB TMP1,CNT,Q_N_2
				SUB TMP1,#1
				LSL TMP1,#2				
				LDR Q_N_2,[MEM,TMP1]				
				
				ADD Q_N_1,Q_N_2
				SUB TMP1,CNT,#1
				LSL TMP1,#2
				STR Q_N_1,[MEM,TMP1]
				
				CMP Q_N_1,Q_MAX
				BLS NEXT
				MOV Q_MAX,Q_N_1
				
NEXT				
				ADD CNT,#1
				CMP CNT,DIM
				BLS FOR

EXIT
				MOV R0,Q_MAX	
				POP{R3-R6,PC}
				ENDP
				END