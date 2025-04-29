X			RN	0
N			RN	1
Y			RN	2
M			RN	3
PRIME_N		RN	4
PRIME_M		RN	5
P			RN	6
Q			RN	7
R			RN	8
TEMP		RN	9
COUNTER		RN	10
POW_X		RN	11
			AREA my_Func, CODE, READONLY
computeG	PROC
			EXPORT	computeG 
			PUSH	{R4-R11,LR}
			MOV 	COUNTER,N
			MOV 	PRIME_N,N
L1			MOV 	TEMP,#1
			TST		X,TEMP
			ITT		EQ
			LSREQ	X,1
			SUBEQ	PRIME_N,#1
			SUB 	COUNTER,#1
			CMP 	COUNTER,0
			BHI 	L1
			MUL 	POW_X,X,X
			ADD		P,PRIME_N,PRIME_N
			MOV 	COUNTER,M
			MOV 	PRIME_M,M
L2			MOV 	TEMP,#1
			TST		Y,TEMP
			ITT		EQ
			LSREQ	Y,1
			SUBEQ	PRIME_M,#1
			SUB 	COUNTER,#1
			CMP 	COUNTER,0
			BHI 	L2	
			MUL		Y,POW_X
			ADD		Q,P,PRIME_M
			MOV		TEMP,#3
			LSL		TEMP,Q
			SUB		TEMP,TEMP,Y
			MUL 	X,TEMP
			ADD		R,Q,PRIME_N
			LSR		X,#1
			MOV		R0,X
			CMP     N,M
			BHI		N_MAX
			MOV		R1,M
			B		EXIT
N_MAX		MOV		R1,N	
EXIT		POP     {R4-R11,PC}
			ENDP
			END