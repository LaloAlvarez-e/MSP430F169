/**
 *
 * @file WDT_WriteRegister.h
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

#ifndef DRIVERLIB_WDT_DRIVER_INTRINSICS_PRIMITIVES_HEADER_WDT_WRITEREGISTER_H_
#define DRIVERLIB_WDT_DRIVER_INTRINSICS_PRIMITIVES_HEADER_WDT_WRITEREGISTER_H_

#include "DriverLib/WDT/Peripheral/Header/WDT_Enum.h"

#pragma CODE_SECTION(WDT__vWriteRegister_16bits_RAM, ".TI.ramfunc")

void WDT__vWriteRegister_8bits(WDT_Register8Bits_t* pstRegisterData);
void WDT__vWriteRegister_16bits(WDT_Register16Bits_t* pstRegisterData);
void WDT__vWriteRegister_16bits_RAM(WDT_Register16Bits_t* pstRegisterData);

#endif /* DRIVERLIB_WDT_DRIVER_INTRINSICS_PRIMITIVES_HEADER_WDT_WRITEREGISTER_H_ */
