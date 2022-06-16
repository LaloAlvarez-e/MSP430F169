/**
 *
 * @file TIMERA_WriteRegister.c
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
#include "DriverLib/TIMERA/Driver/Intrinsics/Primitives/Header/TIMERA_WriteRegister.h"

#include "DriverLib/TIMERA/Peripheral/TIMERA_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

void TIMERA__vWriteRegister(TIMERA_Register_t* pstRegisterData)
{
    pstRegisterData->uptrAddress += TIMERA_BASE;
    MCU__vWriteRegister_16bits(pstRegisterData);
}

void TIMERA_CC__vWriteRegister(TIMERA_nCC enModuleArg,
                            TIMERA_Register_t* pstRegisterData)
{
    uintptr_t ptrPortBase;
    ptrPortBase = TIMERA_CC__uptrBlockBaseAddress(enModuleArg);
    pstRegisterData->uptrAddress += ptrPortBase;
    MCU__vWriteRegister_16bits(pstRegisterData);
}
