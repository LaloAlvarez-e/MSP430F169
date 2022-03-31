/**
 *
 * @file CLOCK_WriteRegister.h
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

#ifndef CLOCK_DRIVER_INTRINSICS_PRIMITIVES_HEADER_CLOCK_WRITEREGISTER_H_
#define CLOCK_DRIVER_INTRINSICS_PRIMITIVES_HEADER_CLOCK_WRITEREGISTER_H_

#include "DriverLib/CLOCK/Peripheral/Header/CLOCK_Enum.h"

void CLOCK__vWriteRegister(CLOCK_Register_t* pstRegisterData);

#endif /* CLOCK_DRIVER_INTRINSICS_PRIMITIVES_HEADER_CLOCK_WRITEREGISTER_H_ */
