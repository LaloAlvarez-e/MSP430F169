/**
 *
 * @file FLASH_Address.h
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
 * @verbatim 1 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 1 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_FLASH_DRIVER_INTRINSICS_PRIMITIVES_HEADER_FLASH_ADDRESS_H_
#define DRIVERLIB_FLASH_DRIVER_INTRINSICS_PRIMITIVES_HEADER_FLASH_ADDRESS_H_

#include "DriverLib/FLASH/Peripheral/Header/FLASH_Enum.h"

#pragma CODE_SECTION(FLASH__u16GetMainStartAddress_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__u16GetInfoStartAddress_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__u16GetMainEndAddress_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__u16GetInfoEndAddress_RAM, ".TI.ramfunc")

uint16_t FLASH__u16GetMainStartAddress_RAM(void);
uint16_t FLASH__u16GetInfoStartAddress_RAM(void);
uint16_t FLASH__u16GetMainEndAddress_RAM(void);
uint16_t FLASH__u16GetInfoEndAddress_RAM(void);

uint16_t FLASH__u16GetMainStartAddress(void);
uint16_t FLASH__u16GetInfoStartAddress(void);
uint16_t FLASH__u16GetMainEndAddress(void);
uint16_t FLASH__u16GetInfoEndAddress(void);




#endif /* DRIVERLIB_FLASH_DRIVER_INTRINSICS_PRIMITIVES_HEADER_FLASH_ADDRESS_H_ */
