/**
 *
 * @file WDT_StructPeripheral.h
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

#ifndef DRIVERLIB_WDT_PERIPHERAL_HEADER_WDT_STRUCTPERIPHERAL_H_
#define DRIVERLIB_WDT_PERIPHERAL_HEADER_WDT_STRUCTPERIPHERAL_H_

#include "DriverLib/WDT/Peripheral/Header/WDT_StructRegister.h"

typedef volatile struct
{
    union
    {
        volatile unsigned char IE1;
        WDT_IE1_t IE1_bits;
    };
    const unsigned char reserved1;
    union
    {
        volatile unsigned char IFG1;
        WDT_IFG1_t IFG1_bits;
    };
    const unsigned char reserved2 [285U];
    union
    {
        volatile unsigned short CTL;
        WDT_CTL_t CTL_bits;
    };
}WDT_t;

#endif /* DRIVERLIB_WDT_PERIPHERAL_HEADER_WDT_STRUCTPERIPHERAL_H_ */
