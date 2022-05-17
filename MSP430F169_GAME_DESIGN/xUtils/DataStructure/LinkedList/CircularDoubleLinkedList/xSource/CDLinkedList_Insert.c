/**
 *
 * @file CDLinkedList_Insert.c
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
#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/xHeader/CDLinkedList_Insert.h>

#include <stdlib.h>
#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/Intrinsics/CDLinkedList_Intrinsics.h>

#define INSERT_NEXT (0UL)
#define INSERT_PREVIOUS (1UL)

#define DATA_UPDATE (0UL)
#define DATA_STATIC (1UL)

/** TODO:
 *  Crear functiones "insert" para poder realizar combinaciones de pvData, u32Value
 *
 */

static CDLinkedList_nSTATUS CDLinkedList__enInsertGeneric(CDLinkedList_t* pstList,
                                                        CDLinkedListItem_t* pstItem,
                                                        CDLinkedListItem_t* pstNewItem,
                                                        void* pvData,
                                                        uint32_t u32Insert,
                                                        uint32_t u32DataUpdate);

static CDLinkedList_nSTATUS CDLinkedList__enInsertGeneric(CDLinkedList_t* pstList,
                                                        CDLinkedListItem_t* pstItem,
                                                        CDLinkedListItem_t* pstNewItem,
                                                        void* pvData,
                                                        uint32_t u32Insert,
                                                        uint32_t u32DataUpdate)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedListItem_t* pstItemTemp = (CDLinkedListItem_t*) 0UL ;
    CDLinkedListItem_t* pstItemNextNode = (CDLinkedListItem_t*) 0UL ;
    CDLinkedListItem_t* pstItemPreviousNode = (CDLinkedListItem_t*) 0UL ;
    CDLinkedListItem_t* pstHeadItem = (CDLinkedListItem_t*) 0UL ;
    CDLinkedListItem_t* pstTailItem = (CDLinkedListItem_t*) 0UL ;
    uint32_t u32SizeReg = 0U;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeReg = CDLinkedList__u32GetSize(pstList);
        if(((uint32_t) 0UL != (uint32_t) pstItem) || (0UL == u32SizeReg))
        {
            if((uint32_t) 0UL != (uint32_t) pstNewItem)
            {
                enStatus = CDLinkedList_enSTATUS_OK;
                if(DATA_UPDATE == u32DataUpdate)
                {
                    CDLinkedList_Item__vSetData(pstNewItem, pvData);
                }
                CDLinkedList_Item__vSetOwnerList(pstNewItem, (void*) pstList);

                if(0UL == u32SizeReg)
                {
                    CDLinkedList__vSetHead(pstList, pstNewItem);
                    pstItemTemp = pstNewItem;
                    CDLinkedList_Item__vSetNextItem(pstNewItem, pstItemTemp );
                    CDLinkedList_Item__vSetPreviousItem(pstNewItem, pstItemTemp );

                    CDLinkedList__vSetTail(pstList, pstNewItem);
                }
                else
                {
                    if(INSERT_NEXT == u32Insert)
                    {
                        pstHeadItem = CDLinkedList__pstGetHead(pstList);
                        pstItemNextNode = CDLinkedList_Item__pstGetNextItem(pstItem);

                        CDLinkedList_Item__vSetNextItem(pstNewItem, pstItemNextNode );
                        CDLinkedList_Item__vSetPreviousItem(pstNewItem, pstItem);
                        if((uint32_t) pstHeadItem == (uint32_t) pstItemNextNode)
                        {
                            CDLinkedList__vSetTail(pstList, pstNewItem);
                        }

                        CDLinkedList_Item__vSetPreviousItem(pstItemNextNode, pstNewItem);
                        CDLinkedList_Item__vSetNextItem(pstItem, pstNewItem);
                    }
                    else
                    {
                        pstTailItem = CDLinkedList__pstGetTail(pstList);
                        pstItemPreviousNode = CDLinkedList_Item__pstGetPreviousItem(pstItem);

                        CDLinkedList_Item__vSetNextItem(pstNewItem, pstItem );
                        CDLinkedList_Item__vSetPreviousItem(pstNewItem, pstItemPreviousNode);

                        if((uint32_t) pstTailItem == (uint32_t) pstItemPreviousNode)
                        {
                            CDLinkedList__vSetHead(pstList, pstNewItem);
                        }

                        CDLinkedList_Item__vSetNextItem(pstItemPreviousNode, pstNewItem);
                        CDLinkedList_Item__vSetPreviousItem(pstItem, pstNewItem);
                    }
                }
                u32SizeReg++;
                CDLinkedList__vSetSize(pstList, u32SizeReg);
            }
        }
    }
    return (enStatus);
}

