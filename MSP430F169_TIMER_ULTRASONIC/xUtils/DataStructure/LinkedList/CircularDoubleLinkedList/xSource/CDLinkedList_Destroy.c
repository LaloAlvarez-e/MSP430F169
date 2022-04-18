/**
 *
 * @file CDLinkedList_Destroy.c
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
#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/xHeader/CDLinkedList_Destroy.h>

#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/Intrinsics/List/xHeader/CDLinkedList_Size.h>
#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/Intrinsics/List/xHeader/CDLinkedList_Tail.h>
#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/xHeader/CDLinkedList_Init.h>
#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/xHeader/CDLinkedList_Remove.h>

void CDLinkedList__vDestroy(CDLinkedList_t* pstList)
 {
     CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
     CDLinkedListItem_t* pstTailItem = (CDLinkedListItem_t*) 0UL;
     void * pvDataItem = (void*)0UL;
     uint32_t u32SizeReg = 0UL;
     void (*pvfListDestroy) (void* List) = (void (*) (void* List) )0UL;

     if((CDLinkedList_t*)0 != pstList)
     {
         enStatus = CDLinkedList_enSTATUS_OK;
         u32SizeReg = CDLinkedList__u32GetSize(pstList);
         pvfListDestroy = pstList->pvfDestroy;
         while (u32SizeReg> 0UL)
         {
             pstTailItem = CDLinkedList__pstGetTail(pstList);
             enStatus = CDLinkedList__enRemoveInList_GetData(pstList, pstTailItem, (void **) & pvDataItem);
             if((CDLinkedList_enSTATUS_OK == enStatus ) && ( (uint32_t) 0 != (uint32_t) pstList->pvfDestroyItemData))
             {
                 pstList->pvfDestroyItemData(pvDataItem);
             }
             u32SizeReg = CDLinkedList__u32GetSize(pstList);
         }

         pstList->pfu32Match = (uint32_t (*) (const void *pcvKey1, const void *pcvKey2)) 0UL;
         pstList->pvfDestroy = (void (*) (void* List)) 0UL;
         pstList->pvfDestroyItemData = (void (*) (void* DataContainer)) 0UL;
         pstList->pvfDestroyItem = (void (*) (void* Item)) 0UL;
         pstList->pstHead = (CDLinkedListItem_t *) 0UL;
         pstList->pstTail = (CDLinkedListItem_t *) 0UL;
         pstList->pstLastItemRead = (CDLinkedListItem_t*)  0UL;
         pstList->u32Size = 0UL;

         if((CDLinkedList_enSTATUS_OK == enStatus ) && ( (uint32_t) 0 != (uint32_t) pvfListDestroy))
         {
             pvfListDestroy(pstList);
             pstList = (CDLinkedList_t*)0UL;
         }
     }
 }
