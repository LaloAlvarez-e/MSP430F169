/**
 *
 * @file GPIO_WriteRegister.h
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

#ifndef GPIO_DRIVER_INTRINSICS_PRIMITIVES_HEADER_GPIO_WRITEREGISTER_H_
#define GPIO_DRIVER_INTRINSICS_PRIMITIVES_HEADER_GPIO_WRITEREGISTER_H_

#include "DriverLib/GPIO/Peripheral/Header/GPIO_Enum.h"


void GPIO__vWriteRegister(GPIO_nPORT enPortArg,
                          GPIO_Register_t* pstRegisterData);

#endif /* GPIO_DRIVER_INTRINSICS_PRIMITIVES_HEADER_GPIO_WRITEREGISTER_H_ */