CDLinkedList_nSTATUS CDLinkedList__enInsertNext_WithData(CDLinkedList_t* pstList,
                                                      CDLinkedListItem_t* pstItem,
                                                      CDLinkedListItem_t* pstNewItem,
                                                      void* pvData)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    enStatus = CDLinkedList__enInsertGeneric(pstList, pstItem, pstNewItem, pvData, INSERT_NEXT, DATA_UPDATE);
    return (enStatus);
}

CDLinkedList_nSTATUS CDLinkedList__enInsertNext(CDLinkedList_t* pstList,
                                                      CDLinkedListItem_t* pstItem,
                                                      CDLinkedListItem_t* pstNewItem)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    enStatus = CDLinkedList__enInsertGeneric(pstList, pstItem, pstNewItem, (void*) 0UL, INSERT_NEXT, DATA_STATIC);
    return (enStatus);
}

CDLinkedListItem_t* CDLinkedList__pstInsertNext_WithData(CDLinkedList_t* pstList, CDLinkedListItem_t* pstItem, void* pvData)
{
    CDLinkedListItem_t* pstNewItem = (CDLinkedListItem_t*) 0UL ;
    uint32_t u32SizeReg = 0U;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeReg = CDLinkedList__u32GetSize(pstList);
        if(((uint32_t) 0UL != (uint32_t) pstItem) || (0UL == u32SizeReg))
        {
            #if defined (__TI_ARM__ )
            pstNewItem = (CDLinkedListItem_t*) memalign((size_t) 4, (size_t) sizeof(CDLinkedListItem_t));
            #elif defined (__GNUC__ )
            pstNewItem = (CDLinkedListItem_t*) malloc(sizeof(CDLinkedListItem_t));
            #endif

            CDLinkedList__enInsertNext_WithData(pstList, pstItem, pstNewItem, pvData);
        }
    }
    return (pstNewItem);
}

CDLinkedListItem_t* CDLinkedList__pstInsertNext(CDLinkedList_t* pstList, CDLinkedListItem_t* pstItem)
{
    CDLinkedListItem_t* pstNewItem = (CDLinkedListItem_t*) 0UL ;
    uint32_t u32SizeReg = 0U;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeReg = CDLinkedList__u32GetSize(pstList);
        if(((uint32_t) 0UL != (uint32_t) pstItem) || (0UL == u32SizeReg))
        {
            #if defined (__TI_ARM__ )
            pstNewItem = (CDLinkedListItem_t*) memalign((size_t) 4, (size_t) sizeof(CDLinkedListItem_t));
            #elif defined (__GNUC__ )
            pstNewItem = (CDLinkedListItem_t*) malloc(sizeof(CDLinkedListItem_t));
            #endif

            CDLinkedList__enInsertNext(pstList, pstItem, pstNewItem);
        }
    }
    return (pstNewItem);
}

CDLinkedList_nSTATUS CDLinkedList__enInsertPrevious_WithData(CDLinkedList_t* pstList,
                                                      CDLinkedListItem_t* pstItem,
                                                      CDLinkedListItem_t* pstNewItem,
                                                      void* pvData)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    enStatus = CDLinkedList__enInsertGeneric(pstList, pstItem, pstNewItem, pvData, INSERT_PREVIOUS, DATA_UPDATE);
    return (enStatus);
}

CDLinkedList_nSTATUS CDLinkedList__enInsertPrevious(CDLinkedList_t* pstList,
                                                      CDLinkedListItem_t* pstItem,
                                                      CDLinkedListItem_t* pstNewItem)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    enStatus = CDLinkedList__enInsertGeneric(pstList, pstItem, pstNewItem, (void*) 0UL, INSERT_PREVIOUS, DATA_STATIC);
    return (enStatus);
}


