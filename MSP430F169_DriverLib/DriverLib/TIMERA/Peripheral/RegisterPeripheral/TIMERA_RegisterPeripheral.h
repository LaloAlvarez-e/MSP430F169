/**
 *
 * @file TIMERA_RegisterPeripheral.h
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

#ifndef TIMERA_PERIPHERAL_REGISTERPERIPHERAL_TIMERA_REGISTERPERIPHERAL_H_
#define TIMERA_PERIPHERAL_REGISTERPERIPHERAL_TIMERA_REGISTERPERIPHERAL_H_

#include "DriverLib/TIMERA/Peripheral/RegisterPeripheral/Header/TIMERA_RegisterPeripheral_CC0.h"
#include "DriverLib/TIMERA/Peripheral/RegisterPeripheral/Header/TIMERA_RegisterPeripheral_CC1.h"
#include "DriverLib/TIMERA/Peripheral/RegisterPeripheral/Header/TIMERA_RegisterPeripheral_CC2.h"
#include "DriverLib/TIMERA/Peripheral/Header/TIMERA_Enum.h"

#define TIMERA ((TIMERA_t*) TIMERA_BASE)


/******************************************************************************************
 ************************************ 1 CTL *********************************************
 ******************************************************************************************/
#define TIMERA_CTL_R  (*(volatile uint16_t*) (TIMERA_BASE + TIMERA_CTL_OFFSET))
#define TIMERA_CTL    ((TIMERA_CTL_t*) (TIMERA_BASE + TIMERA_CTL_OFFSET))

/******************************************************************************************
 ************************************ 2 R *********************************************
 ******************************************************************************************/
#define TIMERA_R_R  (*(volatile uint16_t*) (TIMERA_BASE + TIMERA_R_OFFSET))
#define TIMERA_R    ((TIMERA_R_t*) (TIMERA_BASE + TIMERA_R_OFFSET))


/******************************************************************************************
 ************************************ 3 IV *********************************************
 ******************************************************************************************/
#define TIMERA_IV_R  (*(volatile uint16_t*) (TIMERA_BASE + TIMERA_IV_OFFSET))
#define TIMERA_IV    ((TIMERA_IV_t*) (TIMERA_BASE + TIMERA_IV_OFFSET))


uintptr_t TIMERA_CC__uptrBlockBaseAddress(TIMERA_nCC enModuleArg);
uintptr_t TIMERA__uptrBlockBaseAddress(void);

#endif /* TIMERA_PERIPHERAL_REGISTERPERIPHERAL_TIMERA_REGISTERPERIPHERAL_H_ */
