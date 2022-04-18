/**
 *
 * @file Conversion_Conversion.c
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

#include <xUtils/Conversion/Conversion_Number2String/Conversion_Primitives/xHeader/Conversion_Conversion.h>

CONV_nSTATUS Conv__enConversion(char* pcPointer, uint64_t u64Number, uint8_t* u8Length, uint8_t u8Base, const char* pcLookUpTable)
{
    CONV_nSTATUS enStatus = CONV_enSTATUS_ERROR;
    uint8_t  u8Num = 0U;
    uint64_t u64NumberReg = 0U;
    const char* pcLookUpTableReg = 0U;
    if(((uint32_t) 0 != (uint32_t) pcPointer) && ((uint32_t) 0 != (uint32_t) pcLookUpTable) && ((uint32_t) 0 != (uint32_t) u8Length))
    {
        enStatus = CONV_enSTATUS_OK;
        *u8Length = 0U;
        *pcPointer = (char)0;/*guarda el fin de cadena en la ultima posicion*/

        do{
            (*u8Length)++;
            pcPointer -= 1U;/*se decrementa la posicion donse guardara el valor*/
            u64NumberReg = u64Number;
            u64NumberReg %= u8Base;
            u8Num = (uint8_t) (u64NumberReg);/*obtiene el digito de menor peso*/
            pcLookUpTableReg = pcLookUpTable;
            pcLookUpTableReg += u8Num;
            (*pcPointer) = (char) *pcLookUpTableReg;/*convierte el valor en caracter*/
            u64Number /= u8Base;
        }  while((u64Number > 0U));/*mientras exista un digito sigue el ciclo*/
    }
    return (enStatus);
}


