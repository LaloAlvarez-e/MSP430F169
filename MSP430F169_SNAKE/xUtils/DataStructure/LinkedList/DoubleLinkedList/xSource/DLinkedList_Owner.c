/**
 *
 * @file DLinkedList_Owner.c
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
 * @verbatim 14 jul. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 14 jul. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/xHeader/DLinkedList_Owner.h>

#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/DLinkedList_Intrinsics.h>

DLinkedList_nSTATUS DLinkedList__enIsItemOwnerList(const DLinkedList_t* pstList, const DLinkedListItem_t* const pstItem)
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    DLinkedList_t* pstOwnerListItem = (DLinkedList_t*) 0UL;
    pstOwnerListItem = (DLinkedList_t*) DLinkedList_Item__pvGetOwnerList(pstItem);
    if((uint32_t) pstOwnerListItem == (uint32_t) pstList )
    {
        enStatus = DLinkedList_enSTATUS_OK;
    }
    return (enStatus);
}