CDLinkedListItem_t* CDLinkedList__pstInsertPrevious_WithData(CDLinkedList_t* pstList, CDLinkedListItem_t* pstItem, void* pvData)
{
    CDLinkedListItem_t* pstNewItem = (CDLinkedListItem_t*) 0UL ;
    uint32_t u32SizeReg = 0U;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeReg = CDLinkedList__u32GetSize(pstList);
        if(((uint32_t) 0UL != (uint32_t) pstItem) || (0UL == u32SizeReg))
        {
            #if defined (__TI_ARM__ )
            pstNewItem = (CDLinkedListItem_t*) memalign((size_t) 4, (size_t) sizeof(CDLinkedListItem_t));
            #elif defined (__GNUC__ )
            pstNewItem = (CDLinkedListItem_t*) malloc(sizeof(CDLinkedListItem_t));
            #endif

            CDLinkedList__enInsertPrevious_WithData(pstList, pstItem, pstNewItem, pvData);
        }
    }
    return (pstNewItem);
}


CDLinkedListItem_t* CDLinkedList__pstInsertPrevious(CDLinkedList_t* pstList, CDLinkedListItem_t* pstItem)
{
    CDLinkedListItem_t* pstNewItem = (CDLinkedListItem_t*) 0UL ;
    uint32_t u32SizeReg = 0U;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeReg = CDLinkedList__u32GetSize(pstList);
        if(((uint32_t) 0UL != (uint32_t) pstItem) || (0UL == u32SizeReg))
        {
            #if defined (__TI_ARM__ )
            pstNewItem = (CDLinkedListItem_t*) memalign((size_t) 4, (size_t) sizeof(CDLinkedListItem_t));
            #elif defined (__GNUC__ )
            pstNewItem = (CDLinkedListItem_t*) malloc(sizeof(CDLinkedListItem_t));
            #endif

            CDLinkedList__enInsertPrevious(pstList, pstItem, pstNewItem);
        }
    }
    return (pstNewItem);
}

CDLinkedList_nSTATUS  CDLinkedList__enInsertPreviousLastItemRead_WithData(CDLinkedList_t* pstList,
                                           CDLinkedListItem_t* pstNewItem,
                                           void* pvData)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedListItem_t* pstLastItemItem = (CDLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = CDLinkedList__pstGetLastItemRead(pstList);
        if(0UL == (uint32_t) pstLastItemItem)
        {
            enStatus = CDLinkedList__enInsertAtTail_WithData(pstList,pstNewItem,pvData);
        }
        else
        {
            enStatus = CDLinkedList__enInsertPrevious_WithData(pstList, pstLastItemItem, pstNewItem, pvData);
        }
    }
    return (enStatus);
}

CDLinkedList_nSTATUS  CDLinkedList__enInsertPreviousLastItemRead(CDLinkedList_t* pstList,
                                           CDLinkedListItem_t* pstNewItem)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedListItem_t* pstLastItemItem = (CDLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = CDLinkedList__pstGetLastItemRead(pstList);
        if(0UL == (uint32_t) pstLastItemItem)
        {
            enStatus = CDLinkedList__enInsertAtTail(pstList,pstNewItem);
        }
        else
        {
            enStatus = CDLinkedList__enInsertPrevious(pstList, pstLastItemItem, pstNewItem);
        }
    }
    return (enStatus);
}

CDLinkedListItem_t*  CDLinkedList__pstInsertPreviousLastItemRead_WithData(CDLinkedList_t* pstList, void* pvData)
{
    CDLinkedListItem_t* pstNewItem = (CDLinkedListItem_t*) 0UL ;
    CDLinkedListItem_t* pstLastItemItem = (CDLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = CDLinkedList__pstGetLastItemRead(pstList);
        if(0UL == (uint32_t) pstLastItemItem)
        {
            pstLastItemItem = CDLinkedList__pstInsertAtTail(pstList);
        }
        else
        {
            pstNewItem = CDLinkedList__pstInsertPrevious_WithData(pstList, pstLastItemItem, pvData);
        }
    }
    return (pstNewItem);
}

CDLinkedListItem_t*  CDLinkedList__pstInsertPreviousLastItemRead(CDLinkedList_t* pstList)
{
    CDLinkedListItem_t* pstNewItem = (CDLinkedListItem_t*) 0UL ;
    CDLinkedListItem_t* pstLastItemItem = (CDLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = CDLinkedList__pstGetLastItemRead(pstList);
        if(0UL == (uint32_t) pstLastItemItem)
        {
            pstLastItemItem = CDLinkedList__pstInsertAtTail(pstList);
        }
        else
        {
            pstNewItem = CDLinkedList__pstInsertPrevious(pstList, pstLastItemItem);
        }
    }
    return (pstNewItem);
}


