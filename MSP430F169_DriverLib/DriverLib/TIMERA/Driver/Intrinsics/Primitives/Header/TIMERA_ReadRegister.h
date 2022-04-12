/**
 *
 * @file TIMERA_ReadRegister.h
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

#ifndef TIMERA_DRIVER_INTRINSICS_PRIMITIVES_HEADER_TIMERA_READREGISTER_H_
#define TIMERA_DRIVER_INTRINSICS_PRIMITIVES_HEADER_TIMERA_READREGISTER_H_

#include "DriverLib/TIMERA/Peripheral/Header/TIMERA_Enum.h"

uint16_t TIMERA__u16ReadRegister(TIMERA_Register_t* pstRegisterData);
uint16_t TIMERA_CC__u16ReadRegister(TIMERA_nCC enModuleArg,
                                 TIMERA_Register_t* pstRegisterData);

#endif /* TIMERA_DRIVER_INTRINSICS_PRIMITIVES_HEADER_TIMERA_READREGISTER_H_ */
