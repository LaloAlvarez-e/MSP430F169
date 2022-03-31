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
    CLOCK__vWriteRegister(CLOCK_BCSCTL1_OFFSET,
                         u8ResistorSelect,
                         CLOCK_BCSCTL1_RSEL_MASK,
                         CLOCK_BCSCTL1_R_RSEL_BIT);
}

uint8_t CLOCK__u8GetResistorSelect(void)
{
    uint8_t u8ResistorSelectReg = 0U;

    u8ResistorSelectReg = CLOCK__u8ReadRegister(CLOCK_BCSCTL1_OFFSET,
                                                 CLOCK_BCSCTL1_RSEL_MASK,
                                                 CLOCK_BCSCTL1_R_RSEL_BIT);
    return (u8ResistorSelectReg);
}



