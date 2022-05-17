/**
 *
 * @file CSLinkedList_Remove.c
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
 * @verbatim 10 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 10 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/xHeader/CSLinkedList_Remove.h>

#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/Intrinsics/CSLinkedList_Intrinsics.h>

CSLinkedList_nSTATUS CSLinkedList__enRemoveNextInList_GetData(CSLinkedList_t* pstList, CSLinkedListItem_t* pstItem, void** pvData)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    CSLinkedList_nSTATUS enStatusRead = CSLinkedList_enSTATUS_ERROR;
    CSLinkedListItem_t* pstItemToRemove = (CSLinkedListItem_t*) 0UL ;
    CSLinkedListItem_t* pstTailItem = (CSLinkedListItem_t*) 0UL ;
    CSLinkedListItem_t* pstHeadItem = (CSLinkedListItem_t*) 0UL ;
    CSLinkedListItem_t* pstItemNextItem = (CSLinkedListItem_t*) 0UL ;
    CSLinkedListItem_t* pstItemToRemoveNextItem = (CSLinkedListItem_t*) 0UL ;
    uint32_t u32SizeReg = 0UL;

    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        u32SizeReg = CSLinkedList__u32GetSize(pstList);
        if(0UL != u32SizeReg)
        {
            enStatus = CSLinkedList_enSTATUS_OK;
            if((uint32_t) 0UL == (uint32_t) pstItem) /* Remove Head*/
            {
                pstItem = CSLinkedList__pstGetTail(pstList);
            }

            pstItemNextItem = CSLinkedList_Item__pstGetNextItem(pstItem);
            if(0UL != (uint32_t) pvData)
            {
                *pvData = CSLinkedList_Item__pvGetData(pstItemNextItem);
            }
            pstItemToRemove = pstItemNextItem;

            if((uint32_t) pstItem == (uint32_t) pstItemToRemove) /*Remove Last item*/
            {
                CSLinkedList__vSetTail(pstList, (CSLinkedListItem_t*)0UL);
                CSLinkedList__vSetHead(pstList, (CSLinkedListItem_t*)0UL);
                CSLinkedList__vSetLastItemRead(pstList, (CSLinkedListItem_t*) 0UL);
            }
            else
            {
                pstItemToRemoveNextItem = CSLinkedList_Item__pstGetNextItem(pstItemToRemove);
                CSLinkedList_Item__vSetNextItem(pstItem, pstItemToRemoveNextItem);

                pstHeadItem = CSLinkedList__pstGetHead(pstList);
                pstTailItem = CSLinkedList__pstGetTail(pstList);
                if((uint32_t) pstItemToRemove == (uint32_t) pstHeadItem)
                {
                    CSLinkedList__vSetHead(pstList, pstItemToRemoveNextItem);
                }
                if((uint32_t) pstItemToRemove == (uint32_t) pstTailItem)
                {
                    CSLinkedList__vSetTail(pstList, pstItem);
                }

                enStatusRead = CSLinkedList__enIsLastItemRead(pstList,pstItemToRemove);
                if((uint32_t) CSLinkedList_enSTATUS_OK == (uint32_t) enStatusRead)
                {
                    CSLinkedList__vSetLastItemRead(pstList, pstItem);
                }
            }

            CSLinkedList_Item__vSetOwnerList(pstItemToRemove,  (void *) 0UL);
            CSLinkedList_Item__vSetNextItem(pstItemToRemove,  (CSLinkedListItem_t *) 0UL);
            if(0UL !=  (uint32_t)  pstList->pvfDestroyItem)
            {
                CSLinkedList_Item__vSetValue(pstItemToRemove, 0UL);
                CSLinkedList_Item__vSetData(pstItemToRemove,  (void *) 0UL);
                pstList->pvfDestroyItem(pstItemToRemove);
                pstItemToRemove = (CSLinkedListItem_t*) 0UL;
            }

            u32SizeReg--;
            CSLinkedList__vSetSize(pstList, u32SizeReg);
        }
    }
    return (enStatus);
}

CSLinkedList_nSTATUS CSLinkedList__enRemoveNextInList(CSLinkedList_t* pstList, CSLinkedListItem_t* pstItem)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    enStatus = CSLinkedList__enRemoveNextInList_GetData(pstList, pstItem, (void**) 0UL);
    return (enStatus);
}

CSLinkedList_nSTATUS CSLinkedList__enRemoveNext_GetData(CSLinkedListItem_t* pstItem, void** pvData)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    CSLinkedList_t* pstListReg = (CSLinkedList_t*) 0UL;

    if(0UL != (uint32_t) pstItem)
    {
        enStatus = CSLinkedList_enSTATUS_OK;
        pstListReg = (CSLinkedList_t*) CSLinkedList_Item__pvGetOwnerList(pstItem);
        enStatus = CSLinkedList__enRemoveNextInList_GetData(pstListReg, pstItem, pvData);
    }
    return (enStatus);
}

CSLinkedList_nSTATUS CSLinkedList__enRemoveNext(CSLinkedListItem_t* pstItem)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    enStatus = CSLinkedList__enRemoveNext_GetData(pstItem, (void**) 0UL);
    return (enStatus);
}

