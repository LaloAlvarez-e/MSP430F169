/**
 *
 * @file CLOCK_Selector.c
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
#include "DriverLib/CLOCK/Driver/Header/CLOCK_Selector.h"

#include "DriverLib/CLOCK/Driver/Intrinsics/Primitives/CLOCK_Primitives.h"
#include "DriverLib/CLOCK/Peripheral/CLOCK_Peripheral.h"

CLOCK_nSTATUS CLOCK__enSetSource(CLOCK_nSIGNAL enClockSignal, CLOCK_nSOURCE enSourceClock)
{
    CLOCK_nSTATUS enStatusReg;
    switch (enClockSignal)
    {
    case CLOCK_enSIGNAL_ACLK:
        enStatusReg = CLOCK__enSetACLKSource(enSourceClock);
        break;
    case CLOCK_enSIGNAL_SMCLK:
        enStatusReg = CLOCK__enSetSMCLKSource(enSourceClock);
        break;
    case CLOCK_enSIGNAL_MCLK:
        enStatusReg = CLOCK__enSetMCLKSource(enSourceClock);
        break;
    default:
        enStatusReg = CLOCK_enSTATUS_ERROR;
        break;
    }
    return (enStatusReg);
}

CLOCK_nSTATUS CLOCK__enSetACLKSource(CLOCK_nSOURCE enSourceClock)
{
    CLOCK_nSTATUS enStatusReg;
    switch(enSourceClock)
    {
    case CLOCK_enSOURCE_LFXT1:
        enStatusReg = CLOCK_enSTATUS_OK;
        break;
    default:
        enStatusReg = CLOCK_enSTATUS_ERROR;
        break;
    }
    return (enStatusReg);
}

CLOCK_nSTATUS CLOCK__enSetMCLKSource(CLOCK_nSOURCE enSourceClock)
{
    CLOCK_nSTATUS enStatusReg = CLOCK_enSTATUS_OK;

    CLOCK_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = CLOCK_BCSCTL2_OFFSET;
    pstRegisterData.u8Value = CLOCK_BCSCTL2_SELM_DCO;
    pstRegisterData.u8Mask = CLOCK_BCSCTL2_SELM_MASK;
    pstRegisterData.u8Shift = CLOCK_BCSCTL2_R_SELM_BIT;

    switch(enSourceClock)
    {
    case CLOCK_enSOURCE_LFXT1:
        pstRegisterData.u8Value = CLOCK_BCSCTL2_SELM_LFXT1;
        break;
    case CLOCK_enSOURCE_XT2:
        pstRegisterData.u8Value = CLOCK_BCSCTL2_SELM_XT2;
        break;
    case CLOCK_enSOURCE_DCO:
        break;
    default:
        enStatusReg = CLOCK_enSTATUS_ERROR;
        break;
    }
    CLOCK__vWriteRegister(&pstRegisterData);
    return (enStatusReg);
}

CLOCK_nSTATUS CLOCK__enSetSMCLKSource(CLOCK_nSOURCE enSourceClock)
{
    CLOCK_nSTATUS enStatusReg = CLOCK_enSTATUS_OK;

    CLOCK_Register_t pstRegisterData;
    pstRegisterData.uptrAddress = CLOCK_BCSCTL2_OFFSET;
    pstRegisterData.u8Value = CLOCK_BCSCTL2_SELS_DCO;
    pstRegisterData.u8Mask = CLOCK_BCSCTL2_SELS_MASK;
    pstRegisterData.u8Shift = CLOCK_BCSCTL2_R_SELS_BIT;

    switch(enSourceClock)
    {
    case CLOCK_enSOURCE_XT2:
        pstRegisterData.u8Value = CLOCK_BCSCTL2_SELS_XT2;
        break;
    case CLOCK_enSOURCE_DCO:
        break;
    default:
        enStatusReg = CLOCK_enSTATUS_ERROR;
        break;
    }
    CLOCK__vWriteRegister(&pstRegisterData);
    return (enStatusReg);
}

CLOCK_nSOURCE CLOCK__enGetSource(CLOCK_nSIGNAL enClockSignal)
{
    CLOCK_nSOURCE enSourceReg = CLOCK_enSOURCE_LFXT1;
    switch (enClockSignal)
    {
    case CLOCK_enSIGNAL_ACLK:
        enSourceReg = CLOCK__enGetACLKSource();
        break;
    case CLOCK_enSIGNAL_SMCLK:
        enSourceReg = CLOCK__enGetSMCLKSource();
        break;
    case CLOCK_enSIGNAL_MCLK:
        enSourceReg = CLOCK__enGetMCLKSource();
        break;
    default:
        break;
    }
    return (enSourceReg);
}


CLOCK_nSOURCE CLOCK__enGetACLKSource(void)
{
    const CLOCK_nSOURCE enSourceReg = CLOCK_enSOURCE_LFXT1;
    return (enSourceReg);
}

CLOCK_nSOURCE CLOCK__enGetSMCLKSource(void)
{
    CLOCK_nSOURCE enSourceReg = CLOCK_enSOURCE_DCO;
    CLOCK_Register_t pstRegisterData;

    pstRegisterData.uptrAddress = CLOCK_BCSCTL2_OFFSET;
    pstRegisterData.u8Value = CLOCK_BCSCTL2_SELS_DCO;
    pstRegisterData.u8Mask = CLOCK_BCSCTL2_SELS_MASK;
    pstRegisterData.u8Shift = CLOCK_BCSCTL2_R_SELS_BIT;

    (void) CLOCK__u8ReadRegister(&pstRegisterData);

    switch(pstRegisterData.u8Value)
    {
    case CLOCK_BCSCTL2_SELS_DCO:
        enSourceReg = CLOCK_enSOURCE_DCO;
        break;
    case CLOCK_BCSCTL2_SELS_XT2:
        enSourceReg = CLOCK_enSOURCE_XT2;
        break;
    default:
        break;
    }

    return (enSourceReg);
}



CLOCK_nSOURCE CLOCK__enGetMCLKSource(void)
{
    CLOCK_nSOURCE enSourceReg = CLOCK_enSOURCE_DCO;
    CLOCK_Register_t pstRegisterData;

    pstRegisterData.uptrAddress = CLOCK_BCSCTL2_OFFSET;
    pstRegisterData.u8Value = CLOCK_BCSCTL2_SELM_DCO;
    pstRegisterData.u8Mask = CLOCK_BCSCTL2_SELM_MASK;
    pstRegisterData.u8Shift = CLOCK_BCSCTL2_R_SELM_BIT;

    (void) CLOCK__u8ReadRegister(&pstRegisterData);

    switch(pstRegisterData.u8Value)
    {
    case CLOCK_BCSCTL2_SELM_DCO:
        enSourceReg = CLOCK_enSOURCE_DCO;
        break;
    case CLOCK_BCSCTL2_SELM_XT2:
        enSourceReg = CLOCK_enSOURCE_XT2;
        break;
    case CLOCK_BCSCTL2_SELM_LFXT1:
        enSourceReg = CLOCK_enSOURCE_LFXT1;
        break;
    default:
        break;
    }
    return (enSourceReg);
}
