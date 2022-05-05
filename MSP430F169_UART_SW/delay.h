/**
 *
 * @file delay.h
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

#ifndef DELAY_H_
#define DELAY_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

void Delay__vInit(void);
void Delay__v10miliseconds(uint16_t u16DelayArg);

#endif /* DELAY_H_ */
