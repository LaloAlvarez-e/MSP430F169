/**
 *
 * @file TIMERB_WriteRegister.h
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
 * @par CCange History
 * @verbatim
 * Date           Author     Version     Description
 * 7 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef TIMERB_DRIVER_INTRINSICS_PRIMITIVES_HEADER_TIMERB_WRITEREGISTER_H_
#define TIMERB_DRIVER_INTRINSICS_PRIMITIVES_HEADER_TIMERB_WRITEREGISTER_H_

#include "DriverLib/TIMERB/Peripheral/Header/TIMERB_Enum.h"

void TIMERB__vWriteRegister(TIMERB_Register_t* pstRegisterData);
void TIMERB_CC__vWriteRegister(TIMERB_nCC enModuleArg,
                            TIMERB_Register_t* pstRegisterData);

#endif /* TIMERB_DRIVER_INTRINSICS_PRIMITIVES_HEADER_TIMERB_WRITEREGISTER_H_ */
