/**
 *
 * @file GPIO_RegisterAddress.h
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

#ifndef GPIO_PERIPHERAL_HEADER_GPIO_REGISTERADDRESS_H_
#define GPIO_PERIPHERAL_HEADER_GPIO_REGISTERADDRESS_H_

#define GPIO_BASE (0x18U)

#define PORT1_BASE (0x20U)
#define PORT2_BASE (0x28U)
#define PORT3_BASE (0x18U)
#define PORT4_BASE (0x1CU)
#define PORT5_BASE (0x30U)
#define PORT6_BASE (0x34U)

#define PORT_IN_OFFSET (0x00U)
#define PORT_OUT_OFFSET (0x01U)
#define PORT_DIR_OFFSET (0x02U)
#define PORT_SEL_OFFSET (0x03U)
#define PORT_IFG_OFFSET (0x03U)
#define PORT_IES_OFFSET (0x04U)
#define PORT_IE_OFFSET (0x05U)
#define PORT_EXT_SEL_OFFSET (0x06U)

#endif /* GPIO_PERIPHERAL_HEADER_GPIO_REGISTERADDRESS_H_ */
