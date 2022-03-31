/**
 *
 * @file SVS_ReadRegister.h
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

#ifndef DRIVERLIB_SVS_DRIVER_INTRINSICS_PRIMITIVES_HEADER_SVS_READREGISTER_H_
#define DRIVERLIB_SVS_DRIVER_INTRINSICS_PRIMITIVES_HEADER_SVS_READREGISTER_H_

#include "DriverLib/SVS/Peripheral/Header/SVS_Enum.h"

uint8_t SVS__u8ReadRegister(SVS_Register_t* pstRegisterData);

#endif /* DRIVERLIB_SVS_DRIVER_INTRINSICS_PRIMITIVES_HEADER_SVS_READREGISTER_H_ */
