/**
 *
 * @file uart.h
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
 * @verbatim 4 may. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 4 may. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef UART_H_
#define UART_H_


#include "DriverLib/MCU/Header/MCU_Common.h"

void UART__vInit(void);
uint8_t UART__u8RxReady(void);
void UART__vTxByte(uint8_t u8DataArg);


#endif /* UART_H_ */
