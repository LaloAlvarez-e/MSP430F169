/**
 *
 * @file DAC12_RegisterPeripheral_CH2.h
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

#ifndef DAC12_PERIPHERAL_REGISTERPERIPHERAL_HEADER_DAC12_REGISTERPERIPHERAL_CH2_H_
#define DAC12_PERIPHERAL_REGISTERPERIPHERAL_HEADER_DAC12_REGISTERPERIPHERAL_CH2_H_

#include "DriverLib/DAC12/Peripheral/Header/DAC12_RegisterAddress.h"
#include "DriverLib/DAC12/Peripheral/Header/DAC12_StructPeripheral.h"
#include "DriverLib/MCU/Header/MCU_Common.h"

#define DAC12_CH2 ((DAC12_CH2_t*) DAC12_CH2_BASE)

/******************************************************************************************
 ************************************ 1 CTL *********************************************
 ******************************************************************************************/
#define DAC12_CH2_CTL_R  (*(volatile uint8_t*) (DAC12_CH2_BASE + DAC12_CH_CTL_OFFSET))
#define DAC12_CH2_CTL    ((DAC12_CH_CTL_t*) (DAC12_CH2_BASE + DAC12_CH_CTL_OFFSET))

/******************************************************************************************
 ************************************ 2 MEM *********************************************
 ******************************************************************************************/
#define DAC12_CH2_MEM_R (*(volatile uint16_t*) (DAC12_CH2_BASE + DAC12_CH_MEM_OFFSET + DAC12_CH2_OFFSET))
#define DAC12_CH2_MEM ((DAC12_CH_MEM_t*) (DAC12_CH2_BASE + DAC12_CH_MEM_OFFSET + DAC12_CH2_OFFSET))

#endif /* DAC12_PERIPHERAL_REGISTERPERIPHERAL_HEADER_DAC12_REGISTERPERIPHERAL_CH2_H_ */
