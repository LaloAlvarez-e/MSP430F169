/**
 *
 * @file Queue_Peek.h
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
 * @verbatim 13 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 13 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#ifndef XUTILS_DATASTRUCTURE_QUEUE_XHEADER_QUEUE_PEEK_H_
#define XUTILS_DATASTRUCTURE_QUEUE_XHEADER_QUEUE_PEEK_H_

#include <xUtils/DataStructure/Queue/xHeader/Queue_Struct.h>

uint32_t Queue__u32GetNMember(const Queue_t* pstQueue, void** pvData, uint32_t u32Members, uint32_t u32MaxSize);
uint32_t Queue__u32GetAllMember(const Queue_t* pstQueue, void** pvData, uint32_t u32MaxSize);
void * Queue__pvPeek(const Queue_t* pstQueue);

#endif /* XUTILS_DATASTRUCTURE_QUEUE_XHEADER_QUEUE_PEEK_H_ */
