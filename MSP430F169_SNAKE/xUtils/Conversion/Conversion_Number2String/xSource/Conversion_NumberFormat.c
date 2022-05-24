/**
 *
 * @file Conversion_NumberFormat.c
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
 * @verbatim 7 dic. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 7 dic. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/Standard/Standard.h>
#include <xUtils/Conversion/Conversion_Number2String/xHeader/Conversion_NumberFormat.h>
#include <xUtils/Conversion/Conversion_Number2String/Conversion_Primitives/xHeader/Conversion_Inversion.h>


CONV_nSTATUS Conv__enNumber2String_Format(CONV_OUT_t pvfOut, char* pcBufferOut, char* pcBufferIn, uint32_t u32Index, uint32_t u32MaxLenght, uint32_t u32BufInLenght, uint32_t* pu32BufOutLenght, uint32_t u32Width, uint32_t u32flags, uint32_t u32Negative, uint32_t u32Base, uint32_t u32Prec)
{

    CONV_nSTATUS enStatus = CONV_enSTATUS_ERROR;
    char* pcBufferTemp = 0;
    char  cCharTemp = 0;
    uint32_t u32flagsTemp = 0U;

    if(((uint32_t) 0U != (uint32_t) pcBufferOut) && ((uint32_t) 0U != (uint32_t) pcBufferIn ) && ((uint32_t) 0U != (uint32_t) pu32BufOutLenght) )
    {
        /* pad leading zeros */
        if ((uint32_t) 0U == (u32flags & (uint32_t) CONV_enFLAGS_LEFT))
        {
            if((uint32_t) 0U != u32Width)
            {
                if((uint32_t) CONV_enFLAGS_ZEROPAD == (u32flags & (uint32_t) CONV_enFLAGS_ZEROPAD))
                {
                    u32flagsTemp = (uint32_t) CONV_enFLAGS_PLUS | (uint32_t) CONV_enFLAGS_SPACE;
                    u32flagsTemp &= u32flags;
                    if(((uint32_t) 0U != u32Negative) || ((uint32_t) 0U != u32flagsTemp))
                    {
                        u32Width--;
                    }
                    else{}
                }
                else{}
            }
            else{}


            while ((u32BufInLenght < u32Prec) && (u32BufInLenght < (uint32_t) CONV_enBUFFER_SIZE_NUMBER))
            {
                pcBufferTemp = pcBufferIn;
                pcBufferTemp += u32BufInLenght;
                *pcBufferTemp = '0';
                u32BufInLenght++;
            }
            while ((((uint32_t) CONV_enFLAGS_ZEROPAD == (u32flags & (uint32_t) CONV_enFLAGS_ZEROPAD)) && (u32BufInLenght < u32Width)) && (u32BufInLenght < (uint32_t) CONV_enBUFFER_SIZE_NUMBER))
            {
                pcBufferTemp = pcBufferIn;
                pcBufferTemp += u32BufInLenght;
                *pcBufferTemp = '0';
                u32BufInLenght++;
            }
        }
        else{}

        /* handle hash */
        if ((uint32_t) CONV_enFLAGS_HASH == (u32flags & (uint32_t) CONV_enFLAGS_HASH))
        {
            if ((uint32_t) 0U != u32BufInLenght)
            {
                if((uint32_t) 0U == (u32flags & (uint32_t) CONV_enFLAGS_PRECISION))
                {
                    if((u32BufInLenght == u32Prec) || (u32BufInLenght == u32Width))
                    {
                        u32BufInLenght--;
                        if (((uint32_t) 0U != u32BufInLenght) && ( (uint32_t) 16U == u32Base))
                        {
                            u32BufInLenght--;
                        }
                        else{}
                    }
                    else{}
                }
                else{}
            }
            else{}


            if ((uint32_t) CONV_enBUFFER_SIZE_NUMBER > u32BufInLenght )
            {
                if((uint32_t) 16U == u32Base)
                {
                    if((uint32_t) 0U == (u32flags & (uint32_t) CONV_enFLAGS_UPPERCASE))
                    {
                        cCharTemp = 'x';
                        pcBufferTemp = pcBufferIn;
                        pcBufferTemp += u32BufInLenght;
                        *pcBufferTemp = cCharTemp;
                        u32BufInLenght++;
                    }
                    /*( (uint32_t) CONV_enFLAGS_UPPERCASE == (u32flags & (uint32_t) CONV_enFLAGS_UPPERCASE))*/
                    else
                    {
                        cCharTemp = 'X';
                        pcBufferTemp = pcBufferIn;
                        pcBufferTemp += u32BufInLenght;
                        *pcBufferTemp = cCharTemp;
                        u32BufInLenght++;
                    }
                }
                else if((uint32_t) 2U == u32Base)
                {
                    cCharTemp = 'b';
                    pcBufferTemp = pcBufferIn;
                    pcBufferTemp += u32BufInLenght;
                    *pcBufferTemp = cCharTemp;
                    u32BufInLenght++;
                }
                else{}
            }
            else{}

            if ((uint32_t) CONV_enBUFFER_SIZE_NUMBER > u32BufInLenght )
            {
                cCharTemp = '0';
                pcBufferTemp = pcBufferIn;
                pcBufferTemp += u32BufInLenght;
                *pcBufferTemp = cCharTemp;
                u32BufInLenght++;
            }
            else{}
        }
        else{}

        if ((uint32_t) CONV_enBUFFER_SIZE_NUMBER > u32BufInLenght )
        {
            if ((uint32_t) 0U != u32Negative)
            {
                pcBufferTemp = pcBufferIn;
                pcBufferTemp += u32BufInLenght;
                *pcBufferTemp = '-';
                u32BufInLenght++;
            }
            else if ((uint32_t) CONV_enFLAGS_PLUS == (u32flags & (uint32_t) CONV_enFLAGS_PLUS))
            {
                pcBufferTemp = pcBufferIn;
                pcBufferTemp += u32BufInLenght;
                *pcBufferTemp = '+';  /* ignore the space if the '+' exists */
                u32BufInLenght++;
            }
            else if ((uint32_t) CONV_enFLAGS_SPACE == (u32flags & (uint32_t) CONV_enFLAGS_SPACE))
            {
                pcBufferTemp = pcBufferIn;
                pcBufferTemp += u32BufInLenght;
                *pcBufferTemp = ' ';
                u32BufInLenght++;
            }
            else{}
        }

        enStatus = Conv__enOutInversion(pvfOut, pcBufferOut, (const char*)pcBufferIn, u32Index, u32MaxLenght, u32BufInLenght, pu32BufOutLenght, u32Width, u32flags);
    }
  return (enStatus);
}


