/**
 *
 * @file SLinkedList_Remove.c
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
 * @verbatim 6 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */

#include <xUtils/DataStructure/LinkedList/SingleLinkedList/xHeader/SLinkedList_Remove.h>

#include <xUtils/DataStructure/LinkedList/SingleLinkedList/Intrinsics/SLinkedList_Intrinsics.h>

#define REMOVE_NEXT (1UL)
#define REMOVE_CURRENT (0UL)

static SLinkedList_nSTATUS SLinkedList__enRemoveGeneric(SLinkedList_t* pstList, SLinkedListItem_t* pstItem, void** pvData, uint32_t u32Remove);

static SLinkedList_nSTATUS SLinkedList__enRemoveGeneric(SLinkedList_t* pstList, SLinkedListItem_t* pstItem, void** pvData, uint32_t u32Remove)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    SLinkedList_nSTATUS enStatusRead = SLinkedList_enSTATUS_ERROR;
    SLinkedListItem_t* pstItemToRemove = (SLinkedListItem_t*) 0UL ;
    SLinkedListItem_t* pstHeadNextItem = (SLinkedListItem_t*) 0UL ;
    SLinkedListItem_t* pstHeadData = (SLinkedListItem_t*) 0UL ;
    SLinkedListItem_t* pstItemNextItem = (SLinkedListItem_t*) 0UL ;
    SLinkedListItem_t* pstItemNextNextItem = (SLinkedListItem_t*) 0UL ;
    void* pstItemNextItemData = (void*) 0UL ;
    uint32_t u32ItemNextItemValue = 0UL ;
    void* pstItemNextItemOwner = (void*) 0UL ;

    void* pstItemItemData = (void*) 0UL ;

    void* pstItemDataTemp = (void*) 0UL ;

    uint32_t u32SizeReg = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeReg = SLinkedList__u32GetSize(pstList);
        if(0UL != u32SizeReg)
        {
            if((uint32_t) 0UL == (uint32_t) pstItem)
            {
                enStatus = SLinkedList_enSTATUS_OK;
                pstHeadData = SLinkedList__pstGetHead(pstList);
                pstItemDataTemp = SLinkedList_Item__pvGetData(pstHeadData);
                pstItemToRemove = pstHeadData;
                pstHeadNextItem = SLinkedList_Item__pstGetNextItem(pstItemToRemove);
                SLinkedList__vSetHead(pstList, pstHeadNextItem);
                if(1UL == u32SizeReg)
                {
                    SLinkedList__vSetTail(pstList, (SLinkedListItem_t*)0UL);
                }

                enStatusRead = SLinkedList__enIsLastItemRead(pstList,pstItemToRemove);
                if((uint32_t) SLinkedList_enSTATUS_OK == (uint32_t) enStatusRead)
                {
                    SLinkedList__vSetLastItemRead(pstList, pstHeadNextItem);
                }
            }
            else
            {
                pstItemNextItem = SLinkedList_Item__pstGetNextItem(pstItem);
                if((uint32_t) 0UL != (uint32_t) pstItemNextItem)
                {
                    enStatus = SLinkedList_enSTATUS_OK;

                    pstItemNextItemData = SLinkedList_Item__pvGetData(pstItemNextItem);
                    u32ItemNextItemValue = SLinkedList_Item__u32GetValue(pstItemNextItem);
                    pstItemNextItemOwner = SLinkedList_Item__pvGetOwnerList(pstItemNextItem);

                    if(REMOVE_CURRENT == u32Remove)
                    {
                        pstItemItemData = SLinkedList_Item__pvGetData(pstItem);

                        SLinkedList_Item__vSetData(pstItem, pstItemNextItemData);
                        SLinkedList_Item__vSetValue(pstItem, u32ItemNextItemValue);
                        SLinkedList_Item__vSetOwnerList(pstItem, pstItemNextItemOwner);

                        pstItemDataTemp = pstItemItemData;
                    }
                    else
                    {
                        pstItemDataTemp = pstItemNextItemData;
                    }

                    pstItemToRemove = pstItemNextItem;
                    pstItemNextNextItem = SLinkedList_Item__pstGetNextItem(pstItemToRemove);

                    SLinkedList_Item__vSetNextItem(pstItem, pstItemNextNextItem);

                    if((uint32_t) 0UL == (uint32_t) pstItemToRemove)
                    {
                        SLinkedList__vSetTail(pstList, (SLinkedListItem_t*)pstItem);
                    }

                    enStatusRead = SLinkedList__enIsLastItemRead(pstList,pstItemToRemove);
                    if((uint32_t) SLinkedList_enSTATUS_OK == (uint32_t) enStatusRead)
                    {
                        SLinkedList__vSetLastItemRead(pstList, pstItem);
                    }
                }
            }

            if(SLinkedList_enSTATUS_OK == enStatus)
            {
                if(0UL != (uint32_t) pvData)
                {
                    *pvData = pstItemDataTemp;
                }

                SLinkedList_Item__vSetOwnerList(pstItemToRemove,  (void *) 0UL);
                SLinkedList_Item__vSetNextItem(pstItemToRemove,  (SLinkedListItem_t *) 0UL);
                if(0UL !=  (uint32_t)  pstList->pvfDestroyItem)
                {
                    SLinkedList_Item__vSetValue(pstItemToRemove, 0UL);
                    SLinkedList_Item__vSetData(pstItemToRemove,  (void *) 0UL);
                    pstList->pvfDestroyItem(pstItemToRemove);
                    pstItemToRemove = (SLinkedListItem_t*) 0UL;
                }

                u32SizeReg--;
                SLinkedList__vSetSize(pstList, u32SizeReg);
            }
        }
    }
    return (enStatus);
}

