/**
 *
 * @file CDLinkedList_Remove.c
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
 * @verbatim 11 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 11 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */

#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/xHeader/CDLinkedList_Remove.h>

#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/Intrinsics/CDLinkedList_Intrinsics.h>

CDLinkedList_nSTATUS CDLinkedList__enRemoveInList_GetData(CDLinkedList_t* pstList, CDLinkedListItem_t* pstItem, void** pvData)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedList_nSTATUS enStatusRead = CDLinkedList_enSTATUS_ERROR;
    CDLinkedListItem_t* pstItemNextNode = (CDLinkedListItem_t*) 0UL ;
    CDLinkedListItem_t* pstItemPreviousNode = (CDLinkedListItem_t*) 0UL ;
    CDLinkedListItem_t* pstHeadItem = (CDLinkedListItem_t*) 0UL ;
    CDLinkedListItem_t* pstTailItem = (CDLinkedListItem_t*) 0UL ;
    uint32_t u32SizeReg = 0UL;

    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        u32SizeReg = CDLinkedList__u32GetSize(pstList);
        if(((uint32_t) 0UL != (uint32_t) pstItem) && (0UL != u32SizeReg))
        {
            enStatus = CDLinkedList_enSTATUS_OK;
            if(0UL != (uint32_t) pvData)
            {
                *pvData = CDLinkedList_Item__pvGetData(pstItem);
            }

            pstHeadItem = CDLinkedList__pstGetHead(pstList);
            pstTailItem = CDLinkedList__pstGetTail(pstList);

            pstItemNextNode = CDLinkedList_Item__pstGetNextItem(pstItem);
            pstItemPreviousNode = CDLinkedList_Item__pstGetPreviousItem(pstItem);

            if((uint32_t) pstHeadItem == (uint32_t) pstTailItem)/*Last Item*/
            {
                CDLinkedList__vSetTail(pstList, (CDLinkedListItem_t*) 0UL);
                CDLinkedList__vSetHead(pstList, (CDLinkedListItem_t*) 0UL);
                CDLinkedList__vSetLastItemRead(pstList, (CDLinkedListItem_t*) 0UL);
            }
            else
            {
                if((uint32_t) pstHeadItem == (uint32_t) pstItem)
                {
                    CDLinkedList__vSetHead(pstList, pstItemNextNode);
                }
                if((uint32_t) pstTailItem == (uint32_t) pstItem)
                {
                    CDLinkedList__vSetTail(pstList, pstItemPreviousNode);
                }
                CDLinkedList_Item__vSetNextItem(pstItemPreviousNode, pstItemNextNode);
                CDLinkedList_Item__vSetPreviousItem(pstItemNextNode, pstItemPreviousNode);

                enStatusRead = CDLinkedList__enIsLastItemRead(pstList,pstItem);
                if((uint32_t) CDLinkedList_enSTATUS_OK == (uint32_t) enStatusRead)
                {
                    CDLinkedList__vSetLastItemRead(pstList, pstItemPreviousNode);
                }
            }

            CDLinkedList_Item__vSetOwnerList(pstItem,  (void *) 0UL);
            CDLinkedList_Item__vSetNextItem(pstItem,  (CDLinkedListItem_t *) 0UL);
            CDLinkedList_Item__vSetPreviousItem(pstItem,  (CDLinkedListItem_t *) 0UL);
            if(0UL !=  (uint32_t)  pstList->pvfDestroyItem)
            {
                CDLinkedList_Item__vSetValue(pstItem, 0UL);
                CDLinkedList_Item__vSetData(pstItem,  (void *) 0UL);
                pstList->pvfDestroyItem(pstItem);
                pstItem = (CDLinkedListItem_t*) 0UL;
            }

            u32SizeReg--;
            CDLinkedList__vSetSize(pstList, u32SizeReg);
        }
    }
    return (enStatus);
}

CDLinkedList_nSTATUS CDLinkedList__enRemoveInList(CDLinkedList_t* pstList, CDLinkedListItem_t* pstItem)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    enStatus = CDLinkedList__enRemoveInList_GetData(pstList, pstItem, (void**) 0UL);
    return (enStatus);
}

CDLinkedList_nSTATUS CDLinkedList__enRemove_GetData(CDLinkedListItem_t* pstItem, void** pvData)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedList_t* pstListReg = (CDLinkedList_t*) 0UL;

    if(0UL != (uint32_t) pstItem)
    {
        enStatus = CDLinkedList_enSTATUS_OK;
        pstListReg = (CDLinkedList_t*) CDLinkedList_Item__pvGetOwnerList(pstItem);
        enStatus = CDLinkedList__enRemoveInList_GetData(pstListReg, pstItem, pvData);
    }
    return (enStatus);
}

