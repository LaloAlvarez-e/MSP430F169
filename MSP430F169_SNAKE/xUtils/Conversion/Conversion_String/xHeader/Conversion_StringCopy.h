/**
 *
 * @file Conversion_StringCopy.h
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
#ifndef XUTILS_CONVERSION_CONVERSION_STRING_XHEADER_CONVERSION_STRINGCOPY_H_
#define XUTILS_CONVERSION_CONVERSION_STRING_XHEADER_CONVERSION_STRINGCOPY_H_

#include <xUtils/Standard/Standard.h>

char* CONV_pcStringCopy(char* pcStringDest, const char* pcStringSource, uint32_t u32MaxSize);
void* CONV_pvMemoryCopy(void* pvMemoryDest, const void* pvMemorySource, size_t szLength);

#endif /* XUTILS_CONVERSION_CONVERSION_STRING_XHEADER_CONVERSION_STRINGCOPY_H_ */
