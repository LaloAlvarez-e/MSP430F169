/*
 * PRINTF.c
 *
 *  Created on: 15 may. 2020
 *      Author: vyldram
 */

#include <xApplication/Printf/Generic/xHeader/Printf.h>

#include <xUtils/Conversion/Conversion_Number/Conversion_Number.h>
#include <xUtils/Conversion/Conversion_Number2String/Conversion_Number2String.h>
#include <xUtils/Conversion/Conversion_String/Conversion_String.h>
#include <xUtils/Conversion/Conversion_String2Number/Conversion_String2Number.h>

#if defined (__TI_ARM__ )
    #pragma CHECK_MISRA("-6.3, -10.1, -10.3, -12.2, -12.7, -12.10, -14.5, -16.1")
#endif
/* internal vsnprintf*/
uint32_t vsnprintf__u32UserGeneric(CONV_OUT_t pvfOut, char* pcBuffer, const uint32_t u32MaxLength, const char* pcFormat, va_list vaList)
{
  uint32_t u32Flags = 0U;
  uint32_t u32Width = 0U;
  uint32_t u32Negative = 0U;
  uint32_t u32LengthOut = 0U;
  uint64_t u64ValueTemp = 0ULL;
  uint32_t u32Precision = 0U;
  uint32_t u32PrecisionTemp = 0U;
  uint32_t n = 0U;
  uint32_t u32Index = 0U;
  uint32_t  u32Base = 0U;

  uint32_t u32ValueTemp = 0UL;

  uint32_t u32lteration = 0U;

  float64_t  f64DoubleArgument = 0;
  uintptr_t pvPointerArgument = 0U;
  int32_t  s32WidthArgument = 0;
  int32_t  s32WidthArgumentTemp = 0;
  int32_t  s32PrecisionArgument = 0;
  int32_t  s32ValueArgument = 0L;
  int32_t  s32ValueArgumentTemp = 0L;
  uint32_t  u32ValueArgument = 0UL;
  char*  pcValueArgument = 0U;
  int64_t  s64ValueArgument = 0LL;
  int64_t  s64ValueArgumentTemp = 0LL;
  uint64_t  u64ValueArgument = 0ULL;
  uint16_t  u16ValueArgument = 0U;
  int16_t  s16ValueArgument = 0;
  uint8_t  u8ValueArgument = 0U;
  int8_t  s8ValueArgument = 0;
  char  cValueArgument = '\0';
  if ((uint32_t) 0U == (uint32_t) pcBuffer) {
    /*use null output function*/
    pvfOut = &Conv__vOutNull;
  }

  while ('\0' != *pcFormat)
  {
    /* pcFormat specifier?  %[u32Flags][u32Width][.u32Precision][length]*/
    if ('%' != *pcFormat )
    {
      /* no*/
      pvfOut(*pcFormat, pcBuffer, u32Index, u32MaxLength);
      u32Index++;
      pcFormat += 1U;
      continue;
    }
    else
    {
      /* yes, evaluate it*/
      pcFormat += 1U;
    }

    /* evaluate u32Flags*/
    u32Flags = 0U;
    do
    {
      switch (*pcFormat)
      {
        case '0':
            u32Flags |= (uint32_t) CONV_enFLAGS_ZEROPAD;
            pcFormat += 1U;
            n = 1U;
            break;
        case '-':
            u32Flags |= (uint32_t) CONV_enFLAGS_LEFT;
            pcFormat += 1U;
            n = 1U;
            break;
        case '+':
            u32Flags |= (uint32_t) CONV_enFLAGS_PLUS;
            pcFormat += 1U;
            n = 1U;
            break;
        case ' ':
            u32Flags |= (uint32_t) CONV_enFLAGS_SPACE;
            pcFormat += 1U;
            n = 1U;
            break;
        case '#':
            u32Flags |= (uint32_t) CONV_enFLAGS_HASH;
            pcFormat += 1U;
            n = 1U;
            break;
        default :
            n = 0U;
            break;
      }
    } while (n);

    /* evaluate u32Width field*/
    u32Width = 0U;
    if (CONV_enDIGIT_OK == Conv__enIsDigit(*pcFormat))
    {
       Conv__s32String2UInteger( &pcFormat, &u64ValueTemp);
       u32Width = (uint32_t) u64ValueTemp;
    }
    else if ('*' == *pcFormat)
    {
        s32WidthArgument = (int32_t) va_arg(vaList, int32_t);
        if (s32WidthArgument < 0)
        {
            u32Flags |= (uint32_t) CONV_enFLAGS_LEFT;    /* reverse padding*/
            s32WidthArgumentTemp = 0;
            s32WidthArgumentTemp -= s32WidthArgument;
            u32Width = (uint32_t) (s32WidthArgumentTemp);
        }
        else
        {
            u32Width = (uint32_t) s32WidthArgument;
        }
        pcFormat += 1U;
    }
    else{}

    /* evaluate u32Precision field */
    u32Precision = 0U;
    if ( '.' == *pcFormat )
    {
      u32Flags |= (uint32_t) CONV_enFLAGS_PRECISION;
      pcFormat += 1U;
      if(CONV_enDIGIT_OK == Conv__enIsDigit(*pcFormat) )
      {
          Conv__s32String2UInteger( &pcFormat, &u64ValueTemp);
          u32Precision = (uint32_t) u64ValueTemp;
      }
      else if ('*' == *pcFormat)
      {
          s32PrecisionArgument = (int32_t) va_arg(vaList, int32_t);
          if(s32PrecisionArgument >= 0)
          {
              u32Precision = (uint32_t) s32PrecisionArgument;
          }
          else
          {
              u32Precision = 0U;
          }
        pcFormat += 1U;
      }
      else{}
    }

    /* evaluate length field*/
    switch (*pcFormat)
    {
      case 'l' :
        u32Flags |= (uint32_t) CONV_enFLAGS_LONG;
        pcFormat += 1U;
        if ( 'l' == *pcFormat)
        {
          u32Flags |= (uint32_t) CONV_enFLAGS_LONG_LONG;
          pcFormat += 1U;
        }
        break;
      case 'h' :
        u32Flags |= (uint32_t) CONV_enFLAGS_SHORT;
        pcFormat += 1U;
        if ('h' == *pcFormat)
        {
          u32Flags |= (uint32_t) CONV_enFLAGS_CHAR;
          pcFormat += 1U;
        }
        break;
      case 't' :
          u32Flags |= (uint32_t) CONV_enFLAGS_LONG;
          pcFormat += 1U;
          break;
      case'j' :
          u32Flags |= (uint32_t) CONV_enFLAGS_LONG_LONG;
          pcFormat += 1U;
          break;
      case  'z' :

          u32Flags |= (uint32_t) CONV_enFLAGS_LONG;
          pcFormat += 1U;
          break;
      default :
        break;
    }

    /* evaluate specifier*/
    switch (*pcFormat)
    {
      case 'd' :
      case 'i' :
      case 'u' :
      case 'x' :
      case 'X' :
      case 'o' :
      case  'b' :
      {
        /* set the u32Base*/
          u32Base = 0U;
        if ( ('x' == *pcFormat) || ('X' == *pcFormat) )
        {
          u32Base = 16U;
        }
        else if ('o' == *pcFormat )
        {
          u32Base = 8U;
        }
        else if ('b' == *pcFormat )
        {
          u32Base = 2U;
        }
        else
        {
          u32Base = 10U;
          u32Flags &= ~(uint32_t) CONV_enFLAGS_HASH;   /* no hash for dec pcFormat*/
        }

        /* uppercase*/
        if ('X' == *pcFormat) {
          u32Flags |= (uint32_t) CONV_enFLAGS_UPPERCASE;
        }

        /* no plus or space flag for U, x, X, o, b*/
        if (('i' != *pcFormat ) && ('d' != *pcFormat))
        {
          u32Flags &= ~((uint32_t) CONV_enFLAGS_PLUS | (uint32_t) CONV_enFLAGS_SPACE);
        }

        /* ignore '0' flag when u32Precision is given*/
        if (0U != (u32Flags & (uint32_t) CONV_enFLAGS_PRECISION))
        {
          u32Flags &= ~(uint32_t) CONV_enFLAGS_ZEROPAD;
        }

        /* convert the integer*/
        if (('i' == *pcFormat) || ('d' == *pcFormat))
        {
          /* signed*/
          if (0U != (u32Flags & (uint32_t) CONV_enFLAGS_LONG_LONG))
          {
                s64ValueArgument = (int64_t) va_arg(vaList, int64_t);
                if(s64ValueArgument >= 0)
                {
                    u64ValueTemp = (uint64_t) s64ValueArgument;
                    u32Negative = 0U;
                }
                else
                {
                    s64ValueArgumentTemp = 0;
                    s64ValueArgumentTemp -= s64ValueArgument;
                    u64ValueTemp = (uint64_t) s64ValueArgumentTemp;
                    u32Negative = 1U;
                }

                Conv__enNumber2String_LongLong(pvfOut, pcBuffer, u64ValueTemp, u32Index, u32MaxLength, &u32LengthOut, u32Width, u32Flags, u32Negative, (uint64_t) u32Base, u32Precision);
                u32Index = u32LengthOut;
          }
          else if (0U != (u32Flags & (uint32_t) CONV_enFLAGS_LONG))
          {
              s32ValueArgument = (int32_t) va_arg(vaList, int32_t);
              if(s32ValueArgument >= 0)
              {
                  u32ValueTemp = (uint32_t) s32ValueArgument;
                  u32Negative = 0U;
              }
              else
              {
                  s32ValueArgumentTemp = 0;
                  s32ValueArgumentTemp -= s32ValueArgument;
                  u32ValueTemp = (uint32_t) s32ValueArgumentTemp;
                  u32Negative = 1U;
              }

              Conv__enNumber2String_Long(pvfOut, pcBuffer, u32ValueTemp, u32Index, u32MaxLength, &u32LengthOut, u32Width, u32Flags, u32Negative, u32Base, u32Precision);
              u32Index = u32LengthOut;

          }
          else
          {
              if(0U != (u32Flags & (uint32_t) CONV_enFLAGS_CHAR))
              {
                  s8ValueArgument = (int8_t) va_arg(vaList, int32_t);
                  s32ValueArgument = (int32_t) s8ValueArgument;
              }
              else  if(0U != (u32Flags & (uint32_t) CONV_enFLAGS_SHORT))
              {
                  s16ValueArgument = (int16_t) va_arg(vaList, int32_t);
                  s32ValueArgument = (int32_t) s16ValueArgument;
              }
              else
              {
                  s32ValueArgument = (int32_t) va_arg(vaList, int32_t);
              }

              if(s32ValueArgument >= 0)
              {
                  u32ValueTemp = (uint32_t) s32ValueArgument;
                  u32Negative = 0U;
              }
              else
              {
                  s32ValueArgumentTemp = 0;
                  s32ValueArgumentTemp -= s32ValueArgument;
                  u32ValueTemp = (uint32_t) s32ValueArgumentTemp;
                  u32Negative = 1U;
              }

              Conv__enNumber2String_Long(pvfOut, pcBuffer, u32ValueTemp, u32Index, u32MaxLength, &u32LengthOut, u32Width, u32Flags, u32Negative, u32Base, u32Precision);
              u32Index = u32LengthOut;
          }
        }
        else
        {
          /* unsigned*/
          if (u32Flags & (uint32_t) CONV_enFLAGS_LONG_LONG)
          {
              u64ValueArgument = (uint64_t) va_arg(vaList, uint64_t);
              u32Negative = 0U;

              Conv__enNumber2String_LongLong(pvfOut, pcBuffer, u64ValueArgument, u32Index, u32MaxLength, &u32LengthOut, u32Width, u32Flags, u32Negative, (uint64_t) u32Base, u32Precision);
              u32Index = u32LengthOut;
          }
          else if (u32Flags & (uint32_t) CONV_enFLAGS_LONG)
          {
              u32ValueArgument = (uint32_t) va_arg(vaList, uint32_t);
              u32Negative = 0U;

              Conv__enNumber2String_Long(pvfOut, pcBuffer, u32ValueArgument, u32Index, u32MaxLength, &u32LengthOut, u32Width, u32Flags, u32Negative, u32Base, u32Precision);
              u32Index = u32LengthOut;
          }
          else
          {

              if(0U != (u32Flags & (uint32_t) CONV_enFLAGS_CHAR))
              {
                  u8ValueArgument = (uint8_t) va_arg(vaList, int32_t);
                  u32ValueArgument = (uint32_t) u8ValueArgument;
              }
              else  if(0U != (u32Flags & (uint32_t) CONV_enFLAGS_SHORT))
              {
                  u16ValueArgument = (uint16_t) va_arg(vaList, uint32_t);
                  u32ValueArgument = (uint32_t) u16ValueArgument;
              }
              else
              {
                  u32ValueArgument = (uint32_t) va_arg(vaList, uint32_t);
              }
              u32Negative = 0U;

              Conv__enNumber2String_Long(pvfOut, pcBuffer, u32ValueArgument, u32Index, u32MaxLength, &u32LengthOut, u32Width, u32Flags, u32Negative, u32Base, u32Precision);
              u32Index = u32LengthOut;
          }
        }
        pcFormat += 1U;
        break;
      }
      case 'f' :
      case 'F' :
        if ('F' == *pcFormat)
        {
            u32Flags |= (uint32_t) CONV_enFLAGS_UPPERCASE;
        }
        f64DoubleArgument = (float64_t) va_arg(vaList, float64_t);
        Conv__enNumber2String_Float(pvfOut, pcBuffer, f64DoubleArgument, u32Index, u32MaxLength, &u32LengthOut, u32Width, u32Flags, u32Precision);
        u32Index = u32LengthOut;

        pcFormat += 1U;
        break;
      case 'e':
      case 'E':
      case 'g':
      case 'G':
        if (( 'g' == *pcFormat) || ('G' == *pcFormat))
        {
            u32Flags |= (uint32_t) CONV_enFLAGS_ADAPT_EXP;
        }
        if (('E' == *pcFormat ) || ('G' == *pcFormat))
        {
            u32Flags |= (uint32_t) CONV_enFLAGS_UPPERCASE;
        }

        f64DoubleArgument = (float64_t) va_arg(vaList, float64_t);
        Conv__enNumber2String_Exponential(pvfOut, pcBuffer, f64DoubleArgument, u32Index, u32MaxLength, &u32LengthOut, u32Width, u32Flags, u32Precision);
        u32Index = u32LengthOut;
        pcFormat += 1U;
        break;

      case 'c' :
      {
          cValueArgument = (char)va_arg(vaList, int32_t);
          u32lteration = 1U;
        /* pre padding*/
        if (0U == (u32Flags & (uint32_t) CONV_enFLAGS_LEFT))
        {
            while (u32lteration < u32Width)
            {
                u32lteration++;
                pvfOut(' ', pcBuffer, u32Index, u32MaxLength);
                u32Index++;
            }
        }
        /* char output*/
        pvfOut(cValueArgument, pcBuffer, u32Index, u32MaxLength);
        u32Index++;
        /* post padding*/
        if (0U != (u32Flags & (uint32_t) CONV_enFLAGS_LEFT))
        {
            while (u32lteration < u32Width)
            {
                u32lteration++;
                pvfOut(' ', pcBuffer, u32Index, u32MaxLength);
                u32Index++;
            }
        }
        pcFormat += 1U;
        break;
      }

      case 's' :
      {
        pcValueArgument = (char*) va_arg(vaList, char*);
        if(0U == u32Precision)
        {
            u32PrecisionTemp = (uint32_t) -1;
        }
        else
        {
            u32PrecisionTemp = u32Precision;
        }
        u32lteration = CONV_u32StringLength(pcValueArgument, u32PrecisionTemp);
        /* pre padding*/
        if (0U != (u32Flags & (uint32_t) CONV_enFLAGS_PRECISION))
        {
            if(u32lteration> u32Precision)
            {
                u32lteration = u32Precision;
            }
        }
        if (0U == (u32Flags & (uint32_t) CONV_enFLAGS_LEFT))
        {
          while (u32lteration < u32Width)
          {
            u32lteration++;
            pvfOut(' ', pcBuffer, u32Index, u32MaxLength);
            u32Index++;
          }
        }
        /* string output*/
        while (('\0' != *pcValueArgument) && ((0U == (u32Flags & (uint32_t) CONV_enFLAGS_PRECISION)) || (0U != u32Precision)))
        {
            u32Precision--;
          pvfOut(*pcValueArgument, pcBuffer, u32Index, u32MaxLength);
          u32Index++;
          pcValueArgument += 1U;
        }
        /* post padding*/
        if (0U != (u32Flags & (uint32_t) CONV_enFLAGS_LEFT))
        {
          while (u32lteration < u32Width)
          {
              u32lteration++;
            pvfOut(' ', pcBuffer, u32Index, u32MaxLength);
            u32Index++;
          }
        }
        pcFormat += 1U;
        break;
      }

      case 'p' :
      {
        u32Width = sizeof(void*) * 2U;
        u32Flags |= (uint32_t) CONV_enFLAGS_ZEROPAD | (uint32_t) CONV_enFLAGS_UPPERCASE;

        pvPointerArgument = (uintptr_t) va_arg(vaList, void*);
        u32ValueArgument = (uint32_t) pvPointerArgument;
        u32Negative = 0U;

        Conv__enNumber2String_Long(pvfOut, pcBuffer, u32ValueArgument, u32Index, u32MaxLength, &u32LengthOut, u32Width, u32Flags, u32Negative, 16U, u32Precision);
        u32Index = u32LengthOut;


        pcFormat += 1U;
        break;
      }

      case '%' :
        pvfOut('%', pcBuffer, u32Index, u32MaxLength);
        u32Index++;
        pcFormat += 1U;
        break;

      default :
        pvfOut(*pcFormat, pcBuffer, u32Index, u32MaxLength);
        u32Index++;
        pcFormat += 1U;
        break;
    }
  }

  /* termination*/
  if(u32Index > u32MaxLength)
  {
      u32Index = u32MaxLength;
      u32Index -= 1U;
  }
  pvfOut((char)0, pcBuffer, u32Index, u32MaxLength);

  /* return written chars without terminating \0*/
  return (u32Index);
}


