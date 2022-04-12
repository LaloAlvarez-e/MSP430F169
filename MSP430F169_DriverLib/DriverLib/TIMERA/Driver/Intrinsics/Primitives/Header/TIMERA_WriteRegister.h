/**
 *
 * @file TIMERA_WriteRegister.h
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

#ifndef TIMERA_DRIVER_INTRINSICS_PRIMITIVES_HEADER_TIMERA_WRITEREGISTER_H_
#define TIMERA_DRIVER_INTRINSICS_PRIMITIVES_HEADER_TIMERA_WRITEREGISTER_H_

#include "DriverLib/TIMERA/Peripheral/Header/TIMERA_Enum.h"

void TIMERA__vWriteRegister(TIMERA_Register_t* pstRegisterData);
void TIMERA_CC__vWriteRegister(TIMERA_nCC enModuleArg,
                            TIMERA_Register_t* pstRegisterData);

#endif /* TIMERA_DRIVER_INTRINSICS_PRIMITIVES_HEADER_TIMERA_WRITEREGISTER_H_ */
