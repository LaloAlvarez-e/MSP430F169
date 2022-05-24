/**
 *
 * @file Conversion_StringCopy.c
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
 * @verbatim 5 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 5 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/Standard/Standard.h>
#include <xUtils/Conversion/Conversion_String/xHeader/Conversion_StringCopy.h>

#if defined (__TI_ARM__ ) || defined (__MSP430__ )
    #pragma CHECK_MISRA("-6.3")
#endif

static void CONV_vCopyLoopCharIf(char* pcMemoryDest, const char* pcMemorySource, size_t szLength);
static void CONV_vCopyLoopIntIf(int* pwMemoryDest, const int* pwMemorySource, size_t szLength);
static void CONV_vCopyReverseLoopCharIf(char* pcMemoryDest, const char* pcMemorySource, size_t szLength);
static void CONV_vCopyReverseLoopIntIf(int* pwMemoryDest, const int* pwMemorySource, size_t szLength);

char* CONV_pcStringCopy(char* pcStringDest, const char* pcStringSource, uint32_t u32MaxSize)
{
    char* pcStringReg = pcStringDest;
    if(((uint32_t) 0U != (uint32_t) pcStringSource) && ((uint32_t) 0U != (uint32_t) pcStringDest))
    {
        while(((char)0 != (char) *pcStringSource) && ((uint32_t) 0 != (uint32_t) u32MaxSize))
        {
            *pcStringReg = *pcStringSource;
            pcStringSource += 1U;
            pcStringReg += 1U;
            u32MaxSize--;
        }
        if((uint32_t) 0 != (uint32_t) u32MaxSize)
        {
            *pcStringReg = '\0';
        }
    }
    return (pcStringDest);
}

#define CONV_WORDSIZE   ((size_t) sizeof(int))
#define CONV_WORDMASK   (CONV_WORDSIZE - 1UL)

static void CONV_vCopyLoopCharIf(char* pcMemoryDest, const char* pcMemorySource, size_t szLength)
{
    if(0UL != szLength)
    {
        do
        {
            *pcMemoryDest = *pcMemorySource;
            pcMemorySource += 1UL;
            pcMemoryDest += 1UL;
            szLength--;
        }while(0UL != szLength);
    }

}

static void CONV_vCopyLoopIntIf(int* pwMemoryDest, const int* pwMemorySource, size_t szLength)
{
    if(0UL != szLength)
    {
        do
        {
            *pwMemoryDest = *pwMemorySource;
            pwMemorySource += 1UL;
            pwMemoryDest += 1UL;
            szLength--;
        }while(0UL != szLength);
    }

}
static void CONV_vCopyReverseLoopCharIf(char* pcMemoryDest, const char* pcMemorySource, size_t szLength)
{
    if(0UL != szLength)
    {
        do
        {
            pcMemoryDest -= 1UL;
            pcMemorySource -= 1UL;
            *pcMemoryDest = *pcMemorySource;
            szLength--;
        }while(0UL != szLength);
    }
}

static void CONV_vCopyReverseLoopIntIf(int* pwMemoryDest, const int* pwMemorySource, size_t szLength)
{
    if(0UL != szLength)
    {
        do
        {
            pwMemoryDest -= 1UL;
            pwMemorySource -= 1UL;
            *pwMemoryDest = *pwMemorySource;
            szLength--;
        }while(0UL != szLength);
    }
}

void* CONV_pvMemoryCopy(void* pvMemoryDest, const void* pvMemorySource, size_t szLength)
{
    char* pcMemoryDestReg = (char*) pvMemoryDest;
    const char* pcMemorySourceReg = (const char*) pvMemorySource;
    size_t szSizeTem = 0UL;
    if(((uint32_t) pvMemorySource != (uint32_t) pvMemoryDest) && (0UL != szLength ))
    {
        if((uint32_t) pcMemoryDestReg < (uint32_t) pcMemorySourceReg)
        {
            szSizeTem = (size_t) pcMemorySourceReg;
            size_t szTempAlign = szSizeTem;
            szTempAlign |= (size_t) pcMemoryDestReg;
            if(0UL != (szTempAlign & CONV_WORDMASK))
            {
                szTempAlign = szSizeTem ^ (size_t) pcMemoryDestReg;
                if((szTempAlign & CONV_WORDMASK) || (szLength < CONV_WORDSIZE))
                {
                    szSizeTem =  szLength;
                }
                else
                {
                    szTempAlign = szSizeTem & CONV_WORDMASK;
                    szSizeTem = CONV_WORDSIZE;
                    szSizeTem -= szTempAlign;
                }
                szLength -= szSizeTem;
                CONV_vCopyLoopCharIf(pcMemoryDestReg, pcMemorySourceReg, szSizeTem);
            }
            szSizeTem = szLength;
            szSizeTem /= CONV_WORDSIZE;
            CONV_vCopyLoopIntIf((int*)pcMemoryDestReg, (const int*)pcMemorySourceReg, szSizeTem);
            szSizeTem = szLength;
            szSizeTem &= CONV_WORDMASK;
            CONV_vCopyLoopCharIf(pcMemoryDestReg, pcMemorySourceReg, szSizeTem);
        }
        else
        {
            pcMemorySourceReg += szLength;
            pcMemoryDestReg += szLength;
            szSizeTem = (size_t) pcMemorySourceReg;
            size_t szTempAlign = szSizeTem;
            szTempAlign |= (size_t) pcMemoryDestReg;
            if(szTempAlign & CONV_WORDMASK)
            {
                szTempAlign = szSizeTem;
                szTempAlign ^= (size_t) pcMemoryDestReg;
                if((szTempAlign & CONV_WORDMASK) || (szLength <= CONV_WORDSIZE))
                {
                    szSizeTem =  szLength;
                }
                else
                {
                    szSizeTem &= CONV_WORDMASK;
                }
                szLength -= szSizeTem;
                CONV_vCopyReverseLoopCharIf(pcMemoryDestReg, pcMemorySourceReg, szSizeTem);
            }
            szSizeTem = szLength;
            szSizeTem /= CONV_WORDSIZE;
            CONV_vCopyReverseLoopIntIf((int*) pcMemoryDestReg, (const int*) pcMemorySourceReg ,szSizeTem);
            szSizeTem = szLength;
            szSizeTem &= CONV_WORDMASK;
            CONV_vCopyReverseLoopCharIf(pcMemoryDestReg, pcMemorySourceReg, szSizeTem);
        }
    }
    return (pvMemoryDest);
}

#if defined (__TI_ARM__ ) || defined (__MSP430__ )
    #pragma RESET_MISRA("6.3")
#endif
