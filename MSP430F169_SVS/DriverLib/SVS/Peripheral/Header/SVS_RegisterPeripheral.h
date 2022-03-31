/**
 *
 * @file SVS_RegisterPeripheral.h
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
 * @verbatim 24 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 24 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_SVS_PERIPHERAL_HEADER_SVS_REGISTERPERIPHERAL_H_
#define DRIVERLIB_SVS_PERIPHERAL_HEADER_SVS_REGISTERPERIPHERAL_H_

#include "DriverLib/SVS/Peripheral/Header/SVS_RegisterAddress.h"
#include "DriverLib/SVS/Peripheral/Header/SVS_StructPeripheral.h"
#include "DriverLib/MCU/Header/MCU_Common.h"

#define SVS ((SVS_t*) SVS_BASE)

/******************************************************************************************
 ************************************ 1 CTL *********************************************
 ******************************************************************************************/
#define SVS_CTL_R (*(volatile uint16_t*) (SVS_BASE + SVS_CTL_OFFSET))
#define SVS_CTL ((SVS_CTL_t*) (SVS_BASE + SVS_CTL_OFFSET))

#endif /* DRIVERLIB_SVS_PERIPHERAL_HEADER_SVS_REGISTERPERIPHERAL_H_ */
