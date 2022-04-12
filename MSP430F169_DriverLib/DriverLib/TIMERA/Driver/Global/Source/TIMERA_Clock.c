/**
 *
 * @file TIMERA_Clock.c
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
 * @verbatim 9 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/TIMERA/Driver/Global/Header/TIMERA_Clock.h"

#include "DriverLib/TIMERA/Driver/Intrinsics/TIMERA_Intrinsics.h"
#include "DriverLib/TIMERA/Peripheral/TIMERA_Peripheral.h"

void TIMERA__vSetClockSource(TIMERA_nCLOCK enClockArg)
{
    TIMERA_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERA_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) enClockArg;
    pstRegisterData.u16Mask = TIMERA_CTL_SSEL_MASK;
    pstRegisterData.u8Shift = TIMERA_CTL_R_SSEL_BIT;
    TIMERA__vWriteRegister(&pstRegisterData);
}

TIMERA_nCLOCK TIMERA__enGetClockSource(void)
{
    TIMERA_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = TIMERA_CTL_OFFSET;
    pstRegisterData.u16Value = (uint16_t) TIMERA_enCLOCK_TACLK;
    pstRegisterData.u16Mask = TIMERA_CTL_SSEL_MASK;
    pstRegisterData.u8Shift = TIMERA_CTL_R_SSEL_BIT;
    (void) TIMERA__u16ReadRegister(&pstRegisterData);
    return ((TIMERA_nCLOCK) pstRegisterData.u16Value);
}
