/**
 *
 * @file Button.h
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
 * @verbatim 17 may. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 17 may. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

void Button__vInit(void);
uint8_t Button__u8GetUpValue(void);
uint8_t Button__u8GetRightValue(void);
uint8_t Button__u8GetLeftValue(void);
uint8_t Button__u8GetDownValue(void);
uint8_t Button__u8GetAllValues(void);



#endif /* BUTTON_H_ */
