/**
 *
 * @file CLOCK_Resistor.c
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
#include "DriverLib/CLOCK/Driver/DCO/Header/CLOCK_Resistor.h"

#include "DriverLib/CLOCK/Driver/Intrinsics/Primitives/CLOCK_Primitives.h"
#include "DriverLib/CLOCK/Peripheral/CLOCK_Peripheral.h"


void CLOCK__vSetDCOResistorSelect(CLOCK_nRESISTOR enResistorSelect)
{
    CLOCK__vWriteRegister(CLOCK_BCSCTL2_OFFSET,
                         (uint8_t) enResistorSelect,
                         CLOCK_BCSCTL2_DCOR_MASK,
                         CLOCK_BCSCTL2_R_DCOR_BIT);
}

CLOCK_nRESISTOR CLOCK__enGetDCOResistorSelect(void)
{
    CLOCK_nRESISTOR enResistorSelectReg = CLOCK_enRESISTOR_INTERNAL;

    enResistorSelectReg = (CLOCK_nRESISTOR) CLOCK__u8ReadRegister(CLOCK_BCSCTL2_OFFSET,
                                                                 CLOCK_BCSCTL2_DCOR_MASK,
                                                                 CLOCK_BCSCTL2_R_DCOR_BIT);
    return (enResistorSelectReg);
}




