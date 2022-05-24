/**
 *
 * @file Conversion_UInteger2String.c
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
#include <xUtils/Standard/Standard.h>
#include <xUtils/Conversion/xHeader/Conversion_Enum.h>
#include <xUtils/Conversion/Conversion_Number2String/Conversion_Primitives/Conversion_Primitives.h>
#include <xUtils/Conversion/Conversion_Number2String/xHeader/Conversion_UInteger2String.h>

#define INT2STRINGMAX    (21U)

const char CONV_pc8Decimal[10] = {'0','1','2','3','4','5','6','7','8','9'};

uint8_t Conv__u8UInt2String(uint64_t u64Number, char* pcConv)
{
    char       pcConvTemp[INT2STRINGMAX] = {0UL};/*longitud maxima de long 12 digitos con signo*/
    uint8_t u8Length = 0U;
    CONV_nSTATUS enStatus = CONV_enSTATUS_ERROR;
    char *pcPointerActual = &pcConvTemp[INT2STRINGMAX - 1U];/*empezamos llenando desde la ultima posicion*/

    enStatus = Conv__enConversion(pcPointerActual, u64Number, &u8Length, 10U, CONV_pc8Decimal);
    if(CONV_enSTATUS_OK == enStatus)
    {
        pcPointerActual -= u8Length;
        enStatus = Conv__enInversion(pcPointerActual, pcConv, u8Length);
        if(CONV_enSTATUS_ERROR == enStatus)
        {
            u8Length = 0U;
        }
    }
    return (u8Length);
}