CSLinkedList_nSTATUS CSLinkedList__enRemoveInList_GetData(CSLinkedList_t* pstList, CSLinkedListItem_t* pstItem, void** pvData)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    CSLinkedList_nSTATUS enStatusRead = CSLinkedList_enSTATUS_ERROR;
    CSLinkedListItem_t* pstItemToRemove = (CSLinkedListItem_t*) 0UL ;
    CSLinkedListItem_t* pstHeadNextItem = (CSLinkedListItem_t*) 0UL ;
    CSLinkedListItem_t* pstHeadItem = (CSLinkedListItem_t*) 0UL ;
    CSLinkedListItem_t* pstTailItem = (CSLinkedListItem_t*) 0UL ;
    CSLinkedListItem_t* pstItemNextItem = (CSLinkedListItem_t*) 0UL ;
    CSLinkedListItem_t* pstItemNextNextItem = (CSLinkedListItem_t*) 0UL ;
    void* pstItemNextItemData = (void*) 0UL ;
    void* pstItemNextOwnerList = (void*) 0UL;
    uint32_t u32ItemNextItemValue = 0UL ;
    void* pstItemItemData = (void*) 0UL ;
    uint32_t u32ItemItemValue = 0UL ;
    uint32_t u32SizeReg = 0UL;

    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        u32SizeReg = CSLinkedList__u32GetSize(pstList);
        if(0UL != u32SizeReg)
        {
            if((uint32_t) 0UL == (uint32_t) pstItem)
            {
                enStatus = CSLinkedList_enSTATUS_OK;
                pstHeadItem = CSLinkedList__pstGetHead(pstList);

                pstHeadNextItem = CSLinkedList_Item__pstGetNextItem(pstHeadItem);
                if(0UL != (uint32_t) pvData)
                {
                    *pvData = CSLinkedList_Item__pvGetData(pstHeadItem);
                }
                pstItemToRemove = pstHeadItem;

                if((uint32_t) pstItemToRemove == (uint32_t) pstHeadNextItem) /*Remove Last item*/
                {
                    CSLinkedList__vSetHead(pstList, (CSLinkedListItem_t*) 0UL);
                    CSLinkedList__vSetTail(pstList, (CSLinkedListItem_t*) 0UL);
                    CSLinkedList__vSetLastItemRead(pstList,  (CSLinkedListItem_t*) 0UL);
                }
                else
                {
                    pstTailItem = CSLinkedList__pstGetTail(pstList);
                    CSLinkedList__vSetHead(pstList, pstHeadNextItem);
                    CSLinkedList_Item__vSetNextItem(pstTailItem, pstHeadNextItem);

                    enStatusRead = CSLinkedList__enIsLastItemRead(pstList,pstItemToRemove);
                    if((uint32_t) CSLinkedList_enSTATUS_OK == (uint32_t) enStatusRead)
                    {
                        CSLinkedList__vSetLastItemRead(pstList, pstTailItem);
                    }
                }

            }
            else
            {
                pstTailItem = CSLinkedList__pstGetTail(pstList);
                if(((uint32_t) pstItem != (uint32_t) pstTailItem) || (1UL == u32SizeReg))
                {
                    enStatus = CSLinkedList_enSTATUS_OK;

                    pstItemNextItem = CSLinkedList_Item__pstGetNextItem(pstItem);

                    pstItemNextItemData = CSLinkedList_Item__pvGetData(pstItemNextItem);
                    u32ItemNextItemValue = CSLinkedList_Item__u32GetValue(pstItemNextItem);
                    pstItemNextOwnerList = CSLinkedList_Item__pvGetOwnerList(pstItemNextItem);

                    pstItemItemData = CSLinkedList_Item__pvGetData(pstItem);
                    u32ItemItemValue = CSLinkedList_Item__u32GetValue(pstItem);

                    if(0UL != (uint32_t) pvData)
                    {
                        *pvData = pstItemItemData;
                    }
                    pstItemToRemove = pstItemNextItem;

                    pstItemNextNextItem = CSLinkedList_Item__pstGetNextItem(pstItemNextItem);
                    if((uint32_t) pstItemNextItem == (uint32_t) pstItemNextNextItem) /*Last node*/
                    {
                        CSLinkedList__vSetHead(pstList, (CSLinkedListItem_t*) 0UL);
                        CSLinkedList__vSetTail(pstList, (CSLinkedListItem_t*) 0UL);
                        CSLinkedList__vSetLastItemRead(pstList,  (CSLinkedListItem_t*) 0UL);
                    }
                    else
                    {
                        CSLinkedList_Item__vSetNextItem(pstItem, pstItemNextNextItem);
                        CSLinkedList_Item__vSetData(pstItem, pstItemNextItemData);
                        CSLinkedList_Item__vSetValue(pstItem, u32ItemNextItemValue);
                        CSLinkedList_Item__vSetOwnerList(pstItem, pstItemNextOwnerList);

                        CSLinkedList_Item__vSetValue(pstItemToRemove, u32ItemItemValue);
                        CSLinkedList_Item__vSetData(pstItemToRemove, pstItemItemData);

                        if((uint32_t) pstTailItem == (uint32_t) pstItemNextItem)
                        {
                            CSLinkedList__vSetTail(pstList, pstItem);
                        }


                        enStatusRead = CSLinkedList__enIsLastItemRead(pstList,pstItemToRemove);
                        if((uint32_t) CSLinkedList_enSTATUS_OK == (uint32_t) enStatusRead)
                        {
                            CSLinkedList__vSetLastItemRead(pstList, pstItem);
                        }
                    }
                }
            }

            if(CSLinkedList_enSTATUS_OK == enStatus)
            {
                CSLinkedList_Item__vSetOwnerList(pstItemToRemove,  (void *) 0UL);
                CSLinkedList_Item__vSetNextItem(pstItemToRemove,  (CSLinkedListItem_t *) 0UL);
                if(0UL !=  (uint32_t)  pstList->pvfDestroyItem)
                {
                    CSLinkedList_Item__vSetValue(pstItemToRemove, 0UL);
                    CSLinkedList_Item__vSetData(pstItemToRemove,  (void *) 0UL);
                    pstList->pvfDestroyItem(pstItemToRemove);
                    pstItemToRemove = (CSLinkedListItem_t*) 0UL;
                }

                u32SizeReg--;
                CSLinkedList__vSetSize(pstList, u32SizeReg);
            }
        }
    }
    return (enStatus);
}

