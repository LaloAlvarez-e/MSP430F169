/**
 *
 * @file NMI_WriteRegister.h
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

#ifndef DRIVERLIB_NMI_DRIVER_INTRINSICS_PRIMITIVES_HEADER_NMI_WRITEREGISTER_H_
#define DRIVERLIB_NMI_DRIVER_INTRINSICS_PRIMITIVES_HEADER_NMI_WRITEREGISTER_H_

#include "DriverLib/NMI/Peripheral/Header/NMI_Enum.h"

void NMI__vWriteRegister_8bits(NMI_Register8Bits_t* pstRegisterData);
void NMI__vWriteRegister_16bits(NMI_Register16Bits_t* pstRegisterData);

#endif /* DRIVERLIB_NMI_DRIVER_INTRINSICS_PRIMITIVES_HEADER_NMI_WRITEREGISTER_H_ */
