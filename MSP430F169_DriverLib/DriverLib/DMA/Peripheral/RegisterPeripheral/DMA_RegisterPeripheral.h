/**
 *
 * @file DMA_RegisterPeripheral.h
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
 * @verbatim 5 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 5 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DMA_PERIPHERAL_REGISTERPERIPHERAL_DMA_REGISTERPERIPHERAL_H_
#define DMA_PERIPHERAL_REGISTERPERIPHERAL_DMA_REGISTERPERIPHERAL_H_

#include "DriverLib/DMA/Peripheral/RegisterPeripheral/Header/DMA_RegisterPeripheral_CH0.h"
#include "DriverLib/DMA/Peripheral/RegisterPeripheral/Header/DMA_RegisterPeripheral_CH1.h"
#include "DriverLib/DMA/Peripheral/RegisterPeripheral/Header/DMA_RegisterPeripheral_CH2.h"
#include "DriverLib/DMA/Peripheral/Header/DMA_Enum.h"

#define DMA ((DMA_t*) DMA_BASE)


/******************************************************************************************
 ************************************ 1 CTL0 *********************************************
 ******************************************************************************************/
#define DMA_CTL0_R  (*(volatile uint16_t*) (DMA_BASE + DMA_CTL0_OFFSET))
#define DMA_CTL0    ((DMA_CTL0_t*) (DMA_BASE + DMA_CTL0_OFFSET))

/******************************************************************************************
 ************************************ 2 CTL1 *********************************************
 ******************************************************************************************/
#define DMA_CTL1_R  (*(volatile uint16_t*) (DMA_BASE + DMA_CTL1_OFFSET))
#define DMA_CTL1    ((DMA_CTL1_t*) (DMA_BASE + DMA_CTL1_OFFSET))


uintptr_t DMA_CH__uptrBlockBaseAddress(DMA_nCH enChannelArg);
uintptr_t DMA__uptrBlockBaseAddress(void);

#endif /* DMA_PERIPHERAL_REGISTERPERIPHERAL_DMA_REGISTERPERIPHERAL_H_ */
