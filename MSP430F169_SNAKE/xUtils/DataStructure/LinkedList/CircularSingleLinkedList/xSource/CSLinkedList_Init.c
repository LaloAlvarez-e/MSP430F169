/**
 *
 * @file CSLinkedList_Init.c
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
#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/xHeader/CSLinkedList_Init.h>
#include <stdlib.h>

CSLinkedList_t* CSLinkedList__pstInit(void (*pvfDestroyItemDataArg) (void *DataContainer), void (*pvfDestroyItemArg) (void *Item))
{
    CSLinkedList_t *pstList = 0;
#if defined (__TI_ARM__ ) || defined (__MSP430__ )
    pstList = (CSLinkedList_t*) memalign((size_t) 4, (size_t) sizeof(CSLinkedList_t));
#elif defined (__GNUC__ )
    pstList = (CSLinkedList_t*) malloc(sizeof(CSLinkedList_t));
#endif
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstList->u32Size = 0UL;
        pstList->pvfDestroy = &free;
        pstList->pvfDestroyItemData = pvfDestroyItemDataArg;
        pstList->pvfDestroyItem = pvfDestroyItemArg;
        pstList->pstHead = (CSLinkedListItem_t*)  0UL;
        pstList->pstLastItemRead = (CSLinkedListItem_t*)  0UL;
    }
    return (pstList);
}

CSLinkedList_nSTATUS CSLinkedList__enInit(CSLinkedList_t* pstList,
                                          void (*pvfDestroyItemDataArg) (void *DataContainer),
                                          void (*pvfDestroyItemArg) (void *Item))
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        enStatus = CSLinkedList_enSTATUS_OK;
        pstList->u32Size = 0UL;
        pstList->pvfDestroy = (void (*) (void* List))0UL;
        pstList->pvfDestroyItemData = pvfDestroyItemDataArg;
        pstList->pvfDestroyItem = pvfDestroyItemArg;
        pstList->pstHead = (CSLinkedListItem_t*)  0UL;
        pstList->pstLastItemRead = (CSLinkedListItem_t*)  0UL;
    }
    return (enStatus);
}
