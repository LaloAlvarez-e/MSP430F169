/**
 *
 * @file MCU_ArrayCompare.c
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
 * @verbatim 11 mar. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 11 mar. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include "DriverLib/MCU/Header/MCU_ArrayCompare.h"


uint16_t MCU__u16GetNearArrayIndex_32Bits(const uint32_t* pu32ArrayValues,
                                uint32_t u32ValueCompare,
                                uint16_t u16Length)
{
    uint16_t u16Counter;
    uint16_t u16CurrentIndex;
    uint32_t u32ValueTemp;
    uint32_t u32DiferentialMin;
    uint32_t u32DiferentialMax;
    MCU_nSTATUS enStatus;
    u16Counter = 0U;
    u16CurrentIndex = 0UL;
    enStatus = MCU_enSTATUS_ERROR;
    if(0UL != (uintptr_t) pu32ArrayValues)
    {
        while((u16Length != u16Counter) && (MCU_enSTATUS_ERROR == enStatus))
        {
            u32ValueTemp = *pu32ArrayValues;
            if(u32ValueCompare <=  u32ValueTemp)
            {
                u16CurrentIndex = u16Counter;
                if(0U != u16Counter)
                {
                    u32DiferentialMax = u32ValueTemp;
                    u32DiferentialMax -= u32ValueCompare;
                    u32DiferentialMin = u32ValueCompare;
                    u32DiferentialMin -= *(pu32ArrayValues - 1U);
                    if(u32DiferentialMax > u32DiferentialMin)
                    {
                        u16CurrentIndex -= 1UL;
                    }
                }
                enStatus = MCU_enSTATUS_OK;
            }
            pu32ArrayValues++;
            u16Counter++;
        }
    }

    return (u16CurrentIndex);
}

uint16_t MCU__u16GetNearArrayIndex_16Bits(const uint16_t* pu16ArrayValues,
                                uint16_t u16ValueCompare,
                                uint16_t u16Length)
{
    uint16_t u16Counter;
    uint16_t u16CurrentIndex;
    uint16_t u16ValueTemp;
    uint16_t u16DiferentialMin;
    uint16_t u16DiferentialMax;
    MCU_nSTATUS enStatus;
    u16Counter = 0U;
    u16CurrentIndex = 0UL;
    enStatus = MCU_enSTATUS_ERROR;

    if(0UL != (uintptr_t) pu16ArrayValues)
    {
        while((u16Length != u16Counter) && (MCU_enSTATUS_ERROR == enStatus))
        {
            u16ValueTemp = *pu16ArrayValues;
            if(u16ValueCompare <=  u16ValueTemp)
            {
                u16CurrentIndex = u16Counter;
                if(0U != u16Counter)
                {
                    u16DiferentialMax = u16ValueTemp;
                    u16DiferentialMax -= u16ValueCompare;
                    u16DiferentialMin = u16ValueCompare;
                    u16DiferentialMin -= *(pu16ArrayValues - 1U);
                    if(u16DiferentialMax > u16DiferentialMin)
                    {
                        u16CurrentIndex -= 1UL;
                    }
                }
                enStatus = MCU_enSTATUS_OK;
            }
            pu16ArrayValues++;
            u16Counter++;
        }
    }

    return (u16CurrentIndex);
}

uint16_t MCU__u16GetNearArrayIndex_8Bits(const uint8_t* pu8ArrayValues,
                                uint8_t u8ValueCompare,
                                uint16_t u16Length)
{
    uint16_t u16Counter;
    uint16_t u16CurrentIndex;
    uint8_t u8ValueTemp;
    uint8_t u8DiferentialMin;
    uint8_t u8DiferentialMax;
    MCU_nSTATUS enStatus;
    u16Counter = 0U;
    u16CurrentIndex = 0UL;
    enStatus = MCU_enSTATUS_ERROR;

    if(0UL != (uintptr_t) pu8ArrayValues)
    {
        while((u16Length != u16Counter) && (MCU_enSTATUS_ERROR == enStatus))
        {
            u8ValueTemp = *pu8ArrayValues;
            if(u8ValueCompare <=  u8ValueTemp)
            {
                u16CurrentIndex = u16Counter;
                if(0U != u16Counter)
                {
                    u8DiferentialMax = u8ValueTemp;
                    u8DiferentialMax -= u8ValueCompare;
                    u8DiferentialMin = u8ValueCompare;
                    u8DiferentialMin -= *(pu8ArrayValues - 1U);
                    if(u8DiferentialMax > u8DiferentialMin)
                    {
                        u16CurrentIndex -= 1UL;
                    }
                }
                enStatus = MCU_enSTATUS_OK;
            }
            pu8ArrayValues++;
            u16Counter++;
        }
    }

    return (u16CurrentIndex);
}

uint16_t MCU__u16GetNearArrayIndex(const void* pvArrayValues,
                                uint8_t u8ValueCompare,
                                uint16_t u16Length,
                                uint8_t u8ByteLength)
{
    uint16_t u16CurrentIndex;
    const uint8_t* pu8ArrayValues;
    const uint16_t* pu16ArrayValues;
    const uint32_t* pu32ArrayValues;
    u16CurrentIndex = 0UL;
    if(0UL != (uintptr_t) pvArrayValues)
    {
        switch(u8ByteLength)
        {
        case 0U:
            pu8ArrayValues = (uint8_t*) pvArrayValues;
            u16CurrentIndex = MCU__u16GetNearArrayIndex_8Bits(pu8ArrayValues, u8ValueCompare, u16Length);
            break;
        case 1U:
            pu16ArrayValues = (uint16_t*) pvArrayValues;
            u16CurrentIndex = MCU__u16GetNearArrayIndex_16Bits(pu16ArrayValues, u8ValueCompare, u16Length);
            break;
        case 2U:
            pu32ArrayValues = (uint32_t*) pvArrayValues;
            u16CurrentIndex = MCU__u16GetNearArrayIndex_32Bits(pu32ArrayValues, u8ValueCompare, u16Length);
            break;
        default :
            break;
        }
    }
    return (u16CurrentIndex);
}
