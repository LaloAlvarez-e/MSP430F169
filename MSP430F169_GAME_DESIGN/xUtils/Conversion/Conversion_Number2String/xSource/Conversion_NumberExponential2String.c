/**
 *
 * @file Conversion_NumberExponential2String.c
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
 * @verbatim 10 dic. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 10 dic. 2020     vyldram    1.0         initial Version@endverbatim
 */

#include <xUtils/Standard/Standard.h>
#include <xUtils/Conversion/Conversion_Number2String/xHeader/Conversion_NumberExponential2String.h>
#include <xUtils/Conversion/Conversion_Number2String/xHeader/Conversion_NumberFloat2String.h>
#include <xUtils/Conversion/Conversion_Number2String/xHeader/Conversion_NumberLong2String.h>
#include <xUtils/Conversion/Conversion_Number2String/xHeader/Conversion_NumberFormat.h>



CONV_nSTATUS Conv__enNumber2String_Exponential(CONV_OUT_t pvfOut, char* pcBufferOut, float64_t f64Value, uint32_t u32Index, uint32_t u32MaxLenght, uint32_t* pu32BufOutLenght, uint32_t u32Width, uint32_t u32flags, uint32_t u32Prec)
{

    CONV_nSTATUS enConvStatus = CONV_enSTATUS_ERROR;
    char cCharTemp = 0;
    uint32_t u32Negative = 0U;
    uint32_t u32flagsTemp = 0U;
    uint64_t u64TempLong = 0U;
    int64_t s64Temp = 0U;

    uint64_t u64Temp = 0U;
    uint64_t u64Temp2 = 0U;
    uint64_t u64TempShift = 0U;
    uint64_t u64TempShift2 = 0U;

    float64_t f64Temp = 0U;
    float64_t f64Temp2 = 0U;

    float64_t f64DoubleZ = 0;
    float64_t f64DoubleZ2 = 0;

    float64_t f64ValueTemp = 0;

    float64_t f64DoubleDiv0 = 0;
    float64_t f64DoubleDiv1 = 0;
    float64_t f64DoubleDiv2 = 0;
    float64_t f64DoubleDiv3 = 0;

    uint32_t  u32MinWidth = 0U;
    uint32_t u32FloatWidth = 0U;
    CONV_FLOAT_UNION_t uFloatConversion = {0UL};
    int64_t  s64Exponential2 = 0;
    int64_t  s64Exponential2Temp = 0;
    int64_t  s64ExponentialValue = 0;

    size_t szStartIndex = 0U;

    if(((uint32_t) 0U != (uint32_t) pvfOut) && ((uint32_t) 0U != (uint32_t) pcBufferOut) && ((uint32_t) 0U != (uint32_t) pu32BufOutLenght))
    {
        /* check for NaN and special f64Values*/
        if (((float64_t) DBL_MAX < (float64_t) f64Value ) || ((float64_t) -DBL_MAX > (float64_t) f64Value))
        {
            enConvStatus = Conv__enNumber2String_Float(pvfOut, pcBufferOut, f64Value, u32Index, u32MaxLenght, pu32BufOutLenght, u32Width, u32flags, u32Prec);
        }
        else
        {
            /* determine the sign*/
            if(f64Value < 0.0)
            {
                u32Negative = 1U;
                f64ValueTemp = 0.0;
                f64ValueTemp -= f64Value;
                f64Value = f64ValueTemp;
            }
            else
            {
                u32Negative = 0U;
            }

            /* default precision*/
            if ( (uint32_t) 0U == (u32flags & (uint32_t) CONV_enFLAGS_PRECISION))
            {
                u32Prec = CONV_DEFAULT_FLOAT_PRECISION;
            }

            uFloatConversion.FLOAT = (float64_t) f64Value;
            u64Temp = (uint64_t) uFloatConversion.UNSIGNED >> (uint64_t) 52ULL;
            u64Temp &= (uint64_t) 0x07FFULL;
            u64TempLong = u64Temp;
            s64Exponential2 = (int64_t) u64TempLong;
            s64Exponential2 -= 1023;           /* effectively log2*/

            u64Temp = (uint64_t) uFloatConversion.UNSIGNED;
            u64TempShift = 1ULL;
            u64TempShift <<= 52ULL;
            u64TempShift -= 1ULL;
            u64Temp &= u64TempShift;

            u64TempShift2 = 1023ULL ;
            u64TempShift2 <<= 52ULL;

            u64Temp2 = u64Temp | u64TempShift2;
            uFloatConversion.UNSIGNED = u64Temp2;  /* drop the exponent so uFloatConversion.FLOAT is now in [1, 2)*/

            /* now approximate log10 from the log2 integer part and an expansion of ln around 1.5*/
            f64Temp = uFloatConversion.FLOAT;
            f64Temp -= 1.5;
            f64Temp *= 0.289529654602168;

            f64Temp2 = (float64_t) s64Exponential2;
            f64Temp2 *= 0.301029995663981;
            f64Temp2 += 0.1760912590558 ;
            f64Temp2 += f64Temp;
            s64ExponentialValue = (int64_t) (f64Temp2);

            /* now we want to compute 10^s64ExponentialValue but we want to be sure it won't overflow*/
            f64Temp = (float64_t) s64ExponentialValue;
            f64Temp *= 3.321928094887362;
            f64Temp += 0.5;
            s64Exponential2 = (int64_t) (f64Temp);

            f64Temp2 = (float64_t) s64ExponentialValue;
            f64Temp2 *= 2.302585092994046;
            f64Temp = (float64_t) s64Exponential2;
            f64Temp *= 0.6931471805599453;

            f64DoubleZ = f64Temp2 - f64Temp;
            f64DoubleZ2 = f64DoubleZ * f64DoubleZ;

            s64Exponential2Temp = s64Exponential2;
            s64Exponential2Temp += 1023;
            u64TempLong = (uint64_t) s64Exponential2Temp;
            u64Temp = (uint64_t) u64TempLong;
            u64Temp <<= 52ULL;
            uFloatConversion.UNSIGNED = u64Temp;

            /* compute exp(z) using continued fractions, see https://en.wikipedia.org/wiki/Exponential_function#Continued_fractions_for_ex*/
            f64DoubleDiv0 = f64DoubleZ2;
            f64DoubleDiv0 /= 14.0;
            f64DoubleDiv0 += 10.0;

            f64DoubleDiv1 = f64DoubleZ2;
            f64DoubleDiv1 /= f64DoubleDiv0;
            f64DoubleDiv1 += 6.0;

            f64DoubleDiv2 = f64DoubleZ2;
            f64DoubleDiv2 /= f64DoubleDiv1;
            f64DoubleDiv2 += 2.0;
            f64DoubleDiv2 -= f64DoubleZ;

            f64DoubleDiv3 = f64DoubleZ;
            f64DoubleDiv3 *= 2.0;
            f64DoubleDiv3 /= f64DoubleDiv2;
            f64DoubleDiv3 += 1.0;

            uFloatConversion.FLOAT *= f64DoubleDiv3;

            /* correct for rounding errors*/
            if (f64Value < uFloatConversion.FLOAT) {
              s64ExponentialValue--;
              uFloatConversion.FLOAT /= 10.0;
            }

            /* the exponent format is "%+03d" and largest f64Value is "307", so set aside 4-5 characters*/
            if((s64ExponentialValue < 100) && (s64ExponentialValue > -100))
            {
                u32MinWidth = 4U;
            }
            else
            {
                u32MinWidth = 5U;
            }

            /* in "%g" mode, "u32Prec" is the number of *significant figures* not decimals*/
            if ((uint32_t) 0U != (u32flags & (uint32_t) CONV_enFLAGS_ADAPT_EXP))
            {
              /* do we want to fall-back to "%f" mode?*/
              if (((float64_t) 1e-4 <= f64Value) && ((float64_t) 1e6 > f64Value))
              {
                if ((int64_t) u32Prec > s64ExponentialValue)
                {
                    s64Temp = (int64_t) u32Prec;
                    s64Temp -= s64ExponentialValue;
                    s64Temp -= 1;
                    u32Prec = (uint32_t) s64Temp;
                }
                else
                {
                  u32Prec = 0U;
                }
                u32flags |= (uint32_t) CONV_enFLAGS_PRECISION;   /* make sure _ftoa respects precision*/
                /* no characters in exponent*/
                u32MinWidth = 0U;
                s64ExponentialValue = 0;
              }
              else
              {
                /* we use one sigfig for the whole part*/
                if ((u32Prec > 0U) && ((uint32_t) 0U != (u32flags & (uint32_t) CONV_enFLAGS_PRECISION))) {
                  u32Prec -= 1U;
                }
              }
            }

            /* will everything fit?*/
            u32FloatWidth = u32Width;
            if (u32Width > u32MinWidth)
            {
              /* we didn't fall-back so subtract the characters required for the exponent*/
              u32FloatWidth -= u32MinWidth;
            } else
            {
              /* not enough characters, so go back to default sizing*/
              u32FloatWidth = 0U;
            }
            if (((uint32_t) 0U != (u32flags & (uint32_t) CONV_enFLAGS_LEFT)) && (0U != u32MinWidth))
            {
              /* if we're padding on the right, DON'T pad the floating part*/
              u32FloatWidth = 0U;
            }

            /* rescale the float f64Value*/
            if ((int64_t) 0LL != s64ExponentialValue)
            {
              if((0.0f < uFloatConversion.FLOAT) || ( 0.0f > uFloatConversion.FLOAT))
              {
                  f64Value /= uFloatConversion.FLOAT;
              }
            }

            /* output the floating part*/
            szStartIndex = (size_t) u32Index;
            if((uint32_t) 0U != u32Negative)
            {
                f64ValueTemp = -f64Value;
            }
            else
            {
                f64ValueTemp = f64Value;
            }
            u32flagsTemp = u32flags & ~((uint32_t) CONV_enFLAGS_ADAPT_EXP);

            enConvStatus = Conv__enNumber2String_Float(pvfOut, pcBufferOut, f64ValueTemp, u32Index, u32MaxLenght, pu32BufOutLenght, u32FloatWidth, u32flagsTemp, u32Prec);
            if(CONV_enSTATUS_OK == enConvStatus)
            {
                u32Index = *pu32BufOutLenght;
                /* output the exponent part*/
                if (0U != u32MinWidth)
                {
                  /* output the exponential symbol*/
                    u32flagsTemp = u32flags & (uint32_t) CONV_enFLAGS_UPPERCASE;
                    if((uint32_t) 0U != u32flagsTemp)
                    {
                        cCharTemp = 'E';
                    }
                    else
                    {
                        cCharTemp = 'e';
                    }
                    pvfOut(cCharTemp, pcBufferOut, u32Index, u32MaxLenght);
                    u32Index++;
                  /* output the exponent f64Value*/
                  if(s64ExponentialValue < 0)
                  {
                      s64Temp = -s64ExponentialValue;
                      u32Negative = (uint32_t) 1U;
                  }
                  else
                  {
                      s64Temp = s64ExponentialValue;
                      u32Negative = (uint32_t) 0U;
                  }
                  u32flagsTemp = (uint32_t) CONV_enFLAGS_ZEROPAD | (uint32_t) CONV_enFLAGS_PLUS;
                   enConvStatus = Conv__enNumber2String_Long(pvfOut, pcBufferOut, (uint32_t) s64Temp, u32Index, u32MaxLenght, pu32BufOutLenght, u32MinWidth-1U, u32flagsTemp, u32Negative, (uint32_t) 10U, (uint32_t) 0U);
                   u32Index = *pu32BufOutLenght;
                 /* might need to right-pad spaces*/
                  if ((uint32_t) 0U != (u32flags & (uint32_t) CONV_enFLAGS_LEFT))
                  {
                    while ((u32Index - szStartIndex) < u32Width)
                    {
                        pvfOut(' ', pcBufferOut, u32Index, u32MaxLenght);
                        u32Index++;
                    }
                  }
                }
                *pu32BufOutLenght = u32Index;
            }
        }
    }
    return (enConvStatus);
}