CSLinkedList_nSTATUS CSLinkedList__enRemoveInList(CSLinkedList_t* pstList, CSLinkedListItem_t* pstItem)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    enStatus = CSLinkedList__enRemoveInList_GetData(pstList, pstItem, (void**) 0UL);
    return (enStatus);
}

CSLinkedList_nSTATUS CSLinkedList__enRemove_GetData(CSLinkedListItem_t* pstItem, void** pvData)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    CSLinkedList_t* pstListReg = (CSLinkedList_t*) 0UL;

    if(0UL != (uint32_t) pstItem)
    {
        enStatus = CSLinkedList_enSTATUS_OK;
        pstListReg = (CSLinkedList_t*) CSLinkedList_Item__pvGetOwnerList(pstItem);
        enStatus = CSLinkedList__enRemoveInList_GetData(pstListReg, pstItem, pvData);
    }
    return (enStatus);
}

CSLinkedList_nSTATUS CSLinkedList__enRemove(CSLinkedListItem_t* pstItem)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    enStatus = CSLinkedList__enRemove_GetData(pstItem, (void**) 0UL);
    return (enStatus);
}

CSLinkedList_nSTATUS  CSLinkedList__enRemoveTail_GetData(CSLinkedList_t* pstList, void** pvData)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    CSLinkedListItem_t* pstEndItem = (CSLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        u32SizeList = CSLinkedList__u32GetSize(pstList);
        if(1UL <  u32SizeList)
        {
            u32SizeList--;
            pstEndItem = CSLinkedList__pstGetHead(pstList);
            u32SizeList--;
            while(0UL != u32SizeList)
            {
                pstEndItem = CSLinkedList_Item__pstGetNextItem(pstEndItem);
                u32SizeList--;
            }
        }
        enStatus = CSLinkedList__enRemoveNextInList_GetData(pstList, pstEndItem, pvData);
    }
    return (enStatus);
}

CSLinkedList_nSTATUS  CSLinkedList__enRemoveTail(CSLinkedList_t* pstList)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    enStatus = CSLinkedList__enRemoveTail_GetData(pstList, (void**) 0UL);
    return (enStatus);
}

CSLinkedList_nSTATUS  CSLinkedList__enRemoveHead_GetData(CSLinkedList_t* pstList, void** pvData)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        enStatus = CSLinkedList__enRemoveNextInList_GetData(pstList, (CSLinkedListItem_t*) 0UL, pvData);
    }
    return (enStatus);
}

CSLinkedList_nSTATUS  CSLinkedList__enRemoveHead(CSLinkedList_t* pstList)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    enStatus = CSLinkedList__enRemoveHead_GetData(pstList, (void**) 0UL);
    return (enStatus);
}

CSLinkedList_nSTATUS  CSLinkedList__enRemovePos_GetData(CSLinkedList_t* pstList, uint32_t u32Position, void** pvData)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    CSLinkedListItem_t* pstItem = (CSLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        u32SizeList = CSLinkedList__u32GetSize(pstList);
        if(u32Position < u32SizeList)
        {
            if(0UL != u32Position)
            {
                pstItem = CSLinkedList__pstGetHead(pstList);
                u32Position--;
                while(0UL != u32Position)
                {
                    pstItem = CSLinkedList_Item__pstGetNextItem(pstItem);
                    u32Position--;
                }
            }
            enStatus = CSLinkedList__enRemoveNextInList_GetData(pstList, pstItem, pvData);
        }
    }
    return (enStatus);
}

CSLinkedList_nSTATUS  CSLinkedList__enRemovePos(CSLinkedList_t* pstList, uint32_t u32Position)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    enStatus = CSLinkedList__enRemovePos_GetData(pstList, u32Position, (void**) 0UL);
    return (enStatus);
}
