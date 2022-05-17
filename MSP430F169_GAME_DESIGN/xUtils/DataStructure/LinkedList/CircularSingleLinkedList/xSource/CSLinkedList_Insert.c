/**
 *
 * @file CSLinkedList_Insert.c
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
 * @verbatim 9 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/xHeader/CSLinkedList_Insert.h>

#include <stdlib.h>
#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/Intrinsics/CSLinkedList_Intrinsics.h>

#define DATA_UPDATE (0UL)
#define DATA_STATIC (1UL)

static CSLinkedList_nSTATUS CSLinkedList__enInsertNextGeneric(CSLinkedList_t* pstList,
                                             CSLinkedListItem_t* pstPreviousItem,
                                             CSLinkedListItem_t* pstNewItem,
                                             void* pvData,
                                             uint32_t u32DataUpdate);

static CSLinkedList_nSTATUS CSLinkedList__enInsertNextGeneric(CSLinkedList_t* pstList,
                                             CSLinkedListItem_t* pstPreviousItem,
                                             CSLinkedListItem_t* pstNewItem,
                                             void* pvData,
                                             uint32_t u32DataUpdate)
{
    CSLinkedList_nSTATUS enStatusReturn = CSLinkedList_enSTATUS_ERROR;
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    CSLinkedListItem_t* pstNextItemReg = (CSLinkedListItem_t*) 0UL ;
    CSLinkedListItem_t* pstNewItem1 = (CSLinkedListItem_t*) 0UL ;
    CSLinkedListItem_t* pstListHeadItem = (CSLinkedListItem_t*) 0UL ;
    CSLinkedListItem_t* pstListTailItem = (CSLinkedListItem_t*) 0UL ;
    uint32_t u32SizeReg = 0U;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        if((uint32_t) 0UL != (uint32_t) pstNewItem)
        {
            enStatusReturn = CSLinkedList_enSTATUS_OK;
            if(DATA_UPDATE == u32DataUpdate)
            {
                CSLinkedList_Item__vSetData(pstNewItem, pvData);
            }
            CSLinkedList_Item__vSetOwnerList(pstNewItem, (void*) pstList);

            u32SizeReg = CSLinkedList__u32GetSize(pstList);
            if(0UL == u32SizeReg) /*Empty List*/
            {
                pstNewItem1 = pstNewItem;
                CSLinkedList_Item__vSetNextItem(pstNewItem, pstNewItem1);
                CSLinkedList__vSetHead(pstList, pstNewItem);
                CSLinkedList__vSetTail(pstList, pstNewItem);
            }
            else if((uint32_t) 0UL == (uint32_t) pstPreviousItem) /*Insert to head*/
            {
                pstListTailItem = CSLinkedList__pstGetTail(pstList);
                pstListHeadItem = CSLinkedList__pstGetHead(pstList);
                CSLinkedList_Item__vSetNextItem(pstNewItem, pstListHeadItem);
                CSLinkedList_Item__vSetNextItem(pstListTailItem, pstNewItem);
                CSLinkedList__vSetHead(pstList, pstNewItem);
            }
            else /*Insert beetween nodes*/
            {
                enStatus = CSLinkedList__enIsTail(pstList, pstPreviousItem);
                if((uint32_t) CSLinkedList_enSTATUS_OK == (uint32_t) enStatus)
                {
                    CSLinkedList__vSetTail(pstList, pstNewItem);
                }
                pstNextItemReg = CSLinkedList_Item__pstGetNextItem(pstPreviousItem);
                CSLinkedList_Item__vSetNextItem(pstNewItem, pstNextItemReg);
                CSLinkedList_Item__vSetNextItem(pstPreviousItem, pstNewItem);
            }
            u32SizeReg++;
            CSLinkedList__vSetSize(pstList, u32SizeReg);
        }
    }
    return(enStatusReturn);
}

