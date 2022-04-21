/**
 *
 * @file ADC12_InterruptRoutine_Source.h
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

#ifndef ADC12_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_ADC12_INTERRUPTROUTINE_SOURCE_H_
#define ADC12_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_ADC12_INTERRUPTROUTINE_SOURCE_H_

#include "DriverLib/MCU/Header/MCU_Common.h"
#include "DriverLib/ADC12/Peripheral/Header/ADC12_Enum.h"

MCU__pu16fIRQSourceHandler_t ADC12_CH__pu16fGetIRQSourceHandler(ADC12_nCH enChannelArg);
void ADC12_CH__vSetIRQSourceHandler(ADC12_nCH enChannelArg,
                               MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler);

MCU__pu16fIRQSourceHandler_t ADC12__pu16fGetIRQSourceHandler(ADC12_nINTERRUPT enInterruptArg);
void ADC12__vSetIRQSourceHandler(ADC12_nINTERRUPT enInterruptArg,
                               MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler);


#endif /* ADC12_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_ADC12_INTERRUPTROUTINE_SOURCE_H_ */
