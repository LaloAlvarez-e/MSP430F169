/**
 *
 * @file DLinkedList_Reverse.c
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
 * @verbatim 8 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 8 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/xHeader/DLinkedList_Reverse.h>

#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/DLinkedList_Intrinsics.h>

DLinkedList_nSTATUS DLinkedList__enReverse(DLinkedList_t* pstList)
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    DLinkedListItem_t* pstNextItemReg = (DLinkedListItem_t*) 0UL ;
    DLinkedListItem_t* pstNextNextNode = (DLinkedListItem_t*) 0UL ;
    DLinkedListItem_t* pstNextPreviousNode = (DLinkedListItem_t*) 0UL ;
    DLinkedListItem_t* pstItem = (DLinkedListItem_t*) 0UL ;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstItem = DLinkedList__pstGetHead(pstList);
        DLinkedList__vSetTail(pstList, pstItem);
        if((uint32_t) 0UL != (uint32_t) pstItem)
        {
            pstNextItemReg = DLinkedList_Item__pstGetNextItem(pstItem);
            if((uint32_t) 0UL != (uint32_t) pstNextItemReg)
            {
                enStatus = DLinkedList_enSTATUS_OK;
                DLinkedList_Item__vSetNextItem(pstItem, (DLinkedListItem_t*)0UL);
                DLinkedList_Item__vSetPreviousItem(pstItem, pstNextItemReg);

                while((uint32_t) 0UL != (uint32_t) pstNextItemReg)
                {
                    pstNextNextNode = DLinkedList_Item__pstGetNextItem(pstNextItemReg);
                    DLinkedList_Item__vSetPreviousItem(pstNextItemReg, pstNextNextNode);
                    DLinkedList_Item__vSetNextItem(pstNextItemReg, pstItem);
                    pstNextPreviousNode = DLinkedList_Item__pstGetPreviousItem(pstNextItemReg);

                    pstItem = pstNextItemReg;
                    pstNextItemReg = pstNextPreviousNode;
                }
                DLinkedList__vSetHead(pstList, pstItem);
            }
        }
    }
    return (enStatus);
}



