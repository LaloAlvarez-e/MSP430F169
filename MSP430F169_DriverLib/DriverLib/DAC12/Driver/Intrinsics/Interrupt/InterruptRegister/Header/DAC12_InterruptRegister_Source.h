/**
 *
 * @file DAC12_InterruptRegister_Source.h
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

#ifndef DAC12_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_HEADER_DAC12_INTERRUPTREGISTER_SOURCE_H_
#define DAC12_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_HEADER_DAC12_INTERRUPTREGISTER_SOURCE_H_

#include "DriverLib/DAC12/Peripheral/Header/DAC12_Enum.h"
#include "DriverLib/MCU/Header/MCU_Common.h"

void DAC12_CH__vRegisterIRQSourceHandler(DAC12_nCH enChannelArg,
         MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler);

#endif /* DAC12_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_HEADER_DAC12_INTERRUPTREGISTER_SOURCE_H_ */
