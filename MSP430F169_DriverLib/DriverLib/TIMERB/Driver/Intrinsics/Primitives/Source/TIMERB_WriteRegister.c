/**
 *
 * @file TIMERB_WriteRegister.c
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
#include "DriverLib/TIMERB/Driver/Intrinsics/Primitives/Header/TIMERB_WriteRegister.h"

#include "DriverLib/TIMERB/Peripheral/TIMERB_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

void TIMERB__vWriteRegister(TIMERB_Register_t* pstRegisterData)
{
    uintptr_t ptrBase = TIMERB_BASE;
    pstRegisterData->uptrAddress += ptrBase;
    MCU__vWriteRegister_16bits(pstRegisterData);
}

void TIMERB_CC__vWriteRegister(TIMERB_nCC enModuleArg,
                            TIMERB_Register_t* pstRegisterData)
{
    uintptr_t ptrPortBase = 0U;
    ptrPortBase = TIMERB_CC__uptrBlockBaseAddress(enModuleArg);
    pstRegisterData->uptrAddress += ptrPortBase;
    MCU__vWriteRegister_16bits(pstRegisterData);
}
