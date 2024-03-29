/**
 *
 * @file DMA_Trigger.h
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
 * @verbatim 25 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 25 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_DMA_DRIVER_HEADER_DMA_TRIGGER_H_
#define DRIVERLIB_DMA_DRIVER_HEADER_DMA_TRIGGER_H_

#include "DriverLib/DMA/Peripheral/Header/DMA_Enum.h"

void DMA_CH__vSetTrigger(DMA_nCH enChannelArg,
                      DMA_nCH_TRIGGER enTriggerArg);

DMA_nCH_TRIGGER DMA_CH__enGetTrigger(DMA_nCH enChannelArg);

#endif /* DRIVERLIB_DMA_DRIVER_HEADER_DMA_TRIGGER_H_ */
