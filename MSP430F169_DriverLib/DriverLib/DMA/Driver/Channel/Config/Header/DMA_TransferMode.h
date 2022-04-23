/**
 *
 * @file DMA_TransferMode.h
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

#ifndef DRIVERLIB_DMA_DRIVER_CHANNEL_CONFIG_HEADER_DMA_TRANSFERMODE_H_
#define DRIVERLIB_DMA_DRIVER_CHANNEL_CONFIG_HEADER_DMA_TRANSFERMODE_H_

#include "DriverLib/DMA/Peripheral/Header/DMA_Enum.h"

void DMA_CH__vSetTransferMode(DMA_nCH enChannelArg,
                          DMA_nCH_MODE enModeArg);

DMA_nCH_MODE DMA_CH__enGetTransferMode(DMA_nCH enChannelArg);

#endif /* DRIVERLIB_DMA_DRIVER_CHANNEL_CONFIG_HEADER_DMA_TRANSFERMODE_H_ */
