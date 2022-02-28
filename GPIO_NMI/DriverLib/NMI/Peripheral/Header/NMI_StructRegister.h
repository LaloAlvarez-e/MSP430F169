/**
 *
 * @file NMI_StructRegister.h
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

#ifndef DRIVERLIB_NMI_PERIPHERAL_HEADER_NMI_STRUCTREGISTER_H_
#define DRIVERLIB_NMI_PERIPHERAL_HEADER_NMI_STRUCTREGISTER_H_

typedef volatile struct
{
    const unsigned short reserved1 : 5;
    volatile unsigned short NMI_ : 1;
    volatile unsigned short NMIES : 1;
    const unsigned short reserved2 : 1;
    volatile unsigned short PW : 8;
}NMI_CTL_t;

typedef volatile struct
{
    const unsigned char reserved1 : 4;
    volatile unsigned char IE : 1;
    const unsigned char reserved2 : 3;
}NMI_IE1_t;

typedef volatile struct
{
    const unsigned char reserved1 : 4;
    volatile unsigned char IFG : 1;
    const unsigned char reserved2 : 3;
}NMI_IFG1_t;

#endif /* DRIVERLIB_NMI_PERIPHERAL_HEADER_NMI_STRUCTREGISTER_H_ */
