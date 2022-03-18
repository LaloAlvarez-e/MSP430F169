/**
 *
 * @file DMA_Selection.h
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
 * @verbatim 10 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 10 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DMA_DRIVER_HEADER_DMA_SELECTION_H_
#define DMA_DRIVER_HEADER_DMA_SELECTION_H_

#include "DriverLib/DMA/Peripheral/Header/DMA_Enum.h"

void DMA__vSetSelection(DMA_nPORT enPortArg,
                         DMA_nPIN enPinMask,
                         DMA_nSEL enSelection);
void DMA__vSetSelectionByNumber(DMA_nPORT enPortArg,
                             DMA_nPIN_NUMBER enPinNumber,
                             DMA_nSEL enSelection);

DMA_nPIN DMA__enGetSelection(DMA_nPORT enPortArg,
                               DMA_nPIN enPinMask);
DMA_nSEL DMA__enGetSelectionByNumber(DMA_nPORT enPortArg,
                                       DMA_nPIN_NUMBER enPinNumber);

#endif /* DMA_DRIVER_HEADER_DMA_SELECTION_H_ */
