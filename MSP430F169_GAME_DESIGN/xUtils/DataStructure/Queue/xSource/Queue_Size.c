/**
 *
 * @file Queue_Size.c
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
#include <xUtils/DataStructure/Queue/xHeader/Queue_Size.h>
#include <xUtils/DataStructure/LinkedList/SingleLinkedList/Intrinsics/List/xHeader/SLinkedList_Size.h>

uint32_t Queue__u32GetSize(const Queue_t* const pstQueue)
{
    return SLinkedList__u32GetSize((const SLinkedList_t*) pstQueue);
}

Queue_nSTATUS Queue__enIsEmpty(const Queue_t* const pstQueue)
{
    Queue_nSTATUS enStatus = Queue_enSTATUS_ERROR;
    uint32_t u32SizeReg = 0UL;
    u32SizeReg = SLinkedList__u32GetSize((const SLinkedList_t*) pstQueue);

    if(u32SizeReg == 0UL)
    {
        enStatus = Queue_enSTATUS_OK;
    }

    return enStatus;
}


