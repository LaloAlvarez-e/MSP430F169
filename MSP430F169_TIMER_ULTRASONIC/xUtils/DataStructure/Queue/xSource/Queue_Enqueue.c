/**
 *
 * @file Queue_Enqueue.c
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
#include <xUtils/DataStructure/Queue/xHeader/Queue_Enqueue.h>
#include <xUtils/DataStructure/LinkedList/SingleLinkedList/xHeader/SLinkedList_Insert.h>

Queue_nSTATUS Queue__enEnqueue(Queue_t* pstQueue, void* pvData)
{
    Queue_nSTATUS enStatus = Queue_enSTATUS_ERROR;
    SLinkedListItem_t* pstNewElement = (SLinkedListItem_t*) 0UL ;
    pstNewElement = SLinkedList__pstInsertAtTail_WithData((SLinkedList_t*) pstQueue, pvData);
    if(0UL != (uint32_t) pstNewElement)
    {
        enStatus = Queue_enSTATUS_OK;
    }
    return enStatus;
}


