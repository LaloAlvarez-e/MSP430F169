/**
 *
 * @file Font.h
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
#ifndef XUTILS_FONT_FONT_H_
#define XUTILS_FONT_FONT_H_

#include <xUtils/Font/xHeader/Font_Enum.h>

extern const uint16_t FONT_u16_16x24[24UL * 95UL];
extern const uint16_t FONT_u16_8x16[16UL * 96UL];
extern const uint16_t FONT_u16_8x16_MS_Gothic[16UL * 95UL];
extern const uint16_t FONT_u16_8x16_System[16UL * 95UL];
extern const uint16_t FONT_u16_12x12 [12UL * 96UL];
extern const uint16_t FONT_u16_8x12 [12UL * 96UL];
extern const uint16_t FONT_u16_11x16[11UL * 94UL] ;
extern const uint16_t FONT_u16_8x8 [8UL * 96UL] ;
extern const uint16_t FONT_u16_6x8[8UL * 96UL] ;
extern const uint16_t FONT_u16_5x7[5UL * 99UL];

extern FONT_t FONT_s16x24;
extern FONT_t FONT_s11x16;
extern FONT_t FONT_s8x16;
extern FONT_t FONT_s8x16_MS_Gothic;
extern FONT_t FONT_s8x16_System;
extern FONT_t FONT_s12x12;
extern FONT_t FONT_s8x12 ;
extern FONT_t FONT_s8x8;
extern FONT_t FONT_s6x8;
extern FONT_t FONT_s5x7;

#endif /* XUTILS_FONT_FONT_H_ */
