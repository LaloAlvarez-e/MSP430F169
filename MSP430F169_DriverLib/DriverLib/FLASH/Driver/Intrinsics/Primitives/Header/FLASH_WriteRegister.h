/**
 *
 * @file FLASH_WriteRegister.h
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

#ifndef DRIVERLIB_FLASH_DRIVER_INTRINSICS_PRIMITIVES_HEADER_FLASH_WRITEREGISTER_H_
#define DRIVERLIB_FLASH_DRIVER_INTRINSICS_PRIMITIVES_HEADER_FLASH_WRITEREGISTER_H_

#include "DriverLib/FLASH/Peripheral/Header/FLASH_Enum.h"

void FLASH__vWriteRegister_8bits(FLASH_Register8Bits_t* pstRegisterData);
void FLASH__vWriteRegister_16bits(FLASH_Register16Bits_t* pstRegisterData);

#endif /* DRIVERLIB_FLASH_DRIVER_INTRINSICS_PRIMITIVES_HEADER_FLASH_WRITEREGISTER_H_ */
