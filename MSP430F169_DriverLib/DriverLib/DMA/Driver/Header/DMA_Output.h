/**
 *
 * @file DMA_Output.h
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

#ifndef DMA_DRIVER_HEADER_DMA_OUTPUT_H_
#define DMA_DRIVER_HEADER_DMA_OUTPUT_H_

#include "DriverLib/DMA/Peripheral/Header/DMA_Enum.h"

void DMA__vSetOutput(DMA_nPORT enPortArg,
                         DMA_nPIN enPinMask,
                         DMA_nLEVEL enOutput);
void DMA__vSetOutputByNumber(DMA_nPORT enPortArg,
                             DMA_nPIN_NUMBER enPinNumber,
                             DMA_nLEVEL enOutput);

DMA_nPIN DMA__enGetOutput(DMA_nPORT enPortArg,
                               DMA_nPIN enPinMask);
DMA_nLEVEL DMA__enGetOutputByNumber(DMA_nPORT enPortArg,
                                       DMA_nPIN_NUMBER enPinNumber);

#endif /* DMA_DRIVER_HEADER_DMA_OUTPUT_H_ */
