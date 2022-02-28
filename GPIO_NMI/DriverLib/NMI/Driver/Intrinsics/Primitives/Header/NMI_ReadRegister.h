/**
 *
 * @file NMI_ReadRegister.h
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
 * @verbatim 25 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 25 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DRIVERLIB_NMI_DRIVER_INTRINSICS_PRIMITIVES_HEADER_NMI_READREGISTER_H_
#define DRIVERLIB_NMI_DRIVER_INTRINSICS_PRIMITIVES_HEADER_NMI_READREGISTER_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

uint8_t NMI__u8ReadRegister(uintptr_t uptrRegisterAddress,
                             uint8_t u8RegisterMask,
                             uint8_t u8RegisterShift);

uint16_t NMI__u16ReadRegister(uintptr_t uptrRegisterAddress,
                             uint16_t u16RegisterMask,
                             uint8_t u8RegisterShift);

#endif /* DRIVERLIB_NMI_DRIVER_INTRINSICS_PRIMITIVES_HEADER_NMI_READREGISTER_H_ */
