/**
 *
 * @file SLinkedList_Init.c
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
#include <xUtils/DataStructure/LinkedList/SingleLinkedList/xHeader/SLinkedList_Init.h>
#include <stdlib.h>

SLinkedList_t* SLinkedList__pstInit(void (*pvfDestroyItemDataArg) (void *DataContainer),
                                          void (*pvfDestroyItemArg) (void *Item))
{
    SLinkedList_t *pstList = 0;
#if defined (__TI_ARM__ ) || defined (__MSP430__ )
    pstList = (SLinkedList_t*) memalign((size_t) 4, (size_t) sizeof(SLinkedList_t));
#elif defined (__GNUC__ )
    pstList = (SLinkedList_t*) malloc(sizeof(SLinkedList_t));
#endif
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstList->u32Size = 0UL;
        pstList->pvfDestroy = &free;
        pstList->pvfDestroyItemData = pvfDestroyItemDataArg;
        pstList->pvfDestroyItem = pvfDestroyItemArg;
        pstList->pstHead = (SLinkedListItem_t*)  0UL;
        pstList->pstTail = (SLinkedListItem_t*)  0UL;
        pstList->pstLastItemRead = (SLinkedListItem_t*)  0UL;
    }
    return (pstList);
}

SLinkedList_nSTATUS SLinkedList__enInit(SLinkedList_t* pstList,
                                        void (*pvfDestroyItemDataArg) (void *DataContainer),
                                        void (*pvfDestroyItemArg) (void *Item))
{
    SLinkedList_nSTATUS enStatus = SLinkedList_enSTATUS_ERROR;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        enStatus = SLinkedList_enSTATUS_OK;
        pstList->u32Size = 0UL;
        pstList->pvfDestroy = (void (*) (void* List))0UL;
        pstList->pvfDestroyItemData = pvfDestroyItemDataArg;
        pstList->pvfDestroyItem = pvfDestroyItemArg;
        pstList->pstHead = (SLinkedListItem_t*)  0UL;
        pstList->pstTail = (SLinkedListItem_t*)  0UL;
        pstList->pstLastItemRead = (SLinkedListItem_t*)  0UL;
    }
    return (enStatus);
}
