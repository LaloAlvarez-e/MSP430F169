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

#pragma CODE_SECTION(FLASH__uptrGetMainStartAddress_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__uptrGetInfoStartAddress_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__uptrGetMainEndAddress_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__uptrGetInfoEndAddress_RAM, ".TI.ramfunc")

uintptr_t FLASH__uptrGetMainStartAddress_RAM(void);
uintptr_t FLASH__uptrGetInfoStartAddress_RAM(void);
uintptr_t FLASH__uptrGetMainEndAddress_RAM(void);
uintptr_t FLASH__uptrGetInfoEndAddress_RAM(void);

uintptr_t FLASH__uptrGetMainStartAddress(void);
uintptr_t FLASH__uptrGetInfoStartAddress(void);
uintptr_t FLASH__uptrGetMainEndAddress(void);
uintptr_t FLASH__uptrGetInfoEndAddress(void);




#endif /* DRIVERLIB_FLASH_DRIVER_INTRINSICS_PRIMITIVES_HEADER_FLASH_ADDRESS_H_ */
