/**
 *
 * @file DLinkedList_Insert.c
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
#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/xHeader/DLinkedList_Insert.h>

#include <stdlib.h>
#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/DLinkedList_Intrinsics.h>

#define DATA_UPDATE (0UL)
#define DATA_STATIC (1UL)

static DLinkedList_nSTATUS DLinkedList__enInsertNextGeneric(DLinkedList_t* pstList,
                                                   DLinkedListItem_t* pstPreviousItemArg,
                                                   DLinkedListItem_t* pstNewItem,
                                                   void* pvData,
                                                   uint32_t u32DataUpdate);

DLinkedList_nSTATUS DLinkedList__enInsertPreviousGeneric(DLinkedList_t* pstList,
                                                       DLinkedListItem_t* pstNextItemArg,
                                                       DLinkedListItem_t* pstNewItem,
                                                       void* pvData,
                                                       uint32_t u32DataUpdate);

static DLinkedList_nSTATUS DLinkedList__enInsertNextGeneric(DLinkedList_t* pstList,
                                                   DLinkedListItem_t* pstPreviousItemArg,
                                                   DLinkedListItem_t* pstNewItem,
                                                   void* pvData,
                                                   uint32_t u32DataUpdate)
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    DLinkedListItem_t* pstItemNextNode = (DLinkedListItem_t*) 0UL ;
    uint32_t u32SizeReg = 0U;

    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeReg = DLinkedList__u32GetSize(pstList);
        if(((uint32_t) 0UL != (uint32_t) pstPreviousItemArg) || (0UL == u32SizeReg))
        {
            if((uint32_t) 0UL != (uint32_t) pstNewItem)
            {
                enStatus = DLinkedList_enSTATUS_OK;
                if(DATA_UPDATE == u32DataUpdate)
                {
                    DLinkedList_Item__vSetData(pstNewItem, pvData);
                }
                DLinkedList_Item__vSetOwnerList(pstNewItem, (void*) pstList);

                if(0UL == u32SizeReg)
                {
                    DLinkedList__vSetHead(pstList, pstNewItem);

                    DLinkedList_Item__vSetNextItem(pstNewItem, (DLinkedListItem_t*) 0UL );
                    DLinkedList_Item__vSetPreviousItem(pstNewItem, (DLinkedListItem_t*) 0UL );

                    DLinkedList__vSetTail(pstList, pstNewItem);
                }
                else
                {
                    pstItemNextNode = DLinkedList_Item__pstGetNextItem(pstPreviousItemArg);

                    DLinkedList_Item__vSetNextItem(pstNewItem, pstItemNextNode );
                    DLinkedList_Item__vSetPreviousItem(pstNewItem, pstPreviousItemArg);

                    if((uint32_t) 0UL == (uint32_t) pstItemNextNode)
                    {
                        DLinkedList__vSetTail(pstList, pstNewItem);
                    }
                    else
                    {
                        DLinkedList_Item__vSetPreviousItem(pstItemNextNode, pstNewItem);
                    }
                    DLinkedList_Item__vSetNextItem(pstPreviousItemArg, pstNewItem);
                }

                u32SizeReg++;
                DLinkedList__vSetSize(pstList, u32SizeReg);
            }
        }
    }
    return (enStatus);
}


DLinkedList_nSTATUS DLinkedList__enInsertPreviousGeneric(DLinkedList_t* pstList,
                                                       DLinkedListItem_t* pstNextItemArg,
                                                       DLinkedListItem_t* pstNewItem,
                                                       void* pvData,
                                                       uint32_t u32DataUpdate)
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    DLinkedListItem_t* pstItemPreviousNode = (DLinkedListItem_t*) 0UL ;
    uint32_t u32SizeReg = 0U;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeReg = DLinkedList__u32GetSize(pstList);
        if(((uint32_t) 0UL != (uint32_t) pstNextItemArg) || (0UL == u32SizeReg))
        {
           if((uint32_t) 0UL != (uint32_t) pstNewItem)
           {
               enStatus = DLinkedList_enSTATUS_OK;
               if(DATA_UPDATE == u32DataUpdate)
               {
                   DLinkedList_Item__vSetData(pstNewItem, pvData);
               }
               DLinkedList_Item__vSetOwnerList(pstNewItem, (void*) pstList);

               if(0UL == u32SizeReg)
               {
                   DLinkedList__vSetHead(pstList, pstNewItem);

                   DLinkedList_Item__vSetNextItem(pstNewItem, (DLinkedListItem_t*) 0UL );
                   DLinkedList_Item__vSetPreviousItem(pstNewItem, (DLinkedListItem_t*) 0UL );

                   DLinkedList__vSetTail(pstList, pstNewItem);
               }
               else
               {
                   pstItemPreviousNode = DLinkedList_Item__pstGetPreviousItem(pstNextItemArg);

                   DLinkedList_Item__vSetNextItem(pstNewItem, pstNextItemArg );
                   DLinkedList_Item__vSetPreviousItem(pstNewItem, pstItemPreviousNode);

                   if((uint32_t) 0UL == (uint32_t) pstItemPreviousNode)
                   {
                       DLinkedList__vSetHead(pstList, pstNewItem);
                   }
                   else
                   {
                       DLinkedList_Item__vSetNextItem(pstItemPreviousNode, pstNewItem);
                   }
                   DLinkedList_Item__vSetPreviousItem(pstNextItemArg, pstNewItem);
               }
               u32SizeReg++;
               DLinkedList__vSetSize(pstList, u32SizeReg);

               }
       }
   }
   return (enStatus);
}

DLinkedList_nSTATUS DLinkedList__enInsertNext_WithData(DLinkedList_t* pstList,
                                            DLinkedListItem_t* pstPreviousItemArg,
                                            DLinkedListItem_t* pstNewItem,
                                            void* pvData)
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    enStatus = DLinkedList__enInsertNextGeneric(pstList, pstPreviousItemArg, pstNewItem, pvData, DATA_UPDATE);
    return (enStatus);
}

DLinkedList_nSTATUS DLinkedList__enInsertNext(DLinkedList_t* pstList,
                                            DLinkedListItem_t* pstPreviousItemArg,
                                            DLinkedListItem_t* pstNewItem)
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    enStatus = DLinkedList__enInsertNextGeneric(pstList, pstPreviousItemArg, pstNewItem, (void*) 0UL, DATA_STATIC);
    return (enStatus);
}

DLinkedListItem_t* DLinkedList__pstInsertNext_WithData(DLinkedList_t* pstList,
                                             DLinkedListItem_t* pstPreviousItemArg,
                                             void* pvData)
{
    DLinkedListItem_t* pstNewItem = (DLinkedListItem_t*) 0UL ;
    uint32_t u32SizeReg = 0U;

    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeReg = DLinkedList__u32GetSize(pstList);
        if(((uint32_t) 0UL != (uint32_t) pstPreviousItemArg) || (0UL == u32SizeReg))
        {
            #if defined (__TI_ARM__ )
            pstNewItem = (DLinkedListItem_t*) memalign((size_t) 4, (size_t) sizeof(DLinkedListItem_t));
            #elif defined (__GNUC__ )
            pstNewItem = (DLinkedListItem_t*) malloc(sizeof(DLinkedListItem_t));
            #endif

            DLinkedList__enInsertNext_WithData(pstList, pstPreviousItemArg, pstNewItem, pvData);
        }
    }
    return (pstNewItem);
}

DLinkedListItem_t* DLinkedList__pstInsertNext(DLinkedList_t* pstList,
                                             DLinkedListItem_t* pstPreviousItemArg)
{
    DLinkedListItem_t* pstNewItem = (DLinkedListItem_t*) 0UL ;
    uint32_t u32SizeReg = 0U;

    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeReg = DLinkedList__u32GetSize(pstList);
        if(((uint32_t) 0UL != (uint32_t) pstPreviousItemArg) || (0UL == u32SizeReg))
        {
            #if defined (__TI_ARM__ )
            pstNewItem = (DLinkedListItem_t*) memalign((size_t) 4, (size_t) sizeof(DLinkedListItem_t));
            #elif defined (__GNUC__ )
            pstNewItem = (DLinkedListItem_t*) malloc(sizeof(DLinkedListItem_t));
            #endif

            DLinkedList__enInsertNext(pstList, pstPreviousItemArg, pstNewItem);
        }
    }
    return (pstNewItem);
}



DLinkedList_nSTATUS DLinkedList__enInsertPrevious_WithData(DLinkedList_t* pstList,
                                                       DLinkedListItem_t* pstNextItemArg,
                                                       DLinkedListItem_t* pstNewItem,
                                                       void* pvData)
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    enStatus = DLinkedList__enInsertPreviousGeneric(pstList, pstNextItemArg, pstNewItem, pvData, DATA_UPDATE);
    return (enStatus);
}

DLinkedList_nSTATUS DLinkedList__enInsertPrevious(DLinkedList_t* pstList,
                                                       DLinkedListItem_t* pstNextItemArg,
                                                       DLinkedListItem_t* pstNewItem)
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    enStatus = DLinkedList__enInsertPreviousGeneric(pstList, pstNextItemArg, pstNewItem, (void*) 0UL, DATA_STATIC);
    return (enStatus);
}

DLinkedListItem_t* DLinkedList__pstInsertPrevious_WithData(DLinkedList_t* pstList,
                                                        DLinkedListItem_t* pstNextItemArg,
                                                        void* pvData)
{
    DLinkedListItem_t* pstNewItem = (DLinkedListItem_t*) 0UL ;
    uint32_t u32SizeReg = 0U;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeReg = DLinkedList__u32GetSize(pstList);
        if(((uint32_t) 0UL != (uint32_t) pstNextItemArg) || (0UL == u32SizeReg))
        {
            #if defined (__TI_ARM__ )
            pstNewItem = (DLinkedListItem_t*) memalign((size_t) 4, (size_t) sizeof(DLinkedListItem_t));
            #elif defined (__GNUC__ )
            pstNewItem = (DLinkedListItem_t*) malloc(sizeof(DLinkedListItem_t));
            #endif

            DLinkedList__enInsertPrevious_WithData(pstList, pstNextItemArg, pstNewItem, pvData);
        }
    }
    return (pstNewItem);
}

DLinkedListItem_t* DLinkedList__pstInsertPrevious(DLinkedList_t* pstList,
                                                        DLinkedListItem_t* pstNextItemArg)
{
    DLinkedListItem_t* pstNewItem = (DLinkedListItem_t*) 0UL ;
    uint32_t u32SizeReg = 0U;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeReg = DLinkedList__u32GetSize(pstList);
        if(((uint32_t) 0UL != (uint32_t) pstNextItemArg) || (0UL == u32SizeReg))
        {
            #if defined (__TI_ARM__ )
            pstNewItem = (DLinkedListItem_t*) memalign((size_t) 4, (size_t) sizeof(DLinkedListItem_t));
            #elif defined (__GNUC__ )
            pstNewItem = (DLinkedListItem_t*) malloc(sizeof(DLinkedListItem_t));
            #endif

            DLinkedList__enInsertPrevious(pstList, pstNextItemArg, pstNewItem);
        }
    }
    return (pstNewItem);
}


DLinkedList_nSTATUS  DLinkedList__enInsertPreviousLastItemRead_WithData(DLinkedList_t* pstList,
                                           DLinkedListItem_t* pstNewItem,
                                           void* pvData)
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    DLinkedListItem_t* pstLastItemItem = (DLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = DLinkedList__pstGetLastItemRead(pstList);
        enStatus = DLinkedList__enInsertPrevious_WithData(pstList, pstLastItemItem, pstNewItem, pvData);
    }
    return (enStatus);
}

DLinkedList_nSTATUS  DLinkedList__enInsertPreviousLastItemRead(DLinkedList_t* pstList,
                                           DLinkedListItem_t* pstNewItem)
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    DLinkedListItem_t* pstLastItemItem = (DLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = DLinkedList__pstGetLastItemRead(pstList);
        enStatus = DLinkedList__enInsertPrevious(pstList, pstLastItemItem, pstNewItem);
    }
    return (enStatus);
}

DLinkedListItem_t*  DLinkedList__pstInsertPreviousLastItemRead_WithData(DLinkedList_t* pstList, void* pvData)
{
    DLinkedListItem_t* pstNewItem = (DLinkedListItem_t*) 0UL ;
    DLinkedListItem_t* pstLastItemItem = (DLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = DLinkedList__pstGetLastItemRead(pstList);
        pstNewItem = DLinkedList__pstInsertPrevious_WithData(pstList, pstLastItemItem, pvData);
    }
    return (pstNewItem);
}

DLinkedListItem_t*  DLinkedList__pstInsertPreviousLastItemRead(DLinkedList_t* pstList)
{
    DLinkedListItem_t* pstNewItem = (DLinkedListItem_t*) 0UL ;
    DLinkedListItem_t* pstLastItemItem = (DLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = DLinkedList__pstGetLastItemRead(pstList);
        pstNewItem = DLinkedList__pstInsertPrevious(pstList, pstLastItemItem);
    }
    return (pstNewItem);
}


DLinkedList_nSTATUS  DLinkedList__enInsertNextLastItemRead_WithData(DLinkedList_t* pstList,
                                           DLinkedListItem_t* pstNewItem,
                                           void* pvData)
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    DLinkedListItem_t* pstLastItemItem = (DLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = DLinkedList__pstGetLastItemRead(pstList);
        enStatus = DLinkedList__enInsertNext_WithData(pstList, pstLastItemItem, pstNewItem, pvData);
    }
    return (enStatus);
}

DLinkedList_nSTATUS  DLinkedList__enInsertNextLastItemRead(DLinkedList_t* pstList,
                                           DLinkedListItem_t* pstNewItem)
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    DLinkedListItem_t* pstLastItemItem = (DLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = DLinkedList__pstGetLastItemRead(pstList);
        enStatus = DLinkedList__enInsertNext(pstList, pstLastItemItem, pstNewItem);
    }
    return (enStatus);
}

DLinkedListItem_t*  DLinkedList__pstInsertNextLastItemRead_WithData(DLinkedList_t* pstList, void* pvData)
{
    DLinkedListItem_t* pstNewItem = (DLinkedListItem_t*) 0UL ;
    DLinkedListItem_t* pstLastItemItem = (DLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = DLinkedList__pstGetLastItemRead(pstList);
        pstNewItem = DLinkedList__pstInsertNext_WithData(pstList, pstLastItemItem, pvData);
    }
    return (pstNewItem);
}

DLinkedListItem_t*  DLinkedList__pstInsertNextLastItemRead(DLinkedList_t* pstList)
{
    DLinkedListItem_t* pstNewItem = (DLinkedListItem_t*) 0UL ;
    DLinkedListItem_t* pstLastItemItem = (DLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = DLinkedList__pstGetLastItemRead(pstList);
        pstNewItem = DLinkedList__pstInsertNext(pstList, pstLastItemItem);
    }
    return (pstNewItem);
}



DLinkedList_nSTATUS  DLinkedList__enInsertAtTail_WithData(DLinkedList_t* pstList,
                                           DLinkedListItem_t* pstNewItem,
                                           void* pvData)
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    DLinkedListItem_t* pstEndItem = (DLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstEndItem = DLinkedList__pstGetTail(pstList);
        enStatus = DLinkedList__enInsertNext_WithData(pstList, pstEndItem, pstNewItem, pvData);
    }
    return (enStatus);
}

DLinkedList_nSTATUS  DLinkedList__enInsertAtTail(DLinkedList_t* pstList,
                                           DLinkedListItem_t* pstNewItem)
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    DLinkedListItem_t* pstEndItem = (DLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstEndItem = DLinkedList__pstGetTail(pstList);
        enStatus = DLinkedList__enInsertNext(pstList, pstEndItem, pstNewItem);
    }
    return (enStatus);
}

DLinkedListItem_t*  DLinkedList__pstInsertAtTail_WithData(DLinkedList_t* pstList,
                                                    void* pvData)
{
    DLinkedListItem_t* pstNewItem = (DLinkedListItem_t*) 0UL ;
    DLinkedListItem_t* pstEndItem = (DLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstEndItem = DLinkedList__pstGetTail(pstList);
        pstNewItem = DLinkedList__pstInsertNext_WithData(pstList, pstEndItem, pvData);
    }
    return (pstNewItem);
}

DLinkedListItem_t*  DLinkedList__pstInsertAtTail(DLinkedList_t* pstList)
{
    DLinkedListItem_t* pstNewItem = (DLinkedListItem_t*) 0UL ;
    DLinkedListItem_t* pstEndItem = (DLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstEndItem = DLinkedList__pstGetTail(pstList);
        pstNewItem = DLinkedList__pstInsertNext(pstList, pstEndItem);
    }
    return (pstNewItem);
}

DLinkedList_nSTATUS DLinkedList__enInsertAtHead_WithData(DLinkedList_t* pstList,
                                            DLinkedListItem_t* pstNewItem,
                                            void* pvData)
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    DLinkedListItem_t* pstBeginItem = (DLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstBeginItem = DLinkedList__pstGetHead(pstList);
        enStatus = DLinkedList__enInsertPrevious_WithData(pstList, pstBeginItem, pstNewItem, pvData);
    }
    return (enStatus);
}

DLinkedList_nSTATUS DLinkedList__enInsertAtHead(DLinkedList_t* pstList,
                                            DLinkedListItem_t* pstNewItem)
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    DLinkedListItem_t* pstBeginItem = (DLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstBeginItem = DLinkedList__pstGetHead(pstList);
        enStatus = DLinkedList__enInsertPrevious(pstList, pstBeginItem, pstNewItem);
    }
    return (enStatus);
}

DLinkedListItem_t* DLinkedList__pstInsertAtHead_WithData(DLinkedList_t* pstList, void* pvData)
{
    DLinkedListItem_t* pstNewItem = (DLinkedListItem_t*) 0UL ;
    DLinkedListItem_t* pstBeginItem = (DLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstBeginItem = DLinkedList__pstGetHead(pstList);
        pstNewItem = DLinkedList__pstInsertPrevious_WithData(pstList, pstBeginItem, pvData);
    }
    return (pstNewItem);
}

DLinkedListItem_t* DLinkedList__pstInsertAtHead(DLinkedList_t* pstList)
{
    DLinkedListItem_t* pstNewItem = (DLinkedListItem_t*) 0UL ;
    DLinkedListItem_t* pstBeginItem = (DLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstBeginItem = DLinkedList__pstGetHead(pstList);
        pstNewItem = DLinkedList__pstInsertPrevious(pstList, pstBeginItem);
    }
    return (pstNewItem);
}

DLinkedList_nSTATUS  DLinkedList__enInsertPos_WithData(DLinkedList_t* pstList,
                                           DLinkedListItem_t* pstNewItem,
                                            uint32_t u32Position,
                                            void* pvData)
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    DLinkedListItem_t* pstItem = (DLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    uint32_t u32SizeForward = 0UL;
    uint32_t u32SizeBackward = 0UL;
    uint32_t u32SizeOptimum = 0UL;
    uint32_t u32Direction = 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeList = DLinkedList__u32GetSize(pstList);
        if(u32Position <= u32SizeList)
        {
            if(0UL == u32Position) /*Insert Head*/
            {
                enStatus = DLinkedList__enInsertAtHead_WithData(pstList, pstNewItem, pvData);
            }
            else if(u32Position == u32SizeList) /*Insert Tail*/
            {
                enStatus = DLinkedList__enInsertAtTail_WithData(pstList, pstNewItem, pvData);
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

                if(0UL == u32Direction) /*Forward*/
                {
                    pstItem = DLinkedList__pstGetHead(pstList);
                    u32SizeOptimum --;
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = DLinkedList_Item__pstGetNextItem(pstItem);
                        u32SizeOptimum--;
                    }
                    enStatus = DLinkedList__enInsertNext_WithData(pstList, pstItem, pstNewItem, pvData);
                }
                else /*Backward*/
                {
                    pstItem = DLinkedList__pstGetTail(pstList);
                    u32SizeOptimum--;
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = DLinkedList_Item__pstGetPreviousItem(pstItem);
                        u32SizeOptimum--;
                    }
                    enStatus = DLinkedList__enInsertPrevious_WithData(pstList, pstItem, pstNewItem, pvData);
                }
            }
        }
    }
    return (enStatus);
}

