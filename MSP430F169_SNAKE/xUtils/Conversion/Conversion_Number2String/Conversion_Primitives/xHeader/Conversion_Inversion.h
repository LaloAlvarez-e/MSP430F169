/**
 *
 * @file Conversion_Inversion.h
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
#ifndef XUTILS_CONVERSION_XHEADER_CONVERSION_NUMBER2STRING_CONVERSION_PRIMITIVES_CONVERSION_INVERSION_H_
#define XUTILS_CONVERSION_XHEADER_CONVERSION_NUMBER2STRING_CONVERSION_PRIMITIVES_CONVERSION_INVERSION_H_

#include <xUtils/Standard/Standard.h>
#include <xUtils/Conversion/xHeader/Conversion_Enum.h>
#include <xUtils/Conversion/Conversion_Number2String/Conversion_Primitives/xHeader/Conversion_Wrapper.h>


CONV_nSTATUS Conv__enInversion(const char* const pcPointerIn, char* const pcPointerOut, uint8_t u8Length);
CONV_nSTATUS Conv__enOutInversion(CONV_OUT_t pvfOut, char* pvBufferOut, const char* pvBufferIn, uint32_t u32Index, uint32_t u32MaxLenght, uint32_t u32BufInLenght, uint32_t* pu32BufOutLenght, uint32_t u32Width, uint32_t u32flags);
#endif /* XUTILS_CONVERSION_XHEADER_CONVERSION_NUMBER2STRING_CONVERSION_PRIMITIVES_CONVERSION_INVERSION_H_ */
