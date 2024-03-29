/**
 *
 * @file DMA_InterruptRegister_Source.h
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

#ifndef DMA_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_HEADER_DMA_INTERRUPTREGISTER_SOURCE_H_
#define DMA_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_HEADER_DMA_INTERRUPTREGISTER_SOURCE_H_

#include "DriverLib/DMA/Peripheral/Header/DMA_Enum.h"
#include "DriverLib/MCU/Header/MCU_Common.h"

void DMA_CH__vRegisterIRQSourceHandler(DMA_nCH enChannelArg, DMA_nCH_TRIGGER enTrigger,
         MCU__pu16fIRQSourceHandler_t pu16fIRQSourceHandler);

#endif /* DMA_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_HEADER_DMA_INTERRUPTREGISTER_SOURCE_H_ */
