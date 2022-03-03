/**
 *
 * @file CLOCK_Enable.c
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
 * @verbatim 13 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 13 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/CLOCK/Driver/Header/CLOCK_Enable.h"

#include "DriverLib/CLOCK/Driver/Intrinsics/Primitives/CLOCK_Primitives.h"
#include "DriverLib/CLOCK/Peripheral/CLOCK_Peripheral.h"
#include "DriverLib/MCU/MCU.h"

CLOCK_nSTATUS CLOCK__enSetEnable(CLOCK_nSOURCE enClockSource, CLOCK_nENABLE enEnable)
{
    CLOCK_nSTATUS enStatusReg = CLOCK_enSTATUS_OK;
    switch (enClockSource)
    {
    case CLOCK_enSOURCE_LFXT1:
        CLOCK__vSetLFXT1Enable(enEnable);
        break;
    case CLOCK_enSOURCE_XT2:
        CLOCK__vSetXT2Enable(enEnable);
        break;
    case CLOCK_enSOURCE_DCO:
        CLOCK__vSetDCOEnable(enEnable);
        break;
    default:
        enStatusReg = CLOCK_enSTATUS_ERROR;
        break;
    }
    return (enStatusReg);
}

void CLOCK__vSetLFXT1Enable(CLOCK_nENABLE enEnable)
{
    if(CLOCK_enENABLE_ENA != enEnable)
    {
        __bis_SR_register(OSCOFF);
    }
    else
    {
        __bic_SR_register(OSCOFF);
    }
}

void CLOCK__vSetDCOEnable(CLOCK_nENABLE enEnable)
{
    if(CLOCK_enENABLE_ENA != enEnable)
    {
        __bis_SR_register(SCG0);
    }
    else
    {
        __bic_SR_register(SCG0);
    }
}

void CLOCK__vSetXT2Enable(CLOCK_nENABLE enEnable)
{
    CLOCK_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = CLOCK_BCSCTL1_OFFSET;
    pstRegisterData.u8Value = (uint8_t) enEnable;
    pstRegisterData.u8Mask = CLOCK_BCSCTL1_XT2OFF_MASK;
    pstRegisterData.u8Shift = CLOCK_BCSCTL1_R_XT2OFF_BIT;
    CLOCK__vWriteRegister(&pstRegisterData);
}

CLOCK_nENABLE CLOCK__enGetEnable(CLOCK_nSOURCE enClockSource)
{
    CLOCK_nENABLE enEnableReg = CLOCK_enENABLE_DIS;
    switch (enClockSource)
    {
    case CLOCK_enSOURCE_LFXT1:
        enEnableReg = CLOCK__enGetLFXT1Enable();
        break;
    case CLOCK_enSOURCE_XT2:
        enEnableReg = CLOCK__enGetXT2Enable();
        break;
    case CLOCK_enSOURCE_DCO:
        enEnableReg = CLOCK__enGetDCOEnable();
        break;
    default:
        break;
    }
    return (enEnableReg);
}

CLOCK_nENABLE CLOCK__enGetLFXT1Enable(void)
{
    CLOCK_nENABLE enEnableReg = CLOCK_enENABLE_ENA;
    uint8_t u8OscOffReg = 0U;

    u8OscOffReg = __get_SR_register();
    u8OscOffReg &= OSCOFF;
    if(0U != u8OscOffReg)
    {
        enEnableReg = CLOCK_enENABLE_DIS;
    }
    return (enEnableReg);
}

CLOCK_nENABLE CLOCK__enGetDCOEnable(void)
{
    CLOCK_nENABLE enEnableReg = CLOCK_enENABLE_ENA;
    uint8_t u8OscOffReg = 0U;

    u8OscOffReg = __get_SR_register();
    u8OscOffReg &= SCG0;
    if(0U != u8OscOffReg)
    {
        enEnableReg = CLOCK_enENABLE_DIS;
    }
    return (enEnableReg);
}

CLOCK_nENABLE CLOCK__enGetXT2Enable(void)
{
    CLOCK_Register_t pstRegisterData = {0UL};
    pstRegisterData.uptrAddress = CLOCK_BCSCTL1_OFFSET;
    pstRegisterData.u8Value = (uint8_t) CLOCK_enENABLE_ENA;
    pstRegisterData.u8Mask = CLOCK_BCSCTL1_XT2OFF_MASK;
    pstRegisterData.u8Shift = CLOCK_BCSCTL1_R_XT2OFF_BIT;
    (void) CLOCK__u8ReadRegister(&pstRegisterData);
    return ((CLOCK_nENABLE) pstRegisterData.u8Value);
}
