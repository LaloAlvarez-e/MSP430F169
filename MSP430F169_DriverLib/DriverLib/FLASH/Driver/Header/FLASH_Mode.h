/**
 *
 * @file FLASH_Mode.h
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
 * @verbatim 26 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 26 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_MODE_H_
#define DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_MODE_H_

#include "DriverLib/FLASH/Peripheral/Header/FLASH_Enum.h"

void FLASH__vSetMode(FLASH_nMODE enMode);
FLASH_nMODE FLASH__enGetMode(void);

#endif /* DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_MODE_H_ */
