N			RN	0
CNT			RN	1
SUM			RN	2
TMP1		RN	3
TMP2		RN	4
			AREA MY_CODE,CODE,READONLY
aliquot		PROC
			EXPORT aliquot
			PUSH{LR}
			LDR SUM,=0
			LDR CNT,=1
FOR			
			UDIV TMP1,N,CNT
			MUL  TMP1,CNT
			SUB  TMP1,N,TMP1
			CMP  TMP1,#0
			BNE  NEXT_I
			ADD  SUM,CNT
NEXT_I
			ADD CNT,#1
			CMP CNT,N
			BLO FOR
perfect
			CMP N,SUM
			BNE deficient
			LDR R0,=1
			B EXIT
			
deficient
			CMP N,SUM
			BHS abundant
			LDR R0,=0
			B EXIT
			
abundant
			LDR R0,=2
EXIT	
			POP{PC}
			ENDP
			END