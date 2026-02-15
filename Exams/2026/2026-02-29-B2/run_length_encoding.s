INPUT					RN	0
N						RN	1
FLAG					RN	2
DIGIT					RN	3
CNT						RN	4
TMP1					RN	5
TMP2					RN	6
PREV					RN	7
						AREA	MY_CODE,CODE,READONLY

run_length_encoding		PROC
						EXPORT run_length_encoding
						PUSH{R4-R7,LR}
						LDR N,=0
						LDR FLAG,=1
						LDR  TMP1,=10
						MOV  TMP2,INPUT
						UDIV INPUT,TMP1
						MUL  TMP1,INPUT,TMP1
						SUB  PREV,TMP2,TMP1
						ADD  CNT,#1
						
LOOP
						CMP  INPUT,#0
						ITT   EQ
						LDREQ FLAG,=0
						BEQ   LAST
						LDR  TMP1,=10
						MOV  TMP2,INPUT
						UDIV INPUT,TMP1
						MUL  TMP1,INPUT,TMP1
						SUB  DIGIT,TMP2,TMP1	
						CMP  DIGIT,PREV
						ITT  EQ
						ADDEQ CNT,#1
						BEQ  NEXT
LAST
						LDR TMP1,=10
						MUL N,TMP1
						ADD N,PREV
						MUL N,TMP1
						ADD N,CNT
						MOV PREV,DIGIT
						LDR CNT,=1
						
NEXT
						CMP FLAG,#1
						BEQ LOOP
						
						LDR INPUT,=0
						LDR FLAG,=1
WHILE					
						CMP  N,#0
						BEQ  EXIT
						LDR  TMP1,=100
						MOV  TMP2,N
						UDIV N,TMP1
						MUL  TMP1,N,TMP1
						SUB  DIGIT,TMP2,TMP1	
						LDR  TMP1,=100
						MUL  INPUT,TMP1
						ADD  INPUT,DIGIT
						B WHILE
EXIT
						POP{R4-R7,PC}
						ENDP
						END