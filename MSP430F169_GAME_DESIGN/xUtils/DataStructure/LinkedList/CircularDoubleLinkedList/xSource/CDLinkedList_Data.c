/**
 *
 * @file CDLinkedList_Data.c
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
#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/xHeader/CDLinkedList_Data.h>

#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/Intrinsics/CDLinkedList_Intrinsics.h>
#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/xHeader/CDLinkedList_Item.h>

void* CDLinkedList__pvGetDataItemPos(const CDLinkedList_t* pstList, uint32_t u32Position)
{
    CDLinkedListItem_t* pstItem = (CDLinkedListItem_t*) 0UL;
    void* pvItemData = (void*) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = CDLinkedList__pstGetItemPos(pstList, u32Position);
        if((uint32_t) 0UL != (uint32_t) pstItem)
        {
            pvItemData = CDLinkedList_Item__pvGetData(pstItem);
        }
    }
    return (pvItemData);
}

uint32_t CDLinkedList__u32GetValueItemPos(const CDLinkedList_t* pstList, uint32_t u32Position)
{
    CDLinkedListItem_t* pstItem = (CDLinkedListItem_t*) 0UL;
    uint32_t u32ItemData = 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = CDLinkedList__pstGetItemPos(pstList, u32Position);
        if((uint32_t) 0UL != (uint32_t) pstItem)
        {
            u32ItemData = CDLinkedList_Item__u32GetValue(pstItem);
        }
    }
    return (u32ItemData);
}

void* CDLinkedList__pvGetDataTail(const CDLinkedList_t* pstList)
{
    CDLinkedListItem_t* pstItem = (CDLinkedListItem_t*) 0UL;
    void* pvItemData = (void*) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = CDLinkedList__pstGetTail(pstList);
        if((uint32_t) pstItem != (uint32_t) 0UL)
        {
            pvItemData = CDLinkedList_Item__pvGetData(pstItem);
        }
    }
    return (pvItemData);
}

uint32_t CDLinkedList__u32GetValueTail(const CDLinkedList_t* pstList)
{
    CDLinkedListItem_t* pstItem = (CDLinkedListItem_t*) 0UL;
    uint32_t u32ItemValue = (uint32_t) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = CDLinkedList__pstGetTail(pstList);
        if((uint32_t) pstItem != (uint32_t) 0UL)
        {
            u32ItemValue = CDLinkedList_Item__u32GetValue(pstItem);
        }
    }
    return (u32ItemValue);
}

void* CDLinkedList__pvGetDataHead(const CDLinkedList_t* pstList)
{
    CDLinkedListItem_t* pstItem = (CDLinkedListItem_t*) 0UL;
    void* pvItemData = (void*) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = CDLinkedList__pstGetHead(pstList);
        if((uint32_t) pstItem != (uint32_t) 0UL)
        {
            pvItemData = CDLinkedList_Item__pvGetData(pstItem);
        }
    }
    return (pvItemData);
}

uint32_t CDLinkedList__u32GetValueHead(const CDLinkedList_t* pstList)
{
    CDLinkedListItem_t* pstItem = (CDLinkedListItem_t*) 0UL;
    uint32_t u32ItemValue = (uint32_t) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = CDLinkedList__pstGetHead(pstList);
        if((uint32_t) pstItem != (uint32_t) 0UL)
        {
            u32ItemValue = CDLinkedList_Item__u32GetValue(pstItem);
        }
    }
    return (u32ItemValue);
}

void* CDLinkedList__pvGetDataNextItem(CDLinkedList_t* const pstList)
{
    CDLinkedListItem_t* pstLastItemReg = (CDLinkedListItem_t*) 0UL;
    CDLinkedListItem_t* pstNextItemReg = (CDLinkedListItem_t*) 0UL;
    void* pvItemData = (void*) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstLastItemReg = CDLinkedList__pstGetLastItemRead(pstList);
        if((uint32_t) pstLastItemReg != (uint32_t) 0UL)
        {
            pstNextItemReg = CDLinkedList_Item__pstGetNextItem(pstLastItemReg);
        }
        else
        {
            pstNextItemReg = CDLinkedList__pstGetHead(pstList);
        }
        CDLinkedList__vSetLastItemRead(pstList, pstNextItemReg);
        pvItemData = CDLinkedList_Item__pvGetData(pstNextItemReg);
    }
    return (pvItemData);
}

void* CDLinkedList__pvGetDataPreviousItem(CDLinkedList_t* pstList)
{
    CDLinkedListItem_t* pstLastItemReg = (CDLinkedListItem_t*) 0UL;
    CDLinkedListItem_t* pstPreviousItemReg = (CDLinkedListItem_t*) 0UL;
    void* pvItemData = (void*) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstLastItemReg = CDLinkedList__pstGetLastItemRead(pstList);
        if((uint32_t) pstLastItemReg != (uint32_t) 0UL)
        {
            pstPreviousItemReg = CDLinkedList_Item__pstGetPreviousItem(pstLastItemReg);
        }
        else
        {
            pstPreviousItemReg = CDLinkedList__pstGetTail(pstList);
        }
        CDLinkedList__vSetLastItemRead(pstList, pstPreviousItemReg);
        pvItemData = CDLinkedList_Item__pvGetData(pstPreviousItemReg);
    }
    return (pvItemData);
}
