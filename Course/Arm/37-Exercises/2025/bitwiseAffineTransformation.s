A_MATRIX							RN	0
B_MATRIX							RN	1
C_MATRIX							RN	2
CNT1								RN	3
CNT2								RN	4
TMP									RN	5
TMP2								RN	6
MASK								RN	7
RESULT								RN	8
									AREA MY_CODE,CODE,READONLY
bitwiseAffineTransformation			PROC
									EXPORT bitwiseAffineTransformation
									PUSH{R4-R8,LR}
									LDR CNT1,=0
									
AND_FOR
									LDRB TMP,[A_MATRIX,CNT1]
									AND  TMP,B_MATRIX
									LDR  TMP2,=1
									AND  TMP2,TMP
									LDR  CNT2,=1
									
XOR_FOR								
									LDR MASK,=1
									LSL MASK,CNT2
									TST TMP,MASK
									ITE	EQ		;EQ=BIT0
									EOREQ	TMP2,#0
									EORNE	TMP2,#1
									ADD CNT2,#1
									CMP CNT2,#8
									BNE XOR_FOR
									LDR TMP,=7
									SUB TMP,CNT1									
									LSR TMP,C_MATRIX,TMP
									AND TMP,#1
									EOR TMP2,TMP
									LDR TMP,=7
									SUB TMP,CNT1
									LSL TMP2,TMP
									ORR RESULT,TMP2
									ADD CNT1,#1
									CMP CNT1,#8
									BNE	AND_FOR
									MOV R0,RESULT
									POP{R4-R8,PC}
									ENDP
									END
										