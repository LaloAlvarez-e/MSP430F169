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
#include "CLOCK/Driver/Header/CLOCK_Selector.h"

#include "CLOCK/Driver/Intrinsics/Primitives/CLOCK_Primitives.h"
#include "CLOCK/Peripheral/CLOCK_Peripheral.h"

CLOCK_nSTATUS CLOCK__enSetSource(CLOCK_nSIGNAL enClockSignal, CLOCK_nSOURCE enSourceClock)
{
    CLOCK_nSTATUS enStatusReg = CLOCK_enSTATUS_ERROR;
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
        break;
    }
    return (enStatusReg);
}

CLOCK_nSTATUS CLOCK__enSetACLKSource(CLOCK_nSOURCE enSourceClock)
{
    CLOCK_nSTATUS enStatusReg = CLOCK_enSTATUS_OK;
    switch(enSourceClock)
    {
    case CLOCK_enSOURCE_LFXT1:
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
    switch(enSourceClock)
    {
    case CLOCK_enSOURCE_LFXT1:
        CLOCK__vWriteRegister(CLOCK_BCSCTL2_OFFSET,
                              CLOCK_BCSCTL2_SELM_LFXT1,
                             CLOCK_BCSCTL2_SELM_MASK,
                             CLOCK_BCSCTL2_R_SELM_BIT);
        break;
    case CLOCK_enSOURCE_XT2:
        CLOCK__vWriteRegister(CLOCK_BCSCTL2_OFFSET,
                              CLOCK_BCSCTL2_SELM_XT2,
                             CLOCK_BCSCTL2_SELM_MASK,
                             CLOCK_BCSCTL2_R_SELM_BIT);
        break;
    case CLOCK_enSOURCE_DCO:
        CLOCK__vWriteRegister(CLOCK_BCSCTL2_OFFSET,
                              CLOCK_BCSCTL2_SELM_DCO,
                             CLOCK_BCSCTL2_SELM_MASK,
                             CLOCK_BCSCTL2_R_SELM_BIT);
        break;
    default:
        enStatusReg = CLOCK_enSTATUS_ERROR;
        break;
    }
    return (enStatusReg);
}

CLOCK_nSTATUS CLOCK__enSetSMCLKSource(CLOCK_nSOURCE enSourceClock)
{
    CLOCK_nSTATUS enStatusReg = CLOCK_enSTATUS_OK;
    switch(enSourceClock)
    {
    case CLOCK_enSOURCE_XT2:
        CLOCK__vWriteRegister(CLOCK_BCSCTL2_OFFSET,
                              CLOCK_BCSCTL2_SELS_XT2,
                             CLOCK_BCSCTL2_SELS_MASK,
                             CLOCK_BCSCTL2_R_SELS_BIT);
        break;
    case CLOCK_enSOURCE_DCO:
        CLOCK__vWriteRegister(CLOCK_BCSCTL2_OFFSET,
                              CLOCK_BCSCTL2_SELS_DCO,
                             CLOCK_BCSCTL2_SELS_MASK,
                             CLOCK_BCSCTL2_R_SELS_BIT);
        break;
    default:
        enStatusReg = CLOCK_enSTATUS_ERROR;
        break;
    }
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
    CLOCK_nSOURCE enSourceReg = CLOCK_enSOURCE_LFXT1;
    return (enSourceReg);
}

CLOCK_nSOURCE CLOCK__enGetSMCLKSource(void)
{
    CLOCK_nSOURCE enSourceReg = CLOCK_enSOURCE_DCO;
    uint8_t u8RegValue = 0U;

    u8RegValue = CLOCK__u8ReadRegister(CLOCK_BCSCTL2_OFFSET,
                                       CLOCK_BCSCTL2_SELS_MASK,
                                       CLOCK_BCSCTL2_R_SELS_BIT);
    switch(u8RegValue)
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
    uint8_t u8RegValue = 0U;

    u8RegValue = CLOCK__u8ReadRegister(CLOCK_BCSCTL2_OFFSET,
                                       CLOCK_BCSCTL2_SELM_MASK,
                                       CLOCK_BCSCTL2_R_SELM_BIT);
    switch(u8RegValue)
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
