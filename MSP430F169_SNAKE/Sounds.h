/**
 *
 * @file Sounds.h
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

#ifndef SOUNDS_H_
#define SOUNDS_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

#define SOUND_SHOOT_SIZE (4081U)
extern const uint8_t Sounds__pu8shoot[SOUND_SHOOT_SIZE];

#define SOUND_INVADERKILLED_SIZE (3378U)
extern const uint8_t Sounds__pu8invaderkilled[SOUND_INVADERKILLED_SIZE];

#define SOUND_FASTINVADER_SIZE (1099U)
extern const uint8_t Sounds__pu8fastinvader4[SOUND_FASTINVADER_SIZE];

#define SOUND_HIGHPITCH_SIZE (1803U)
extern const uint8_t Sounds__pu8highpitch[SOUND_HIGHPITCH_SIZE];



#endif /* SOUNDS_H_ */
