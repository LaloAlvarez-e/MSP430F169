/**
 *
 * @file SlidePot.h
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

#ifndef SLIDEPOT_H_
#define SLIDEPOT_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

uint16_t SlidePort__u16GetValue(void);
void SlidePot__vInit(void);

#endif /* SLIDEPOT_H_ */
