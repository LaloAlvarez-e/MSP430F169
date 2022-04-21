/**
 *
 * @file ADC12_RegisterPeripheral_CH12.h
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

#ifndef DRIVERLIB_ADC12_PERIPHERAL_REGISTERPERIPHERAL_HEADER_ADC12_REGISTERPERIPHERAL_CH12_H_
#define DRIVERLIB_ADC12_PERIPHERAL_REGISTERPERIPHERAL_HEADER_ADC12_REGISTERPERIPHERAL_CH12_H_

#include "DriverLib/ADC12/Peripheral/Header/ADC12_RegisterAddress.h"
#include "DriverLib/ADC12/Peripheral/Header/ADC12_StructPeripheral.h"
#include "DriverLib/MCU/Header/MCU_Common.h"

#define ADC12_CH12 ((ADC12_CH12_t*) ADC12_CH12_BASE)

/******************************************************************************************
 ************************************ 1 CTL *********************************************
 ******************************************************************************************/
#define ADC12_CH12_CTL_R  (*(volatile uint8_t*) (ADC12_CH12_BASE + ADC12_CH_CTL_OFFSET))
#define ADC12_CH12_CTL    ((ADC12_CH_CTL_t*) (ADC12_CH12_BASE + ADC12_CH_CTL_OFFSET))

/******************************************************************************************
 ************************************ 2 MEM *********************************************
 ******************************************************************************************/
#define ADC12_CH12_MEM_R (*(volatile uint16_t*) (ADC12_CH12_BASE + ADC12_CH_MEM_OFFSET + ADC12_CH12_OFFSET))
#define ADC12_CH12_MEM ((ADC12_CH_MEM_t*) (ADC12_CH12_BASE + ADC12_CH_MEM_OFFSET + ADC12_CH12_OFFSET))

#endif /* DRIVERLIB_ADC12_PERIPHERAL_REGISTERPERIPHERAL_HEADER_ADC12_REGISTERPERIPHERAL_CH12_H_ */
