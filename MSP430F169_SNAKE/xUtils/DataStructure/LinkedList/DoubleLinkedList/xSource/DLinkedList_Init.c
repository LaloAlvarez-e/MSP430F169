/**
 *
 * @file DLinkedList_Init.c
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

#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/xHeader/DLinkedList_Init.h>
#include <stdlib.h>

DLinkedList_t* DLinkedList__pstInit(void (*pvfDestroyItemDataArg) (void *DataContainer), void (*pvfDestroyItemArg) (void *Item))
{
    DLinkedList_t *pstList = 0;
#if defined (__TI_ARM__ ) || defined (__MSP430__ )
    pstList = (DLinkedList_t*) memalign((size_t) 4, (size_t) sizeof(DLinkedList_t));
#elif defined (__GNUC__ )
    pstList = (DLinkedList_t*) malloc(sizeof(DLinkedList_t));
#endif
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstList->u32Size = 0UL;
        pstList->pvfDestroy = &free;
        pstList->pvfDestroyItemData = pvfDestroyItemDataArg;
        pstList->pvfDestroyItem = pvfDestroyItemArg;
        pstList->pstHead = (DLinkedListItem_t*)  0UL;
        pstList->pstTail = (DLinkedListItem_t*)  0UL;
        pstList->pstLastItemRead = (DLinkedListItem_t*)  0UL;
    }
    return (pstList);
}


DLinkedList_nSTATUS DLinkedList__enInit(DLinkedList_t* pstList,
                                        void (*pvfDestroyItemDataArg) (void *DataContainer),
                                        void (*pvfDestroyItemArg) (void *Item))
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        enStatus = DLinkedList_enSTATUS_OK;
        pstList->u32Size = 0UL;
        pstList->pvfDestroy = (void (*) (void* List))0UL;
        pstList->pvfDestroyItemData = pvfDestroyItemDataArg;
        pstList->pvfDestroyItem = pvfDestroyItemArg;
        pstList->pstHead = (DLinkedListItem_t*)  0UL;
        pstList->pstTail = (DLinkedListItem_t*)  0UL;
        pstList->pstLastItemRead = (DLinkedListItem_t*)  0UL;
    }
    return (enStatus);
}



