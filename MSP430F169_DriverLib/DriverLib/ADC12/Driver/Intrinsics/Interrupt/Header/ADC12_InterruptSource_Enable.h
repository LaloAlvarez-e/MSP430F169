/**
 *
 * @file ADC12_InterruptSource_Enable.h
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

#ifndef ADC12_DRIVER_INTRINSICS_INTERRUPT_HEADER_ADC12_INTERRUPTSOURCE_ENABLE_H_
#define ADC12_DRIVER_INTRINSICS_INTERRUPT_HEADER_ADC12_INTERRUPTSOURCE_ENABLE_H_

#include "DriverLib/ADC12/Peripheral/Header/ADC12_Enum.h"

void ADC12_CH__vSetEnableInterruptSource(ADC12_nCH enChannelArg,
                                    ADC12_nINT_ENABLE enState);
void ADC12_CH__vEnaInterruptSource(ADC12_nCH enChannelArg);
void ADC12_CH__vDisInterruptSource(ADC12_nCH enChannelArg);
ADC12_nINT_ENABLE ADC12_CH__enGetEnableInterruptSource(ADC12_nCH enChannelArg);

void ADC12__vSetEnableInterruptSource(ADC12_nINTERRUPT enInterruptArg,
                                    ADC12_nINT_ENABLE enState);
void ADC12__vEnaInterruptSource(ADC12_nINTERRUPT enInterruptArg);
void ADC12__vDisInterruptSource(ADC12_nINTERRUPT enInterruptArg);
ADC12_nINT_ENABLE ADC12__enGetEnableInterruptSource(ADC12_nINTERRUPT enInterruptArg);

#endif /* ADC12_DRIVER_INTRINSICS_INTERRUPT_HEADER_ADC12_INTERRUPTSOURCE_ENABLE_H_ */
