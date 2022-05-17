/**
 *
 * @file DLinkedList_Data.c
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
#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/xHeader/DLinkedList_Data.h>

#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/DLinkedList_Intrinsics.h>
#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/xHeader/DLinkedList_Item.h>

void* DLinkedList__pvGetDataItemPos(const DLinkedList_t* pstList, uint32_t u32Position)
{
    DLinkedListItem_t* pstItem = (DLinkedListItem_t*) 0UL;
    void* pvItemData = (void*) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = DLinkedList__pstGetItemPos(pstList, u32Position);
        if((uint32_t) 0UL != (uint32_t) pstItem)
        {
            pvItemData = DLinkedList_Item__pvGetData(pstItem);
        }
    }
    return (pvItemData);
}

void* DLinkedList__pvGetDataTail(const DLinkedList_t* pstList)
{
    DLinkedListItem_t* pstItem = (DLinkedListItem_t*) 0UL;
    void* pvItemData = (void*) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = DLinkedList__pstGetTail(pstList);
        if((uint32_t) 0UL != (uint32_t) pstItem)
        {
            pvItemData = DLinkedList_Item__pvGetData(pstItem);
        }
    }
    return (pvItemData);
}

void* DLinkedList__pvGetDataHead(const DLinkedList_t* pstList)
{
    DLinkedListItem_t* pstItem = (DLinkedListItem_t*) 0UL;
    void* pvItemData = (void*) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = DLinkedList__pstGetHead(pstList);
        if((uint32_t) 0UL != (uint32_t) pstItem)
        {
            pvItemData = DLinkedList_Item__pvGetData(pstItem);
        }
    }
    return (pvItemData);
}


uint32_t DLinkedList__u32GetValueItemPos(const DLinkedList_t* pstList, uint32_t u32Position)
{
    DLinkedListItem_t* pstItem = (DLinkedListItem_t*) 0UL;
    uint32_t u32ItemValue = (uint32_t) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = DLinkedList__pstGetItemPos(pstList, u32Position);
        if((uint32_t) 0UL != (uint32_t) pstItem)
        {
            u32ItemValue = DLinkedList_Item__u32GetValue(pstItem);
        }
    }
    return (u32ItemValue);
}

uint32_t DLinkedList__u32GetValueTail(const DLinkedList_t* pstList)
{
    DLinkedListItem_t* pstItem = (DLinkedListItem_t*) 0UL;
    uint32_t u32ItemValue = (uint32_t) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = DLinkedList__pstGetTail(pstList);
        if((uint32_t) 0UL != (uint32_t) pstItem)
        {
            u32ItemValue = DLinkedList_Item__u32GetValue(pstItem);
        }
    }
    return (u32ItemValue);
}

uint32_t DLinkedList__u32GetValueHead(const DLinkedList_t* pstList)
{
    DLinkedListItem_t* pstItem = (DLinkedListItem_t*) 0UL;
    uint32_t u32ItemValue = (uint32_t) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstItem = DLinkedList__pstGetHead(pstList);
        if((uint32_t) 0UL != (uint32_t) pstItem)
        {
            u32ItemValue = DLinkedList_Item__u32GetValue(pstItem);
        }
    }
    return (u32ItemValue);
}

void* DLinkedList__pvGetDataNextItem(DLinkedList_t* pstList)
{
    DLinkedListItem_t* pstLastItemReg = (DLinkedListItem_t*) 0UL;
    DLinkedListItem_t* pstNextItemReg = (DLinkedListItem_t*) 0UL;
    void* pvItemData = (void*) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstLastItemReg = DLinkedList__pstGetLastItemRead(pstList);
        if((uint32_t) pstLastItemReg != (uint32_t) 0UL)
        {
            pstNextItemReg = DLinkedList_Item__pstGetNextItem(pstLastItemReg);
        }
        else
        {
            pstNextItemReg = DLinkedList__pstGetHead(pstList);
        }
        DLinkedList__vSetLastItemRead(pstList, pstNextItemReg);
        pvItemData = DLinkedList_Item__pvGetData(pstNextItemReg);
    }
    return (pvItemData);
}

void* DLinkedList__pvGetDataPreviousItem(DLinkedList_t* pstList)
{
    DLinkedListItem_t* pstLastItemReg = (DLinkedListItem_t*) 0UL;
    DLinkedListItem_t* pstPreviousItemReg = (DLinkedListItem_t*) 0UL;
    void* pvItemData = (void*) 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        pstLastItemReg = DLinkedList__pstGetLastItemRead(pstList);
        if((uint32_t) pstLastItemReg != (uint32_t) 0UL)
        {
            pstPreviousItemReg = DLinkedList_Item__pstGetPreviousItem(pstLastItemReg);
        }
        else
        {
            pstPreviousItemReg = DLinkedList__pstGetTail(pstList);
        }
        DLinkedList__vSetLastItemRead(pstList, pstPreviousItemReg);
        pvItemData = DLinkedList_Item__pvGetData(pstPreviousItemReg);
    }
    return (pvItemData);
}
