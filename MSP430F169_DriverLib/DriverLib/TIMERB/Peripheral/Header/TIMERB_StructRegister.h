/**
 *
 * @file TIMERB_StructRegister.h
 * @copyright
 * @verbatim InDeviceMex 2021 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 5 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 5 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef TIMERB_PERIPHERAL_HEADER_TIMERB_STRUCTREGISTER_H_
#define TIMERB_PERIPHERAL_HEADER_TIMERB_STRUCTREGISTER_H_

typedef volatile struct
{
    volatile unsigned short IFG : 1;
    volatile unsigned short IE : 1;
    volatile unsigned short CLR : 1;
    volatile const unsigned short reserved1 : 1;
    volatile unsigned short MC : 2;
    volatile unsigned short ID : 2;
    volatile unsigned short SSEL : 2;
    volatile const unsigned short reserved2 : 1;
    volatile unsigned short CNTL : 2;
    volatile unsigned short CLGRP : 2;
    volatile const unsigned short reserved3 : 1;
}TIMERB_CTL_t;

typedef volatile struct
{
    volatile unsigned short R : 16;
}TIMERB_R_t;

typedef volatile struct
{
    volatile unsigned short IFG : 1;
    volatile unsigned short COV : 1;
    volatile unsigned short OUT : 1;
    volatile unsigned short CCI : 1;
    volatile unsigned short IE : 1;
    volatile unsigned short OUTMOD : 3;
    volatile unsigned short CAP : 1;
    volatile unsigned short CLLD : 2;
    volatile unsigned short SCS : 1;
    volatile unsigned short CCIS : 2;
    volatile unsigned short CM : 2;
}TIMERB_CC_CTL_t;

typedef volatile struct
{
    volatile unsigned short R : 16;
}TIMERB_CC_R_t;

typedef volatile struct
{
    volatile unsigned short IV : 16;
}TIMERB_IV_t;

#endif /* TIMERB_PERIPHERAL_HEADER_TIMERB_STRUCTREGISTER_H_ */