CSLinkedList_nSTATUS CSLinkedList__enInsertNext_WithData(CSLinkedList_t* pstList,
                                            CSLinkedListItem_t* pstItem,
                                            CSLinkedListItem_t* pstNewItem,
                                            void* pvData)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    enStatus = CSLinkedList__enInsertNextGeneric(pstList, pstItem, pstNewItem, pvData, DATA_UPDATE);
    return (enStatus);
}

CSLinkedList_nSTATUS CSLinkedList__enInsertNext(CSLinkedList_t* pstList,
                                            CSLinkedListItem_t* pstItem,
                                            CSLinkedListItem_t* pstNewItem)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    enStatus = CSLinkedList__enInsertNextGeneric(pstList, pstItem, pstNewItem, (void*) 0UL, DATA_STATIC);
    return (enStatus);
}



CSLinkedListItem_t* CSLinkedList__pstInsertNext_WithData(CSLinkedList_t* pstList, CSLinkedListItem_t* pstItem, void* pvData)
{
    CSLinkedListItem_t* pstNewItem = (CSLinkedListItem_t*) 0UL ;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        #if defined (__TI_ARM__ )
        pstNewItem = (CSLinkedListItem_t*) memalign((size_t) 4, (size_t) sizeof(CSLinkedListItem_t));
        #elif defined (__GNUC__ )
        pstNewItem = (CSLinkedListItem_t*) malloc(sizeof(CSLinkedListItem_t));
        #endif
        CSLinkedList__enInsertNext_WithData(pstList, pstItem,  pstNewItem, pvData);
    }
    return (pstNewItem);
}

CSLinkedListItem_t* CSLinkedList__pstInsertNext(CSLinkedList_t* pstList, CSLinkedListItem_t* pstItem)
{
    CSLinkedListItem_t* pstNewItem = (CSLinkedListItem_t*) 0UL ;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        #if defined (__TI_ARM__ )
        pstNewItem = (CSLinkedListItem_t*) memalign((size_t) 4, (size_t) sizeof(CSLinkedListItem_t));
        #elif defined (__GNUC__ )
        pstNewItem = (CSLinkedListItem_t*) malloc(sizeof(CSLinkedListItem_t));
        #endif
        CSLinkedList__enInsertNext(pstList, pstItem,  pstNewItem);
    }
    return (pstNewItem);
}


CSLinkedList_nSTATUS  CSLinkedList__enInsertNextLastItemRead_WithData(CSLinkedList_t* pstList,
                                           CSLinkedListItem_t* pstNewItem,
                                           void* pvData)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    CSLinkedListItem_t* pstLastItemItem = (CSLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = CSLinkedList__pstGetLastItemRead(pstList);
        enStatus = CSLinkedList__enInsertNext_WithData(pstList, pstLastItemItem, pstNewItem, pvData);
    }
    return (enStatus);
}

CSLinkedList_nSTATUS  CSLinkedList__enInsertNextLastItemRead(CSLinkedList_t* pstList,
                                           CSLinkedListItem_t* pstNewItem)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    CSLinkedListItem_t* pstLastItemItem = (CSLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = CSLinkedList__pstGetLastItemRead(pstList);
        enStatus = CSLinkedList__enInsertNext(pstList, pstLastItemItem, pstNewItem);
    }
    return (enStatus);
}

CSLinkedListItem_t*  CSLinkedList__pstInsertNextLastItemRead_WithData(CSLinkedList_t* pstList, void* pvData)
{
    CSLinkedListItem_t* pstNewItem = (CSLinkedListItem_t*) 0UL ;
    CSLinkedListItem_t* pstLastItemItem = (CSLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = CSLinkedList__pstGetLastItemRead(pstList);
        pstNewItem = CSLinkedList__pstInsertNext_WithData(pstList, pstLastItemItem, pvData);
    }
    return (pstNewItem);
}

CSLinkedListItem_t*  CSLinkedList__pstInsertNextLastItemRead(CSLinkedList_t* pstList)
{
    CSLinkedListItem_t* pstNewItem = (CSLinkedListItem_t*) 0UL ;
    CSLinkedListItem_t* pstLastItemItem = (CSLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = CSLinkedList__pstGetLastItemRead(pstList);
        pstNewItem = CSLinkedList__pstInsertNext(pstList, pstLastItemItem);
    }
    return (pstNewItem);
}

