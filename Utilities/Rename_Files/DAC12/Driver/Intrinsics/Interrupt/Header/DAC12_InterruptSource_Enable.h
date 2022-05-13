/**
 *
 * @file DAC12_InterruptSource_Enable.h
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

#ifndef DAC12_DRIVER_INTRINSICS_INTERRUPT_HEADER_DAC12_INTERRUPTSOURCE_ENABLE_H_
#define DAC12_DRIVER_INTRINSICS_INTERRUPT_HEADER_DAC12_INTERRUPTSOURCE_ENABLE_H_

#include "DriverLib/DAC12/Peripheral/Header/DAC12_Enum.h"

void DAC12_CH__vSetEnableInterruptSource(DAC12_nCH enChannelArg,
                                    DAC12_nINT_ENABLE enState);
void DAC12_CH__vEnaInterruptSource(DAC12_nCH enChannelArg);
void DAC12_CH__vDisInterruptSource(DAC12_nCH enChannelArg);
DAC12_nINT_ENABLE DAC12_CH__enGetEnableInterruptSource(DAC12_nCH enChannelArg);

void DAC12__vSetEnableInterruptSource(DAC12_nINTERRUPT enInterruptArg,
                                    DAC12_nINT_ENABLE enState);
void DAC12__vEnaInterruptSource(DAC12_nINTERRUPT enInterruptArg);
void DAC12__vDisInterruptSource(DAC12_nINTERRUPT enInterruptArg);
DAC12_nINT_ENABLE DAC12__enGetEnableInterruptSource(DAC12_nINTERRUPT enInterruptArg);

#endif /* DAC12_DRIVER_INTRINSICS_INTERRUPT_HEADER_DAC12_INTERRUPTSOURCE_ENABLE_H_ */
