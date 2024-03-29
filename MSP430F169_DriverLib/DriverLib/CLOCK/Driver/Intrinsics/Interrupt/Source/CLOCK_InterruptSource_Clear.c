/**
 *
 * @file CLOCK_InterruptSource_Clear.c
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
#include "DriverLib/CLOCK/Driver/Intrinsics/Interrupt/Header/CLOCK_InterruptSource_Clear.h"

#include "DriverLib/CLOCK/Driver/Intrinsics/Primitives/CLOCK_Primitives.h"
#include "DriverLib/CLOCK/Peripheral/CLOCK_Peripheral.h"

void CLOCK__vClearInterruptSource(void)
{
    CLOCK_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = CLOCK_IFG1_OFFSET;
    pstRegisterData.u8Value = CLOCK_IFG1_IFG_NOOCCUR;
    pstRegisterData.u8Mask = CLOCK_IFG1_IFG_MASK;
    pstRegisterData.u8Shift = CLOCK_IFG1_R_IFG_BIT;

    CLOCK__vWriteRegister(&pstRegisterData);
}

