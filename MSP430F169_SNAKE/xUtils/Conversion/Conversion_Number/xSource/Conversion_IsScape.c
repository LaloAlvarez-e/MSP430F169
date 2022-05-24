/**
 *
 * @file Conversion_IsScape.c
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
#include <xUtils/Conversion/Conversion_Number/xHeader/Conversion_IsScape.h>

CONV_nSCAPE Conv__enIsScape(char cCharacter)
{
    CONV_nSCAPE enStatus = CONV_enSCAPE_NO;
    if(cCharacter == (char) 0x1BU)
    {
        enStatus = CONV_enSCAPE_OK;
    }
    return (enStatus);
}



