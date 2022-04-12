/**
 *
 * @file TIMERA_ClockClockDivider.h
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
 * @verbatim 9 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_TIMERA_DRIVER_GLOBAL_HEADER_TIMERA_TIMERADIVIDER_H_
#define DRIVERLIB_TIMERA_DRIVER_GLOBAL_HEADER_TIMERA_TIMERADIVIDER_H_

#include "DriverLib/TIMERA/Peripheral/Header/TIMERA_Enum.h"
#include "DriverLib/MCU/Header/MCU_Common.h"

void TIMERA__vSetClockDivider(TIMERA_nCLOCK_DIV enClockDivider);
void TIMERA__vSetClockDividerByNumber(uint8_t u8ClockDivider);

TIMERA_nCLOCK_DIV TIMERA__enGetClockDivider(void);
uint8_t TIMERA__u8GetClockDivider(void);

#endif /* DRIVERLIB_TIMERA_DRIVER_GLOBAL_HEADER_TIMERA_TIMERADIVIDER_H_ */
