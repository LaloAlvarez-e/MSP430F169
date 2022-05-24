/**
 *
 * @file Conversion_NumberFloat2String.c
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
#include <xUtils/Conversion/Conversion_Number2String/Conversion_Primitives/xHeader/Conversion_Inversion.h>


#define FLOAT_PRECISION_MAX (14U)
CONV_nSTATUS Conv__enNumber2String_Float(CONV_OUT_t pvfOut, char* pcBufferOut, float64_t f64Value, uint32_t u32Index, uint32_t u32MaxLenght, uint32_t* pu32BufOutLenght, uint32_t u32Width, uint32_t u32flags, uint32_t u32Prec)
{
  char pvBufferIn[CONV_enBUFFER_SIZE_FLOAT];
  char* cFni = "fni";
  char* cFni_ = "fni+";
  char* cCorrect = 0U;
  size_t szLength = 0U;
  uint32_t  u32LengthIn = 0U;
  float64_t f64Diff = 0.0;
  uint32_t u32Negative = 0U;
  CONV_nSTATUS enStatus = CONV_enSTATUS_ERROR;
  int64_t s64ValueComplete = 0;
  float64_t f64ValueTemp = 0.0;
  uint64_t u64ValueTemp = 0U;
  int64_t s64ValueTemp = 0;
  float64_t f64ValueTemp2 = 0.0;
  uint64_t u64Fractional = 0U;
  uint64_t u64DiffCompare = 0U;
  uint64_t u64DiffCompare2 = 0U;
  uint32_t u32Counter = 0U;
  /* powers of 10*/
  static const float64_t f64Pow10[FLOAT_PRECISION_MAX] = { 1.0, 10.0, 100.0, 1000.0, 10000.0, 100000.0, 1000000.0, 10000000.0, 100000000.0, 1000000000.0, 10000000000.0, 100000000000.0, 1000000000000.0, 10000000000000.0  };

  /* test for special values*/
  if (f64Value < -DBL_MAX)
  {
      enStatus = Conv__enOutInversion(pvfOut, pcBufferOut, "fni-", u32Index, u32MaxLenght, 4U, pu32BufOutLenght, u32Width, u32flags);
  }
  else if (f64Value > DBL_MAX)
  {
      if (0U != (u32flags & (uint32_t) CONV_enFLAGS_PLUS))
      {
          u32LengthIn = 4U ;
          cCorrect = cFni_;
      }
      else
      {
          u32LengthIn = 3U;
          cCorrect = cFni;
      }
      enStatus = Conv__enOutInversion(pvfOut, pcBufferOut, cCorrect, u32Index, u32MaxLenght, u32LengthIn, pu32BufOutLenght, u32Width, u32flags);
  }
 else
 {
      /*
       * test for very large values
       * standard printf behavior is to print EVERY s64ValueComplete number digit -- which could be 100s of characters overflowing your buffers == bad
       */
      if ((f64Value > CONV_MAX_VALUE_FLOAT) || (f64Value < -CONV_MAX_VALUE_FLOAT))
      {
          enStatus = Conv__enNumber2String_Exponential(pvfOut, pcBufferOut, f64Value, u32Index, u32MaxLenght, pu32BufOutLenght, u32Width, u32flags, u32Prec);
      }
      else
      {
          /* test for u32Negative*/
          if (0.0 > f64Value )
          {
            u32Negative = 1U;
            f64Value = - f64Value;
          }

          /* set default precision, if not set explicitly*/
          if ( (uint32_t) 0U == (u32flags & (uint32_t) CONV_enFLAGS_PRECISION))
          {
            u32Prec = CONV_DEFAULT_FLOAT_PRECISION;
          }
          /* limit precision to FLOAT_PRECISION_MAX, cause a u32Prec >= FLOAT_PRECISION_MAX can lead to overflow errors*/
          while ((szLength < (size_t) CONV_enBUFFER_SIZE_FLOAT) && (u32Prec >= FLOAT_PRECISION_MAX))
          {
            pvBufferIn[szLength] = '0';
            szLength++;
            u32Prec--;
          }

          s64ValueComplete = (int64_t) f64Value;
          f64ValueTemp2 = (float64_t) s64ValueComplete;
          f64ValueTemp = f64Value;
          f64ValueTemp -= f64ValueTemp2;
          f64ValueTemp *= f64Pow10[u32Prec];

          u64Fractional = (uint64_t) f64ValueTemp;
          f64Diff = f64ValueTemp;
          f64Diff -= (float64_t) u64Fractional;

          if (0.5 < f64Diff )
          {
            u64Fractional++;
            /* handle rollover, e.g. case 0.99 with u32Prec 1 is 1.0*/
            if (u64Fractional >= (uint64_t) f64Pow10[u32Prec])
            {
              u64Fractional = 0U;
              s64ValueComplete++;
            }
          }
          else if (0.5 > f64Diff )
          {
          }
          else if ((0U == u64Fractional ) || (0U != (u64Fractional & 1U)))
          {
            /* if halfway, round up if odd OR if last digit is 0*/
            u64Fractional++;
          }
          else{}

          if (0U == u32Prec )
          {
            f64Diff = f64Value;
            f64Diff -= (float64_t) s64ValueComplete;
            if(0.5 > f64Diff)
            {
                u64DiffCompare = 0U;
            }
            else
            {
                u64DiffCompare = 1U;
            }

            if(0.5 < f64Diff)
            {
                u64DiffCompare2 = 1U;
            }
            else
            {
                u64DiffCompare2 = 0U;
            }

            if ((u64DiffCompare || u64DiffCompare2 ) && (0U != ((uint64_t) s64ValueComplete & (uint64_t) 1)))
            {
              /* exactly 0.5 and ODD, then round up
               *1.5 -> 2, but 2.5 -> 2 * 1.5 */
              s64ValueComplete++;
            }
          }
          else
          {
            u32Counter = u32Prec;
            /* now do fractional part, as an unsigned number*/
            while (szLength < (size_t) CONV_enBUFFER_SIZE_FLOAT)
            {
              u32Counter--;
              u64ValueTemp = u64Fractional;
              u64ValueTemp %= 10U;
              u64ValueTemp += 48U;
              pvBufferIn[szLength] = (char) u64ValueTemp;
              szLength++;
              u64Fractional /= 10U;
              if (0U == u64Fractional)
              {
                break;
              }
            }
            /* add extra 0s */
            while ((szLength < (size_t) CONV_enBUFFER_SIZE_FLOAT) && (u32Counter > 0U))
            {
                u32Counter--;
                pvBufferIn[szLength] = '0';
                szLength++;
            }
            if (szLength < (size_t) CONV_enBUFFER_SIZE_FLOAT)
            {
              /* add decimal*/
              pvBufferIn[szLength] = '.';
              szLength++;
            }
          }

          /* do s64ValueComplete part, number is reversed*/
          while (szLength < (size_t) CONV_enBUFFER_SIZE_FLOAT)
          {
            s64ValueTemp = s64ValueComplete;
            s64ValueTemp %= 10;
            s64ValueTemp += 48;
            pvBufferIn[szLength] = (char) s64ValueTemp;
            szLength++;
            s64ValueComplete /= 10;
            if (0 == s64ValueComplete)
            {
                break;
            }
          }

          /* pad leading zeros*/
          if ((0U == (u32flags & (uint32_t) CONV_enFLAGS_LEFT) ) && (0U != (u32flags & (uint32_t) CONV_enFLAGS_ZEROPAD)))
          {
            if ((0U != u32Width) && ( (0U != u32Negative) || (0U != (u32flags & ((uint32_t) CONV_enFLAGS_PLUS | (uint32_t) CONV_enFLAGS_SPACE)))))
            {
              u32Width--;
            }
            while ((szLength < u32Width) && (szLength < (size_t) CONV_enBUFFER_SIZE_FLOAT))
            {
              pvBufferIn[szLength] = '0';
              szLength++;
            }
          }

          if (szLength < (size_t) CONV_enBUFFER_SIZE_FLOAT)
          {
            if (0U != u32Negative)
            {
              pvBufferIn[szLength] = '-';
              szLength++;
            }
            else if (0U != (u32flags & (uint32_t) CONV_enFLAGS_PLUS))
            {
              pvBufferIn[szLength] = '+';  /* ignore the space if the '+' exists*/
              szLength++;
            }
            else if (0U != (u32flags & (uint32_t) CONV_enFLAGS_SPACE))
            {
              pvBufferIn[szLength] = ' ';
              szLength++;
            }
            else{}
          }
          enStatus = Conv__enOutInversion(pvfOut, pcBufferOut, pvBufferIn, u32Index, u32MaxLenght, szLength, pu32BufOutLenght, u32Width, u32flags);
      }
  }
  return (enStatus);
}

