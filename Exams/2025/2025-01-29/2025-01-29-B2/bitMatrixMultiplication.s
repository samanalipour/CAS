matrixA							RN	0
matrixB							RN	1	
matrixC							RN	2
CNT_A							RN	3
CNT_B							RN	4
CNT_ELE							RN	5
A_VALUE							RN	6
TMP1							RN	7
B_VALUE							RN	8
TMP2							RN	9
TMP3							RN	10
C_VALUE							RN	11
							AREA MY_CODE,CODE,READONLY
	
bitMatrixMultiplication		PROC
							EXPORT bitMatrixMultiplication
							PUSH{R4-R8,R10,R11,LR}
							LDR CNT_A,=0
FOR_A
							LDRB A_VALUE,[matrixA,CNT_A]
							LDR C_VALUE,=0
							LDR CNT_B,=7
FOR_B
							LDR B_VALUE,=0
							LDR CNT_ELE,=0
FOR_ELE
							LDRB TMP1,[matrixB,CNT_ELE]
							LSR  TMP1,CNT_B
							AND  TMP1,#1
							LDR  TMP2,=7
							SUB  TMP2,CNT_ELE
							LSL  TMP1,TMP2
							ORR  B_VALUE,TMP1
							ADD CNT_ELE,#1
							CMP CNT_ELE,#8
							BNE FOR_ELE
							AND TMP1,A_VALUE,B_VALUE
							LDR CNT_ELE,=1
							MOV TMP2,TMP1
							AND TMP2,#1
FOR_XOR
							MOV TMP3,TMP1
							LSR TMP3,CNT_ELE
							AND TMP3,#1
							CMP TMP3,#1
							ITE EQ
							EOREQ TMP2,#1
							EORNE TMP2,#0
							ADD CNT_ELE,#1
							CMP CNT_ELE,#8
							BNE FOR_XOR
							LSL TMP2,CNT_B
							ORR C_VALUE,TMP2
							SUB CNT_B,#1
							CMP CNT_B,#0
							BGE FOR_B
							STRB C_VALUE,[matrixC,CNT_A]
							ADD CNT_A,#1
							CMP CNT_A,#8
							BNE FOR_A
							POP{R4-R8,R10,R11,PC}
							ENDP
							END