/**
 *
 * @file Conversion_String2Integer.c
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
#include <xUtils/Conversion/Conversion_Number/Conversion_Number.h>
#include <xUtils/Conversion/Conversion_String2Number/xHeader/Conversion_String2Integer.h>



int32_t Conv__s32String2Integer(const char* pcString, int64_t* s64NumSigned )
{
    int32_t s32Length = CONV_enNAN;
    int64_t s64NumSignedReg = 0;

    CONV_nSTATUS enStatus = CONV_enSTATUS_ERROR;
    CONV_nNEGATIVE_SIGN enNegativeSign = CONV_enNEGATIVE_SIGN_NO;
    CONV_nPOSITIVE_SIGN enPositiveSign = CONV_enPOSITIVE_SIGN_NO;
    CONV_nDIGIT enDigit = CONV_enDIGIT_NO;
    CONV_nBACKSPACE enBackSpace = CONV_enBACKSPACE_NO;
    CONV_nSIGNED enSign = CONV_enSIGNED_POSITIVE;

    char cStringBack[30] = {0UL};
    char* pcStringBack = cStringBack;
    uint8_t  u8ValueAux = 0;

    if((uint32_t) 0UL == (uint32_t) pcString)
    {
        s32Length = 0;
        /* The following situation is only valid when CONV_enSTATUS_OK is 0 and CONV_enSTATUS_ERROR is 1*/
        enStatus = (CONV_nSTATUS)Conv__enIsNewLineReturn(*pcString);
        enStatus &= (CONV_nSTATUS)Conv__enIsScape(*pcString);
        enStatus &= (CONV_nSTATUS)Conv__enIsNull(*pcString);
        while(enStatus)
        {

            enDigit = Conv__enIsDigit(*pcString);
            enBackSpace = Conv__enIsBackSpace(*pcString);
            enNegativeSign = Conv__enIsNegativeSign(*pcString);
            enPositiveSign = Conv__enIsPositiveSign(*pcString);

            if((CONV_enNEGATIVE_SIGN_OK == enNegativeSign) && (0 == s32Length))
            {
                enSign = CONV_enSIGNED_NEGATIVE;
                s32Length++;
                *pcStringBack = *pcString;
                pcStringBack += 1U;
            }
            else if((CONV_enPOSITIVE_SIGN_OK == enPositiveSign) && (0 == s32Length))
            {
                enSign = CONV_enSIGNED_POSITIVE;
                s32Length++;
                *pcStringBack = *pcString;
                pcStringBack += 1U;
            }
            else if(CONV_enDIGIT_OK == enDigit)
            {
                s64NumSignedReg *= 10;
                u8ValueAux = (uint8_t) *pcString;
                u8ValueAux -= (uint8_t) '0';
                s64NumSignedReg += (int64_t) u8ValueAux;
                s32Length++;
                *pcStringBack = *pcString;
                pcStringBack += 1U;
            }
            else if((CONV_enBACKSPACE_OK == enBackSpace) && (0 != s32Length))
            {
                pcStringBack -= 1U;
                enDigit = Conv__enIsDigit(*pcStringBack);
                enNegativeSign = Conv__enIsNegativeSign(*pcStringBack);
                if(CONV_enDIGIT_OK == enDigit)
                {
                    s64NumSignedReg /= 10;
                }
                else if(CONV_enNEGATIVE_SIGN_OK == enNegativeSign)
                {
                    enSign = CONV_enSIGNED_POSITIVE;
                }
                else {}
                s32Length--;
            }
            else if (CONV_enBACKSPACE_OK == enBackSpace)
            {
                s32Length = (int32_t) CONV_enNAN;
                break;
            }
            else{}

            pcString += 1U;

            enStatus = (CONV_nSTATUS)Conv__enIsNewLineReturn(*pcString);
            enStatus &= (CONV_nSTATUS)Conv__enIsScape(*pcString);
            enStatus &= (CONV_nSTATUS)Conv__enIsNull(*pcString);
        }

        if((int32_t) CONV_enNAN != s32Length)
        {
            if(CONV_enSIGNED_NEGATIVE == enSign)
            {
                s64NumSignedReg*=-1;
                s32Length++;
            }
            *s64NumSigned = s64NumSignedReg;
        }
    }
    return (s32Length);
}

