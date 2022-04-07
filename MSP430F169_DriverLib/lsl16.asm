;******************************************************************************
;* LSL16.ASM -                                                                *
;*                                                                            *
;* Copyright (c) 2003 Texas Instruments Incorporated                          *
;* http://www.ti.com/                                                         *
;*                                                                            *
;*  Redistribution and  use in source  and binary forms, with  or without     *
;*  modification,  are permitted provided  that the  following conditions     *
;*  are met:                                                                  *
;*                                                                            *
;*     Redistributions  of source  code must  retain the  above copyright     *
;*     notice, this list of conditions and the following disclaimer.          *
;*                                                                            *
;*     Redistributions in binary form  must reproduce the above copyright     *
;*     notice, this  list of conditions  and the following  disclaimer in     *
;*     the  documentation  and/or   other  materials  provided  with  the     *
;*     distribution.                                                          *
;*                                                                            *
;*     Neither the  name of Texas Instruments Incorporated  nor the names     *
;*     of its  contributors may  be used to  endorse or  promote products     *
;*     derived  from   this  software  without   specific  prior  written     *
;*     permission.                                                            *
;*                                                                            *
;*  THIS SOFTWARE  IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS     *
;*  "AS IS"  AND ANY  EXPRESS OR IMPLIED  WARRANTIES, INCLUDING,  BUT NOT     *
;*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR     *
;*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT     *
;*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,     *
;*  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL  DAMAGES  (INCLUDING, BUT  NOT     *
;*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,     *
;*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY     *
;*  THEORY OF  LIABILITY, WHETHER IN CONTRACT, STRICT  LIABILITY, OR TORT     *
;*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE     *
;*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.      *
;*                                                                            *
;******************************************************************************
;-----------------------------------------------------------------------------
;-- 16-bit left shift     
;-----------------------------------------------------------------------------
     .if $DEFINED(__LARGE_CODE_MODEL__)
	.asg RETA,  RET
        .asg 4,    RETADDRSZ
     .else
        .asg 2,    RETADDRSZ
     .endif

     .if __TI_EABI__
        .asg __mspabi_slli, I_LSL
        .asg __mspabi_slli_15, I_LSL_15
        .asg __mspabi_slli_14, I_LSL_14
        .asg __mspabi_slli_13, I_LSL_13
        .asg __mspabi_slli_12, I_LSL_12
        .asg __mspabi_slli_11, I_LSL_11
        .asg __mspabi_slli_10, I_LSL_10
        .asg __mspabi_slli_9, I_LSL_9
        .asg __mspabi_slli_8, I_LSL_8
        .asg __mspabi_slli_7, I_LSL_7
        .asg __mspabi_slli_6, I_LSL_6
        .asg __mspabi_slli_5, I_LSL_5
        .asg __mspabi_slli_4, I_LSL_4
        .asg __mspabi_slli_3, I_LSL_3
        .asg __mspabi_slli_2, I_LSL_2
        .asg __mspabi_slli_1, I_LSL_1
     .endif
	
            .sect  ".text"
	    .align 2
	
     .if $DEFINED(.MSP430X)
	    .global I_LSL

I_LSL:	    .asmfunc stack_usage(RETADDRSZ)
            DEC    R13            ; adjust shift ammount for RPT
            JN     I_LSL_RET      ; skip if no shifting necessary
            RPT    R13
            RLAX.W R12            ; shift by R13 - 1 
I_LSL_RET:  RET
            .endasmfunc
     .else
            .global I_LSL 
            .global I_LSL_15, I_LSL_14, I_LSL_13, I_LSL_12, I_LSL_11
            .global I_LSL_10, I_LSL_9,  I_LSL_8,  I_LSL_7,  I_LSL_6
            .global I_LSL_5,  I_LSL_4,  I_LSL_3,  I_LSL_2,  I_LSL_1 

I_LSL:      .asmfunc stack_usage(RETADDRSZ)
            AND    #15,R13        ; constain range of shift
            XOR    #15,R13        ; invert the shift count
            ADD    R13,R13        ; scale it
            ADD.W  R13,PC         ; branch to the appropriate instruct
         
I_LSL_15:   RLA    R12
I_LSL_14:   RLA    R12
I_LSL_13:   RLA    R12
I_LSL_12:   RLA    R12
I_LSL_11:   RLA    R12
I_LSL_10:   RLA    R12
I_LSL_9:    RLA    R12
I_LSL_8:    RLA    R12
I_LSL_7:    RLA    R12
I_LSL_6:    RLA    R12
I_LSL_5:    RLA    R12
I_LSL_4:    RLA    R12
I_LSL_3:    RLA    R12
I_LSL_2:    RLA    R12
I_LSL_1:    RLA    R12
            RET
            .endasmfunc
     .endif

;******************************************************************************
;* BUILD ATTRIBUTES                                                           *
;*    HW_MPY_INLINE_INFO=1:  file does not have any inlined hw mpy            *
;*    HW_MPY_ISR_INFO   =1:  file does not have ISR's with mpy or func calls  *
;******************************************************************************
	.battr "TI", Tag_File, 1, Tag_HW_MPY_INLINE_INFO(1)
	.battr "TI", Tag_File, 1, Tag_HW_MPY_ISR_INFO(1)
