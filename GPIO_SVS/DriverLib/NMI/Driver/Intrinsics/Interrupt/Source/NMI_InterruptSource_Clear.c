/**
 *
 * @file NMI_InterruptSource_Clear.c
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
#include "DriverLib/NMI/Driver/Intrinsics/Interrupt/Header/NMI_InterruptSource_Clear.h"

#include "DriverLib/NMI/Driver/Intrinsics/Primitives/NMI_Primitives.h"
#include "DriverLib/NMI/Peripheral/NMI_Peripheral.h"

void NMI__vClearInterruptSource(void)
{
    NMI_Register8Bits_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = NMI_IFG1_OFFSET;
    pstRegisterData.u8Value = NMI_IFG1_IFG_NOOCCUR;
    pstRegisterData.u8Mask = NMI_IFG1_IFG_MASK;
    pstRegisterData.u8Shift = NMI_IFG1_R_IFG_BIT;

    NMI__vWriteRegister_8bits(&pstRegisterData);
}