DLinkedList_nSTATUS  DLinkedList__enInsertPos(DLinkedList_t* pstList,
                                           DLinkedListItem_t* pstNewItem,
                                            uint32_t u32Position)
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    DLinkedListItem_t* pstItem = (DLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    uint32_t u32SizeForward = 0UL;
    uint32_t u32SizeBackward = 0UL;
    uint32_t u32SizeOptimum = 0UL;
    uint32_t u32Direction = 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeList = DLinkedList__u32GetSize(pstList);
        if(u32Position <= u32SizeList)
        {
            if(0UL == u32Position) /*Insert Head*/
            {
                enStatus = DLinkedList__enInsertAtHead(pstList, pstNewItem);
            }
            else if(u32Position == u32SizeList) /*Insert Tail*/
            {
                enStatus = DLinkedList__enInsertAtTail(pstList, pstNewItem);
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

                if(0UL == u32Direction) /*Forward*/
                {
                    pstItem = DLinkedList__pstGetHead(pstList);
                    u32SizeOptimum --;
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = DLinkedList_Item__pstGetNextItem(pstItem);
                        u32SizeOptimum--;
                    }
                    enStatus = DLinkedList__enInsertNext(pstList, pstItem, pstNewItem);
                }
                else /*Backward*/
                {
                    pstItem = DLinkedList__pstGetTail(pstList);
                    u32SizeOptimum--;
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = DLinkedList_Item__pstGetPreviousItem(pstItem);
                        u32SizeOptimum--;
                    }
                    enStatus = DLinkedList__enInsertPrevious(pstList, pstItem, pstNewItem);
                }
            }
        }
    }
    return (enStatus);
}

