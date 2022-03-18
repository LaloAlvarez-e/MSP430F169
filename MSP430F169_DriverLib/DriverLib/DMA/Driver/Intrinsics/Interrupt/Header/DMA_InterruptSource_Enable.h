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

void DMA__vSetEnableInterruptSource(DMA_nPORT enPortArg,
                                     DMA_nPIN enPinMask,
                                     DMA_nINT_ENABLE enState);
void DMA__vEnaInterruptSource(DMA_nPORT enPortArg,
                               DMA_nPIN enPinMask);
void DMA__vDisInterruptSource(DMA_nPORT enPortArg,
                               DMA_nPIN enPinMask);

void DMA__vSetEnableInterruptSourceByNumber(DMA_nPORT enPortArg,
                                             DMA_nPIN_NUMBER enPinNumber,
                                             DMA_nINT_ENABLE enState);
void DMA__vEnaInterruptSourceByNumber(DMA_nPORT enPortArg,
                                       DMA_nPIN_NUMBER enPinNumber);
void DMA__vDisInterruptSourceByNumber(DMA_nPORT enPortArg,
                                       DMA_nPIN_NUMBER enPinNumber);

DMA_nPIN DMA__enGetEnableInterruptSource(DMA_nPORT enPortArg,
                                           DMA_nPIN enPinMask);
DMA_nINT_ENABLE DMA__enGetEnableInterruptSourceByNumber(DMA_nPORT enPortArg,
                                           DMA_nPIN_NUMBER enPinNumber);

#endif /* DMA_DRIVER_INTRINSICS_INTERRUPT_HEADER_DMA_INTERRUPTSOURCE_ENABLE_H_ */
