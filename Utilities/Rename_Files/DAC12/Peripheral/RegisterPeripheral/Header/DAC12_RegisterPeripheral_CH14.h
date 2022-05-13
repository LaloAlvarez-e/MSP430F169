/**
 *
 * @file DAC12_RegisterPeripheral_CH14.h
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
 * @verbatim 20 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 20 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_DAC12_PERIPHERAL_REGISTERPERIPHERAL_HEADER_DAC12_REGISTERPERIPHERAL_CH14_H_
#define DRIVERLIB_DAC12_PERIPHERAL_REGISTERPERIPHERAL_HEADER_DAC12_REGISTERPERIPHERAL_CH14_H_

#include "DriverLib/DAC12/Peripheral/Header/DAC12_RegisterAddress.h"
#include "DriverLib/DAC12/Peripheral/Header/DAC12_StructPeripheral.h"
#include "DriverLib/MCU/Header/MCU_Common.h"

#define DAC12_CH14 ((DAC12_CH14_t*) DAC12_CH14_BASE)

/******************************************************************************************
 ************************************ 1 CTL *********************************************
 ******************************************************************************************/
#define DAC12_CH14_CTL_R  (*(volatile uint8_t*) (DAC12_CH14_BASE + DAC12_CH_CTL_OFFSET))
#define DAC12_CH14_CTL    ((DAC12_CH_CTL_t*) (DAC12_CH14_BASE + DAC12_CH_CTL_OFFSET))

/******************************************************************************************
 ************************************ 2 MEM *********************************************
 ******************************************************************************************/
#define DAC12_CH14_MEM_R (*(volatile uint16_t*) (DAC12_CH14_BASE + DAC12_CH_MEM_OFFSET + DAC12_CH14_OFFSET))
#define DAC12_CH14_MEM ((DAC12_CH_MEM_t*) (DAC12_CH14_BASE + DAC12_CH_MEM_OFFSET + DAC12_CH14_OFFSET))


#endif /* DRIVERLIB_DAC12_PERIPHERAL_REGISTERPERIPHERAL_HEADER_DAC12_REGISTERPERIPHERAL_CH14_H_ */
