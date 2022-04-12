/**
 *
 * @file DMA_InterruptSource_Clear.h
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

#ifndef DMA_DRIVER_INTRINSICS_INTERRUPT_HEADER_DMA_INTERRUPTSOURCE_CLEAR_H_
#define DMA_DRIVER_INTRINSICS_INTERRUPT_HEADER_DMA_INTERRUPTSOURCE_CLEAR_H_

#include "DriverLib/DMA/Peripheral/Header/DMA_Enum.h"

void DMA__vClearInterruptSource(DMA_nCH enChannelArg);

#endif /* DMA_DRIVER_INTRINSICS_INTERRUPT_HEADER_DMA_INTERRUPTSOURCE_CLEAR_H_ */
