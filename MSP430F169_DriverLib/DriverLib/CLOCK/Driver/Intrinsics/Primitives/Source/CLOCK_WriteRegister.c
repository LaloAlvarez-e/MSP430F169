/**
 *
 * @file CLOCK_WriteRegister.c
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
#include "DriverLib/CLOCK/Driver/Intrinsics/Primitives/Header/CLOCK_WriteRegister.h"

#include "DriverLib/CLOCK/Peripheral/CLOCK_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

void CLOCK__vWriteRegister(CLOCK_Register_t* pstRegisterData)
{
    pstRegisterData->uptrAddress += CLOCK_BASE;
    MCU__vWriteRegister_8bits(pstRegisterData);
}




