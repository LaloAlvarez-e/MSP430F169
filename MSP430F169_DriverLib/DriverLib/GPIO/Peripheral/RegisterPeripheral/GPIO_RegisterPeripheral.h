/**
 *
 * @file GPIO_RegisterPeripheral.h
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

#ifndef GPIO_PERIPHERAL_REGISTERPERIPHERAL_GPIO_REGISTERPERIPHERAL_H_
#define GPIO_PERIPHERAL_REGISTERPERIPHERAL_GPIO_REGISTERPERIPHERAL_H_

#include "DriverLib/GPIO/Peripheral/RegisterPeripheral/Header/GPIO_RegisterPeripheral_PORT1.h"
#include "DriverLib/GPIO/Peripheral/RegisterPeripheral/Header/GPIO_RegisterPeripheral_PORT2.h"
#include "DriverLib/GPIO/Peripheral/RegisterPeripheral/Header/GPIO_RegisterPeripheral_PORT3.h"
#include "DriverLib/GPIO/Peripheral/RegisterPeripheral/Header/GPIO_RegisterPeripheral_PORT4.h"
#include "DriverLib/GPIO/Peripheral/RegisterPeripheral/Header/GPIO_RegisterPeripheral_PORT5.h"
#include "DriverLib/GPIO/Peripheral/RegisterPeripheral/Header/GPIO_RegisterPeripheral_PORT6.h"
#include "DriverLib/GPIO/Peripheral/Header/GPIO_Enum.h"

#define GPIO ((GPIO_t*) GPIO_BASE)

uintptr_t GPIO__uptrBlockBaseAddress(GPIO_nPORT enPortArg);

#endif /* GPIO_PERIPHERAL_REGISTERPERIPHERAL_GPIO_REGISTERPERIPHERAL_H_ */
