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
    LD R2, DEC_0
    
      
    GETC
    OUT

    ADD R0, R0, #-15
    ADD R0, R0, #-15
    ADD R0, R0, #-15
    ADD R0, R0, #-3
    
    ADD R2, R2, R0
    ADD R2, R2, R0
    ADD R2, R2, R0
    ADD R2, R2, R0       
    ADD R2, R2, R0
    ADD R2, R2, R0
    ADD R2, R2, R0
    ADD R2, R2, R0      
    ADD R2, R2, R0
    ADD R2, R2, R0       
  
    GETC
    OUT
    ADD R0, R0, #-15
    ADD R0, R0, #-15
    ADD R0, R0, #-15
    ADD R0, R0, #-3
    
    ADD R2, R2, R0

    
    LEA R0, MSG_NEWLINE
    PUTS

	HALT
	
    ;----------
    ;Local data
    ;----------
	VALUE_TO_CONVERT .FILL x6666 ;Put in the value to be converted
	
    MSG_NEWLINE .STRINGZ "\n"
    MEG_ENTER_B .STRINGZ "\n\nYou must begin your input with the character \"b\": "
    DATA_PTR .FILL x4000 ;put x4000 into memory here
    
	DEC_16 .FILL #16
    DEC_2  .FILL #2
    DEC_0 .FILL #0
    
    SUB_PRINT_OUT .FILL x3200

	;----------
    ;Remote data
    ;----------
	.orig x4000
	VALUE_XF000 .FILL x8000 ;for the value 1000 0000 0000 0000

.end
