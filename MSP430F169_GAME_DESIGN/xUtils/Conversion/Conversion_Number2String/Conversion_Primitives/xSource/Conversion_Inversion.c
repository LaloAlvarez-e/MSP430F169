/**
 *
 * @file Conversion_Inversion.c
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
#include <xUtils/Conversion/Conversion_Number2String/Conversion_Primitives/xHeader/Conversion_Inversion.h>

CONV_nSTATUS Conv__enInversion(const char* const pcPointerIn, char* const pcPointerOut, uint8_t u8Length)
{
    CONV_nSTATUS enStatus = CONV_enSTATUS_ERROR;
    uint8_t u8I = 0;
    const char* pcPointerInAux = 0U;
    char* pcPointerOutAux = 0U;
    if(((uint32_t) 0 != (uint32_t) pcPointerIn) && ((uint32_t) 0 != (uint32_t) pcPointerOut))
    {
        enStatus = CONV_enSTATUS_OK;
        pcPointerOutAux = pcPointerOut;
        pcPointerInAux = pcPointerIn;
        for (u8I = 0U; u8I <= u8Length; u8I++) /*hace un ciclo burbuja optimizado*/
        {
            *pcPointerOutAux= *pcPointerInAux;
            pcPointerOutAux += 1U;
            pcPointerInAux += 1U;
        }
    }
    return (enStatus);
}

CONV_nSTATUS Conv__enOutInversion(CONV_OUT_t pvfOut, char* pvBufferOut, const char* pvBufferIn, uint32_t u32Index, uint32_t u32MaxLenght, uint32_t u32BufInLenght, uint32_t* pu32BufOutLenght, uint32_t u32Width, uint32_t u32flags)
{
    CONV_nSTATUS enStatus = CONV_enSTATUS_ERROR;
    uint32_t u32Pos = 0;
    const char* pcBufferTemp = 0;
    const uint32_t u32StartIndex = u32Index;


    if(((uint32_t) 0U != (uint32_t) pvBufferOut) && ((uint32_t) 0U != (uint32_t) pvBufferIn) && ((uint32_t) 0U != (uint32_t) pvfOut))
    {
        enStatus = CONV_enSTATUS_OK;
        if ((0U == (u32flags & (uint32_t) CONV_enFLAGS_LEFT)) && (0U == (u32flags & (uint32_t) CONV_enFLAGS_ZEROPAD)))
        {
            for (u32Pos = u32BufInLenght; u32Pos<u32Width; u32Pos++) /*hace un ciclo burbuja optimizado*/
            {
                pvfOut(' ',pvBufferOut, u32Index, u32MaxLenght);
                u32Index++;
            }
        }
        pcBufferTemp = pvBufferIn;
        pcBufferTemp += u32BufInLenght;
        while(0U != u32BufInLenght)
        {
            u32BufInLenght--;
            pcBufferTemp -= 1U;
            pvfOut(*pcBufferTemp, pvBufferOut, u32Index, u32MaxLenght);
            u32Index++;
        }

        if ( (uint32_t) CONV_enFLAGS_LEFT == (u32flags & (uint32_t) CONV_enFLAGS_LEFT))
        {
            while ((u32Index - u32StartIndex) < u32Width)
            {
                pvfOut(' ',pvBufferOut, u32Index, u32MaxLenght);
                u32Index++;
            }
        }

    }
    *pu32BufOutLenght = (uint32_t) u32Index;
    return (enStatus);
}


