/**
 *
 * @file TIMERA_RegisterPeripheral_CC1.h
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
 * @verbatim 9 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_TIMERA_PERIPHERAL_REGISTERPERIPHERAL_HEADER_TIMERA_REGISTERPERIPHERAL_CC1_H_
#define DRIVERLIB_TIMERA_PERIPHERAL_REGISTERPERIPHERAL_HEADER_TIMERA_REGISTERPERIPHERAL_CC1_H_

#include "DriverLib/TIMERA/Peripheral/Header/TIMERA_RegisterAddress.h"
#include "DriverLib/TIMERA/Peripheral/Header/TIMERA_StructPeripheral.h"
#include "DriverLib/MCU/Header/MCU_Common.h"

#define TIMERA_CC1 ((TIMERA_CC_t*) TIMERA_CC1_BASE)

/******************************************************************************************
 ************************************ 1 CTL *********************************************
 ******************************************************************************************/
#define TIMERA_CC1_CTL_R  (*(volatile uint16_t*) (TIMERA_CC1_BASE + TIMERA_CC_CTL_OFFSET))
#define TIMERA_CC1_CTL    ((TIMERA_CC_CTL_t*) (TIMERA_CC1_BASE + TIMERA_CC_CTL_OFFSET))

/******************************************************************************************
 ************************************ 2 R *********************************************
 ******************************************************************************************/
#define TIMERA_CC1_R_R (*(volatile uint16_t*) (TIMERA_CC1_BASE + TIMERA_CC_R_OFFSET))
#define TIMERA_CC1_R ((TIMERA_CC_R_t*) (TIMERA_CC1_BASE + TIMERA_CC_R_OFFSET))

#endif /* DRIVERLIB_TIMERA_PERIPHERAL_REGISTERPERIPHERAL_HEADER_TIMERA_REGISTERPERIPHERAL_CC1_H_ */
