/**
 *
 * @file DMA_IncrementMode.h
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
 * @verbatim 27 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 27 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_DMA_DRIVER_CHANNEL_CONFIG_HEADER_DMA_INCREMENTMODE_H_
#define DRIVERLIB_DMA_DRIVER_CHANNEL_CONFIG_HEADER_DMA_INCREMENTMODE_H_

#include "DriverLib/DMA/Peripheral/Header/DMA_Enum.h"

void DMA__vSetSourceIncrementMode(DMA_nCH enChannelArg,
                            DMA_nCH_INCMODE enIncModeArg);
void DMA__vSetDestIncrementMode(DMA_nCH enChannelArg,
                            DMA_nCH_INCMODE enIncModeArg);

DMA_nCH_INCMODE DMA__enGetSourceIncrementMode(DMA_nCH enChannelArg);
DMA_nCH_INCMODE DMA__enGetDestIncrementMode(DMA_nCH enChannelArg);

#endif /* DRIVERLIB_DMA_DRIVER_CHANNEL_CONFIG_HEADER_DMA_INCREMENTMODE_H_ */
