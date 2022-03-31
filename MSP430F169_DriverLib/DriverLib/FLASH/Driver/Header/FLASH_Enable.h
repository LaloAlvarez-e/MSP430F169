/**
 *
 * @file FLASH_Enable.h
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

#ifndef DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_ENABLE_H_
#define DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_ENABLE_H_

#include "DriverLib/FLASH/Peripheral/Header/FLASH_Enum.h"

void FLASH__vSetEnable(FLASH_nENABLE enEnableArg);
FLASH_nENABLE FLASH__enGetEnable(void);

#endif /* DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_ENABLE_H_ */