DLinkedListItem_t*  DLinkedList__pstInsertPos_WithData(DLinkedList_t* pstList,
                                                    uint32_t u32Position, void* pvData)
{
    DLinkedListItem_t* pstNewItem = (DLinkedListItem_t*) 0UL ;
    DLinkedListItem_t* pstItem = (DLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    uint32_t u32SizeForward = 0UL;
    uint32_t u32SizeBackward = 0UL;
    uint32_t u32SizeOptimum = 0UL;
    uint32_t u32Direction = 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeList = DLinkedList__u32GetSize(pstList);
        if(u32Position <= u32SizeList)
        {
            if(0UL == u32Position) /*Insert Head*/
            {
                pstNewItem = DLinkedList__pstInsertAtHead_WithData(pstList, pvData);
            }
            else if(u32Position == u32SizeList) /*Insert Tail*/
            {
                pstNewItem = DLinkedList__pstInsertAtTail_WithData(pstList, pvData);
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

                if(0UL == u32Direction) /*Forward*/
                {
                    pstItem = DLinkedList__pstGetHead(pstList);
                    u32SizeOptimum --;
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = DLinkedList_Item__pstGetNextItem(pstItem);
                        u32SizeOptimum--;
                    }
                    pstNewItem = DLinkedList__pstInsertNext_WithData(pstList, pstItem, pvData);
                }
                else /*Backward*/
                {
                    pstItem = DLinkedList__pstGetTail(pstList);
                    u32SizeOptimum--;
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = DLinkedList_Item__pstGetPreviousItem(pstItem);
                        u32SizeOptimum--;
                    }
                    pstNewItem = DLinkedList__pstInsertPrevious_WithData(pstList, pstItem, pvData);
                }
            }
        }
    }
    return (pstNewItem);
}


