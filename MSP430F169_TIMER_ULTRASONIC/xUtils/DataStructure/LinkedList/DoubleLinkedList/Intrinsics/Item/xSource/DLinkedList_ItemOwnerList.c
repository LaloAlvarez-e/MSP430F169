/**
 *
 * @file DLinkedList_ItemOwnerList.c
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
 * @verbatim 13 jul. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 13 jul. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/Item/xHeader/DLinkedList_ItemOwnerList.h>

void* DLinkedList_Item__pvGetOwnerList(const DLinkedListItem_t* const pstItem)
{
    void* pvOwnerListReg = (void*) 0UL;
    pvOwnerListReg = pstItem->pvOwnerList;
    return (pvOwnerListReg);
}

void DLinkedList_Item__vSetOwnerList(DLinkedListItem_t* pstItem, void* pvOwnerListArg)
{
    if(0UL != (uint32_t) pstItem)
    {
        pstItem->pvOwnerList = pvOwnerListArg;
    }
}
