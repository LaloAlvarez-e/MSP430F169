/**
 *
 * @file FLASH_KeyViolation.h
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

#ifndef DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_KEYVIOLATION_H_
#define DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_KEYVIOLATION_H_

#include "DriverLib/FLASH/Peripheral/Header/FLASH_Enum.h"

#pragma CODE_SECTION(FLASH__vClearKeyViolation_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__vSetKeyViolation_RAM, ".TI.ramfunc")
#pragma CODE_SECTION(FLASH__enGetKeyViolation_RAM, ".TI.ramfunc")

void FLASH__vSetKeyViolation_RAM(FLASH_nINT_STATUS enStatus);
FLASH_nINT_STATUS FLASH__enGetKeyViolation_RAM(void);
void FLASH__vClearKeyViolation_RAM(void);

void FLASH__vSetKeyViolation(FLASH_nINT_STATUS enStatus);
FLASH_nINT_STATUS FLASH__enGetKeyViolation(void);
void FLASH__vClearKeyViolation(void);



#endif /* DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_KEYVIOLATION_H_ */
