/**
 *
 * @file Queue_Peek.c
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
#include <xUtils/DataStructure/Queue/xHeader/Queue_Peek.h>
#include <xUtils/DataStructure/LinkedList/SingleLinkedList/xHeader/SLinkedList_Data.h>
#include <xUtils/DataStructure/LinkedList/SingleLinkedList/xHeader/SLinkedList_Item.h>

void * Queue__pvPeek(const Queue_t* pstQueue)
{
    return SLinkedList__pvGetDataHead((const SLinkedList_t*)pstQueue);
}

uint32_t Queue__u32GetNMember(const Queue_t* pstQueue, void** pvData, uint32_t u32Members, uint32_t u32MaxSize)
{
    uint32_t u32SizeReg = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstQueue) && ((uint32_t) 0UL != (uint32_t) pvData ) && (0UL != u32Members ) && (0UL != u32MaxSize ))
    {
        u32SizeReg = SLinkedList__u32GetNItem((const SLinkedList_t*)pstQueue, pvData, u32Members, u32MaxSize);
    }
    return u32SizeReg;
}

uint32_t Queue__u32GetAllMember(const Queue_t* pstQueue, void** pvData, uint32_t u32MaxSize)
{
    uint32_t u32SizeReg = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstQueue) && ((uint32_t) 0UL != (uint32_t) pvData ) && ((uint32_t) 0UL != u32MaxSize ))
    {
        u32SizeReg = SLinkedList__u32GetAllItem((const SLinkedList_t*)pstQueue, pvData, u32MaxSize);
    }
    return u32SizeReg;
}

