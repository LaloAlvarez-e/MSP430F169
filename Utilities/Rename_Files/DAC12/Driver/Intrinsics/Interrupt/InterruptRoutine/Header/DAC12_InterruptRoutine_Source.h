/**
 *
 * @file DAC12_InterruptRoutine_Source.h
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

#ifndef DAC12_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_DAC12_INTERRUPTROUTINE_SOURCE_H_
#define DAC12_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_DAC12_INTERRUPTROUTINE_SOURCE_H_

#include "DriverLib/MCU/Header/MCU_Common.h"
#include "DriverLib/DAC12/Peripheral/Header/DAC12_Enum.h"

MCU__pu16fIRQSourceHandler_t DAC12_CH__pu16fGetIRQSourceHandler(DAC12_nCH enChannelArg);
void DAC12_CH__vSetIRQSourceHandler(DAC12_nCH enChannelArg,
                               MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler);

MCU__pu16fIRQSourceHandler_t DAC12__pu16fGetIRQSourceHandler(DAC12_nINTERRUPT enInterruptArg);
void DAC12__vSetIRQSourceHandler(DAC12_nINTERRUPT enInterruptArg,
                               MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler);


#endif /* DAC12_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_HEADER_DAC12_INTERRUPTROUTINE_SOURCE_H_ */
