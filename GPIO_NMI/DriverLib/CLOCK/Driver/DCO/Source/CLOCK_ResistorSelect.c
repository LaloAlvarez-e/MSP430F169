/**
 *
 * @file CLOCK_ResistorSelect.c
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
 * @verbatim 15 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 15 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/CLOCK/Driver/DCO/Header/CLOCK_ResistorSelect.h"

#include "DriverLib/CLOCK/Driver/Intrinsics/Primitives/CLOCK_Primitives.h"
#include "DriverLib/CLOCK/Peripheral/CLOCK_Peripheral.h"

void CLOCK__vSetResistorSelect(uint8_t u8ResistorSelect)
{
    CLOCK_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = CLOCK_BCSCTL1_OFFSET;
    pstRegisterData.u8Value = u8ResistorSelect;
    pstRegisterData.u8Mask = CLOCK_BCSCTL1_RSEL_MASK;
    pstRegisterData.u8Shift = CLOCK_BCSCTL1_R_RSEL_BIT;
    CLOCK__vWriteRegister(&pstRegisterData);
}

uint8_t CLOCK__u8GetResistorSelect(void)
{
    CLOCK_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = CLOCK_BCSCTL1_OFFSET;
    pstRegisterData.u8Value = 0U;
    pstRegisterData.u8Mask = CLOCK_BCSCTL1_RSEL_MASK;
    pstRegisterData.u8Shift = CLOCK_BCSCTL1_R_RSEL_BIT;
    (void) CLOCK__u8ReadRegister(&pstRegisterData);
    return (pstRegisterData.u8Value);
}



