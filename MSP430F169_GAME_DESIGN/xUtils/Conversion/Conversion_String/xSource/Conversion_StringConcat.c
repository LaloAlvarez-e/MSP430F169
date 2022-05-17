/**
 *
 * @file Conversion_StringConcat.c
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
#include <xUtils/Conversion/Conversion_String/xHeader/Conversion_StringConcat.h>

char* CONV_pcStringConcat(char*  pcStringInitial, const char* pcStringConcat, uint32_t u32MaxSize)
{
    char* pcStringReg = pcStringInitial;
    if(((uint32_t) 0U != (uint32_t) pcStringConcat) && ((uint32_t) 0U != (uint32_t) pcStringInitial))
    {
        while(((char)0 != (char) *pcStringReg) && ((uint32_t) 0 != (uint32_t) u32MaxSize))
        {
            pcStringReg += 1U;
            u32MaxSize--;
        }
        while(((char)0 != (char) *pcStringConcat) && ((uint32_t) 0 != (uint32_t) u32MaxSize))
        {
            *pcStringReg = *pcStringConcat;
            pcStringConcat += 1U;
            pcStringReg += 1U;
            u32MaxSize--;
        }
        if((uint32_t) 0 != (uint32_t) u32MaxSize)
        {
            *pcStringReg = '\0';
        }
    }
    return (pcStringInitial);
}
