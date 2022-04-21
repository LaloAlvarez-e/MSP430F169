/**
 *
 * @file ADC12_InterruptSource_Clear.h
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

#ifndef ADC12_DRIVER_INTRINSICS_INTERRUPT_HEADER_ADC12_INTERRUPTSOURCE_CLEAR_H_
#define ADC12_DRIVER_INTRINSICS_INTERRUPT_HEADER_ADC12_INTERRUPTSOURCE_CLEAR_H_

#include "DriverLib/ADC12/Peripheral/Header/ADC12_Enum.h"

void ADC12_CH__vClearInterruptSource(ADC12_nCH enChannelArg);

#endif /* ADC12_DRIVER_INTRINSICS_INTERRUPT_HEADER_ADC12_INTERRUPTSOURCE_CLEAR_H_ */