DLinkedListItem_t*  DLinkedList__pstInsertPos(DLinkedList_t* pstList,
                                                    uint32_t u32Position)
{
    DLinkedListItem_t* pstNewItem = (DLinkedListItem_t*) 0UL ;
    DLinkedListItem_t* pstItem = (DLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    uint32_t u32SizeForward = 0UL;
    uint32_t u32SizeBackward = 0UL;
    uint32_t u32SizeOptimum = 0UL;
    uint32_t u32Direction = 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeList = DLinkedList__u32GetSize(pstList);
        if(u32Position <= u32SizeList)
        {
            if(0UL == u32Position) /*Insert Head*/
            {
                pstNewItem = DLinkedList__pstInsertAtHead(pstList);
            }
            else if(u32Position == u32SizeList) /*Insert Tail*/
            {
                pstNewItem = DLinkedList__pstInsertAtTail(pstList);
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

                if(0UL == u32Direction) /*Forward*/
                {
                    pstItem = DLinkedList__pstGetHead(pstList);
                    u32SizeOptimum --;
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = DLinkedList_Item__pstGetNextItem(pstItem);
                        u32SizeOptimum--;
                    }
                    pstNewItem = DLinkedList__pstInsertNext(pstList, pstItem);
                }
                else /*Backward*/
                {
                    pstItem = DLinkedList__pstGetTail(pstList);
                    u32SizeOptimum--;
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = DLinkedList_Item__pstGetPreviousItem(pstItem);
                        u32SizeOptimum--;
                    }
                    pstNewItem = DLinkedList__pstInsertPrevious(pstList, pstItem);
                }
            }
        }
    }
    return (pstNewItem);
}

