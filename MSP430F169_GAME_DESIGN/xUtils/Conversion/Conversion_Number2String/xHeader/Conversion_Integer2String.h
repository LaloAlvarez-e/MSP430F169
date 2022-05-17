/**
 *
 * @file Conversion_Integer2String.h
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
#ifndef XUTILS_CONVERSION_XHEADER_CONVERSION_NUMBER2STRING_CONVERSION_INTEGER2STRING_H_
#define XUTILS_CONVERSION_XHEADER_CONVERSION_NUMBER2STRING_CONVERSION_INTEGER2STRING_H_

#include <xUtils/Standard/Standard.h>

uint8_t Conv__u8Int2String(int64_t s64Number, char* pcConv);
uint8_t Conv__u8DInt2String(int64_t s64Number, uint8_t u8Positive, uint8_t u8Padding0, uint8_t u8Deci, char* pcConv);
uint8_t Conv__u8Int2StringZeros(int64_t s64Number, int8_t s8CerosLeft, char* pcConv);

#endif /* XUTILS_CONVERSION_XHEADER_CONVERSION_NUMBER2STRING_CONVERSION_INTEGER2STRING_H_ */
