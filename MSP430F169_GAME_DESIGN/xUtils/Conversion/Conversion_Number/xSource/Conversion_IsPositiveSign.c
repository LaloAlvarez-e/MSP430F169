/**
 *
 * @file Conversion_IsPositiveSign.c
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
 * @verbatim 6 dic. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 dic. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/Standard/Standard.h>
#include <xUtils/Conversion/xHeader/Conversion_Enum.h>
#include <xUtils/Conversion/Conversion_Number/xHeader/Conversion_IsPositiveSign.h>

CONV_nPOSITIVE_SIGN Conv__enIsPositiveSign(char cCharacter)
{
    CONV_nPOSITIVE_SIGN enStatus = CONV_enPOSITIVE_SIGN_NO;
    char cChar = (char)cCharacter;
    if((char)'+' == (char)cChar)
    {
        enStatus = CONV_enPOSITIVE_SIGN_OK;
    }

    return (enStatus);
}


