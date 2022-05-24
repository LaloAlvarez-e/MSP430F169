/**
 *
 * @file Conversion_String2UInteger.c
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
 * @verbatim 5 dic. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 5 dic. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/Conversion/Conversion_String2Number/xHeader/Conversion_String2UInteger.h>
#include <xUtils/Conversion/xHeader/Conversion_Enum.h>
#include <xUtils/Conversion/Conversion_Number/Conversion_Number.h>

#if defined (__TI_ARM__ ) || defined (__MSP430__ )
    #pragma CHECK_MISRA("-16.7")
#endif

int32_t Conv__s32String2UInteger(const char** pcString, uint64_t* pu64NumUnsigned )
{
    int32_t s32Length = CONV_enNAN;
    uint64_t u64NumUnsignedTemp = 0U;
    CONV_nDIGIT enDigit = CONV_enDIGIT_NO;
    uint8_t  u8ValueAux = 0;

    if(((uint32_t) 0U != (uint32_t) pcString) && ((uint32_t) 0U != (uint32_t) pu64NumUnsigned))
    {
        s32Length = 0;
        enDigit = Conv__enIsDigit(**pcString);
        while (CONV_enDIGIT_OK == enDigit)
        {
            u64NumUnsignedTemp *= 10U;
            u8ValueAux = (uint8_t) (**pcString);
            u8ValueAux -= (uint8_t) '0';
            u64NumUnsignedTemp += u8ValueAux;
            (*pcString) += 1U;
            s32Length++;
            enDigit = Conv__enIsDigit(**pcString);
        }
        *pu64NumUnsigned = u64NumUnsignedTemp;
    }
    return (s32Length);
}

#if defined (__TI_ARM__ ) || defined (__MSP430__ )
    #pragma RESET_MISRA("16.7")
#endif