CDLinkedList_nSTATUS CDLinkedList__enRemove(CDLinkedListItem_t* pstItem)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    enStatus = CDLinkedList__enRemove_GetData(pstItem, (void**) 0UL);
    return (enStatus);
}


CDLinkedList_nSTATUS CDLinkedList__enRemoveNextInList_GetData(CDLinkedList_t* pstList, const CDLinkedListItem_t* pstItem, void** pvData)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedListItem_t* pstItemNextNode = (CDLinkedListItem_t*) 0UL ;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pstItem))
    {
        pstItemNextNode = CDLinkedList_Item__pstGetNextItem(pstItem);
        enStatus = CDLinkedList__enRemoveInList_GetData(pstList, pstItemNextNode, pvData);
    }
    return (enStatus);
}

CDLinkedList_nSTATUS CDLinkedList__enRemoveNextInList(CDLinkedList_t* pstList, const CDLinkedListItem_t* pstItem)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    enStatus = CDLinkedList__enRemoveNextInList_GetData(pstList, pstItem, (void**) 0UL);
    return (enStatus);
}

CDLinkedList_nSTATUS CDLinkedList__enRemoveNext_GetData(const CDLinkedListItem_t* pstItem, void** pvData)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedList_t* pstListReg = (CDLinkedList_t*) 0UL;

    if(0UL != (uint32_t) pstItem)
    {
        enStatus = CDLinkedList_enSTATUS_OK;
        pstListReg = (CDLinkedList_t*) CDLinkedList_Item__pvGetOwnerList(pstItem);
        enStatus = CDLinkedList__enRemoveNextInList_GetData(pstListReg, pstItem, pvData);
    }
    return (enStatus);
}

CDLinkedList_nSTATUS CDLinkedList__enRemoveNext(const CDLinkedListItem_t* pstItem)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    enStatus = CDLinkedList__enRemoveNext_GetData(pstItem, (void**) 0UL);
    return (enStatus);
}

CDLinkedList_nSTATUS CDLinkedList__enRemovePreviousInList_GetData(CDLinkedList_t* pstList, const CDLinkedListItem_t* pstItem, void** pvData)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedListItem_t* pstItemPreviousNode = (CDLinkedListItem_t*) 0UL ;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pstItem))
    {
        pstItemPreviousNode = CDLinkedList_Item__pstGetPreviousItem(pstItem);
        enStatus = CDLinkedList__enRemoveInList_GetData(pstList, pstItemPreviousNode, pvData);
    }
    return (enStatus);
}

CDLinkedList_nSTATUS CDLinkedList__enRemovePreviousInList(CDLinkedList_t* pstList, const CDLinkedListItem_t* pstItem)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    enStatus = CDLinkedList__enRemovePreviousInList_GetData(pstList, pstItem, (void**) 0UL);
    return (enStatus);
}

CDLinkedList_nSTATUS CDLinkedList__enRemovePrevious_GetData(const CDLinkedListItem_t* pstItem, void** pvData)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedList_t* pstListReg = (CDLinkedList_t*) 0UL;

    if(0UL != (uint32_t) pstItem)
    {
        enStatus = CDLinkedList_enSTATUS_OK;
        pstListReg = (CDLinkedList_t*) CDLinkedList_Item__pvGetOwnerList(pstItem);
        enStatus = CDLinkedList__enRemovePreviousInList_GetData(pstListReg, pstItem, pvData);
    }
    return (enStatus);
}

CDLinkedList_nSTATUS CDLinkedList__enRemovePrevious(const CDLinkedListItem_t* pstItem)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    enStatus = CDLinkedList__enRemovePrevious_GetData(pstItem, (void**) 0UL);
    return (enStatus);
}

CDLinkedList_nSTATUS  CDLinkedList__enRemoveTail_GetData(CDLinkedList_t* pstList, void** pvData)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedListItem_t* pstEndItem = (CDLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstEndItem = CDLinkedList__pstGetTail(pstList);
        enStatus = CDLinkedList__enRemoveInList_GetData(pstList, pstEndItem, pvData);
    }
    return (enStatus);
}

CDLinkedList_nSTATUS  CDLinkedList__enRemoveTail(CDLinkedList_t* pstList)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    enStatus = CDLinkedList__enRemoveTail_GetData(pstList, (void**) 0UL);
    return (enStatus);
}