CSLinkedList_nSTATUS CSLinkedList__enInsertAtTail_WithData(CSLinkedList_t* pstList,
                                           CSLinkedListItem_t* pstNewItem,
                                            void* pvData)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    CSLinkedListItem_t* pstEndItem = (CSLinkedListItem_t*) 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstEndItem = CSLinkedList__pstGetTail(pstList);
        enStatus = CSLinkedList__enInsertNext_WithData(pstList, pstEndItem, pstNewItem, pvData);
    }
    return (enStatus);
}

CSLinkedList_nSTATUS CSLinkedList__enInsertAtTail(CSLinkedList_t* pstList,
                                           CSLinkedListItem_t* pstNewItem)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    CSLinkedListItem_t* pstEndItem = (CSLinkedListItem_t*) 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstEndItem = CSLinkedList__pstGetTail(pstList);
        enStatus = CSLinkedList__enInsertNext(pstList, pstEndItem, pstNewItem);
    }
    return (enStatus);
}


CSLinkedListItem_t*  CSLinkedList__pstInsertAtTail_WithData(CSLinkedList_t* pstList, void* pvData)
{
    CSLinkedListItem_t* pstNewItem = (CSLinkedListItem_t*) 0UL ;
    CSLinkedListItem_t* pstEndItem = (CSLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstEndItem = CSLinkedList__pstGetTail(pstList);
        pstNewItem = CSLinkedList__pstInsertNext_WithData(pstList, pstEndItem, pvData);
    }
    return (pstNewItem);
}

CSLinkedListItem_t*  CSLinkedList__pstInsertAtTail(CSLinkedList_t* pstList)
{
    CSLinkedListItem_t* pstNewItem = (CSLinkedListItem_t*) 0UL ;
    CSLinkedListItem_t* pstEndItem = (CSLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstEndItem = CSLinkedList__pstGetTail(pstList);
        pstNewItem = CSLinkedList__pstInsertNext(pstList, pstEndItem);
    }
    return (pstNewItem);
}

CSLinkedList_nSTATUS CSLinkedList__enInsertAtHead_WithData(CSLinkedList_t* pstList,
                                                CSLinkedListItem_t* pstNewItem,
                                                void* pvData)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;

    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        enStatus = CSLinkedList__enInsertNext_WithData(pstList, (CSLinkedListItem_t*) 0UL, pstNewItem, pvData);
    }
    return (enStatus);
}

CSLinkedList_nSTATUS CSLinkedList__enInsertAtHead(CSLinkedList_t* pstList,
                                                CSLinkedListItem_t* pstNewItem)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;

    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        enStatus = CSLinkedList__enInsertNext(pstList, (CSLinkedListItem_t*) 0UL, pstNewItem);
    }
    return (enStatus);
}

CSLinkedListItem_t*  CSLinkedList__pstInsertAtHead_WithData(CSLinkedList_t* pstList, void* pvData)
{
    CSLinkedListItem_t* pstNewItem = (CSLinkedListItem_t*) 0UL ;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstNewItem = CSLinkedList__pstInsertNext_WithData(pstList, (CSLinkedListItem_t*) 0UL, pvData);
    }
    return (pstNewItem);
}

CSLinkedListItem_t*  CSLinkedList__pstInsertAtHead(CSLinkedList_t* pstList)
{
    CSLinkedListItem_t* pstNewItem = (CSLinkedListItem_t*) 0UL ;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstNewItem = CSLinkedList__pstInsertNext(pstList, (CSLinkedListItem_t*) 0UL);
    }
    return (pstNewItem);
}

