/**
 *
 * @file WDT_StructRegister.h
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
 * @verbatim 24 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 24 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_WDT_PERIPHERAL_HEADER_WDT_STRUCTREGISTER_H_
#define DRIVERLIB_WDT_PERIPHERAL_HEADER_WDT_STRUCTREGISTER_H_

typedef volatile struct
{
    volatile unsigned short IS : 2;
    volatile unsigned short SSEL : 1;
    volatile unsigned short CNTCL : 1;
    volatile unsigned short TMSEL : 1;
    const unsigned short reserved1 : 2;
    volatile unsigned short HOLD : 1;
    volatile unsigned short PW : 8;
}WDT_CTL_t;

typedef volatile struct
{
    volatile unsigned char IE : 1;
    const unsigned char reserved1 : 7;
}WDT_IE1_t;

typedef volatile struct
{
    volatile unsigned char IFG : 1;
    const unsigned char reserved1 : 7;
}WDT_IFG1_t;

#endif /* DRIVERLIB_WDT_PERIPHERAL_HEADER_WDT_STRUCTREGISTER_H_ */
