/**
 *
 * @file NMI_WriteRegister.c
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
#include "DriverLib/NMI/Driver/Intrinsics/Primitives/Header/NMI_WriteRegister.h"

#include "DriverLib/NMI/Peripheral/NMI_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

void NMI__vWriteRegister_8bits(NMI_Register8Bits_t* pstRegisterData)
{
    pstRegisterData->uptrAddress += NMI_BASE;
    MCU__vWriteRegister_8bits(pstRegisterData);
}


void NMI__vWriteRegister_16bits(NMI_Register16Bits_t* pstRegisterData)
{
    pstRegisterData->uptrAddress += NMI_BASE;
    MCU__vWriteRegister_16bits(pstRegisterData);
}