CDLinkedList_nSTATUS  CDLinkedList__enInsertNextLastItemRead_WithData(CDLinkedList_t* pstList,
                                           CDLinkedListItem_t* pstNewItem,
                                           void* pvData)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedListItem_t* pstLastItemItem = (CDLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = CDLinkedList__pstGetLastItemRead(pstList);
        if(0UL == (uint32_t) pstLastItemItem)
        {
            pstLastItemItem = CDLinkedList__pstGetHead(pstList);
        }
        enStatus = CDLinkedList__enInsertNext_WithData(pstList, pstLastItemItem, pstNewItem, pvData);
    }
    return (enStatus);
}

CDLinkedList_nSTATUS  CDLinkedList__enInsertNextLastItemRead(CDLinkedList_t* pstList,
                                           CDLinkedListItem_t* pstNewItem)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedListItem_t* pstLastItemItem = (CDLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = CDLinkedList__pstGetLastItemRead(pstList);
        if(0UL == (uint32_t) pstLastItemItem)
        {
            pstLastItemItem = CDLinkedList__pstGetHead(pstList);
        }
        enStatus = CDLinkedList__enInsertNext(pstList, pstLastItemItem, pstNewItem);
    }
    return (enStatus);
}

CDLinkedListItem_t*  CDLinkedList__pstInsertNextLastItemRead_WithData(CDLinkedList_t* pstList, void* pvData)
{
    CDLinkedListItem_t* pstNewItem = (CDLinkedListItem_t*) 0UL ;
    CDLinkedListItem_t* pstLastItemItem = (CDLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = CDLinkedList__pstGetLastItemRead(pstList);
        if(0UL == (uint32_t) pstLastItemItem)
        {
            pstLastItemItem = CDLinkedList__pstGetHead(pstList);
        }
        pstNewItem = CDLinkedList__pstInsertNext_WithData(pstList, pstLastItemItem, pvData);
    }
    return (pstNewItem);
}

CDLinkedListItem_t*  CDLinkedList__pstInsertNextLastItemRead(CDLinkedList_t* pstList)
{
    CDLinkedListItem_t* pstNewItem = (CDLinkedListItem_t*) 0UL ;
    CDLinkedListItem_t* pstLastItemItem = (CDLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstLastItemItem = CDLinkedList__pstGetLastItemRead(pstList);
        if(0UL == (uint32_t) pstLastItemItem)
        {
            pstLastItemItem = CDLinkedList__pstGetHead(pstList);
        }
        pstNewItem = CDLinkedList__pstInsertNext(pstList, pstLastItemItem);
    }
    return (pstNewItem);
}

CDLinkedList_nSTATUS  CDLinkedList__enInsertAtTail_WithData(CDLinkedList_t* pstList,
                                           CDLinkedListItem_t* pstNewItem,
                                           void* pvData)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedListItem_t* pstEndItem = (CDLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstEndItem = CDLinkedList__pstGetTail(pstList);
        enStatus = CDLinkedList__enInsertNext_WithData(pstList, pstEndItem, pstNewItem, pvData);
    }
    return (enStatus);
}

CDLinkedList_nSTATUS  CDLinkedList__enInsertAtTail(CDLinkedList_t* pstList,
                                           CDLinkedListItem_t* pstNewItem)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedListItem_t* pstEndItem = (CDLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstEndItem = CDLinkedList__pstGetTail(pstList);
        enStatus = CDLinkedList__enInsertNext(pstList, pstEndItem, pstNewItem);
    }
    return (enStatus);
}

CDLinkedListItem_t*  CDLinkedList__pstInsertAtTail_WithData(CDLinkedList_t* pstList, void* pvData)
{
    CDLinkedListItem_t* pstNewItem = (CDLinkedListItem_t*) 0UL ;
    CDLinkedListItem_t* pstEndItem = (CDLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstEndItem = CDLinkedList__pstGetTail(pstList);
        pstNewItem = CDLinkedList__pstInsertNext_WithData(pstList, pstEndItem, pvData);
    }
    return (pstNewItem);
}

