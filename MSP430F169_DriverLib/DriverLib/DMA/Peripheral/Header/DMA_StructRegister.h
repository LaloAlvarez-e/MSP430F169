/**
 *
 * @file DMA_StructRegister.h
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

#ifndef DMA_PERIPHERAL_HEADER_DMA_STRUCTREGISTER_H_
#define DMA_PERIPHERAL_HEADER_DMA_STRUCTREGISTER_H_

typedef volatile struct
{
    volatile unsigned short CH0TSEL : 4;
    volatile unsigned short CH1TSEL : 4;
    volatile unsigned short CH2TSEL : 4;
    volatile unsigned short CH3TSEL : 4;
}DMA_CTL0_t;

typedef volatile struct
{
    volatile unsigned short ENNMI : 1;
    volatile unsigned short ROUNDROBIN : 1;
    volatile unsigned short DMAONFETCH : 1;
    volatile const unsigned short reserved1 : 13;
}DMA_CTL1_t;

typedef volatile struct
{
    volatile unsigned short REQ : 1;
    volatile unsigned short ABORT : 1;
    volatile unsigned short IE : 1;
    volatile unsigned short IFG : 1;
    volatile unsigned short EN : 1;
    volatile unsigned short LEVEL : 1;
    volatile unsigned short SRCBYTE : 1;
    volatile unsigned short DSTBYTE : 1;
    volatile unsigned short SRCINCR : 2;
    volatile unsigned short DSTINCR : 2;
    volatile unsigned short DT : 3;
    volatile const unsigned short reserved1 : 1;
}DMA_CH_CTL_t;

typedef volatile struct
{
    volatile unsigned short SA : 16;
}DMA_CH_SA_t;

typedef volatile struct
{
    volatile unsigned short DA : 16;
}DMA_CH_DA_t;

typedef volatile struct
{
    volatile unsigned short SZ : 16;
}DMA_CH_SZ_t;

#endif /* DMA_PERIPHERAL_HEADER_DMA_STRUCTREGISTER_H_ */
