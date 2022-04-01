/**
 *
 * @file FLASH_Lock.h
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

#ifndef DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_LOCK_H_
#define DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_LOCK_H_

#include "DriverLib/FLASH/Peripheral/Header/FLASH_Enum.h"

#pragma CODE_SECTION(FLASH__vSetLockState_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__enGetLockState_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__vLock_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__vUnlock_RAM, ".TI.ramfunc")

void FLASH__vLock_RAM(void);
void FLASH__vUnlock_RAM(void);
void FLASH__vSetLockState_RAM(FLASH_nLOCK enLockArg);
FLASH_nLOCK FLASH__enGetLockState_RAM(void);

void FLASH__vLock(void);
void FLASH__vUnlock(void);
void FLASH__vSetLockState(FLASH_nLOCK enLockArg);
FLASH_nLOCK FLASH__enGetLockState(void);

#endif /* DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_LOCK_H_ */
