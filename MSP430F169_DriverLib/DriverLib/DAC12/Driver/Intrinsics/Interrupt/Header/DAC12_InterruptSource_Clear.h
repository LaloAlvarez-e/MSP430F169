/**
 *
 * @file DAC12_InterruptSource_Clear.h
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

#ifndef DAC12_DRIVER_INTRINSICS_INTERRUPT_HEADER_DAC12_INTERRUPTSOURCE_CLEAR_H_
#define DAC12_DRIVER_INTRINSICS_INTERRUPT_HEADER_DAC12_INTERRUPTSOURCE_CLEAR_H_

#include "DriverLib/DAC12/Peripheral/Header/DAC12_Enum.h"

void DAC12_CH__vClearInterruptSource(DAC12_nCH enChannelArg);

#endif /* DAC12_DRIVER_INTRINSICS_INTERRUPT_HEADER_DAC12_INTERRUPTSOURCE_CLEAR_H_ */
