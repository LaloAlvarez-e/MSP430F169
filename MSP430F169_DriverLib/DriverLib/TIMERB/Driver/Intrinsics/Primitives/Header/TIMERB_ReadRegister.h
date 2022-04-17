/**
 *
 * @file TIMERB_ReadRegister.h
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

#ifndef TIMERB_DRIVER_INTRINSICS_PRIMITIVES_HEADER_TIMERB_READREGISTER_H_
#define TIMERB_DRIVER_INTRINSICS_PRIMITIVES_HEADER_TIMERB_READREGISTER_H_

#include "DriverLib/TIMERB/Peripheral/Header/TIMERB_Enum.h"

uint16_t TIMERB__u16ReadRegister(TIMERB_Register_t* pstRegisterData);
uint16_t TIMERB_CC__u16ReadRegister(TIMERB_nCC enModuleArg,
                                 TIMERB_Register_t* pstRegisterData);

#endif /* TIMERB_DRIVER_INTRINSICS_PRIMITIVES_HEADER_TIMERB_READREGISTER_H_ */
