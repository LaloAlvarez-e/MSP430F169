/**
 *
 * @file GPIO_RegisterPeripheral_PORT6.h
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

#ifndef GPIO_PERIPHERAL_REGISTERPERIPHERAL_HEADER_GPIO_REGISTERPERIPHERAL_PORT6_H_
#define GPIO_PERIPHERAL_REGISTERPERIPHERAL_HEADER_GPIO_REGISTERPERIPHERAL_PORT6_H_

#include "GPIO/Peripheral/Header/GPIO_RegisterAddress.h"
#include "GPIO/Peripheral/Header/GPIO_StructPeripheral.h"
#include <stdint.h>

#define PORT6 ((PORT_t*) PORT6_BASE)

/******************************************************************************************
 ************************************ 1 IN *********************************************
 ******************************************************************************************/
#define PORT6_IN_R  (*(volatile const uint8_t*) (PORT6_BASE + PORT_IN_OFFSET))
#define PORT6_IN    ((PORT_REG_CONST_t*) (PORT6_BASE + PORT_IN_OFFSET))

/******************************************************************************************
 ************************************ 2 OUT *********************************************
 ******************************************************************************************/
#define PORT6_OUT_R (*(volatile uint8_t*) (PORT6_BASE + PORT_OUT_OFFSET))
#define PORT6_OUT ((PORT_REG_t*) (PORT6_BASE + PORT_OUT_OFFSET))

/******************************************************************************************
 ************************************ 3 DIR *********************************************
 ******************************************************************************************/
#define PORT6_DIR_R (*(volatile uint8_t*) (PORT6_BASE + PORT_DIR_OFFSET))
#define PORT6_DIR ((PORT_REG_t*) (PORT6_BASE + PORT_DIR_OFFSET))

/******************************************************************************************
 ************************************ 3 SEL *********************************************
 ******************************************************************************************/
#define PORT6_SEL_R (*(volatile uint8_t*) (PORT6_BASE + PORT_SEL_OFFSET))
#define PORT6_SEL ((PORT_REG_t*) (PORT6_BASE + PORT_SEL_OFFSET))

#endif /* GPIO_PERIPHERAL_REGISTERPERIPHERAL_HEADER_GPIO_REGISTERPERIPHERAL_PORT6_H_ */