CDLinkedList_nSTATUS  CDLinkedList__enRemoveHead_GetData(CDLinkedList_t* pstList, void** pvData)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedListItem_t* pstBeginItem = (CDLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstBeginItem = CDLinkedList__pstGetHead(pstList);
        enStatus = CDLinkedList__enRemoveInList_GetData(pstList, pstBeginItem, pvData);
    }
    return (enStatus);
}

CDLinkedList_nSTATUS  CDLinkedList__enRemoveHead(CDLinkedList_t* pstList)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    enStatus = CDLinkedList__enRemoveHead_GetData(pstList, (void**) 0UL);
    return (enStatus);
}



CDLinkedList_nSTATUS  CDLinkedList__enRemovePos_GetData(CDLinkedList_t* pstList, uint32_t u32Position, void** pvData)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedListItem_t* pstItem = (CDLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    uint32_t u32SizeForward = 0UL;
    uint32_t u32SizeBackward = 0UL;
    uint32_t u32SizeOptimum = 0UL;
    uint32_t u32Direction = 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        u32SizeList = CDLinkedList__u32GetSize(pstList);
        if(u32Position < u32SizeList)
        {
            if(0UL == u32Position) /*Remove Head*/
            {
                enStatus = CDLinkedList__enRemoveHead_GetData(pstList, pvData);
            }
            else if((uint32_t) u32Position == (uint32_t) (u32SizeList - 1UL)) /*Remove Tail*/
            {
                enStatus = CDLinkedList__enRemoveTail_GetData(pstList, pvData);
            }
            else
            {
                u32SizeBackward = u32SizeList - u32Position;

                u32SizeForward = u32Position;

                if(u32SizeForward > u32SizeBackward)
                {
                    u32SizeOptimum = u32SizeBackward;
                    u32Direction = 1UL;
                }
                else
                {
                    u32SizeOptimum = u32SizeForward;
                    u32Direction = 0UL;
                }

                if(u32Direction == 0UL) /*Forward*/
                {
                    pstItem = CDLinkedList__pstGetHead(pstList);
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = CDLinkedList_Item__pstGetNextItem(pstItem);
                        u32SizeOptimum--;
                    }
                    enStatus = CDLinkedList__enRemoveInList_GetData(pstList, pstItem, pvData);
                }
                else /*Backward*/
                {
                    pstItem = CDLinkedList__pstGetTail(pstList);
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = CDLinkedList_Item__pstGetPreviousItem(pstItem);
                        u32SizeOptimum--;
                    }
                    enStatus = CDLinkedList__enRemoveInList_GetData(pstList, pstItem, pvData);
                }
            }
        }
    }
    return (enStatus);
}

CDLinkedList_nSTATUS  CDLinkedList__enRemovePos(CDLinkedList_t* pstList, uint32_t u32Position)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedListItem_t* pstItem = (CDLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    uint32_t u32SizeForward = 0UL;
    uint32_t u32SizeBackward = 0UL;
    uint32_t u32SizeOptimum = 0UL;
    uint32_t u32Direction = 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        u32SizeList = CDLinkedList__u32GetSize(pstList);
        if(u32Position < u32SizeList)
        {
            if(0UL == u32Position) /*Remove Head*/
            {
                enStatus = CDLinkedList__enRemoveHead(pstList);
            }
            else if((uint32_t) u32Position == (uint32_t) (u32SizeList - 1UL)) /*Remove Tail*/
            {
                enStatus = CDLinkedList__enRemoveTail(pstList);
            }
            else
            {
                u32SizeBackward = u32SizeList - u32Position;

                u32SizeForward = u32Position;

                if(u32SizeForward > u32SizeBackward)
                {
                    u32SizeOptimum = u32SizeBackward;
                    u32Direction = 1UL;
                }
                else
                {
                    u32SizeOptimum = u32SizeForward;
                    u32Direction = 0UL;
                }

                if(u32Direction == 0UL) /*Forward*/
                {
                    pstItem = CDLinkedList__pstGetHead(pstList);
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = CDLinkedList_Item__pstGetNextItem(pstItem);
                        u32SizeOptimum--;
                    }
                    enStatus = CDLinkedList__enRemoveInList(pstList, pstItem);
                }
                else /*Backward*/
                {
                    pstItem = CDLinkedList__pstGetTail(pstList);
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = CDLinkedList_Item__pstGetPreviousItem(pstItem);
                        u32SizeOptimum--;
                    }
                    enStatus = CDLinkedList__enRemoveInList(pstList, pstItem);
                }
            }
        }
    }
    return (enStatus);
}
