/**
 *
 * @file TIMERB_RegisterPeripheral_CC3.h
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
 * @verbatim 17 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 17 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_TIMERB_PERIPHERAL_REGISTERPERIPHERAL_HEADER_TIMERB_REGISTERPERIPHERAL_CC3_H_
#define DRIVERLIB_TIMERB_PERIPHERAL_REGISTERPERIPHERAL_HEADER_TIMERB_REGISTERPERIPHERAL_CC3_H_

#include "DriverLib/TIMERB/Peripheral/Header/TIMERB_RegisterAddress.h"
#include "DriverLib/TIMERB/Peripheral/Header/TIMERB_StructPeripheral.h"
#include "DriverLib/MCU/Header/MCU_Common.h"

#define TIMERB_CC3 ((TIMERB_CC_t*) TIMERB_CC3_BASE)

/******************************************************************************************
 ************************************ 1 CTL *********************************************
 ******************************************************************************************/
#define TIMERB_CC3_CTL_R  (*(volatile uint16_t*) (TIMERB_CC3_BASE + TIMERB_CC_CTL_OFFSET))
#define TIMERB_CC3_CTL    ((TIMERB_CC_CTL_t*) (TIMERB_CC3_BASE + TIMERB_CC_CTL_OFFSET))

/******************************************************************************************
 ************************************ 2 R *********************************************
 ******************************************************************************************/
#define TIMERB_CC3_R_R (*(volatile uint16_t*) (TIMERB_CC3_BASE + TIMERB_CC_R_OFFSET))
#define TIMERB_CC3_R ((TIMERB_CC_R_t*) (TIMERB_CC3_BASE + TIMERB_CC_R_OFFSET))

#endif /* DRIVERLIB_TIMERB_PERIPHERAL_REGISTERPERIPHERAL_HEADER_TIMERB_REGISTERPERIPHERAL_CC3_H_ */
