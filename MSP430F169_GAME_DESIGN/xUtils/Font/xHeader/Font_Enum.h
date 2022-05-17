/**
 *
 * @file Font_Enum.h
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
 * @verbatim 17 feb. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 17 feb. 2021     vyldram    1.0         initial Version@endverbatim
 */
#ifndef XUTILS_FONT_XHEADER_FONT_ENUM_H_
#define XUTILS_FONT_XHEADER_FONT_ENUM_H_

#include <xUtils/Standard/Standard.h>

typedef enum
{
    FONT_enSize_16x24 = 0UL,
    FONT_enSize_11x16 = 1UL,
    FONT_enSize_8x16 = 2UL,
    FONT_enSize_12x12 = 3UL,
    FONT_enSize_8x12 = 4UL,
    FONT_enSize_8x8 = 5UL,
    FONT_enSize_6x8 = 6UL,
    FONT_enSize_5x7 = 7UL,
    FONT_enSize_8x16_MS_Gothic = 8UL,
    FONT_enSize_8x16_System = 9UL,
}FONT_nSize;

typedef struct
{
  const uint16_t *pu16Ascii;
  uint32_t u32Width;
  uint32_t u32Height;
  uint32_t u32Bits;
  int8_t   u32Cor;

} FONT_t;

typedef struct
{
  char *pcString;
  FONT_t *pstFont;
  uint16_t u16PosX;
  uint16_t u16PosY;
  uint16_t u16ColorFG;
  uint16_t u16CcolorBG;
} STRING_t;

#endif /* XUTILS_FONT_XHEADER_FONT_ENUM_H_ */