CDLinkedListItem_t*  CDLinkedList__pstInsertAtTail(CDLinkedList_t* pstList)
{
    CDLinkedListItem_t* pstNewItem = (CDLinkedListItem_t*) 0UL ;
    CDLinkedListItem_t* pstEndItem = (CDLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstEndItem = CDLinkedList__pstGetTail(pstList);
        pstNewItem = CDLinkedList__pstInsertNext(pstList, pstEndItem);
    }
    return (pstNewItem);
}

CDLinkedList_nSTATUS CDLinkedList__enInsertAtHead_WithData(CDLinkedList_t* pstList,
                                            CDLinkedListItem_t* pstNewItem,
                                            void* pvData)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedListItem_t* pstBeginItem = (CDLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstBeginItem = CDLinkedList__pstGetHead(pstList);
        enStatus = CDLinkedList__enInsertPrevious_WithData(pstList, pstBeginItem, pstNewItem, pvData);
    }
    return (enStatus);
}

CDLinkedList_nSTATUS CDLinkedList__enInsertAtHead(CDLinkedList_t* pstList,
                                            CDLinkedListItem_t* pstNewItem)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedListItem_t* pstBeginItem = (CDLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstBeginItem = CDLinkedList__pstGetHead(pstList);
        enStatus = CDLinkedList__enInsertPrevious(pstList, pstBeginItem, pstNewItem);
    }
    return (enStatus);
}

CDLinkedListItem_t*  CDLinkedList__pstInsertAtHead_WithData(CDLinkedList_t* pstList, void* pvData)
{
    CDLinkedListItem_t* pstNewItem = (CDLinkedListItem_t*) 0UL ;
    CDLinkedListItem_t* pstBeginItem = (CDLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstBeginItem = CDLinkedList__pstGetHead(pstList);
        pstNewItem = CDLinkedList__pstInsertPrevious_WithData(pstList, pstBeginItem, pvData);
    }
    return (pstNewItem);
}

CDLinkedListItem_t*  CDLinkedList__pstInsertAtHead(CDLinkedList_t* pstList)
{
    CDLinkedListItem_t* pstNewItem = (CDLinkedListItem_t*) 0UL ;
    CDLinkedListItem_t* pstBeginItem = (CDLinkedListItem_t*) 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        pstBeginItem = CDLinkedList__pstGetHead(pstList);
        pstNewItem = CDLinkedList__pstInsertPrevious(pstList, pstBeginItem);
    }
    return (pstNewItem);
}

CDLinkedList_nSTATUS  CDLinkedList__enInsertPos_WithData(CDLinkedList_t* pstList,
                                           CDLinkedListItem_t* pstNewItem,
                                            uint32_t u32Position,
                                            void* pvData)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedListItem_t* pstItem = (CDLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    uint32_t u32SizeForward = 0UL;
    uint32_t u32SizeBackward = 0UL;
    uint32_t u32SizeOptimum = 0UL;
    uint32_t u32Direction = 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeList = CDLinkedList__u32GetSize(pstList);
        if(u32Position <= u32SizeList)
        {
            if(0UL == u32Position) /*Insert Head*/
            {
                enStatus = CDLinkedList__enInsertAtHead_WithData(pstList, pstNewItem, pvData);
            }
            else if(u32Position == u32SizeList) /*Insert Tail*/
            {
                enStatus = CDLinkedList__enInsertAtTail_WithData(pstList, pstNewItem, pvData);
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
                    pstItem = CDLinkedList__pstGetHead(pstList);
                    u32SizeOptimum --;
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = CDLinkedList_Item__pstGetNextItem(pstItem);
                        u32SizeOptimum--;
                    }
                    enStatus = CDLinkedList__enInsertNext_WithData(pstList, pstItem, pstNewItem, pvData);
                }
                else /*Backward*/
                {
                    pstItem = CDLinkedList__pstGetTail(pstList);
                    u32SizeOptimum--;
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = CDLinkedList_Item__pstGetPreviousItem(pstItem);
                        u32SizeOptimum--;
                    }
                    enStatus = CDLinkedList__enInsertPrevious_WithData(pstList, pstItem, pstNewItem, pvData);
                }
            }
        }
    }
    return (enStatus);
}

