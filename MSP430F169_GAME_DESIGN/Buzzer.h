/**
 *
 * @file Buzzer.h
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

#ifndef BUZZER_H_
#define BUZZER_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

void Buzzer__vInit(void);
void Buzzer__vPlaySound(const uint8_t *pu8SoundToPlay, uint16_t u16SoundSize);



#endif /* BUZZER_H_ */
