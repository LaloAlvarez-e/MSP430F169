/**
 *
 * @file DMA_InterruptSource_Status.h
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

#ifndef DMA_DRIVER_INTRINSICS_INTERRUPT_HEADER_DMA_INTERRUPTSOURCE_STATUS_H_
#define DMA_DRIVER_INTRINSICS_INTERRUPT_HEADER_DMA_INTERRUPTSOURCE_STATUS_H_

#include "DriverLib/DMA/Peripheral/Header/DMA_Enum.h"

void DMA__vSetStatusInterruptSource(DMA_nPORT enPortArg,
                                     DMA_nPIN enPinMask,
                                     DMA_nINT_STATUS enStatus);
void DMA__vSetStatusInterruptSourceByNumber(DMA_nPORT enPortArg,
                                             DMA_nPIN_NUMBER enPinNumber,
                                             DMA_nINT_STATUS enStatus);

DMA_nINT_STATUS DMA__enGetStatusInterruptSourceByNumber(DMA_nPORT enPortArg,
                                           DMA_nPIN_NUMBER enPinNumber);
DMA_nPIN DMA__enGetStatusInterruptSource(DMA_nPORT enPortArg,
                                           DMA_nPIN enPinMask);

#endif /* DMA_DRIVER_INTRINSICS_INTERRUPT_HEADER_DMA_INTERRUPTSOURCE_STATUS_H_ */