CDLinkedList_nSTATUS  CDLinkedList__enInsertPos(CDLinkedList_t* pstList,
                                           CDLinkedListItem_t* pstNewItem,
                                            uint32_t u32Position)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedListItem_t* pstItem = (CDLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    uint32_t u32SizeForward = 0UL;
    uint32_t u32SizeBackward = 0UL;
    uint32_t u32SizeOptimum = 0UL;
    uint32_t u32Direction = 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeList = CDLinkedList__u32GetSize(pstList);
        if(u32Position <= u32SizeList)
        {
            if(0UL == u32Position) /*Insert Head*/
            {
                enStatus = CDLinkedList__enInsertAtHead(pstList, pstNewItem);
            }
            else if(u32Position == u32SizeList) /*Insert Tail*/
            {
                enStatus = CDLinkedList__enInsertAtTail(pstList, pstNewItem);
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
                    pstItem = CDLinkedList__pstGetHead(pstList);
                    u32SizeOptimum --;
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = CDLinkedList_Item__pstGetNextItem(pstItem);
                        u32SizeOptimum--;
                    }
                    enStatus = CDLinkedList__enInsertNext(pstList, pstItem, pstNewItem);
                }
                else /*Backward*/
                {
                    pstItem = CDLinkedList__pstGetTail(pstList);
                    u32SizeOptimum--;
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = CDLinkedList_Item__pstGetPreviousItem(pstItem);
                        u32SizeOptimum--;
                    }
                    enStatus = CDLinkedList__enInsertPrevious(pstList, pstItem, pstNewItem);
                }
            }
        }
    }
    return (enStatus);
}


CDLinkedListItem_t*  CDLinkedList__pstInsertPos_WithData(CDLinkedList_t* pstList, uint32_t u32Position, void* pvData)
{
    CDLinkedListItem_t* pstNewItem = (CDLinkedListItem_t*) 0UL ;
    CDLinkedListItem_t* pstItem = (CDLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    uint32_t u32SizeForward = 0UL;
    uint32_t u32SizeBackward = 0UL;
    uint32_t u32SizeOptimum = 0UL;
    uint32_t u32Direction = 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeList = CDLinkedList__u32GetSize(pstList);
        if(u32Position <= u32SizeList)
        {
            if(0UL == u32Position) /*Insert Head*/
            {
                pstNewItem = CDLinkedList__pstInsertAtHead_WithData(pstList, pvData);
            }
            else if(u32Position == u32SizeList) /*Insert Tail*/
            {
                pstNewItem = CDLinkedList__pstInsertAtTail_WithData(pstList, pvData);
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
                    u32SizeOptimum --;
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = CDLinkedList_Item__pstGetNextItem(pstItem);
                        u32SizeOptimum--;
                    }
                    pstNewItem = CDLinkedList__pstInsertNext_WithData(pstList, pstItem, pvData);
                }
                else /*Backward*/
                {
                    pstItem = CDLinkedList__pstGetTail(pstList);
                    u32SizeOptimum--;
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = CDLinkedList_Item__pstGetPreviousItem(pstItem);
                        u32SizeOptimum--;
                    }
                    pstNewItem = CDLinkedList__pstInsertPrevious_WithData(pstList, pstItem, pvData);
                }
            }
        }
    }
    return (pstNewItem);
}


CDLinkedListItem_t*  CDLinkedList__pstInsertPos(CDLinkedList_t* pstList, uint32_t u32Position)
{
    CDLinkedListItem_t* pstNewItem = (CDLinkedListItem_t*) 0UL ;
    CDLinkedListItem_t* pstItem = (CDLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    uint32_t u32SizeForward = 0UL;
    uint32_t u32SizeBackward = 0UL;
    uint32_t u32SizeOptimum = 0UL;
    uint32_t u32Direction = 0UL;
    if(((uint32_t) 0UL != (uint32_t) pstList))
    {
        u32SizeList = CDLinkedList__u32GetSize(pstList);
        if(u32Position <= u32SizeList)
        {
            if(0UL == u32Position) /*Insert Head*/
            {
                pstNewItem = CDLinkedList__pstInsertAtHead(pstList);
            }
            else if(u32Position == u32SizeList) /*Insert Tail*/
            {
                pstNewItem = CDLinkedList__pstInsertAtTail(pstList);
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
                    u32SizeOptimum --;
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = CDLinkedList_Item__pstGetNextItem(pstItem);
                        u32SizeOptimum--;
                    }
                    pstNewItem = CDLinkedList__pstInsertNext(pstList, pstItem);
                }
                else /*Backward*/
                {
                    pstItem = CDLinkedList__pstGetTail(pstList);
                    u32SizeOptimum--;
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = CDLinkedList_Item__pstGetPreviousItem(pstItem);
                        u32SizeOptimum--;
                    }
                    pstNewItem = CDLinkedList__pstInsertPrevious(pstList, pstItem);
                }
            }
        }
    }
    return (pstNewItem);
}

