/**
 *
 * @file DMA_InterruptSource_Enable.h
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

#ifndef DMA_DRIVER_INTRINSICS_INTERRUPT_HEADER_DMA_INTERRUPTSOURCE_ENABLE_H_
#define DMA_DRIVER_INTRINSICS_INTERRUPT_HEADER_DMA_INTERRUPTSOURCE_ENABLE_H_

#include "DriverLib/DMA/Peripheral/Header/DMA_Enum.h"


void DMA_CH__vSetEnableInterruptSource(DMA_nCH enChannelArg,
                                    DMA_nCH_INT_ENABLE enState);
void DMA_CH__vEnaInterruptSource(DMA_nCH enChannelArg);
void DMA_CH__vDisInterruptSource(DMA_nCH enChannelArg);
DMA_nCH_INT_ENABLE DMA_CH__enGetEnableInterruptSource(DMA_nCH enChannelArg);

#endif /* DMA_DRIVER_INTRINSICS_INTERRUPT_HEADER_DMA_INTERRUPTSOURCE_ENABLE_H_ */
