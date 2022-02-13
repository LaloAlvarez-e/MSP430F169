/**
 *
 * @file GPIO_RegisterPeripheral_PORT5.h
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

#ifndef GPIO_PERIPHERAL_REGISTERPERIPHERAL_HEADER_GPIO_REGISTERPERIPHERAL_PORT5_H_
#define GPIO_PERIPHERAL_REGISTERPERIPHERAL_HEADER_GPIO_REGISTERPERIPHERAL_PORT5_H_

#include "GPIO/Peripheral/Header/GPIO_RegisterAddress.h"
#include "GPIO/Peripheral/Header/GPIO_StructPeripheral.h"
#include "MCU/Header/MCU_Common.h"

#define PORT5 ((PORT_t*) PORT5_BASE)

/******************************************************************************************
 ************************************ 1 IN *********************************************
 ******************************************************************************************/
#define PORT5_IN_R  (*(volatile const uint8_t*) (PORT5_BASE + PORT_IN_OFFSET))
#define PORT5_IN    ((PORT_REG_CONST_t*) (PORT5_BASE + PORT_IN_OFFSET))

/******************************************************************************************
 ************************************ 2 OUT *********************************************
 ******************************************************************************************/
#define PORT5_OUT_R (*(volatile uint8_t*) (PORT5_BASE + PORT_OUT_OFFSET))
#define PORT5_OUT ((PORT_REG_t*) (PORT5_BASE + PORT_OUT_OFFSET))

/******************************************************************************************
 ************************************ 3 DIR *********************************************
 ******************************************************************************************/
#define PORT5_DIR_R (*(volatile uint8_t*) (PORT5_BASE + PORT_DIR_OFFSET))
#define PORT5_DIR ((PORT_REG_t*) (PORT5_BASE + PORT_DIR_OFFSET))

/******************************************************************************************
 ************************************ 3 SEL *********************************************
 ******************************************************************************************/
#define PORT5_SEL_R (*(volatile uint8_t*) (PORT5_BASE + PORT_SEL_OFFSET))
#define PORT5_SEL ((PORT_REG_t*) (PORT5_BASE + PORT_SEL_OFFSET))




#endif /* GPIO_PERIPHERAL_REGISTERPERIPHERAL_HEADER_GPIO_REGISTERPERIPHERAL_PORT5_H_ */
