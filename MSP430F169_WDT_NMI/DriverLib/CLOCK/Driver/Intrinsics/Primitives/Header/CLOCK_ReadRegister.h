/**
 *
 * @file CLOCK_ReadRegister.h
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
 * @verbatim 12 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 12 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef CLOCK_DRIVER_INTRINSICS_PRIMITIVES_HEADER_CLOCK_READREGISTER_H_
#define CLOCK_DRIVER_INTRINSICS_PRIMITIVES_HEADER_CLOCK_READREGISTER_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

uint8_t CLOCK__u8ReadRegister(uintptr_t uptrRegisterAddress,
                             uint8_t u8RegisterMask,
                             uint8_t u8RegisterShift);


#endif /* CLOCK_DRIVER_INTRINSICS_PRIMITIVES_HEADER_CLOCK_READREGISTER_H_ */
