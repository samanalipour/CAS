				AREA    example, CODE, READONLY
adder			PROC
				EXPORT adder
				PUSH{LR}
				ADD R0,R1
				POP{PC}	
				ENDP
				END