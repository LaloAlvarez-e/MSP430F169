/**
 *
 * @file CLOCK_Enable.h
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
 * @verbatim 13 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 13 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef CLOCK_DRIVER_HEADER_CLOCK_ENABLE_H_
#define CLOCK_DRIVER_HEADER_CLOCK_ENABLE_H_

#include "CLOCK/Peripheral/Header/CLOCK_Enum.h"
#include "MCU/Header/MCU_Common.h"

CLOCK_nSTATUS CLOCK__enSetEnable(CLOCK_nSOURCE enClockSource, CLOCK_nENABLE enEnable);
void CLOCK__vSetLFXT1Enable(CLOCK_nENABLE enEnable);
void CLOCK__vSetDCOEnable(CLOCK_nENABLE enEnable);
void CLOCK__vSetXT2Enable(CLOCK_nENABLE enEnable);

CLOCK_nENABLE CLOCK__enGetEnable(CLOCK_nSOURCE enClockSource);
CLOCK_nENABLE CLOCK__enGetLFXT1Enable(void);
CLOCK_nENABLE CLOCK__enGetDCOEnable(void);
CLOCK_nENABLE CLOCK__enGetXT2Enable(void);

#endif /* CLOCK_DRIVER_HEADER_CLOCK_ENABLE_H_ */
