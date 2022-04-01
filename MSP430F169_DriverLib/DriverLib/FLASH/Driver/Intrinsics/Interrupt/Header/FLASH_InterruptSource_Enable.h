/**
 *
 * @file FLASH_InterruptSource_Enable.h
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
 * @verbatim 25 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 25 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_FLASH_DRIVER_INTRINSICS_INTERRUPT_HEADER_FLASH_INTERRUPTSOURCE_ENABLE_H_
#define DRIVERLIB_FLASH_DRIVER_INTRINSICS_INTERRUPT_HEADER_FLASH_INTERRUPTSOURCE_ENABLE_H_

#include "DriverLib/FLASH/Peripheral/Header/FLASH_Enum.h"

#pragma CODE_SECTION(FLASH__vSetEnableInterruptSource_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__vEnaInterruptSource_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__vDisInterruptSource_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__enGetEnableInterruptSource_RAM, ".TI.ramfunc")

void FLASH__vSetEnableInterruptSource_RAM(FLASH_nINT_ENABLE enState);
void FLASH__vEnaInterruptSource_RAM(void);
void FLASH__vDisInterruptSource_RAM(void);
FLASH_nINT_ENABLE FLASH__enGetEnableInterruptSource_RAM(void);

void FLASH__vSetEnableInterruptSource(FLASH_nINT_ENABLE enState);
void FLASH__vEnaInterruptSource(void);
void FLASH__vDisInterruptSource(void);
FLASH_nINT_ENABLE FLASH__enGetEnableInterruptSource(void);

#endif /* DRIVERLIB_FLASH_DRIVER_INTRINSICS_INTERRUPT_HEADER_FLASH_INTERRUPTSOURCE_ENABLE_H_ */
