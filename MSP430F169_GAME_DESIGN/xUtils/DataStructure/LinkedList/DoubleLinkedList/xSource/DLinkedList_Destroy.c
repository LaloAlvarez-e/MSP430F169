/**
 *
 * @file DLinkedList_Destroy.c
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
#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/xHeader/DLinkedList_Destroy.h>

#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/List/xHeader/DLinkedList_Size.h>
#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/List/xHeader/DLinkedList_Tail.h>
#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/xHeader/DLinkedList_Init.h>
#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/xHeader/DLinkedList_Remove.h>

void DLinkedList__vDestroy(DLinkedList_t* pstList)
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    DLinkedListItem_t* pstTailItem = (DLinkedListItem_t*) 0UL;
    void * pvDataItem = (void*)0UL;
    uint32_t u32SizeReg = 0UL;
    void (*pvfListDestroy) (void* List) = (void (*) (void* List) )0UL;

    if((DLinkedList_t*)0 != pstList)
    {
        enStatus = DLinkedList_enSTATUS_OK;
        u32SizeReg = DLinkedList__u32GetSize(pstList);
        pvfListDestroy = pstList->pvfDestroy;
        while (u32SizeReg > 0UL)
        {
            pstTailItem = DLinkedList__pstGetTail(pstList);
            enStatus = DLinkedList__enRemoveInList_GetData(pstList, pstTailItem, (void **) & pvDataItem);
            if((DLinkedList_enSTATUS_OK == enStatus ) && ( (uint32_t) 0 != (uint32_t) pstList->pvfDestroyItemData))
            {
                pstList->pvfDestroyItemData(pvDataItem);
            }
            u32SizeReg = DLinkedList__u32GetSize(pstList);
        }

        pstList->pfu32Match = (uint32_t (*) (const void *pcvKey1, const void *pcvKey2)) 0UL;
        pstList->pvfDestroy = (void (*) (void* List)) 0UL;
        pstList->pvfDestroyItemData = (void (*) (void* DataContainer)) 0UL;
        pstList->pvfDestroyItem = (void (*) (void* Item)) 0UL;
        pstList->pstHead = (DLinkedListItem_t *) 0UL;
        pstList->pstTail = (DLinkedListItem_t *) 0UL;
        pstList->pstLastItemRead = (DLinkedListItem_t*)  0UL;
        pstList->u32Size = 0UL;

        if((DLinkedList_enSTATUS_OK == enStatus ) && (0UL != (uint32_t) pvfListDestroy))
        {
            pvfListDestroy(pstList);
            pstList = (DLinkedList_t*) 0UL;
        }
    }
}
