/**
 *
 * @file FLASH_Busy.h
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

#ifndef DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_BUSY_H_
#define DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_BUSY_H_

#include "DriverLib/FLASH/Peripheral/Header/FLASH_Enum.h"

#pragma CODE_SECTION(FLASH__enGetBusyState_RAM, ".TI.ramfunc")

FLASH_nBUSY FLASH__enGetBusyState_RAM(void);
FLASH_nBUSY FLASH__enGetBusyState(void);

#endif /* DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_BUSY_H_ */
