/**
 *
 * @file FLASH_Erase.h
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

#ifndef DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_ERASE_H_
#define DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_ERASE_H_

#include "DriverLib/FLASH/Peripheral/Header/FLASH_Enum.h"

#pragma CODE_SECTION(FLASH__vStartEraseProcess_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__enGetEraseProcess_RAM, ".TI.ramfunc")

void FLASH__vStartEraseProcess_RAM(FLASH_nERASE enEraseProcessArg);
FLASH_nERASE FLASH__enGetEraseProcess_RAM(void);

void FLASH__vStartEraseProcess(FLASH_nERASE enEraseProcessArg);
FLASH_nERASE FLASH__enGetEraseProcess(void);




#endif /* DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_ERASE_H_ */
