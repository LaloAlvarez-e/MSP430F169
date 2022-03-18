/**
 *
 * @file CLOCK_StructRegister.h
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
 * @verbatim 12 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 12 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef CLOCK_PERIPHERAL_HEADER_CLOCK_STRUCTREGISTER_H_
#define CLOCK_PERIPHERAL_HEADER_CLOCK_STRUCTREGISTER_H_

typedef volatile struct
{
    volatile unsigned char MOD : 5;
    volatile unsigned char DCO : 3;
}CLOCK_DCOCTL_t;

typedef volatile struct
{
    volatile unsigned char RSEL : 3;
    volatile unsigned char XT5V : 1;
    volatile unsigned char DIVA : 2;
    volatile unsigned char XTS : 1;
    volatile unsigned char XT2OFF : 1;
}CLOCK_BCSCTL1_t;

typedef volatile struct
{
    volatile unsigned char DCOR : 1;
    volatile unsigned char DIVS : 2;
    volatile unsigned char SELS : 1;
    volatile unsigned char DIVM : 2;
    volatile unsigned char SELM : 2;
}CLOCK_BCSCTL2_t;

typedef volatile struct
{
    const unsigned char reserved1 : 1;
    volatile unsigned char IE : 1;
    const unsigned char reserved2 : 6;
}CLOCK_IE1_t;

typedef volatile struct
{
    const unsigned char reserved1 : 1;
    volatile unsigned char IFG : 1;
    const unsigned char reserved2 : 6;
}CLOCK_IFG1_t;


#endif /* CLOCK_PERIPHERAL_HEADER_CLOCK_STRUCTREGISTER_H_ */
