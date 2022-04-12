/**
 *
 * @file TIMERA_Count.h
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

#ifndef DRIVERLIB_TIMERA_DRIVER_GLOBAL_HEADER_TIMERA_COUNT_H_
#define DRIVERLIB_TIMERA_DRIVER_GLOBAL_HEADER_TIMERA_COUNT_H_

#include "DriverLib/TIMERA/Peripheral/Header/TIMERA_Enum.h"

void TIMERA__vSetCount(uint16_t u16CountArg);
void TIMERA__vClearCount(void);
uint16_t TIMERA__enGetCount(void);

#endif /* DRIVERLIB_TIMERA_DRIVER_GLOBAL_HEADER_TIMERA_COUNT_H_ */
