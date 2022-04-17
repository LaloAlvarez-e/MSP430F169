/**
 *
 * @file TIMERB_RegisterPeripheral.h
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

#ifndef TIMERB_PERIPHERAL_REGISTERPERIPHERAL_TIMERB_REGISTERPERIPHERAL_H_
#define TIMERB_PERIPHERAL_REGISTERPERIPHERAL_TIMERB_REGISTERPERIPHERAL_H_

#include "DriverLib/TIMERB/Peripheral/RegisterPeripheral/Header/TIMERB_RegisterPeripheral_CC0.h"
#include "DriverLib/TIMERB/Peripheral/RegisterPeripheral/Header/TIMERB_RegisterPeripheral_CC1.h"
#include "DriverLib/TIMERB/Peripheral/RegisterPeripheral/Header/TIMERB_RegisterPeripheral_CC2.h"
#include "DriverLib/TIMERB/Peripheral/RegisterPeripheral/Header/TIMERB_RegisterPeripheral_CC3.h"
#include "DriverLib/TIMERB/Peripheral/RegisterPeripheral/Header/TIMERB_RegisterPeripheral_CC4.h"
#include "DriverLib/TIMERB/Peripheral/RegisterPeripheral/Header/TIMERB_RegisterPeripheral_CC5.h"
#include "DriverLib/TIMERB/Peripheral/RegisterPeripheral/Header/TIMERB_RegisterPeripheral_CC6.h"
#include "DriverLib/TIMERB/Peripheral/Header/TIMERB_Enum.h"

#define TIMERB ((TIMERB_t*) TIMERB_BASE)


/******************************************************************************************
 ************************************ 1 CTL *********************************************
 ******************************************************************************************/
#define TIMERB_CTL_R  (*(volatile uint16_t*) (TIMERB_BASE + TIMERB_CTL_OFFSET))
#define TIMERB_CTL    ((TIMERB_CTL_t*) (TIMERB_BASE + TIMERB_CTL_OFFSET))

/******************************************************************************************
 ************************************ 2 R *********************************************
 ******************************************************************************************/
#define TIMERB_R_R  (*(volatile uint16_t*) (TIMERB_BASE + TIMERB_R_OFFSET))
#define TIMERB_R    ((TIMERB_R_t*) (TIMERB_BASE + TIMERB_R_OFFSET))


/******************************************************************************************
 ************************************ 3 IV *********************************************
 ******************************************************************************************/
#define TIMERB_IV_R  (*(volatile uint16_t*) (TIMERB_BASE + TIMERB_IV_OFFSET))
#define TIMERB_IV    ((TIMERB_IV_t*) (TIMERB_BASE + TIMERB_IV_OFFSET))


uintptr_t TIMERB_CC__uptrBlockBaseAddress(TIMERB_nCC enModuleArg);
uintptr_t TIMERB__uptrBlockBaseAddress(void);

#endif /* TIMERB_PERIPHERAL_REGISTERPERIPHERAL_TIMERB_REGISTERPERIPHERAL_H_ */
