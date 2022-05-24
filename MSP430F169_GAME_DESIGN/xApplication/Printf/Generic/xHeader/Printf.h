/*
 * PRINTF.h
 *
 *  Created on: 15 may. 2020
 *      Author: vyldram
 */

#ifndef HEADER_APP_PRINTF_H_
#define HEADER_APP_PRINTF_H_

#include <xUtils/Standard/Standard.h>
#include <stdarg.h>
#include <xUtils/Conversion/Conversion_Number2String/Conversion_Primitives/xHeader/Conversion_Wrapper.h>

/* internal conv flag definitions*/
uint32_t vsnprintf__u32UserGeneric(CONV_OUT_t pvfOut, char* pcBuffer, const uint32_t u32MaxLength, const char* pcFormat, va_list vaList);
uint32_t printf__u32User(const char* pcFormat, ...);
uint32_t sprintf__u32User(char* pcBuffer, const char* pcFormat, ...);
uint32_t  snprintf__u32User(char* pcBuffer, uint32_t u32Count, const char* pcFormat, ...);
uint32_t vprintf__u32User(const char* pcFormat, va_list vaList);
uint32_t vsprintf__u32User(char* pcBuffer, const char* pcFormat, va_list vaList);
uint32_t vsnprintf__u32User(char* pcBuffer, const uint32_t u32Count, const char* pcFormat, va_list vaList);
uint32_t fctprintf__u32User(void (*pvfFunctionOut)(char cCharacter, void* pvPrintArguments), void* pvPrintArguments, const char* pcFormat, ...);

#endif /* HEADER_APP_PRINTF_H_ */
