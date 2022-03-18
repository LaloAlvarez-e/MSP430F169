/**
 *
 * @file DMA_Direction.h
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
 * @verbatim 9 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DMA_DRIVER_HEADER_DMA_DIRECTION_H_
#define DMA_DRIVER_HEADER_DMA_DIRECTION_H_

#include "DriverLib/DMA/Peripheral/Header/DMA_Enum.h"

void DMA__vSetDirection(DMA_nPORT enPortArg,
                         DMA_nPIN enPinMask,
                         DMA_nDIR enDirection);
void DMA__vSetDirectionByNumber(DMA_nPORT enPortArg,
                                 DMA_nPIN_NUMBER enPinNumber,
                                 DMA_nDIR enDirection);

DMA_nPIN DMA__enGetDirection(DMA_nPORT enPortArg,
                               DMA_nPIN enPinMask);
DMA_nDIR DMA__enGetDirectionByNumber(DMA_nPORT enPortArg,
                                       DMA_nPIN_NUMBER enPinNumber);

#endif /* DMA_DRIVER_HEADER_DMA_DIRECTION_H_ */
