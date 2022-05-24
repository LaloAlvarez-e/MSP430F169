/**
 *
 * @file Conversion_StringLength.c
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
 * @verbatim 17 jul. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 17 jul. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/Standard/Standard.h>
#include <xUtils/Conversion/Conversion_String/xHeader/Conversion_StringLength.h>

uint32_t CONV_u32StringLength(const char* pcString, uint32_t u32MaxSize)
{
  const char* pcStringReg = 0;
  uint32_t u32Count = 0;
  if(0 != pcString)
  {
      pcStringReg = pcString;
      while(((char)0 != (char) *pcStringReg) && ((uint32_t) 0 != (uint32_t) u32MaxSize))
      {
          pcStringReg += 1U;
          u32MaxSize--;
      }
      u32Count = (uint32_t) pcStringReg;
      u32Count -= (uint32_t) pcString;
  }
  return ( (uint32_t) u32Count);
}

