/**
 *
 * @file DAC12_StructPeripheral.h
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

#ifndef DAC12_PERIPHERAL_HEADER_DAC12_STRUCTPERIPHERAL_H_
#define DAC12_PERIPHERAL_HEADER_DAC12_STRUCTPERIPHERAL_H_

#include "DriverLib/DAC12/Peripheral/Header/DAC12_StructRegister.h"

typedef volatile struct
{
    union
    {
        volatile unsigned char CH_CTL[16U];
        DAC12_CH_CTL_t CH_CTL_bits[16U];
    };
    const unsigned char reserved1[176U];
    union
    {
        volatile unsigned short CH_MEM[16U];
        DAC12_CH_MEM_t CH_MEM_bits[16U];
    };
    const unsigned char reserved2[64U];
    union
    {
        volatile unsigned short CTL0;
        DAC12_CTL0_t CTL0_bits;
    };
    union
    {
        volatile unsigned short CTL1;
        DAC12_CTL1_t CTL1_bits;
    };
    union
    {
        volatile unsigned short IFG;
        DAC12_IFG_t IFG_bits;
    };
    union
    {
        volatile unsigned short IE;
        DAC12_IE_t IE_bits;
    };
    union
    {
        volatile unsigned short IV;
        DAC12_IV_t IV_bits;
    };
}DAC12_t;


typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        DAC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[191U];
    union
    {
        volatile unsigned short MEM;
        DAC12_CH_MEM_t MEM_bits;
    };
}DAC12_CH0_t;


typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        DAC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[192U];
    union
    {
        volatile unsigned short MEM;
        DAC12_CH_MEM_t MEM_bits;
    };
}DAC12_CH1_t;
typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        DAC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[193U];
    union
    {
        volatile unsigned short MEM;
        DAC12_CH_MEM_t MEM_bits;
    };
}DAC12_CH2_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        DAC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[194U];
    union
    {
        volatile unsigned short MEM;
        DAC12_CH_MEM_t MEM_bits;
    };
}DAC12_CH3_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        DAC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[195U];
    union
    {
        volatile unsigned short MEM;
        DAC12_CH_MEM_t MEM_bits;
    };
}DAC12_CH4_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        DAC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[196U];
    union
    {
        volatile unsigned short MEM;
        DAC12_CH_MEM_t MEM_bits;
    };
}DAC12_CH5_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        DAC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[197U];
    union
    {
        volatile unsigned short MEM;
        DAC12_CH_MEM_t MEM_bits;
    };
}DAC12_CH6_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        DAC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[198U];
    union
    {
        volatile unsigned short MEM;
        DAC12_CH_MEM_t MEM_bits;
    };
}DAC12_CH7_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        DAC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[199U];
    union
    {
        volatile unsigned short MEM;
        DAC12_CH_MEM_t MEM_bits;
    };
}DAC12_CH8_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        DAC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[200U];
    union
    {
        volatile unsigned short MEM;
        DAC12_CH_MEM_t MEM_bits;
    };
}DAC12_CH9_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        DAC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[201U];
    union
    {
        volatile unsigned short MEM;
        DAC12_CH_MEM_t MEM_bits;
    };
}DAC12_CH10_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        DAC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[202U];
    union
    {
        volatile unsigned short MEM;
        DAC12_CH_MEM_t MEM_bits;
    };
}DAC12_CH11_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        DAC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[203U];
    union
    {
        volatile unsigned short MEM;
        DAC12_CH_MEM_t MEM_bits;
    };
}DAC12_CH12_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        DAC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[204U];
    union
    {
        volatile unsigned short MEM;
        DAC12_CH_MEM_t MEM_bits;
    };
}DAC12_CH13_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        DAC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[205U];
    union
    {
        volatile unsigned short MEM;
        DAC12_CH_MEM_t MEM_bits;
    };
}DAC12_CH14_t;

typedef volatile struct
{
    union
    {
        volatile unsigned char CTL;
        DAC12_CH_CTL_t CTL_bits;
    };
    const unsigned char reserved1[206U];
    union
    {
        volatile unsigned short MEM;
        DAC12_CH_MEM_t MEM_bits;
    };
}DAC12_CH15_t;

#endif /* DAC12_PERIPHERAL_HEADER_DAC12_STRUCTPERIPHERAL_H_ */
