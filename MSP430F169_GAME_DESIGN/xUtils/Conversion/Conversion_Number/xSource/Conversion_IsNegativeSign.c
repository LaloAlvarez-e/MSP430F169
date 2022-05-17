/**
 *
 * @file Conversion_IsNegativeSign.c
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
 * @verbatim 5 dic. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 5 dic. 2020     vyldram    1.0         initial Version@endverbatim
 */
 #include <xUtils/Standard/Standard.h>
#include <xUtils/Conversion/xHeader/Conversion_Enum.h>
#include <xUtils/Conversion/Conversion_Number/xHeader/Conversion_IsNegativeSign.h>

CONV_nNEGATIVE_SIGN Conv__enIsNegativeSign(char cCharacter)
{
    CONV_nNEGATIVE_SIGN enStatus = CONV_enNEGATIVE_SIGN_NO;
    char cChar = (char)cCharacter;
    if((char)'-' == cChar)
    {
        enStatus = CONV_enNEGATIVE_SIGN_OK;
    }

    return (enStatus);
}


