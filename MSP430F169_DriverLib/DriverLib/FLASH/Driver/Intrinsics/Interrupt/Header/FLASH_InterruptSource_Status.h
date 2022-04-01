/**
 *
 * @file FLASH_InterruptSource_Status.h
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

#ifndef DRIVERLIB_FLASH_DRIVER_INTRINSICS_INTERRUPT_HEADER_FLASH_INTERRUPTSOURCE_STATUS_H_
#define DRIVERLIB_FLASH_DRIVER_INTRINSICS_INTERRUPT_HEADER_FLASH_INTERRUPTSOURCE_STATUS_H_

#include "DriverLib/FLASH/Peripheral/Header/FLASH_Enum.h"

#pragma CODE_SECTION(FLASH__vSetStatusInterruptSource_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__enGetStatusInterruptSource_RAM, ".TI.ramfunc")

void FLASH__vSetStatusInterruptSource_RAM(FLASH_nINT_STATUS enStatus);
FLASH_nINT_STATUS FLASH__enGetStatusInterruptSource_RAM(void);

void FLASH__vSetStatusInterruptSource(FLASH_nINT_STATUS enStatus);
FLASH_nINT_STATUS FLASH__enGetStatusInterruptSource(void);

#endif /* DRIVERLIB_FLASH_DRIVER_INTRINSICS_INTERRUPT_HEADER_FLASH_INTERRUPTSOURCE_STATUS_H_ */