/**TODO: Replicar CDLinkedList__enInsertInDescendingOrderByValue y CDLinkedList__enInsertInAscendingOrderByValue
 * en los otros tipos de linkedlist
 * */

CDLinkedList_nSTATUS  CDLinkedList__enInsertInDescendingOrderByValue(CDLinkedList_t* pstList,
                                           CDLinkedListItem_t* pstNewItem)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedListItem_t* pstItem = (CDLinkedListItem_t*) 0UL;
    CDLinkedListItem_t* pstItemAux = (CDLinkedListItem_t*) 0UL;
    uint32_t u32NewItemValueReg = 0UL;
    uint32_t u32ItemValueReg = 0UL;
    uint32_t u32SizeList = 0UL;
    if(( 0UL != (uint32_t) pstList) && ( 0UL != (uint32_t) pstNewItem))
    {

        u32SizeList = CDLinkedList__u32GetSize(pstList);
        if(0UL == u32SizeList)
        {
            enStatus =  CDLinkedList__enInsertAtHead(pstList, pstNewItem);
        }
        else
        {
            u32NewItemValueReg = CDLinkedList_Item__u32GetValue(pstNewItem);

            pstItem = CDLinkedList__pstGetHead(pstList);
            u32ItemValueReg = CDLinkedList_Item__u32GetValue(pstItem);
            u32SizeList--;
            while((0UL != u32SizeList) && (u32ItemValueReg > u32NewItemValueReg))
            {
                pstItemAux = pstItem;
                pstItem = CDLinkedList_Item__pstGetNextItem(pstItemAux);
                u32ItemValueReg = CDLinkedList_Item__u32GetValue(pstItem);
                u32SizeList--;
            }
            if(u32ItemValueReg >= u32NewItemValueReg)
            {
                enStatus = CDLinkedList__enInsertNext(pstList,pstItem, pstNewItem);
            }
            else
            {
                enStatus = CDLinkedList__enInsertPrevious(pstList, pstItem, pstNewItem);
            }
        }
    }
    return (enStatus);
}


CDLinkedList_nSTATUS  CDLinkedList__enInsertInAscendingOrderByValue(CDLinkedList_t* pstList,
                                           CDLinkedListItem_t* pstNewItem)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedListItem_t* pstItem = (CDLinkedListItem_t*) 0UL;
    CDLinkedListItem_t* pstItemAux = (CDLinkedListItem_t*) 0UL;
    uint32_t u32NewItemValueReg = 0UL;
    uint32_t u32ItemValueReg = 0UL;
    uint32_t u32SizeList = 0UL;
    if(( 0UL != (uint32_t) pstList) && ( 0UL != (uint32_t) pstNewItem))
    {

        u32SizeList = CDLinkedList__u32GetSize(pstList);
        if(0UL == u32SizeList)
        {
            enStatus =  CDLinkedList__enInsertAtHead(pstList, pstNewItem);
        }
        else
        {
            u32NewItemValueReg = CDLinkedList_Item__u32GetValue(pstNewItem);

            pstItem = CDLinkedList__pstGetHead(pstList);
            u32ItemValueReg = CDLinkedList_Item__u32GetValue(pstItem);
            u32SizeList--;
            while((0UL != u32SizeList) && (u32ItemValueReg < u32NewItemValueReg))
            {
                pstItemAux = pstItem;
                pstItem = CDLinkedList_Item__pstGetNextItem(pstItemAux);
                u32ItemValueReg = CDLinkedList_Item__u32GetValue(pstItem);
                u32SizeList--;
            }
            if(u32ItemValueReg <= u32NewItemValueReg)
            {
                enStatus = CDLinkedList__enInsertNext(pstList,pstItem, pstNewItem);
            }
            else
            {
                enStatus = CDLinkedList__enInsertPrevious(pstList, pstItem, pstNewItem);
            }
        }
    }
    return (enStatus);
}
