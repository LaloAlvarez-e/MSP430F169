/**
 *
 * @file NMI_InterruptSource_Status.c
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
#include "DriverLib/NMI/Driver/Intrinsics/Interrupt/Header/NMI_InterruptSource_Status.h"

#include "DriverLib/NMI/Driver/Intrinsics/Primitives/NMI_Primitives.h"
#include "DriverLib/NMI/Peripheral/NMI_Peripheral.h"

void NMI__vSetStatusInterruptSource(NMI_nINT_STATUS enStatus)
{
    NMI_Register8Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = NMI_IFG1_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enStatus;
    pstRegisterData.u8Mask = NMI_IFG1_IFG_MASK;
    pstRegisterData.u8Shift = NMI_IFG1_R_IFG_BIT;

    NMI__vWriteRegister_8bits(&pstRegisterData);
}

NMI_nINT_STATUS NMI__enGetStatusInterruptSource(void)
{
    NMI_Register8Bits_t pstRegisterData;
    pstRegisterData.uptrAddress = NMI_IFG1_OFFSET;
    pstRegisterData.u8Value = (uint8_t) NMI_enINT_STATUS_NOOCCUR;
    pstRegisterData.u8Mask = NMI_IFG1_IFG_MASK;
    pstRegisterData.u8Shift = NMI_IFG1_R_IFG_BIT;

    (void) NMI__u8ReadRegister(&pstRegisterData);
    return ((NMI_nINT_STATUS) pstRegisterData.u8Value);
}
