/**
 *
 * @file Segments_Enum.h
 * @copyright
 * @verbatim InDeviceMex 2021 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 16 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 16 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef MODULES_SEGMENTS_HEADER_SEGMENTS_ENUM_H_
#define MODULES_SEGMENTS_HEADER_SEGMENTS_ENUM_H_

typedef enum
{
    SEGMENTS_enDIGIT1 = 0U,
    SEGMENTS_enDIGIT2 = 1U,
    SEGMENTS_enDIGIT3 = 2U,
    SEGMENTS_enDIGIT4 = 3U,
    SEGMENTS_enDIGIT_MAX = 4U,
}SEGMENTS_nDIGIT;

typedef enum
{
    SEGMENTS_enSEGA = 0U,
    SEGMENTS_enSEGB = 1U,
    SEGMENTS_enSEGC = 2U,
    SEGMENTS_enSEGD = 3U,
    SEGMENTS_enSEGE = 4U,
    SEGMENTS_enSEGF = 5U,
    SEGMENTS_enSEGG = 6U,
    SEGMENTS_enDOT = 7U,
    SEGMENTS_enSEG_MAX = 8U,
}SEGMENTS_nSEG;


typedef enum
{
    SEGMENTS_enCOMMON_ANODE = 0U,
    SEGMENTS_enCOMMON_CATHODE = 1U,
}SEGMENTS_nCOMMON;



#endif /* MODULES_SEGMENTS_HEADER_SEGMENTS_ENUM_H_ */
