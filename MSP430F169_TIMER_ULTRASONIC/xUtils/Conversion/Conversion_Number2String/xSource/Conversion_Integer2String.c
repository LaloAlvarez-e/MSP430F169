/**
 *
 * @file Conversion_Integer2String.c
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
#include <xUtils/Conversion/Conversion_Number2String/xHeader/Conversion_Integer2String.h>

#define INT2STRINGMAX    (21U)

static const char Conversion_pc8Decimal[10] = {
 '0','1','2','3','4','5','6','7','8','9'
};

static char CONV_pcConvTemp[30] = {0UL}; /*longitud maxima de long 12 digitos con signo*/

/*ToDo review Conv__u8DInt2String*/
uint8_t Conv__u8DInt2String(int64_t s64Number, uint8_t u8Positive, uint8_t u8Padding0, uint8_t u8Deci, char* pcConv)
{
    char *pcPointerActual = 0U;
    char *pcPointerActualAux = 0U;
    char* pcConvAux = 0U;
    int8_t s8CharAux = 0U;
    uint8_t u8DeciActual = 0U;
    int8_t s8Num = 0;
    int8_t s8I = 0;
    uint8_t u8FlagSign = 1;
    uint8_t u8Comp1 = 0;
    uint8_t u8Comp2 = 0;
    int32_t s32Result = 0;
    int64_t  s64NumberReg = s64Number;/*paso el Numero a un registro para aumentar rendimiento*/
    uint32_t u32ResultAux = 0;

    pcPointerActual = &CONV_pcConvTemp[21 - 1];/*empezamos llenando desde la ultima posicion*/
    *pcPointerActual = (char) 0;/*guarda el fin de cadena en la ultima posicion*/

    if (u8Deci>(uint8_t) 19)
    {
        u8Deci = (uint8_t) 19;
    }
    do {
        pcPointerActual -= 1U;/*se decrementa la posicion donse guardara el valor*/
        s8Num = (int8_t) (s64NumberReg % 10);/*obtiene el digito de menor peso*/
        if(s8Num<0)
        {
            s8Num*=-1;
        }

        if(0 != s64NumberReg)
        {
            u8Comp1 = 1U;
        }
        else
        {
            u8Comp1 = 0U;
        }
        if(0UL == u8DeciActual)
        {
            u8Comp2 = 1U;
        }
        else
        {
            u8Comp2 = 0U;
        }
        u8Comp1 |= u8Comp2;
        if ((uint8_t) 1 == u8Comp1)
        {
            s8CharAux = s8Num;
            s8CharAux += (int8_t) '0';
            *pcPointerActual = (char)s8CharAux;
            u8DeciActual++;
        }
        else
        {
            if(u8Padding0)
            {
                *pcPointerActual = '0';/*pcConvierte el valor en caracter*/
                u8DeciActual++;
            }
            else if (u8FlagSign)
            {
                if (s64Number < 0)
                {
                    *pcPointerActual = '-';/*si el s32Numero es negativo guarda el signo negativo*/
                }
                else if (u8Positive)
                {
                    *pcPointerActual = '+';/*si el s32Numero es negativo guarda el signo negativo*/
                }
                else{}
                u8FlagSign = (uint8_t) 0;
            }
            else
            {
                *pcPointerActual= ' ';
                u8DeciActual++;
            }

        }
        s64NumberReg /= 10;
    }  while((0 != s64NumberReg) || (u8DeciActual<u8Deci));/*mientras exista un digito sigue el ciclo*/

    if(u8FlagSign)
    {
        if (s64Number < 0)
        {
            pcPointerActual -= 1U;
            *pcPointerActual = '-';/*si el s32Numero es negativo guarda el signo negativo*/
        }
        else if (u8Positive)
        {
            pcPointerActual -= 1U;
            *pcPointerActual = '+';/*si el s32Numero es negativo guarda el signo negativo*/
        }
        else{}
    }
    s64NumberReg = (int64_t) &CONV_pcConvTemp[21 - 1];
    s64NumberReg += 1;
    u32ResultAux = ((uint32_t) pcPointerActual);
    s64NumberReg -= (int64_t) u32ResultAux;/*realiza la resta de cuantos caracteres se utilizaron*/

    pcConvAux = pcConv;
    pcConvAux += (uint8_t) s64NumberReg;
    pcPointerActualAux = pcPointerActual;
    pcPointerActualAux += (uint8_t) s64NumberReg;
    for (s8I = (int8_t) (s64NumberReg-1); s8I >= (int8_t) 0; s8I--) /*hace un ciclo burbuja optimizado*/
    {
          pcConvAux -= 1U;
          pcPointerActualAux -= 1U;
         *pcConvAux= *pcPointerActualAux;
    }
    s32Result = (int32_t) s64NumberReg;
    s32Result -= 1;
    return (uint8_t) (s32Result);
}


