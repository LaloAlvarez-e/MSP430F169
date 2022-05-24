/**
 *
 * @file Conversion_IsDigit.c
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
 * @verbatim 17 jul. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 17 jul. 2020     vyldram    1.0         initial Version@endverbatim
 */
 #include <xUtils/Standard/Standard.h>
#include <xUtils/Conversion/xHeader/Conversion_Enum.h>
#include <xUtils/Conversion/Conversion_Number/xHeader/Conversion_IsDigit.h>

CONV_nDIGIT Conv__enIsDigit(char cCharacter)
{
    CONV_nDIGIT enStatus = CONV_enDIGIT_NO;
    uint8_t u8Char = (uint8_t) cCharacter;
    if((u8Char >= (uint8_t) '0') && (u8Char <= (uint8_t) '9'))
    {
        enStatus = CONV_enDIGIT_OK;
    }

    return (enStatus);
}
