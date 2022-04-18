/**
 *
 * @file Conversion_Hexa2String.c
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
#include <xUtils/Conversion/Conversion_Number2String/xHeader/Conversion_Hexa2String.h>
#include <xUtils/Conversion/Conversion_Number2String/Conversion_Primitives/Conversion_Primitives.h>

#define HEX2STRINGMAX    (19U)

const char CONV_pc8Hexa[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
uint8_t Conv__u8Hex2String(uint64_t u64Number, char* pcConv)
{
    CONV_nSTATUS enStatus = CONV_enSTATUS_ERROR;
    char  pcConvTemp[HEX2STRINGMAX] = {0UL};/*longitud maxima de long 16 digitos*/
    char  *pcPointerActual= &pcConvTemp[HEX2STRINGMAX - 1U];
    uint8_t u8Length = 0U;

    enStatus = Conv__enConversion(pcPointerActual, u64Number, &u8Length, 16U, CONV_pc8Hexa);
    if(CONV_enSTATUS_OK == enStatus)
    {
        u8Length++;
        pcPointerActual -= u8Length;
        *pcPointerActual = 'x';
        u8Length++;
        pcPointerActual -= 1U;
        *pcPointerActual = '0';
        enStatus = Conv__enInversion(pcPointerActual, pcConv, u8Length);
        if(CONV_enSTATUS_ERROR == enStatus)
        {
            u8Length = 0U;
        }
    }
    return (u8Length);
}



const char CONV_pc8HEXA[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
uint8_t Conv__u8HEX2String(uint64_t u64Number, char* pcConv)
{
    CONV_nSTATUS enStatus = CONV_enSTATUS_ERROR;
    char  pcConvTemp[HEX2STRINGMAX] = {0UL};/*longitud maxima de long 16 digitos*/
    char  *pcPointerActual= &pcConvTemp[HEX2STRINGMAX - 1U];
    uint8_t u8Length = 0U;

    enStatus = Conv__enConversion(pcPointerActual, u64Number, &u8Length, 16U, CONV_pc8HEXA);
    if(CONV_enSTATUS_OK == enStatus)
    {
        u8Length++;
        pcPointerActual -= u8Length;
        *pcPointerActual = 'X';
        u8Length++;
        pcPointerActual -= 1U;
        *pcPointerActual = '0';
        enStatus = Conv__enInversion(pcPointerActual, pcConv, u8Length);
        if(CONV_enSTATUS_ERROR == enStatus)
        {
            u8Length = 0U;
        }
    }
    return (u8Length);
}