uint8_t Conv__u8Int2String(int64_t s64Number, char* pcConv)
{
    char    *pcPointerActual = &CONV_pcConvTemp[INT2STRINGMAX-1U];/*empezamos llenando desde la ultima posicion;*/
    char    *pcPointerActualAux = 0U;
    char*  pcConvAux = 0U;
    uint8_t u8Num = 0;
    int8_t  s8I = 0;
    int64_t s64NumberReg = s64Number;/*paso el s32Numero a un registro para aumentar rendimiento*/
    int64_t s64NumberRegAlt = 0;
    int8_t  s8FlagSign = 0;
    uint32_t u32ResultAux = 0;

    *pcPointerActual = (char)0;/*guarda el fin de cadena en la ultima posicion*/
    if(s64NumberReg < 0)
    {
        s64NumberReg*=-1;
        s8FlagSign = 1;
    }

    do {
        pcPointerActual -= 1U;/*se decrementa la posicion donse guardara el valor*/
        s64NumberRegAlt = s64NumberReg;
        s64NumberRegAlt %= (int64_t) 10;
        u8Num = (uint8_t) s64NumberRegAlt;/*obtiene el digito de menor peso*/
        *pcPointerActual = (char) Conversion_pc8Decimal[u8Num];/*pcConvierte el valor en caracter*/
        s64NumberReg /= 10;
        pcPointerActualAux = CONV_pcConvTemp;
        pcPointerActualAux += s8FlagSign;
    }   while((s64NumberReg != 0) && (pcPointerActual>(pcPointerActualAux)));/*mientras exista un digito sigue el ciclo*/

    if (s8FlagSign == 1)
    {
        pcPointerActual -= 1U;
        *pcPointerActual = '-';/*si el s32Numero es negativo guarda el signo negativo*/
    }
    s64NumberReg = (int64_t) CONV_pcConvTemp;
    s64NumberReg += (int64_t) INT2STRINGMAX;
    s64NumberReg -= 1;
    u32ResultAux = ((uint32_t) pcPointerActual);
    s64NumberReg -= (int64_t) u32ResultAux;/*realiza la resta de cuantos caracteres se utilizaron*/

    pcConvAux = pcConv;
    pcConvAux += s64NumberReg;
    pcPointerActualAux = pcPointerActual;
    pcPointerActualAux += s64NumberReg;
    for (s8I = (int8_t) s64NumberReg; s8I >= (int8_t) 0; s8I--) /*hace un ciclo burbuja optimizado*/
    {
        *pcConvAux= *pcPointerActualAux;
        pcConvAux -= 1U;
        pcPointerActualAux -= 1U;
    }

    return ( (uint8_t) s64NumberReg);
}



uint8_t Conv__u8Int2StringZeros(int64_t s64Number, int8_t s8CerosLeft, char* pcConv)
{
    char    *pcPointerActual = &CONV_pcConvTemp[INT2STRINGMAX - 1U];/*empezamos llenando desde la ultima posicion*/
    char *pcPointerActualAux = 0U;
    char* pcConvAux = 0U;
    uint8_t u8Num = 0;
    int8_t  s8I = 0;
    int64_t s64NumberReg = s64Number;/*paso el s32Numero a un registro para aumentar rendimiento*/
    int64_t s64NumberRegAlt = 0;
    int8_t  s8FlagSign = 0;
    uint32_t u32ResultAux = 0;

    if(s8CerosLeft>(int8_t) (INT2STRINGMAX-2U))
    {
        s8CerosLeft = (int8_t) (INT2STRINGMAX-2U);
    }

    *pcPointerActual = (char)0;/*guarda el fin de cadena en la ultima posicion*/
    if(s64NumberReg < 0)
    {
        s64NumberReg*=-1;
        s8FlagSign = 1;
    }

    pcPointerActualAux = CONV_pcConvTemp;
    pcPointerActualAux += s8FlagSign;

    do {
        pcPointerActual -= 1U;/*se decrementa la posicion donse guardara el valor*/

        s64NumberRegAlt = s64NumberReg;
        s64NumberRegAlt %= (int64_t) 10;
        u8Num = (uint8_t) s64NumberRegAlt;/*obtiene el digito de menor peso*/
        *pcPointerActual = (char) Conversion_pc8Decimal[u8Num];/*pcConvierte el valor en caracter*/
        s8CerosLeft--;
        s64NumberReg /= 10;

    }  while((s64NumberReg != 0) && (pcPointerActual>(pcPointerActualAux)));/*mientras exista un digito sigue el ciclo*/

    while((pcPointerActual>(pcPointerActualAux)) && (s8CerosLeft>0))
    {
        pcPointerActual -= 1U;
        *pcPointerActual = '0';
        s8CerosLeft--;
    }
    if (s8FlagSign == 1)
    {
        pcPointerActual -= 1U;
        *pcPointerActual = '-';/*si el s32Numero es negativo guarda el signo negativo*/
    }
    s64NumberReg = (int64_t) CONV_pcConvTemp;
    s64NumberReg += (int64_t) INT2STRINGMAX;
    s64NumberReg -= 1;
    u32ResultAux = ((uint32_t) pcPointerActual);
    s64NumberReg -= (int64_t) u32ResultAux;/*realiza la resta de cuantos caracteres se utilizaron*/

    pcConvAux = pcConv;
    pcConvAux += s64NumberReg;
    pcPointerActualAux = pcPointerActual;
    pcPointerActualAux += s64NumberReg;
    for (s8I = (int8_t) s64NumberReg; s8I >= (int8_t) 0; s8I--) /*hace un ciclo burbuja optimizado*/
    {
        *pcConvAux= *pcPointerActualAux;
        pcConvAux -= 1U;
        pcPointerActualAux -= 1U;
    }

    return ( (uint8_t) s64NumberReg);

}




