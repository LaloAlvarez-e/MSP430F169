/**
 *
 * @file CLOCK_Mode.c
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
 * @verbatim 14 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 14 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/CLOCK/Driver/Header/CLOCK_Mode.h"

#include "DriverLib/CLOCK/Driver/Intrinsics/Primitives/CLOCK_Primitives.h"
#include "DriverLib/CLOCK/Peripheral/CLOCK_Peripheral.h"


void CLOCK__vSetLFXT1FrequencyMode(CLOCK_nFREQMODE enFrequencyMode)
{
    CLOCK_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = CLOCK_BCSCTL1_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enFrequencyMode;
    pstRegisterData.u8Mask = CLOCK_BCSCTL1_XTS_MASK;
    pstRegisterData.u8Shift = CLOCK_BCSCTL1_R_XTS_BIT;
    CLOCK__vWriteRegister(&pstRegisterData);
}

CLOCK_nFREQMODE CLOCK__enGetLFXT1FrequencyMode(void)
{
    CLOCK_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = CLOCK_BCSCTL1_OFFSET;
    pstRegisterData.u8Value = (uint8_t) CLOCK_enFREQMODE_LOW;
    pstRegisterData.u8Mask = CLOCK_BCSCTL1_XTS_MASK;
    pstRegisterData.u8Shift = CLOCK_BCSCTL1_R_XTS_BIT;
    (void) CLOCK__u8ReadRegister(&pstRegisterData);
    return ((CLOCK_nFREQMODE) pstRegisterData.u8Value);
}


