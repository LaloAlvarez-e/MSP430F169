/**
 *
 * @file DMA_RegisterDefines_CTL1.h
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
 * @verbatim 6 feb. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 feb. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef DMA_PERIPHERAL_REGISTERDEFINES_HEADER_DMA_REGISTERDEFINES_CTL1_H_
#define DMA_PERIPHERAL_REGISTERDEFINES_HEADER_DMA_REGISTERDEFINES_CTL1_H_

#include "DriverLib/MCU/Header/MCU_Common.h"

/******************************************************************************************
 ************************************ 2 CTL1 *********************************************
 ******************************************************************************************/
/*-----------*/
#define DMA_CTL1_R_ENNMI_BIT ((uint16_t) 0U)

#define DMA_CTL1_ENNMI_MASK ((uint16_t) 0x01U)
#define DMA_CTL1_ENNMI_DIS ((uint16_t) 0x00U)
#define DMA_CTL1_ENNMI_ENA ((uint16_t) 0x01U)

#define DMA_CTL1_R_ENNMI_MASK (DMA_CTL1_ENNMI_MASK << DMA_CTL1_R_ENNMI_BIT)
#define DMA_CTL1_R_ENNMI_DIS (DMA_CTL1_ENNMI_DIS << DMA_CTL1_R_ENNMI_BIT)
#define DMA_CTL1_R_ENNMI_ENA (DMA_CTL1_ENNMI_ENA << DMA_CTL1_R_ENNMI_BIT)
/*-----------*/

/*-----------*/
#define DMA_CTL1_R_ROUNDROBIN_BIT ((uint16_t) 1U)

#define DMA_CTL1_ROUNDROBIN_MASK ((uint16_t) 0x01U)
#define DMA_CTL1_ROUNDROBIN_STATIC ((uint16_t) 0x00U)
#define DMA_CTL1_ROUNDROBIN_ENA ((uint16_t) 0x01U)

#define DMA_CTL1_R_ROUNDROBIN_MASK (DMA_CTL1_ROUNDROBIN_MASK << DMA_CTL1_R_ROUNDROBIN_BIT)
#define DMA_CTL1_R_ROUNDROBIN_STATIC (DMA_CTL1_ROUNDROBIN_STATIC << DMA_CTL1_R_ROUNDROBIN_BIT)
#define DMA_CTL1_R_ROUNDROBIN_ENA (DMA_CTL1_ROUNDROBIN_ENA << DMA_CTL1_R_ROUNDROBIN_BIT)
/*-----------*/

/*-----------*/
#define DMA_CTL1_R_DMAONFETCH_BIT ((uint16_t) 2U)

#define DMA_CTL1_DMAONFETCH_MASK ((uint16_t) 0x01U)
#define DMA_CTL1_DMAONFETCH_IMMENDIATE ((uint16_t) 0x00U)
#define DMA_CTL1_DMAONFETCH_NEXT ((uint16_t) 0x01U)

#define DMA_CTL1_R_DMAONFETCH_MASK (DMA_CTL1_DMAONFETCH_MASK << DMA_CTL1_R_DMAONFETCH_BIT)
#define DMA_CTL1_R_DMAONFETCH_IMMENDIATE (DMA_CTL1_DMAONFETCH_IMMENDIATE << DMA_CTL1_R_DMAONFETCH_BIT)
#define DMA_CTL1_R_DMAONFETCH_NEXT (DMA_CTL1_DMAONFETCH_NEXT << DMA_CTL1_R_DMAONFETCH_BIT)
/*-----------*/


#endif /* DMA_PERIPHERAL_REGISTERDEFINES_HEADER_DMA_REGISTERDEFINES_CTL1_H_ */
