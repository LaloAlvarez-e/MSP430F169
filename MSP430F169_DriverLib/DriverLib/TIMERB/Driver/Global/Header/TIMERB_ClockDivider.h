/**
 *
 * @file TIMERB_ClockClockDivider.h
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

#ifndef DRIVERLIB_TIMERB_DRIVER_GLOBAL_HEADER_TIMERB_TIMERBDIVIDER_H_
#define DRIVERLIB_TIMERB_DRIVER_GLOBAL_HEADER_TIMERB_TIMERBDIVIDER_H_

#include "DriverLib/TIMERB/Peripheral/Header/TIMERB_Enum.h"
#include "DriverLib/MCU/Header/MCU_Common.h"

void TIMERB__vSetClockDivider(TIMERB_nCLOCK_DIV enClockDivider);
void TIMERB__vSetClockDividerByNumber(uint8_t u8ClockDivider);

TIMERB_nCLOCK_DIV TIMERB__enGetClockDivider(void);
uint8_t TIMERB__u8GetClockDivider(void);

#endif /* DRIVERLIB_TIMERB_DRIVER_GLOBAL_HEADER_TIMERB_TIMERBDIVIDER_H_ */
