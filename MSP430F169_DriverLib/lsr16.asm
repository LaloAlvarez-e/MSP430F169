;******************************************************************************
;* LSR16.ASM -                                                                *
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
;---------------------------------------------------------------------------
;-- 16-bit logical right shift     
;---------------------------------------------------------------------------
     .if $DEFINED(__LARGE_CODE_MODEL__)
	.asg RETA,  RET
        .asg 4,    RETADDRSZ
     .else
        .asg 2,    RETADDRSZ
     .endif

     .if __TI_EABI__
        .asg __mspabi_srli, I_LSR
        .asg __mspabi_srli_15, I_LSR_15
        .asg __mspabi_srli_14, I_LSR_14
        .asg __mspabi_srli_13, I_LSR_13
        .asg __mspabi_srli_12, I_LSR_12
        .asg __mspabi_srli_11, I_LSR_11
        .asg __mspabi_srli_10, I_LSR_10
        .asg __mspabi_srli_9, I_LSR_9
        .asg __mspabi_srli_8, I_LSR_8
        .asg __mspabi_srli_7, I_LSR_7
        .asg __mspabi_srli_6, I_LSR_6
        .asg __mspabi_srli_5, I_LSR_5
        .asg __mspabi_srli_4, I_LSR_4
        .asg __mspabi_srli_3, I_LSR_3
        .asg __mspabi_srli_2, I_LSR_2
        .asg __mspabi_srli_1, I_LSR_1
     .endif
	
            .sect  ".text"
	    .align 2

     .if $DEFINED(.MSP430X)
            .global I_LSR 

I_LSR:      .asmfunc stack_usage(RETADDRSZ)
            DEC    R13            ; adjust shift ammount for RPT
            JN     I_LSR_RET      ; skip if no shifting necessary
            RPT    R13
            RRUX.W R12            ; shift by R13 - 1 
I_LSR_RET:  RET
            .endasmfunc
     .else
            .global I_LSR 
            .global I_LSR_15, I_LSR_14, I_LSR_13, I_LSR_12, I_LSR_11
            .global I_LSR_10, I_LSR_9,  I_LSR_8,  I_LSR_7,  I_LSR_6
            .global I_LSR_5,  I_LSR_4,  I_LSR_3,  I_LSR_2,  I_LSR_1 

I_LSR:      .asmfunc stack_usage(RETADDRSZ)
            AND    #15,R13        ; constrain range of shift     
            XOR    #15,R13        ; invert the shift count
            ADD    R13,R13        ; scale it
            ADD    R13,R13        ; scale it
            ADD    R13,PC         ; branch to the appropriate instruct

I_LSR_15:   CLRC
            RRC    R12
I_LSR_14:   CLRC
            RRC    R12
I_LSR_13:   CLRC
            RRC    R12
I_LSR_12:   CLRC
            RRC    R12
I_LSR_11:   CLRC
            RRC    R12
I_LSR_10:   CLRC
            RRC    R12
I_LSR_9:    CLRC
            RRC    R12
I_LSR_8:    CLRC
            RRC    R12
I_LSR_7:    CLRC
            RRC    R12
I_LSR_6:    CLRC
            RRC    R12
I_LSR_5:    CLRC
            RRC    R12
I_LSR_4:    CLRC
            RRC    R12
I_LSR_3:    CLRC
            RRC    R12
I_LSR_2:    CLRC
            RRC    R12
I_LSR_1:    CLRC
            RRC    R12
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
