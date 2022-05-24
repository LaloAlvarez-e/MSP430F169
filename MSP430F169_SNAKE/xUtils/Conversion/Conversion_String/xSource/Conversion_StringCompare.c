/**
 *
 * @file Conversion_StringCompare.c
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
 * @verbatim 5 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 5 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/Standard/Standard.h>
#include <xUtils/Conversion/Conversion_String/xHeader/Conversion_StringCompare.h>

int32_t CONV_s32StringCompare(const char*  pcString1, const char* pcString2, uint32_t u32MaxSize)
{
    int32_t s32Result = 0;
    if(((uint32_t) 0U != (uint32_t) pcString2) && ((uint32_t) 0U != (uint32_t) pcString1))
    {
        while(((char)0 != (char) *pcString1) && ((char)0 != (char) *pcString2) && ((uint32_t) 0 != (uint32_t) u32MaxSize))
        {
            if ( (uint8_t) *pcString1 > (uint8_t) *pcString2)
            {
                s32Result = 1;
                break;
            }
            else if ( (uint8_t) *pcString1 < (uint8_t) *pcString2)
            {
                s32Result = -1;
                break;
            }
            else {}

            pcString2 += 1U;
            pcString1 += 1U;
            u32MaxSize--;
        }
        if((0 == s32Result) && ((uint32_t) 0 != (uint32_t) u32MaxSize))
        {
            if((char)0 != (char)*pcString2 )
            {
                s32Result = -1;
            }
            else if((char)0 != (char)*pcString1 )
            {
                s32Result = 1;
            }
            else{}
        }
    }

    return (s32Result);
}



