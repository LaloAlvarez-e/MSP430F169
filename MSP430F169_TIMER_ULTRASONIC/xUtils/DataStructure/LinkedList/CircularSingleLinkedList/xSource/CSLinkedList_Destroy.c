/**
 *
 * @file CSLinkedList_Destroy.c
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
#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/xHeader/CSLinkedList_Destroy.h>

#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/Intrinsics/List/xHeader/CSLinkedList_Size.h>
#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/Intrinsics/List/xHeader/CSLinkedList_Head.h>
#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/xHeader/CSLinkedList_Init.h>
#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/xHeader/CSLinkedList_Remove.h>

void CSLinkedList__vDestroy(CSLinkedList_t* pstList)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    CSLinkedListItem_t* pstHeadItem = (CSLinkedListItem_t*) 0UL;
    void * pvDataItem = (void*)0UL;
    uint32_t u32SizeReg = 0UL;
    void (*pvfListDestroy) (void* List) = (void (*) (void* List) )0UL;

    if((CSLinkedList_t*)0 != pstList)
    {
        enStatus = CSLinkedList_enSTATUS_OK;
        u32SizeReg = CSLinkedList__u32GetSize(pstList);
        pvfListDestroy = pstList->pvfDestroy;
        while (u32SizeReg> 0UL)
        {
            pstHeadItem = CSLinkedList__pstGetHead(pstList);
            enStatus = CSLinkedList__enRemoveNextInList_GetData(pstList, pstHeadItem, (void **) & pvDataItem);
            if((CSLinkedList_enSTATUS_OK == enStatus ) && ( (uint32_t) 0 != (uint32_t) pstList->pvfDestroyItemData))
            {
                pstList->pvfDestroyItemData(pvDataItem);
            }
            u32SizeReg = CSLinkedList__u32GetSize(pstList);
        }

        pstList->pfu32Match = (uint32_t (*) (const void *pcvKey1, const void *pcvKey2)) 0UL;
        pstList->pvfDestroy = (void (*) (void* List)) 0UL;
        pstList->pvfDestroyItemData = (void (*) (void* DataContainer)) 0UL;
        pstList->pvfDestroyItem = (void (*) (void* Item)) 0UL;
        pstList->pstHead = (CSLinkedListItem_t *) 0UL;
        pstList->pstTail = (CSLinkedListItem_t *) 0UL;
        pstList->pstLastItemRead = (CSLinkedListItem_t*)  0UL;
        pstList->u32Size = 0UL;

        if((CSLinkedList_enSTATUS_OK == enStatus ) && ( (uint32_t) 0 != (uint32_t) pvfListDestroy))
        {
            pvfListDestroy(pstList);
            pstList = (CSLinkedList_t*)0UL;
        }
    }
}
