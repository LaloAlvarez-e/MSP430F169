/**
 *
 * @file FLASH_Write.h
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

#ifndef DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_WRITE_H_
#define DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_WRITE_H_

#include "DriverLib/FLASH/Peripheral/Header/FLASH_Enum.h"

#pragma CODE_SECTION(FLASH__vStartWriteProcess_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__enGetWriteProcess_RAM, ".TI.ramfunc")

void FLASH__vStartWriteProcess_RAM(FLASH_nWRITE enWriteProcessArg);
FLASH_nWRITE FLASH__enGetWriteProcess_RAM(void);

void FLASH__vStartWriteProcess(FLASH_nWRITE enWriteProcessArg);
FLASH_nWRITE FLASH__enGetWriteProcess(void);

#endif /* DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_WRITE_H_ */
