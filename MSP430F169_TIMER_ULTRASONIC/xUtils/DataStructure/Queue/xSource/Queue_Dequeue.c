/**
 *
 * @file Queue_Dequeue.c
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
#include <xUtils/DataStructure/Queue/xHeader/Queue_Dequeue.h>
#include <xUtils/DataStructure/LinkedList/SingleLinkedList/xHeader/SLinkedList_Remove.h>

Queue_nSTATUS Queue__enDequeue(Queue_t* pstQueue, void** pvData)
{
    return (Queue_nSTATUS ) SLinkedList__enRemoveHead_GetData((SLinkedList_t*) pstQueue, pvData);
}