uint32_t printf__u32User(const char* pcFormat, ...)
{
  va_list vaList;
  va_start(vaList, pcFormat);
  char pcBuffer[1] = {'\0'};
  const uint32_t u32Length = vsnprintf__u32UserGeneric( &Conv__vOutChar, pcBuffer, (size_t) -1, pcFormat, vaList);
  va_end(vaList);
  return (u32Length);
}


uint32_t sprintf__u32User(char* pcBuffer, const char* pcFormat, ...)
{
  va_list vaList;
  va_start(vaList, pcFormat);
  const uint32_t u32Length = vsnprintf__u32UserGeneric( &Conv__vOutBuffer, pcBuffer, (size_t) -1, pcFormat, vaList);
  va_end(vaList);
  return (u32Length);
}


uint32_t  snprintf__u32User(char* pcBuffer, uint32_t u32Count, const char* pcFormat, ...)
{
  va_list vaList;
  va_start(vaList, pcFormat);
  const uint32_t u32Length = vsnprintf__u32UserGeneric( &Conv__vOutBuffer, pcBuffer, u32Count, pcFormat, vaList);
  va_end(vaList);
  return (u32Length);
}


uint32_t fctprintf__u32User(void (*pvfFunctionOut) (char cCharacter, void* pvPrintArguments), void* pvPrintArguments, const char* pcFormat, ...)
{
  va_list vaList;
  va_start(vaList, pcFormat);
  CONV_OUT_WRAPPER_t out_fct_wrap = { pvfFunctionOut, pvPrintArguments };
  const uint32_t u32Length = vsnprintf__u32UserGeneric( &Conv__vOutFunction, (char*) & out_fct_wrap, (uint32_t) -1, pcFormat, vaList);
  va_end(vaList);
  return (u32Length);
}

uint32_t vprintf__u32User(const char* pcFormat, va_list vaList)
{
  char pcBuffer[1] = {'\0'};
  return vsnprintf__u32UserGeneric( &Conv__vOutChar, pcBuffer, (uint32_t) -1, pcFormat, vaList);
}

uint32_t vsprintf__u32User(char* pcBuffer, const char* pcFormat, va_list vaList)
{
  return vsnprintf__u32UserGeneric( &Conv__vOutBuffer, pcBuffer, (uint32_t) -1, pcFormat, vaList);
}

uint32_t vsnprintf__u32User(char* pcBuffer, const uint32_t u32Count, const char* pcFormat, va_list vaList)
{
  return vsnprintf__u32UserGeneric( &Conv__vOutBuffer, pcBuffer, u32Count, pcFormat, vaList);
}


#if defined (__TI_ARM__ )
    #pragma RESET_MISRA("6.3, 10.1, 10.3, 12.2, 12.7, 12.10, 14.5, 16.1")
#endif
