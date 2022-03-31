/**
 *
 * @file GPIO_ReadRegister.h
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
 * @verbatim 7 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 7 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef GPIO_DRIVER_INTRINSICS_PRIMITIVES_HEADER_GPIO_READREGISTER_H_
#define GPIO_DRIVER_INTRINSICS_PRIMITIVES_HEADER_GPIO_READREGISTER_H_

#include "GPIO/Peripheral/Header/GPIO_Enum.h"

uint8_t GPIO__u8ReadRegister(GPIO_nPORT enPortArg,
                             uintptr_t uptrRegisterAddress,
                             uint8_t u8RegisterMask,
                             uint8_t u8RegisterShift);

#endif /* GPIO_DRIVER_INTRINSICS_PRIMITIVES_HEADER_GPIO_READREGISTER_H_ */
