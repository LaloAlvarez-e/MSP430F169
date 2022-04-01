;******************************************************************************
;* EPILOG.ASM -                                                               *
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
;-- func_epilog_#:
;--
;--  This implements epilogs for functions which pop saved registers off the
;--  runtime stack.  This is used when we are compiling for minimum code size.
;--
;--  NOTE: This function requires that the codegen allocates and saves 
;--        registers in a particular order.  If that order changes, then this
;--        code must be fixed. 
;-----------------------------------------------------------------------------

     .if $DEFINED(__LARGE_CODE_MODEL__)
        .asg  4, RETADDRSZ
     .else
        .asg  2, RETADDRSZ
     .endif

     .if __TI_EABI__
	.asg __mspabi_func_epilog, func_epilog
	.asg __mspabi_func_epilog_7, func_epilog_7
	.asg __mspabi_func_epilog_6, func_epilog_6
	.asg __mspabi_func_epilog_5, func_epilog_5
	.asg __mspabi_func_epilog_4, func_epilog_4
	.asg __mspabi_func_epilog_3, func_epilog_3
	.asg __mspabi_func_epilog_2, func_epilog_2
	.asg __mspabi_func_epilog_1, func_epilog_1
     .endif
         .global func_epilog_1, func_epilog_2, func_epilog_3, func_epilog_4
         .global func_epilog_5, func_epilog_6, func_epilog_7


    .sect  ".TI.ramfunc"
	.align 2
	.clink

func_epilog:     .asmfunc stack_usage(RETADDRSZ)
func_epilog_7:   POP    r4
func_epilog_6:   POP    r5
func_epilog_5:   POP    r6
func_epilog_4:   POP    r7
func_epilog_3:   POP    r8
func_epilog_2:   POP    r9
func_epilog_1:   POP    r10
                 RET
                 .endasmfunc

;******************************************************************************
;* BUILD ATTRIBUTES                                                           *
;*    HW_MPY_INLINE_INFO=1:  file does not have any inlined hw mpy            *
;*    HW_MPY_ISR_INFO   =1:  file does not have ISR's with mpy or func calls  *
;******************************************************************************
	.battr "TI", Tag_File, 1, Tag_HW_MPY_INLINE_INFO(1)
	.battr "TI", Tag_File, 1, Tag_HW_MPY_ISR_INFO(1)
