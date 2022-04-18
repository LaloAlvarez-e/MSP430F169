/**
 *
 * @file Conversion_IsNewLineReturn.c
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
 * @verbatim 18 jul. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 18 jul. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/Conversion/xHeader/Conversion_Enum.h>
#include <xUtils/Conversion/Conversion_Number/xHeader/Conversion_IsNewLineReturn.h>

CONV_nNEWLINERETURN Conv__enIsNewLineReturn(char cCharacter)
{
    CONV_nNEWLINERETURN enStatus = CONV_enNEWLINERETURN_NO;
    if((cCharacter == '\n') || (cCharacter == '\r') )
    {
        enStatus = CONV_enNEWLINERETURN_OK;
    }
    return (enStatus);
}


