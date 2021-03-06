;------------------------------
;Hsu, Kenneth
;Login: shsu007 (shsu007@ucr.edu)
;Section: 023
;TA: Aditya Tammewar
;Lab 05
;------------------------------

.orig x3000
    ;----------
    ;Instructions
    ;----------
    LD R6, DEC_16
    
    GETC                    ; get the first stupid "b"
    OUT
    
    
    DO_WHILE_LOOP_INPUT;storing the numbers in x4000
        GETC
        OUT

        ADD R0, R0, #-15
        ADD R0, R0, #-15
        ADD R0, R0, #-15
        ADD R0, R0, #-3 
        
        
        ADD R2, R2, R2 ;total = 2*total
        ADD R2, R2, R0 ;total = total + R0
        
        ADD R6, R6, #-1
        BRp DO_WHILE_LOOP_INPUT
    END_DO_WHILE_LOOP_INPUT
    
    LEA R0, MSG_NEWLINE
    PUTS
    

	
    LD R7, SUB_PRINT_OUT
    JSRR R7

	HALT
	
    ;----------
    ;Local data
    ;----------
	VALUE_TO_CONVERT .FILL x6666 ;Put in the value to be converted
	
    MSG_NEWLINE .STRINGZ "\n"
    
    DATA_PTR .FILL x4000 ;put x4000 into memory here
    
	DEC_16 .FILL #16
    DEC_0 .FILL #0
    
    SUB_PRINT_OUT .FILL x3200

	;----------
    ;Remote data
    ;----------
	.orig x4000
	VALUE_XF000 .FILL x8000 ;for the value 1000 0000 0000 0000

.orig x3200

    ST R2, R2_BACKUP_x3000
    ST R7, R7_BACKUP_x3200
    
	ADD R1, R2, #0	;R0 <-- VALUE_TO_CONVERT
    
	LD R2, HEX_8000 		;Load in x1000 0000 0000 0000
	LD R3, DEC_16_SUB			;Load in the counter, initialized to 16
	
	DO_WHILE_LOOP 			;used as a for loop and loop 16 times
		AND R4, R1, R2		;getting the first binary digit
		
		BRz PRINT_ZERO		;if it is not a zero, print a "1"
			LEA R0, MSG_1 	;load in "1" in R0
			PUTS 			;print R0
		BRnp END			;else
		PRINT_ZERO:			;if it is not a zero, print a "0"
			LEA R0, MEG_0	;load in "0" in R0
			PUTS			;print R0
		END: 
		ADD R1, R1, R1		;shift left one bit

        ADD R3, R3, #-1 	;reduce counter
        BRp DO_WHILE_LOOP ;If(R1>0); go to DO_WHILE_LOOP
    END_DO_WHILE_LOOP

    LD R2, R2_BACKUP_x3000
    LD R7, R7_BACKUP_x3200
    RET
    
    ;----------
    ;Local data
    ;----------

	MEG_0 .STRINGZ "0"
	MSG_1 .STRINGZ "1"
   	DEC_16_SUB .FILL #16
    DEC_0 .FILL #0
    
    HEX_8000 .FILL x8000
    
    R2_BACKUP_x3000
    R7_BACKUP_x3200

.end
