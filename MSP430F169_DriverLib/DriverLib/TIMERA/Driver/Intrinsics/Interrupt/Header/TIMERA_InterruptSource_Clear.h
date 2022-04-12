/**
 *
 * @file TIMERA_InterruptSource_Clear.h
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
 * @verbatim 7 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 7 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef TIMERA_DRIVER_INTRINSICS_INTERRUPT_HEADER_TIMERA_INTERRUPTSOURCE_CLEAR_H_
#define TIMERA_DRIVER_INTRINSICS_INTERRUPT_HEADER_TIMERA_INTERRUPTSOURCE_CLEAR_H_

#include "DriverLib/TIMERA/Peripheral/Header/TIMERA_Enum.h"

void TIMERA_CC__vClearInterruptSource(TIMERA_nCC enModuleArg);
void TIMERA__vClearInterruptSource(void);

#endif /* TIMERA_DRIVER_INTRINSICS_INTERRUPT_HEADER_TIMERA_INTERRUPTSOURCE_CLEAR_H_ */