SLinkedList_nSTATUS SLinkedList__enRemoveNextInList_GetData(SLinkedList_t* pstList, SLinkedListItem_t* pstItem, void** pvData)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    enStatus = SLinkedList__enRemoveGeneric(pstList, pstItem, pvData, REMOVE_NEXT);
    return (enStatus);
}

SLinkedList_nSTATUS SLinkedList__enRemoveNextInList(SLinkedList_t* pstList, SLinkedListItem_t* pstItem)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    enStatus = SLinkedList__enRemoveNextInList_GetData(pstList, pstItem, (void**) 0UL);
    return (enStatus);
}

SLinkedList_nSTATUS SLinkedList__enRemoveNext_GetData(SLinkedListItem_t* pstItem, void** pvData)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    SLinkedList_t* pstListReg = (SLinkedList_t*) 0UL;

    if(0UL != (uint32_t) pstItem)
    {
        enStatus = SLinkedList_enSTATUS_OK;
        pstListReg = (SLinkedList_t*) SLinkedList_Item__pvGetOwnerList(pstItem);
        enStatus = SLinkedList__enRemoveNextInList_GetData(pstListReg, pstItem, pvData);
    }
    return (enStatus);
}

SLinkedList_nSTATUS SLinkedList__enRemoveNext(SLinkedListItem_t* pstItem)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    enStatus = SLinkedList__enRemoveNext_GetData(pstItem, (void**) 0UL);
    return (enStatus);
}



SLinkedList_nSTATUS SLinkedList__enRemoveInList_GetData(SLinkedList_t* pstList, SLinkedListItem_t* pstItem, void** pvData)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    enStatus = SLinkedList__enRemoveGeneric(pstList, pstItem, pvData, REMOVE_CURRENT);
    return (enStatus);
}

SLinkedList_nSTATUS SLinkedList__enRemoveInList(SLinkedList_t* pstList, SLinkedListItem_t* pstItem)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    enStatus = SLinkedList__enRemoveInList_GetData(pstList, pstItem, (void**) 0UL);
    return (enStatus);
}

SLinkedList_nSTATUS SLinkedList__enRemove_GetData(SLinkedListItem_t* pstItem, void** pvData)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    SLinkedList_t* pstListReg = (SLinkedList_t*) 0UL;

    if(0UL != (uint32_t) pstItem)
    {
        enStatus = SLinkedList_enSTATUS_OK;
        pstListReg = (SLinkedList_t*) SLinkedList_Item__pvGetOwnerList(pstItem);
        enStatus = SLinkedList__enRemoveInList_GetData(pstListReg, pstItem, pvData);
    }
    return (enStatus);
}

SLinkedList_nSTATUS SLinkedList__enRemove(SLinkedListItem_t* pstItem)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    enStatus = SLinkedList__enRemove_GetData(pstItem, (void**) 0UL);
    return (enStatus);
}


SLinkedList_nSTATUS  SLinkedList__enRemoveTail_GetData(SLinkedList_t* pstList, void** pvData)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    SLinkedListItem_t* pstEndItem = (SLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        u32SizeList = SLinkedList__u32GetSize(pstList);
        if(1UL <  u32SizeList)
        {
            u32SizeList--;
            pstEndItem = SLinkedList__pstGetHead(pstList);
            u32SizeList--;
            while(0UL != u32SizeList)
            {
                pstEndItem = SLinkedList_Item__pstGetNextItem(pstEndItem);
                u32SizeList--;
            }
        }
        enStatus = SLinkedList__enRemoveNextInList_GetData(pstList, pstEndItem, pvData);
    }
    return (enStatus);
}

SLinkedList_nSTATUS  SLinkedList__enRemoveTail(SLinkedList_t* pstList)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    enStatus = SLinkedList__enRemoveTail_GetData(pstList, (void**) 0UL);
    return (enStatus);
}


SLinkedList_nSTATUS  SLinkedList__enRemoveHead_GetData(SLinkedList_t* pstList, void** pvData)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        enStatus = SLinkedList__enRemoveNextInList_GetData(pstList, (SLinkedListItem_t*) 0UL, pvData);
    }
    return (enStatus);
}

SLinkedList_nSTATUS  SLinkedList__enRemoveHead(SLinkedList_t* pstList)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    enStatus = SLinkedList__enRemoveHead_GetData(pstList, (void**) 0UL);
    return (enStatus);
}

SLinkedList_nSTATUS  SLinkedList__enRemovePos_GetData(SLinkedList_t* pstList, uint32_t u32Position, void** pvData)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    SLinkedListItem_t* pstItem = (SLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        u32SizeList = SLinkedList__u32GetSize(pstList);
        if(u32Position < u32SizeList)
        {
            if(0UL != u32Position)
            {
                pstItem = SLinkedList__pstGetHead(pstList);
                u32Position--;
                while(0UL != u32Position)
                {
                    pstItem = SLinkedList_Item__pstGetNextItem(pstItem);
                    u32Position--;
                }
            }
            enStatus = SLinkedList__enRemoveNextInList_GetData(pstList, pstItem, pvData);
        }
    }
    return (enStatus);
}

SLinkedList_nSTATUS  SLinkedList__enRemovePos(SLinkedList_t* pstList, uint32_t u32Position)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    enStatus = SLinkedList__enRemovePos_GetData(pstList, u32Position, (void**) 0UL);
    return (enStatus);
}
