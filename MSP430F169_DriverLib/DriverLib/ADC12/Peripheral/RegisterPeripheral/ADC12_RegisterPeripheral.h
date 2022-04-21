/**
 *
 * @file ADC12_RegisterPeripheral.h
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

#ifndef ADC12_PERIPHERAL_REGISTERPERIPHERAL_ADC12_REGISTERPERIPHERAL_H_
#define ADC12_PERIPHERAL_REGISTERPERIPHERAL_ADC12_REGISTERPERIPHERAL_H_

#include "DriverLib/ADC12/Peripheral/RegisterPeripheral/Header/ADC12_RegisterPeripheral_CH0.h"
#include "DriverLib/ADC12/Peripheral/RegisterPeripheral/Header/ADC12_RegisterPeripheral_CH1.h"
#include "DriverLib/ADC12/Peripheral/RegisterPeripheral/Header/ADC12_RegisterPeripheral_CH2.h"
#include "DriverLib/ADC12/Peripheral/RegisterPeripheral/Header/ADC12_RegisterPeripheral_CH3.h"
#include "DriverLib/ADC12/Peripheral/RegisterPeripheral/Header/ADC12_RegisterPeripheral_CH4.h"
#include "DriverLib/ADC12/Peripheral/RegisterPeripheral/Header/ADC12_RegisterPeripheral_CH5.h"
#include "DriverLib/ADC12/Peripheral/RegisterPeripheral/Header/ADC12_RegisterPeripheral_CH6.h"
#include "DriverLib/ADC12/Peripheral/RegisterPeripheral/Header/ADC12_RegisterPeripheral_CH7.h"
#include "DriverLib/ADC12/Peripheral/RegisterPeripheral/Header/ADC12_RegisterPeripheral_CH8.h"
#include "DriverLib/ADC12/Peripheral/RegisterPeripheral/Header/ADC12_RegisterPeripheral_CH9.h"
#include "DriverLib/ADC12/Peripheral/RegisterPeripheral/Header/ADC12_RegisterPeripheral_CH10.h"
#include "DriverLib/ADC12/Peripheral/RegisterPeripheral/Header/ADC12_RegisterPeripheral_CH11.h"
#include "DriverLib/ADC12/Peripheral/RegisterPeripheral/Header/ADC12_RegisterPeripheral_CH12.h"
#include "DriverLib/ADC12/Peripheral/RegisterPeripheral/Header/ADC12_RegisterPeripheral_CH13.h"
#include "DriverLib/ADC12/Peripheral/RegisterPeripheral/Header/ADC12_RegisterPeripheral_CH14.h"
#include "DriverLib/ADC12/Peripheral/RegisterPeripheral/Header/ADC12_RegisterPeripheral_CH15.h"
#include "DriverLib/ADC12/Peripheral/Header/ADC12_Enum.h"

#define ADC12 ((ADC12_t*) ADC12_BASE)


/******************************************************************************************
 ************************************ 1 CTL0 *********************************************
 ******************************************************************************************/
#define ADC12_CTL0_R  (*(volatile uint16_t*) (ADC12_BASE + ADC12_CTL0_OFFSET))
#define ADC12_CTL0    ((ADC12_CTL0_t*) (ADC12_BASE + ADC12_CTL0_OFFSET))

/******************************************************************************************
 ************************************ 2 CTL1 *********************************************
 ******************************************************************************************/
#define ADC12_CTL1_R  (*(volatile uint16_t*) (ADC12_BASE + ADC12_CTL1_OFFSET))
#define ADC12_CTL1    ((ADC12_CTL1_t*) (ADC12_BASE + ADC12_CTL1_OFFSET))

/******************************************************************************************
 ************************************ 3 IE *********************************************
 ******************************************************************************************/
#define ADC12_IE_R  (*(volatile uint16_t*) (ADC12_BASE + ADC12_IE_OFFSET))
#define ADC12_IE    ((ADC12_IE_t*) (ADC12_BASE + ADC12_IE_OFFSET))

/******************************************************************************************
 ************************************ 4 IFG *********************************************
 ******************************************************************************************/
#define ADC12_IFG_R  (*(volatile uint16_t*) (ADC12_BASE + ADC12_IFG_OFFSET))
#define ADC12_IFG    ((ADC12_IFG_t*) (ADC12_BASE + ADC12_IFG_OFFSET))

/******************************************************************************************
 ************************************ 5 IV *********************************************
 ******************************************************************************************/
#define ADC12_IV_R  (*(volatile uint16_t*) (ADC12_BASE + ADC12_IV_OFFSET))
#define ADC12_IV    ((ADC12_IV_t*) (ADC12_BASE + ADC12_IV_OFFSET))

uintptr_t ADC12_CH__uptrBlockBaseAddress(ADC12_nCH enChannelArg);
uintptr_t ADC12__uptrBlockBaseAddress(void);

#endif /* ADC12_PERIPHERAL_REGISTERPERIPHERAL_ADC12_REGISTERPERIPHERAL_H_ */
