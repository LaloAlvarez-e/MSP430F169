/**
 *
 * @file DAC12_RegisterPeripheral.h
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

#ifndef DAC12_PERIPHERAL_REGISTERPERIPHERAL_DAC12_REGISTERPERIPHERAL_H_
#define DAC12_PERIPHERAL_REGISTERPERIPHERAL_DAC12_REGISTERPERIPHERAL_H_

#include "DriverLib/DAC12/Peripheral/RegisterPeripheral/Header/DAC12_RegisterPeripheral_CH0.h"
#include "DriverLib/DAC12/Peripheral/RegisterPeripheral/Header/DAC12_RegisterPeripheral_CH1.h"
#include "DriverLib/DAC12/Peripheral/RegisterPeripheral/Header/DAC12_RegisterPeripheral_CH2.h"
#include "DriverLib/DAC12/Peripheral/RegisterPeripheral/Header/DAC12_RegisterPeripheral_CH3.h"
#include "DriverLib/DAC12/Peripheral/RegisterPeripheral/Header/DAC12_RegisterPeripheral_CH4.h"
#include "DriverLib/DAC12/Peripheral/RegisterPeripheral/Header/DAC12_RegisterPeripheral_CH5.h"
#include "DriverLib/DAC12/Peripheral/RegisterPeripheral/Header/DAC12_RegisterPeripheral_CH6.h"
#include "DriverLib/DAC12/Peripheral/RegisterPeripheral/Header/DAC12_RegisterPeripheral_CH7.h"
#include "DriverLib/DAC12/Peripheral/RegisterPeripheral/Header/DAC12_RegisterPeripheral_CH8.h"
#include "DriverLib/DAC12/Peripheral/RegisterPeripheral/Header/DAC12_RegisterPeripheral_CH9.h"
#include "DriverLib/DAC12/Peripheral/RegisterPeripheral/Header/DAC12_RegisterPeripheral_CH10.h"
#include "DriverLib/DAC12/Peripheral/RegisterPeripheral/Header/DAC12_RegisterPeripheral_CH11.h"
#include "DriverLib/DAC12/Peripheral/RegisterPeripheral/Header/DAC12_RegisterPeripheral_CH12.h"
#include "DriverLib/DAC12/Peripheral/RegisterPeripheral/Header/DAC12_RegisterPeripheral_CH13.h"
#include "DriverLib/DAC12/Peripheral/RegisterPeripheral/Header/DAC12_RegisterPeripheral_CH14.h"
#include "DriverLib/DAC12/Peripheral/RegisterPeripheral/Header/DAC12_RegisterPeripheral_CH15.h"
#include "DriverLib/DAC12/Peripheral/Header/DAC12_Enum.h"

#define DAC12 ((DAC12_t*) DAC12_BASE)


/******************************************************************************************
 ************************************ 1 CTL0 *********************************************
 ******************************************************************************************/
#define DAC12_CTL0_R  (*(volatile uint16_t*) (DAC12_BASE + DAC12_CTL0_OFFSET))
#define DAC12_CTL0    ((DAC12_CTL0_t*) (DAC12_BASE + DAC12_CTL0_OFFSET))

/******************************************************************************************
 ************************************ 2 CTL1 *********************************************
 ******************************************************************************************/
#define DAC12_CTL1_R  (*(volatile uint16_t*) (DAC12_BASE + DAC12_CTL1_OFFSET))
#define DAC12_CTL1    ((DAC12_CTL1_t*) (DAC12_BASE + DAC12_CTL1_OFFSET))

/******************************************************************************************
 ************************************ 3 IE *********************************************
 ******************************************************************************************/
#define DAC12_IE_R  (*(volatile uint16_t*) (DAC12_BASE + DAC12_IE_OFFSET))
#define DAC12_IE    ((DAC12_IE_t*) (DAC12_BASE + DAC12_IE_OFFSET))

/******************************************************************************************
 ************************************ 4 IFG *********************************************
 ******************************************************************************************/
#define DAC12_IFG_R  (*(volatile uint16_t*) (DAC12_BASE + DAC12_IFG_OFFSET))
#define DAC12_IFG    ((DAC12_IFG_t*) (DAC12_BASE + DAC12_IFG_OFFSET))

/******************************************************************************************
 ************************************ 5 IV *********************************************
 ******************************************************************************************/
#define DAC12_IV_R  (*(volatile uint16_t*) (DAC12_BASE + DAC12_IV_OFFSET))
#define DAC12_IV    ((DAC12_IV_t*) (DAC12_BASE + DAC12_IV_OFFSET))

uintptr_t DAC12_CH__uptrBlockBaseAddress(DAC12_nCH enChannelArg);
uintptr_t DAC12__uptrBlockBaseAddress(void);

#endif /* DAC12_PERIPHERAL_REGISTERPERIPHERAL_DAC12_REGISTERPERIPHERAL_H_ */
