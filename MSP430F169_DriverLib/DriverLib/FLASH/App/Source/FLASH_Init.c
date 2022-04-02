/**
 *
 * @file FLASH_Init.c
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
 * @verbatim 1 abr. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 1 abr. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/FLASH/App/Header/FLASH_Init.h"

#include "DriverLib/CLOCK/CLOCK.h"
#include "DriverLib/FLASH/FLASH.h"


static uint32_t FLASH_u32FreqReg = 0UL;

uint32_t FLASH__u32Init(FLASH_nCLOCK enClockSourceArg)
{
    const uint32_t pu32FreqRanges[2U] = {257000UL,476000UL};
    uint8_t u8CountReg = 0U;
    uint32_t u32SysFreqReq = 0UL;

    switch(enClockSourceArg)
    {
    case FLASH_enCLOCK_ACLK:
        u32SysFreqReq = CLOCK__u32GetFrequency(CLOCK_enSIGNAL_ACLK);
        break;
    case FLASH_enCLOCK_MCLK:
        u32SysFreqReq = CLOCK__u32GetFrequency(CLOCK_enSIGNAL_MCLK);
        break;
    case FLASH_enCLOCK_SMCLK:
        u32SysFreqReq = CLOCK__u32GetFrequency(CLOCK_enSIGNAL_SMCLK);
        break;
    default:
        break;
    }

    while(FLASH_enBUSY_BUSY == FLASH__enGetBusyState());

    if(u32SysFreqReq >= pu32FreqRanges[0U])
    {
        do
        {
            u8CountReg++;
            FLASH_u32FreqReg = u32SysFreqReq;
            FLASH_u32FreqReg /= u8CountReg;
        }while((pu32FreqRanges[1U] < FLASH_u32FreqReg) && (u8CountReg < FLASH_CTL2_FN_MASK + 1U));

        if(u8CountReg <= FLASH_CTL2_FN_MASK + 1U)
        {
            u8CountReg--;
            FLASH__vSetClockDivider(u8CountReg);
        }
        else
        {
            FLASH_u32FreqReg = 0U;
        }
    }

    return (FLASH_u32FreqReg);
}



uint32_t FLASH__u32Frequency(void)
{
    return (FLASH_u32FreqReg);
}
uint32_t FLASH__u32Frequency_RAM(void)
{
    return (FLASH_u32FreqReg);
}




