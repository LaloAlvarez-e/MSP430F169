/**
 *
 * @file GPIO_InterruptSource.h
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
 * @verbatim 4 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 4 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef GPIO_HEADER_GPIO_INTERRUPTSOURCE_H_
#define GPIO_HEADER_GPIO_INTERRUPTSOURCE_H_

#include <stdint.h>

uint16_t (*GPIO__pu16fGetInterruptSource(uint8_t u8Pin))(void);
void GPIO__vSetInterruptSource(uint8_t u8Pin, uint16_t (*pu16fFunctionality)(void));

#endif /* GPIO_HEADER_GPIO_INTERRUPTSOURCE_H_ */
