/**
 *
 * @file ADC12_StructPeripheral.h
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
 * @verbatim 5 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 5 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef ADC12_PERIPHERAL_HEADER_ADC12_STRUCTPERIPHERAL_H_
#define ADC12_PERIPHERAL_HEADER_ADC12_STRUCTPERIPHERAL_H_

#include "DriverLib/ADC12/Peripheral/Header/ADC12_StructRegister.h"

typedef volatile struct
{
    union
    {
        volatile unsigned char CH_CTL[16U];
        ADC12_CH_CTL_t CH_CTL_bits[16U];
    };
    const unsigned char reserved1[176U];
    union
    {
        volatile unsigned short CH_MEM[16U];
        ADC12_CH_MEM_t CH_MEM_bits[16U];
    };
    const unsigned char reserved2[64U];
    union
    {
        volatile unsigned short CTL0;
        ADC12_CTL0_t CTL0_bits;
    };
    union
    {
        volatile unsigned short CTL1;
        ADC12_CTL1_t CTL1_bits;
    };
    union
    {
        volatile unsigned short IFG;
        ADC12_IFG_t IFG_bits;
    };
    union
    {
        volatile unsigned short IE;
        ADC12_IE_t IE_bits;
    };
    union
    {
        volatile unsigned short IV;
        ADC12_IV_t IV_bits;
    };
}ADC12_t;


typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        ADC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[191U];
    union
    {
        volatile unsigned short MEM;
        ADC12_CH_MEM_t MEM_bits;
    };
}ADC12_CH0_t;


typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        ADC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[192U];
    union
    {
        volatile unsigned short MEM;
        ADC12_CH_MEM_t MEM_bits;
    };
}ADC12_CH1_t;
typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        ADC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[193U];
    union
    {
        volatile unsigned short MEM;
        ADC12_CH_MEM_t MEM_bits;
    };
}ADC12_CH2_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        ADC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[194U];
    union
    {
        volatile unsigned short MEM;
        ADC12_CH_MEM_t MEM_bits;
    };
}ADC12_CH3_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        ADC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[195U];
    union
    {
        volatile unsigned short MEM;
        ADC12_CH_MEM_t MEM_bits;
    };
}ADC12_CH4_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        ADC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[196U];
    union
    {
        volatile unsigned short MEM;
        ADC12_CH_MEM_t MEM_bits;
    };
}ADC12_CH5_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        ADC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[197U];
    union
    {
        volatile unsigned short MEM;
        ADC12_CH_MEM_t MEM_bits;
    };
}ADC12_CH6_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        ADC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[198U];
    union
    {
        volatile unsigned short MEM;
        ADC12_CH_MEM_t MEM_bits;
    };
}ADC12_CH7_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        ADC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[199U];
    union
    {
        volatile unsigned short MEM;
        ADC12_CH_MEM_t MEM_bits;
    };
}ADC12_CH8_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        ADC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[200U];
    union
    {
        volatile unsigned short MEM;
        ADC12_CH_MEM_t MEM_bits;
    };
}ADC12_CH9_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        ADC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[201U];
    union
    {
        volatile unsigned short MEM;
        ADC12_CH_MEM_t MEM_bits;
    };
}ADC12_CH10_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        ADC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[202U];
    union
    {
        volatile unsigned short MEM;
        ADC12_CH_MEM_t MEM_bits;
    };
}ADC12_CH11_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        ADC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[203U];
    union
    {
        volatile unsigned short MEM;
        ADC12_CH_MEM_t MEM_bits;
    };
}ADC12_CH12_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        ADC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[204U];
    union
    {
        volatile unsigned short MEM;
        ADC12_CH_MEM_t MEM_bits;
    };
}ADC12_CH13_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        ADC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[205U];
    union
    {
        volatile unsigned short MEM;
        ADC12_CH_MEM_t MEM_bits;
    };
}ADC12_CH14_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        ADC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[206U];
    union
    {
        volatile unsigned short MEM;
        ADC12_CH_MEM_t MEM_bits;
    };
}ADC12_CH15_t;

#endif /* ADC12_PERIPHERAL_HEADER_ADC12_STRUCTPERIPHERAL_H_ */
