/**
 *
 * @file TIMERB_Count.h
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

#ifndef DRIVERLIB_TIMERB_DRIVER_GLOBAL_HEADER_TIMERB_COUNT_H_
#define DRIVERLIB_TIMERB_DRIVER_GLOBAL_HEADER_TIMERB_COUNT_H_

#include "DriverLib/TIMERB/Peripheral/Header/TIMERB_Enum.h"

void TIMERB__vSetCount(uint16_t u16CountArg);
void TIMERB__vClearCount(void);
uint16_t TIMERB__enGetCount(void);

#endif /* DRIVERLIB_TIMERB_DRIVER_GLOBAL_HEADER_TIMERB_COUNT_H_ */
