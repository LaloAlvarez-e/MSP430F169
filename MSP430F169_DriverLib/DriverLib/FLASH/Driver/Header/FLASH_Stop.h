/**
 *
 * @file FLASH_Stop.h
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

#ifndef DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_STOP_H_
#define DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_STOP_H_

#include "DriverLib/FLASH/Peripheral/Header/FLASH_Enum.h"

#pragma CODE_SECTION(FLASH__vStopProcess_RAM, ".TI.ramfunc")

void FLASH__vStopProcess_RAM(void);
void FLASH__vStopProcess(void);

#endif /* DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_STOP_H_ */
