/**
 *
 * @file GPIO_RegisterPeripheral_PORT3.h
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

#ifndef GPIO_PERIPHERAL_REGISTERPERIPHERAL_HEADER_GPIO_REGISTERPERIPHERAL_PORT3_H_
#define GPIO_PERIPHERAL_REGISTERPERIPHERAL_HEADER_GPIO_REGISTERPERIPHERAL_PORT3_H_

#include "DriverLib/GPIO/Peripheral/Header/GPIO_RegisterAddress.h"
#include "DriverLib/GPIO/Peripheral/Header/GPIO_StructPeripheral.h"
#include "DriverLib/MCU/Header/MCU_Common.h"

#define PORT3 ((PORT_t*) PORT3_BASE)

/******************************************************************************************
 ************************************ 1 IN *********************************************
 ******************************************************************************************/
#define PORT3_IN_R  (*(volatile const uint8_t*) (PORT3_BASE + PORT_IN_OFFSET))
#define PORT3_IN    ((PORT_REG_CONST_t*) (PORT3_BASE + PORT_IN_OFFSET))

/******************************************************************************************
 ************************************ 2 OUT *********************************************
 ******************************************************************************************/
#define PORT3_OUT_R (*(volatile uint8_t*) (PORT3_BASE + PORT_OUT_OFFSET))
#define PORT3_OUT ((PORT_REG_t*) (PORT3_BASE + PORT_OUT_OFFSET))

/******************************************************************************************
 ************************************ 3 DIR *********************************************
 ******************************************************************************************/
#define PORT3_DIR_R (*(volatile uint8_t*) (PORT3_BASE + PORT_DIR_OFFSET))
#define PORT3_DIR ((PORT_REG_t*) (PORT3_BASE + PORT_DIR_OFFSET))

/******************************************************************************************
 ************************************ 3 SEL *********************************************
 ******************************************************************************************/
#define PORT3_SEL_R (*(volatile uint8_t*) (PORT3_BASE + PORT_SEL_OFFSET))
#define PORT3_SEL ((PORT_REG_t*) (PORT3_BASE + PORT_SEL_OFFSET))


#endif /* GPIO_PERIPHERAL_REGISTERPERIPHERAL_HEADER_GPIO_REGISTERPERIPHERAL_PORT3_H_ */
