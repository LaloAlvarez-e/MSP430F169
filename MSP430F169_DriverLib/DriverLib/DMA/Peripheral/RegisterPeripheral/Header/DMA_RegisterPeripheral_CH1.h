/**
 *
 * @file DMA_RegisterPeripheral_CH1.h
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

#ifndef DMA_PERIPHERAL_REGISTERPERIPHERAL_HEADER_DMA_REGISTERPERIPHERAL_CH1_H_
#define DMA_PERIPHERAL_REGISTERPERIPHERAL_HEADER_DMA_REGISTERPERIPHERAL_CH1_H_

#include "DriverLib/DMA/Peripheral/Header/DMA_RegisterAddress.h"
#include "DriverLib/DMA/Peripheral/Header/DMA_StructPeripheral.h"
#include "DriverLib/MCU/Header/MCU_Common.h"

#define DMA_CH1 ((DMA_CH_t*) DMA_CH1_BASE)

/******************************************************************************************
 ************************************ 1 CTL *********************************************
 ******************************************************************************************/
#define DMA_CH1_CTL_R  (*(volatile uint16_t*) (DMA_CH1_BASE + DMA_CH_CTL_OFFSET))
#define DMA_CH1_CTL    ((DMA_CH_CTL_t*) (DMA_CH1_BASE + DMA_CH_CTL_OFFSET))

/******************************************************************************************
 ************************************ 2 SA *********************************************
 ******************************************************************************************/
#define DMA_CH1_SA_R (*(volatile uint16_t*) (DMA_CH1_BASE + DMA_CH_SA_OFFSET))
#define DMA_CH1_SA ((DMA_CH_SA_t*) (DMA_CH1_BASE + DMA_CH_SA_OFFSET))

/******************************************************************************************
 ************************************ 3 DA *********************************************
 ******************************************************************************************/
#define DMA_CH1_DA_R (*(volatile uint16_t*) (DMA_CH1_BASE + DMA_CH_DA_OFFSET))
#define DMA_CH1_DA ((DMA_CH_DA_t*) (DMA_CH1_BASE + DMA_CH_DA_OFFSET))

/******************************************************************************************
 ************************************ 4 SZ *********************************************
 ******************************************************************************************/
#define DMA_CH1_SZ_R (*(volatile uint16_t*) (DMA_CH1_BASE + DMA_CH_SZ_OFFSET))
#define DMA_CH1_SZ ((DMA_CH_SZ_t*) (DMA_CH1_BASE + DMA_CH_SZ_OFFSET))

#endif /* DMA_PERIPHERAL_REGISTERPERIPHERAL_HEADER_DMA_REGISTERPERIPHERAL_CH1_H_ */
