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
    LD R1, DEC_10   ;R1 <-- #10
    LD R2, PTR      ;R2 <-- remote data x4000
    LD R3, DEC_1    ;R3 <-- #0
    
    DO_WHILE_LOOP
        STR R3, R2, #0  ;R2 <-- R3
        
        ADD R2, R2, x0001
        ADD R3, R3, R3 ;R0 <-- R0 + #1
        ADD R1, R1, #-1 ;R1 <-- R1 - #1
        BRp DO_WHILE_LOOP ;If(R1>0); goto DO_WHILE_LOOP
    END_DO_WHILE_LOOP
    
    LD R7, SUB_PRINT_OUT
    JSRR R7
    
    HALT ;halt program

    ;----------
    ;Local data
    ;----------
    DEC_0 .FILL #0
    DEC_1 .FILL #1
    DEC_10 .FILL #10
    PTR .FILL x4000
    VALUE_XF000 .FILL x8000 ;for the value 1000 0000 0000 0000
    
    SUB_PRINT_OUT .FILL x3200
	
	MEG_0 .STRINGZ "0"
	MSG_1 .STRINGZ "1"
    MSG_ENDL .STRINGZ "\n"
    
    DATA_PTR .FILL x4000 ;put x4000 into memory here

    ;----------
    ;Remote data
    ;----------
    .ORIG x3200
    ARRAY .BLKW #10
    
    
    

.ORIG x3200
    
    ST R7, BACKUP_R7
    
    LD R6, PTR_SUB
    LDR R2, R0, #6
    
    LD R5, DEC_10_SUB
    
    
    PRINT_COUNTER
        ;PRINTING STAGE
        LDR R1, R6, #0	            ;R1 <-- VALUE_TO_CONVERT
        LD R2, VALUE_XF000 	    	;Load in x1000 0000 0000 0000
        LD R3, DEC_16			    ;Load in the counter, initialized to 16
        
        DO_WHILE_LOOP_PRINT 	    ;used as a for loop and loop 16 times
            AND R4, R1, R2		    ;getting the first binary digit
            
            BRz PRINT_ZERO		    ;if it is not a zero, print a "1"
                LEA R0, MSG_1 	    ;load in "1" in R0
                PUTS 			    ;print R0
            BRnp END			    ;else
            PRINT_ZERO:			    ;if it is not a zero, print a "0"
                LEA R0, MEG_0   	;load in "0" in R0
                PUTS			    ;print R0
            END:
            ADD R1, R1, R1		    ;shift left one bit

            ADD R3, R3, #-1	        ;reduce counter
            BRp DO_WHILE_LOOP_PRINT ;If(R3>0); go to DO_WHILE_LOOP
        END_DO_WHILE_LOOP_PRINT

        LEA R0, MSG_ENDL 	        ;load in "\n" in R0
        PUTS 			            ;print R0
            
    ADD R6, R6, x0001               ;move to the next item

    ADD R5, R5, #-1	                ;reduce counter
    BRp PRINT_COUNTER           ;If(R3>0); go to DO_WHILE_LOOP
    END_PRINT_COUNTER
    
    LD R7, BACKUP_R7
    
    RET
    
    ;----------
    ;Local data
    ;----------
    DEC_0 .FILL #0
    DEC_10_SUB .FILL #10
    DEC_16 .FILL #16
    VALUE_XF000 .FILL x8000 ;for the value 1000 0000 0000 0000
    PTR_SUB .FILL x4000
	MEG_0 .STRINGZ "0"
	MSG_1 .STRINGZ "1"
    MSG_ENDL .STRINGZ "\n"
    
    DATA_PTR .FILL x4000 ;put x4000 into memory here
    
    BACKUP_R7 .BLKW #1
.end  
    
    


