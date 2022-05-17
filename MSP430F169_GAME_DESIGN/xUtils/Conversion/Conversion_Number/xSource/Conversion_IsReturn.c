/**
 *
 * @file Conversion_IsReturn.c
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
#include <xUtils/Conversion/Conversion_Number/xHeader/Conversion_IsReturn.h>

CONV_nRETURN Conv__enIsReturn(char cCharacter)
{
    CONV_nRETURN enStatus = CONV_enRETURN_NO;
    if(cCharacter == '\r')
    {
        enStatus = CONV_enRETURN_OK;
    }
    return (enStatus);
}

