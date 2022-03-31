/**
 *
 * @file FLASH_Interval.h
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

#ifndef DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_INTERVAL_H_
#define DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_INTERVAL_H_

#include "DriverLib/FLASH/Peripheral/Header/FLASH_Enum.h"

void FLASH__vSetInterval(FLASH_nINTERVAL enIntervalArg);
FLASH_nINTERVAL FLASH__enGetInterval(void);
uint16_t FLASH__u16GetInterval(void);

#endif /* DRIVERLIB_FLASH_DRIVER_HEADER_FLASH_INTERVAL_H_ */
