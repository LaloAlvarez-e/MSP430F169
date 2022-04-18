/**
 *
 * @file Conversion_NumberLong2String.c
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
#include <xUtils/Conversion/Conversion_Number2String/xHeader/Conversion_NumberLong2String.h>
#include <xUtils/Conversion/Conversion_Number2String/xHeader/Conversion_NumberLongLong2String.h>
#include <xUtils/Conversion/Conversion_Number2String/xHeader/Conversion_NumberFormat.h>


CONV_nSTATUS Conv__enNumber2String_Long(CONV_OUT_t pvfOut, char* pcBufferOut, uint32_t u32Value, uint32_t u32Index, uint32_t u32MaxLenght, uint32_t* pu32BufOutLenght, uint32_t u32Width, uint32_t u32flags, uint32_t u32Negative, uint32_t u32Base, uint32_t u32Prec)
{
    return Conv__enNumber2String_LongLong(pvfOut, pcBufferOut, (uint64_t) u32Value, u32Index, u32MaxLenght, pu32BufOutLenght, u32Width, u32flags, u32Negative, (uint64_t) u32Base, u32Prec);
}

