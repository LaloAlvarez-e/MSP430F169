/**
 *
 * @file NMI_StructPeripheral.h
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

#ifndef DRIVERLIB_NMI_PERIPHERAL_HEADER_NMI_STRUCTPERIPHERAL_H_
#define DRIVERLIB_NMI_PERIPHERAL_HEADER_NMI_STRUCTPERIPHERAL_H_

#include "DriverLib/NMI/Peripheral/Header/NMI_StructRegister.h"

typedef volatile struct
{
    union
    {
        volatile unsigned char IE1;
        NMI_IE1_t IE1_bits;
    };
    const unsigned char reserved1;
    union
    {
        volatile unsigned char IFG1;
        NMI_IFG1_t IFG1_bits;
    };
    const unsigned char reserved2 [285U];
    union
    {
        volatile unsigned char CTL;
        NMI_CTL_t CTL_bits;
    };
}NMI_t;

#endif /* DRIVERLIB_NMI_PERIPHERAL_HEADER_NMI_STRUCTPERIPHERAL_H_ */
