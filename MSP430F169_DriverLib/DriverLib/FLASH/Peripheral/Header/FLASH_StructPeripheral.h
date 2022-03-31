/**
 *
 * @file FLASH_StructPeripheral.h
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

#ifndef DRIVERLIB_FLASH_PERIPHERAL_HEADER_FLASH_STRUCTPERIPHERAL_H_
#define DRIVERLIB_FLASH_PERIPHERAL_HEADER_FLASH_STRUCTPERIPHERAL_H_

#include "DriverLib/FLASH/Peripheral/Header/FLASH_StructRegister.h"

typedef volatile struct
{
    union
    {
        volatile unsigned char IE1;
        FLASH_IE1_t IE1_bits;
    };
    const unsigned char reserved1 [295U];
    union
    {
        volatile unsigned short CTL1;
        FLASH_CTL1_t CTL1_bits;
    };
    union
    {
        volatile unsigned short CTL2;
        FLASH_CTL2_t CTL2_bits;
    };
    union
    {
        volatile unsigned short CTL3;
        FLASH_CTL3_t CTL3_bits;
    };
}FLASH_t;

#endif /* DRIVERLIB_FLASH_PERIPHERAL_HEADER_FLASH_STRUCTPERIPHERAL_H_ */
