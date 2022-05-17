/**
 *
 * @file Conversion_NumberLongLong2String.c
 * @copyright
 * @verbatim InDeviceMex 2020 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 7 dic. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 7 dic. 2020     vyldram    1.0         initial Version@endverbatim
 */

#include <xUtils/Standard/Standard.h>
#include <xUtils/Conversion/Conversion_Number2String/xHeader/Conversion_NumberLongLong2String.h>
#include <xUtils/Conversion/Conversion_Number2String/xHeader/Conversion_NumberFormat.h>

CONV_nSTATUS Conv__enNumber2String_LongLong(CONV_OUT_t pvfOut, char* pcBufferOut, uint64_t u64Value, uint32_t u32Index, uint32_t u32MaxLenght, uint32_t* pu32BufOutLenght, uint32_t u32Width, uint32_t u32flags, uint32_t u32Negative, uint64_t u64Base, uint32_t u32Prec)
{
    uint8_t pu8Buffer[CONV_enBUFFER_SIZE_NUMBER];
    char cDigit = 0;
    uint8_t u8DigitTemp = 0;
    uint32_t  u32Length = 0U;
    CONV_nSTATUS enConvStatus = CONV_enSTATUS_ERROR;
    if(((uint32_t) 0U != (uint32_t) pvfOut) && ((uint32_t) 0U != (uint32_t) pcBufferOut) )
    {
        /* no hash for 0 values*/
        if ((uint64_t) 0U == u64Value) {
            u32flags &= ~(uint32_t) CONV_enFLAGS_HASH;
        }

        /* write if precision != 0 and value is != 0*/
        if ((0U == (u32flags & (uint32_t) CONV_enFLAGS_PRECISION)) || ((uint64_t) 0U != u64Value))
        {
            do
            {
                cDigit = (char) (u64Value % u64Base);
                if((uint8_t) cDigit < (uint8_t) 10)
                {
                    u8DigitTemp = (uint8_t) '0';
                }
                else
                {
                    if(u32flags & (uint32_t) CONV_enFLAGS_UPPERCASE )
                    {
                        u8DigitTemp = (uint8_t) 'A';
                    }
                    else
                    {
                        u8DigitTemp = (uint8_t) 'a' ;
                    }
                    u8DigitTemp -= (uint8_t) 10;
                }

                pu8Buffer[u32Length] = u8DigitTemp + (uint8_t) cDigit ;
                u32Length++;
                u64Value /= u64Base;
            } while (((uint64_t) 0U != u64Value) && (u32Length < (uint32_t) CONV_enBUFFER_SIZE_NUMBER));
        }

        enConvStatus = Conv__enNumber2String_Format(pvfOut, pcBufferOut, (char*)pu8Buffer, u32Index, u32MaxLenght, u32Length, pu32BufOutLenght, u32Width, u32flags, u32Negative, (uint32_t) u64Base, u32Prec);
    }
    return (enConvStatus);
  }

