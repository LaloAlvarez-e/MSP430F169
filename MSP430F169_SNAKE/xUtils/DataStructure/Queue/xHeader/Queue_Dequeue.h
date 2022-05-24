/**
 *
 * @file Queue_Dequeue.h
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
#ifndef XUTILS_DATASTRUCTURE_QUEUE_XHEADER_QUEUE_DEQUEUE_H_
#define XUTILS_DATASTRUCTURE_QUEUE_XHEADER_QUEUE_DEQUEUE_H_

#include <xUtils/DataStructure/Queue/xHeader/Queue_Struct.h>

Queue_nSTATUS Queue__enDequeue(Queue_t* pstQueue, void** pvData);

#endif /* XUTILS_DATASTRUCTURE_QUEUE_XHEADER_QUEUE_DEQUEUE_H_ */
