/**
 *
 * @file TIMERA_ReadRegister.c
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
#include "DriverLib/TIMERA/Driver/Intrinsics/Primitives/Header/TIMERA_ReadRegister.h"

#include "DriverLib/TIMERA/Peripheral/TIMERA_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

uint16_t TIMERA__u16ReadRegister(TIMERA_Register_t* pstRegisterData)
{
    const uintptr_t ptrBase = TIMERA_BASE;
    uint16_t u16RegisterValue = 0U;

    pstRegisterData->uptrAddress += ptrBase;
    u16RegisterValue = MCU__u16ReadRegister(pstRegisterData);

    return (u16RegisterValue);
}

uint16_t TIMERA_CC__u16ReadRegister(TIMERA_nCC enModuleArg,
                                 TIMERA_Register_t* pstRegisterData)
{
    uintptr_t ptrChannelBase = 0U;
    uint16_t u16RegisterValue = 0U;

    ptrChannelBase = TIMERA_CC__uptrBlockBaseAddress(enModuleArg);
    pstRegisterData->uptrAddress += ptrChannelBase;
    u16RegisterValue = MCU__u16ReadRegister(pstRegisterData);

    return (u16RegisterValue);
}