CSLinkedList_nSTATUS CSLinkedList__enInsertPos_WithData(CSLinkedList_t* pstList,
                                            CSLinkedListItem_t* pstNewItem,
                                            uint32_t u32Position,
                                            void* pvData)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    CSLinkedListItem_t* pstItem = (CSLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeList = CSLinkedList__u32GetSize(pstList);
        if(u32Position <= u32SizeList)
        {
            if(0UL == u32Position)
            {
                enStatus = CSLinkedList__enInsertAtHead_WithData(pstList, pstNewItem, pvData);
            }
            else if((u32SizeList) == u32Position)
            {
                enStatus = CSLinkedList__enInsertAtTail_WithData(pstList, pstNewItem, pvData);
            }
            else
            {
                pstItem = CSLinkedList__pstGetHead(pstList);
                u32Position--;
                while(0UL != u32Position)
                {
                    pstItem = CSLinkedList_Item__pstGetNextItem(pstItem);
                    u32Position--;
                }
                enStatus = CSLinkedList__enInsertNext_WithData(pstList, pstItem, pstNewItem, pvData);
            }
        }
    }
    return (enStatus);
}

CSLinkedList_nSTATUS CSLinkedList__enInsertPos(CSLinkedList_t* pstList,
                                            CSLinkedListItem_t* pstNewItem,
                                            uint32_t u32Position)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    CSLinkedListItem_t* pstItem = (CSLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeList = CSLinkedList__u32GetSize(pstList);
        if(u32Position <= u32SizeList)
        {
            if(0UL == u32Position)
            {
                enStatus = CSLinkedList__enInsertAtHead(pstList, pstNewItem);
            }
            else if((u32SizeList) == u32Position)
            {
                enStatus = CSLinkedList__enInsertAtTail(pstList, pstNewItem);
            }
            else
            {
                pstItem = CSLinkedList__pstGetHead(pstList);
                u32Position--;
                while(0UL != u32Position)
                {
                    pstItem = CSLinkedList_Item__pstGetNextItem(pstItem);
                    u32Position--;
                }
                enStatus = CSLinkedList__enInsertNext(pstList, pstItem, pstNewItem);
            }
        }
    }
    return (enStatus);
}

CSLinkedListItem_t*  CSLinkedList__pstInsertPos_WithData(CSLinkedList_t* pstList, uint32_t u32Position, void* pvData)
{
    CSLinkedListItem_t* pstNewItem = (CSLinkedListItem_t*) 0UL ;
    CSLinkedListItem_t* pstItem = (CSLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeList = CSLinkedList__u32GetSize(pstList);
        if(u32Position <= u32SizeList)
        {
            if(0UL == u32Position)
            {
                pstNewItem = CSLinkedList__pstInsertAtHead_WithData(pstList, pvData);
            }
            else if (u32Position == u32SizeList)
            {
                pstNewItem = CSLinkedList__pstInsertAtTail_WithData(pstList, pvData);
            }
            else
            {
                pstItem = CSLinkedList__pstGetHead(pstList);
                u32Position--;
                while(0UL != u32Position)
                {
                    pstItem = CSLinkedList_Item__pstGetNextItem(pstItem);
                    u32Position--;
                }
                pstNewItem = CSLinkedList__pstInsertNext_WithData(pstList, pstItem, pvData);
            }
        }
    }
    return (pstNewItem);
}

CSLinkedListItem_t*  CSLinkedList__pstInsertPos(CSLinkedList_t* pstList, uint32_t u32Position)
{
    CSLinkedListItem_t* pstNewItem = (CSLinkedListItem_t*) 0UL ;
    CSLinkedListItem_t* pstItem = (CSLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeList = CSLinkedList__u32GetSize(pstList);
        if(u32Position <= u32SizeList)
        {
            if(0UL == u32Position)
            {
                pstNewItem = CSLinkedList__pstInsertAtHead(pstList);
            }
            else if (u32Position == u32SizeList)
            {
                pstNewItem = CSLinkedList__pstInsertAtTail(pstList);
            }
            else
            {
                pstItem = CSLinkedList__pstGetHead(pstList);
                u32Position--;
                while(0UL != u32Position)
                {
                    pstItem = CSLinkedList_Item__pstGetNextItem(pstItem);
                    u32Position--;
                }
                pstNewItem = CSLinkedList__pstInsertNext(pstList, pstItem);
            }
        }
    }
    return (pstNewItem);
}
