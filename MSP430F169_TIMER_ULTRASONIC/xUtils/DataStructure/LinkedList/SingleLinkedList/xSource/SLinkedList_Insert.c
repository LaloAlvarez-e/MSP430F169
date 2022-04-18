/**
 *
 * @file SLinkedList_Insert.c
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
#include <xUtils/DataStructure/LinkedList/SingleLinkedList/xHeader/SLinkedList_Insert.h>

#include <stdlib.h>
#include <xUtils/DataStructure/LinkedList/SingleLinkedList/Intrinsics/SLinkedList_Intrinsics.h>

#define DATA_UPDATE (0UL)
#define DATA_STATIC (1UL)

SLinkedList_nSTATUS SLinkedList__enInsertNextGeneric(SLinkedList_t* pstList,
                                            SLinkedListItem_t* pstPreviousItemArg,
                                            SLinkedListItem_t* pstNewItem,
                                            void* pvData,
                                            uint32_t u32DataUpdate);

SLinkedList_nSTATUS SLinkedList__enInsertNextGeneric(SLinkedList_t* pstList,
                                            SLinkedListItem_t* pstPreviousItemArg,
                                            SLinkedListItem_t* pstNewItem,
                                            void* pvData,
                                            uint32_t u32DataUpdate)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    SLinkedListItem_t* pstListHeadItem = (SLinkedListItem_t*) 0UL ;
    SLinkedListItem_t* pstItemNextNode = (SLinkedListItem_t*) 0UL ;
    uint32_t u32SizeReg = 0U;

    if((0UL != (uint32_t) pstList) || (0UL != (uint32_t) pstPreviousItemArg))
    {
        enStatus = SLinkedList_enSTATUS_OK;
        if(DATA_UPDATE == u32DataUpdate)
        {
            SLinkedList_Item__vSetData(pstNewItem, pvData);
        }
        SLinkedList_Item__vSetOwnerList(pstNewItem, (void*) pstList);

        u32SizeReg = SLinkedList__u32GetSize(pstList);
        if(0UL == (uint32_t) pstPreviousItemArg)
        {
            if(0UL == u32SizeReg)
            {
                SLinkedList__vSetTail(pstList, pstNewItem);
            }
            pstListHeadItem = SLinkedList__pstGetHead(pstList);
            SLinkedList_Item__vSetNextItem(pstNewItem, pstListHeadItem);
            SLinkedList__vSetHead(pstList, pstNewItem);
        }
        else
        {
            pstItemNextNode = SLinkedList_Item__pstGetNextItem(pstPreviousItemArg);
            if((uint32_t) 0UL == (uint32_t) pstItemNextNode)
            {
                SLinkedList__vSetTail(pstList, pstNewItem);
            }
            SLinkedList_Item__vSetNextItem(pstNewItem, pstItemNextNode);
            SLinkedList_Item__vSetNextItem(pstPreviousItemArg, pstNewItem);
        }
        u32SizeReg++;
        SLinkedList__vSetSize(pstList, u32SizeReg);
    }
    return (enStatus);
}


SLinkedList_nSTATUS SLinkedList__enInsertNext_WithData(SLinkedList_t* pstList,
                                            SLinkedListItem_t* pstPreviousItemArg,
                                            SLinkedListItem_t* pstNewItem,
                                            void* pvData)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    enStatus = SLinkedList__enInsertNextGeneric(pstList, pstPreviousItemArg, pstNewItem, pvData, DATA_UPDATE);
    return (enStatus);
}

SLinkedList_nSTATUS SLinkedList__enInsertNext(SLinkedList_t* pstList,
                                            SLinkedListItem_t* pstPreviousItemArg,
                                            SLinkedListItem_t* pstNewItem)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    enStatus = SLinkedList__enInsertNextGeneric(pstList, pstPreviousItemArg, pstNewItem, (void*) 0UL, DATA_STATIC);
    return (enStatus);
}

SLinkedListItem_t* SLinkedList__pstInsertNext_WithData(SLinkedList_t* pstList,
                                                    SLinkedListItem_t* pstPreviousItemArg,
                                                    void* pvData)
{
     SLinkedListItem_t* pstNewItem = (SLinkedListItem_t*) 0UL ;
     if(((uint32_t) 0UL != (uint32_t) pstList))
     {
    #if defined (__TI_ARM__ )
         pstNewItem = (SLinkedListItem_t*) memalign((size_t) 4, (size_t) sizeof(SLinkedListItem_t));
    #elif defined (__GNUC__ )
         pstNewItem = (SLinkedListItem_t*) malloc(sizeof(SLinkedListItem_t));
    #endif
         SLinkedList__enInsertNext_WithData(pstList, pstPreviousItemArg, pstNewItem, pvData);
    }
    return (pstNewItem);
}

SLinkedListItem_t* SLinkedList__pstInsertNext(SLinkedList_t* pstList,
                                                    SLinkedListItem_t* pstPreviousItemArg)
{
     SLinkedListItem_t* pstNewItem = (SLinkedListItem_t*) 0UL ;
     pstNewItem = SLinkedList__pstInsertNext_WithData(pstList, pstPreviousItemArg, (void*)0UL);
     if(((uint32_t) 0UL != (uint32_t) pstList))
     {
    #if defined (__TI_ARM__ )
         pstNewItem = (SLinkedListItem_t*) memalign((size_t) 4, (size_t) sizeof(SLinkedListItem_t));
    #elif defined (__GNUC__ )
         pstNewItem = (SLinkedListItem_t*) malloc(sizeof(SLinkedListItem_t));
    #endif
         SLinkedList__enInsertNext(pstList, pstPreviousItemArg, pstNewItem);
    }
    return (pstNewItem);
}


SLinkedList_nSTATUS  SLinkedList__enInsertNextLastItemRead_WithData(SLinkedList_t* pstList,
                                           SLinkedListItem_t* pstNewItem,
                                           void* pvData)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    SLinkedListItem_t* pstLastItemItem = (SLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = SLinkedList__pstGetLastItemRead(pstList);
        enStatus = SLinkedList__enInsertNext_WithData(pstList, pstLastItemItem, pstNewItem, pvData);
    }
    return (enStatus);
}

SLinkedList_nSTATUS  SLinkedList__enInsertNextLastItemRead(SLinkedList_t* pstList,
                                           SLinkedListItem_t* pstNewItem)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    SLinkedListItem_t* pstLastItemItem = (SLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = SLinkedList__pstGetLastItemRead(pstList);
        enStatus = SLinkedList__enInsertNext(pstList, pstLastItemItem, pstNewItem);
    }
    return (enStatus);
}

SLinkedListItem_t*  SLinkedList__pstInsertNextLastItemRead_WithData(SLinkedList_t* pstList, void* pvData)
{
    SLinkedListItem_t* pstNewItem = (SLinkedListItem_t*) 0UL ;
    SLinkedListItem_t* pstLastItemItem = (SLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = SLinkedList__pstGetLastItemRead(pstList);
        pstNewItem = SLinkedList__pstInsertNext_WithData(pstList, pstLastItemItem, pvData);
    }
    return (pstNewItem);
}

SLinkedListItem_t*  SLinkedList__pstInsertNextLastItemRead(SLinkedList_t* pstList)
{
    SLinkedListItem_t* pstNewItem = (SLinkedListItem_t*) 0UL ;
    SLinkedListItem_t* pstLastItemItem = (SLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = SLinkedList__pstGetLastItemRead(pstList);
        pstNewItem = SLinkedList__pstInsertNext(pstList, pstLastItemItem);
    }
    return (pstNewItem);
}


SLinkedList_nSTATUS SLinkedList__enInsertAtTail_WithData(SLinkedList_t* pstList,
                                            SLinkedListItem_t* pstNewItem,
                                            void* pvData)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    SLinkedListItem_t* pstEndItem = (SLinkedListItem_t*) 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstEndItem = SLinkedList__pstGetTail(pstList);
        enStatus = SLinkedList__enInsertNext_WithData(pstList, pstEndItem, pstNewItem, pvData);
    }
    return (enStatus);
}

SLinkedList_nSTATUS SLinkedList__enInsertAtTail(SLinkedList_t* pstList,
                                            SLinkedListItem_t* pstNewItem)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    SLinkedListItem_t* pstEndItem = (SLinkedListItem_t*) 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstEndItem = SLinkedList__pstGetTail(pstList);
        enStatus = SLinkedList__enInsertNext(pstList, pstEndItem, pstNewItem);
    }
    return (enStatus);
}

SLinkedListItem_t* SLinkedList__pstInsertAtTail_WithData(SLinkedList_t* pstList,
                                                   void* pvData)
{
    SLinkedListItem_t* pstNewItem = (SLinkedListItem_t*) 0UL ;
    SLinkedListItem_t* pstEndItem = (SLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstEndItem = SLinkedList__pstGetTail(pstList);
        pstNewItem = SLinkedList__pstInsertNext_WithData(pstList, pstEndItem, pvData);
    }
    return (pstNewItem);
}

SLinkedListItem_t* SLinkedList__pstInsertAtTail(SLinkedList_t* pstList)
{
    SLinkedListItem_t* pstNewItem = (SLinkedListItem_t*) 0UL ;
    SLinkedListItem_t* pstEndItem = (SLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstEndItem = SLinkedList__pstGetTail(pstList);
        pstNewItem = SLinkedList__pstInsertNext(pstList, pstEndItem);
    }
    return (pstNewItem);
}

SLinkedList_nSTATUS SLinkedList__enInsertAtHead_WithData(SLinkedList_t* pstList,
                                                SLinkedListItem_t* pstNewItem,
                                                void* pvData)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;

    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        enStatus = SLinkedList__enInsertNext_WithData(pstList, (SLinkedListItem_t*) 0UL, pstNewItem, pvData);
    }
    return (enStatus);
}

SLinkedList_nSTATUS SLinkedList__enInsertAtHead(SLinkedList_t* pstList,
                                                SLinkedListItem_t* pstNewItem)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;

    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        enStatus = SLinkedList__enInsertNext(pstList, (SLinkedListItem_t*) 0UL, pstNewItem);
    }
    return (enStatus);
}

SLinkedListItem_t*  SLinkedList__pstInsertAtHead_WithData(SLinkedList_t* pstList,
                                                      void* pvData)
{
    SLinkedListItem_t* pstNewItem = (SLinkedListItem_t*) 0UL ;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstNewItem = SLinkedList__pstInsertNext_WithData(pstList, (SLinkedListItem_t*) 0UL, pvData);
    }
    return (pstNewItem);
}

SLinkedListItem_t*  SLinkedList__pstInsertAtHead(SLinkedList_t* pstList)
{
    SLinkedListItem_t* pstNewItem = (SLinkedListItem_t*) 0UL ;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstNewItem = SLinkedList__pstInsertNext(pstList, (SLinkedListItem_t*) 0UL);
    }
    return (pstNewItem);
}

SLinkedList_nSTATUS SLinkedList__enInsertPos_WithData(SLinkedList_t* pstList,
                                            SLinkedListItem_t* pstNewItem,
                                            uint32_t u32Position,
                                            void* pvData)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    SLinkedListItem_t* pstItem = (SLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeList = SLinkedList__u32GetSize(pstList);
        if(u32Position <= u32SizeList)
        {
            if(0UL == u32Position)
            {
                enStatus = SLinkedList__enInsertAtHead_WithData(pstList, pstNewItem, pvData);
            }
            else if((u32SizeList) == u32Position)
            {
                enStatus = SLinkedList__enInsertAtTail_WithData(pstList, pstNewItem, pvData);
            }
            else
            {
                pstItem = SLinkedList__pstGetHead(pstList);
                u32Position--;
                while(0UL != u32Position)
                {
                    pstItem = SLinkedList_Item__pstGetNextItem(pstItem);
                    u32Position--;
                }
                enStatus = SLinkedList__enInsertNext_WithData(pstList, pstItem, pstNewItem, pvData);
            }
        }
    }
    return (enStatus);
}

SLinkedList_nSTATUS SLinkedList__enInsertPos(SLinkedList_t* pstList,
                                            SLinkedListItem_t* pstNewItem,
                                            uint32_t u32Position)
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    SLinkedListItem_t* pstItem = (SLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeList = SLinkedList__u32GetSize(pstList);
        if(u32Position <= u32SizeList)
        {
            if(0UL == u32Position)
            {
                enStatus = SLinkedList__enInsertAtHead(pstList, pstNewItem);
            }
            else if((u32SizeList) == u32Position)
            {
                enStatus = SLinkedList__enInsertAtTail(pstList, pstNewItem);
            }
            else
            {
                pstItem = SLinkedList__pstGetHead(pstList);
                u32Position--;
                while(0UL != u32Position)
                {
                    pstItem = SLinkedList_Item__pstGetNextItem(pstItem);
                    u32Position--;
                }
                enStatus = SLinkedList__enInsertNext(pstList, pstItem, pstNewItem);
            }
        }
    }
    return (enStatus);
}

SLinkedListItem_t*  SLinkedList__pstInsertPos_WithData(SLinkedList_t* pstList,
                                                    uint32_t u32Position,
                                                    void* pvData)
{
    SLinkedListItem_t* pstNewItem = (SLinkedListItem_t*) 0UL ;
    SLinkedListItem_t* pstItem = (SLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeList = SLinkedList__u32GetSize(pstList);
        if(u32Position <= u32SizeList)
        {
            if(0UL == u32Position)
            {
                pstNewItem = SLinkedList__pstInsertAtHead_WithData(pstList, pvData);
            }
            else if((u32SizeList) == u32Position)
            {
                pstNewItem = SLinkedList__pstInsertAtTail_WithData(pstList, pvData);
            }
            else
            {
                pstItem = SLinkedList__pstGetHead(pstList);
                u32Position--;
                while(0UL != u32Position)
                {
                    pstItem = SLinkedList_Item__pstGetNextItem(pstItem);
                    u32Position--;
                }
                pstNewItem = SLinkedList__pstInsertNext_WithData(pstList, pstItem, pvData);
            }
        }
    }
    return (pstNewItem);
}

SLinkedListItem_t*  SLinkedList__pstInsertPos(SLinkedList_t* pstList,
                                                    uint32_t u32Position)
{
    SLinkedListItem_t* pstNewItem = (SLinkedListItem_t*) 0UL ;
    SLinkedListItem_t* pstItem = (SLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeList = SLinkedList__u32GetSize(pstList);
        if(u32Position <= u32SizeList)
        {
            if(0UL == u32Position)
            {
                pstNewItem = SLinkedList__pstInsertAtHead(pstList);
            }
            else if((u32SizeList) == u32Position)
            {
                pstNewItem = SLinkedList__pstInsertAtTail(pstList);
            }
            else
            {
                pstItem = SLinkedList__pstGetHead(pstList);
                u32Position--;
                while(0UL != u32Position)
                {
                    pstItem = SLinkedList_Item__pstGetNextItem(pstItem);
                    u32Position--;
                }
                pstNewItem = SLinkedList__pstInsertNext(pstList, pstItem);
            }
        }
    }
    return (pstNewItem);
}
