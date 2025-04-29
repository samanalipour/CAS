ROW				RN	0
COL				RN	1
BASE			RN	2
CNT				RN	3
PNT				RN	4
TMP				RN	5
TMP2			RN	6
PNT2			RN	7
FLAG			RN	8
RETURN			RN	9
				AREA    example, CODE, READONLY
mazeSolver		PROC
				EXPORT mazeSolver
				PUSH {LR, R4-R9}
				MUL CNT, ROW, COL
				MOV PNT, #0
				MOV TMP, #0
				MOV PNT2, #0
				MOV FLAG ,#1
				MOV RETURN, #0
				
WHILE			
PHASE1				
				LDRB TMP, [BASE,PNT]
				CMP TMP, #' '
				BNE CHECK
C1				
				SUB PNT2, PNT, COL
				LDRB TMP, [BASE,PNT2]
				CMP  TMP, #97
				BLO C2
				CMP TMP,#122
				BHI	C2
				LDR TMP2, ='N'
				STRB TMP2, [BASE,PNT]
				B CHECK
				
				
C2
				ADD PNT2, PNT, #1
				LDRB TMP, [BASE,PNT2]
				CMP  TMP, #97
				BLO C3
				CMP TMP,#122
				BHI	C3
				MOV TMP2, #'E'
				STRB TMP2, [BASE,PNT]
				B CHECK				
C3
				ADD PNT2, PNT, COL
				LDRB TMP, [BASE,PNT2]
				CMP  TMP, #97
				BLO C4
				CMP TMP,#122
				BHI	C4
				MOV TMP2, #'S'
				STRB TMP2, [BASE,PNT]
				B CHECK	
C4
				SUB PNT2, PNT, #1
				LDRB TMP, [BASE,PNT2]
				CMP  TMP, #97
				BLO CHECK
				CMP TMP,#122
				BHI	CHECK
				LDR TMP2, ='W'
				STRB TMP2, [BASE,PNT]					
CHECK			ADD PNT, #1
				SUB CNT, #1
				CMP CNT, #0
				BNE	PHASE1


				MUL CNT, ROW, COL
				MOV PNT, #0
				MOV FLAG,#0
PHASE2			
				LDRB TMP, [BASE,PNT]
				CMP  TMP, #65
				BLO CHECK2
				CMP TMP, #90
				BHI	CHECK2
				ADD TMP,#32
				STRB TMP, [BASE,PNT]
				MOV FLAG, #1
				
CHECK2			ADD PNT, #1
				SUB CNT, #1
				CMP CNT, #0
				BNE	PHASE2
				ADD RETURN, #1
				MUL CNT, ROW, COL
				MOV PNT, #0
				MOV PNT2, #0
				CMP FLAG,#0
				BNE	WHILE
				MOV ROW, RETURN
				POP  {PC, R4-R9}	
				ENDP