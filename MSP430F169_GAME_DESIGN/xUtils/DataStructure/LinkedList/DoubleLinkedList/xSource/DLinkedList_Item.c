/**
 *
 * @file DLinkedList_Item.c
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
#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/xHeader/DLinkedList_Item.h>

#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/DLinkedList_Intrinsics.h>

DLinkedListItem_t*  DLinkedList__pstGetItemPos(const DLinkedList_t* pstList, uint32_t u32Position)
{
    DLinkedListItem_t* pstItem = (DLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    uint32_t u32SizeForward = 0UL;
    uint32_t u32SizeBackward = 0UL;
    uint32_t u32SizeOptimum = 0UL;
    uint32_t u32Direction = 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        u32SizeList = DLinkedList__u32GetSize(pstList);
        if(u32Position < u32SizeList)
        {
            if(0UL == u32Position)
            {
                pstItem = DLinkedList__pstGetHead(pstList);
            }
            else if((uint32_t) u32Position == (uint32_t) (u32SizeList - 1UL))
            {
                pstItem = DLinkedList__pstGetTail(pstList);
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
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = DLinkedList_Item__pstGetNextItem(pstItem);
                        u32SizeOptimum--;
                    }
                }
                else /*Backward*/
                {
                    pstItem = DLinkedList__pstGetTail(pstList);
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = DLinkedList_Item__pstGetPreviousItem(pstItem);
                        u32SizeOptimum--;
                    }
                }
            }
        }
    }
    return (pstItem);
}

uint32_t DLinkedList__u32GetAllItem(const DLinkedList_t* pstList, void** pvData, uint32_t u32MaxLength)
{
    DLinkedListItem_t *pstMember = (DLinkedListItem_t*) 0UL;
    DLinkedListItem_t *pstMemberTemp = (DLinkedListItem_t*) 0UL;
    void* pvDataMember = (void*)0UL;
    uint32_t u32SizeReg = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pvData ) && (0UL != u32MaxLength))
    {
        pstMember = DLinkedList__pstGetHead(pstList);
        while(((uint32_t) 0UL != (uint32_t) pstMember) && (0UL != u32MaxLength))
        {
            pvDataMember = DLinkedList_Item__pvGetData(pstMember);
            *pvData = pvDataMember;
            u32SizeReg++;
            pvData += 1U;
            u32MaxLength--;
            pstMemberTemp = DLinkedList_Item__pstGetNextItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}

uint32_t DLinkedList__u32GetAllItem_Value(const DLinkedList_t* pstList, uint32_t* pu32ValueItem, uint32_t u32MaxLength)
{
    DLinkedListItem_t *pstMember = (DLinkedListItem_t*) 0UL;
    DLinkedListItem_t *pstMemberTemp = (DLinkedListItem_t*) 0UL;
    uint32_t pu32ValueItemMember = (uint32_t)0UL;
    uint32_t u32SizeReg = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pu32ValueItem ) && (0UL != u32MaxLength))
    {
        pstMember = DLinkedList__pstGetHead(pstList);
        while(((uint32_t) 0UL != (uint32_t) pstMember) && (0UL != u32MaxLength))
        {
            pu32ValueItemMember = DLinkedList_Item__u32GetValue(pstMember);
            *pu32ValueItem = pu32ValueItemMember;
            u32SizeReg++;
            pu32ValueItem += 1U;
            u32MaxLength--;
            pstMemberTemp = DLinkedList_Item__pstGetNextItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}


uint32_t DLinkedList__u32GetAllItemBackward(const DLinkedList_t* pstList, void** pvData, uint32_t u32MaxLength)
{
    DLinkedListItem_t *pstMember = (DLinkedListItem_t*) 0UL;
    DLinkedListItem_t *pstMemberTemp = (DLinkedListItem_t*) 0UL;
    void* pvDataMember = (void*)0UL;
    uint32_t u32SizeReg = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pvData ) && (0UL != u32MaxLength))
    {
        pstMember = DLinkedList__pstGetTail(pstList);
        while(((uint32_t) 0UL != (uint32_t) pstMember) && (0UL != u32MaxLength))
        {
            pvDataMember = DLinkedList_Item__pvGetData(pstMember);
            *pvData = pvDataMember;
            u32SizeReg++;
            pvData += 1U;
            u32MaxLength--;
            pstMemberTemp = DLinkedList_Item__pstGetPreviousItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}

uint32_t DLinkedList__u32GetAllItemBackward_Value(const DLinkedList_t* pstList, uint32_t* pu32ValueItem, uint32_t u32MaxLength)
{
    DLinkedListItem_t *pstMember = (DLinkedListItem_t*) 0UL;
    DLinkedListItem_t *pstMemberTemp = (DLinkedListItem_t*) 0UL;
    uint32_t pu32ValueItemMember = (uint32_t)0UL;
    uint32_t u32SizeReg = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pu32ValueItem ) && (0UL != u32MaxLength))
    {
        pstMember = DLinkedList__pstGetTail(pstList);
        while(((uint32_t) 0UL != (uint32_t) pstMember) && (0UL != u32MaxLength))
        {
            pu32ValueItemMember = DLinkedList_Item__u32GetValue(pstMember);
            *pu32ValueItem = pu32ValueItemMember;
            u32SizeReg++;
            pu32ValueItem += 1U;
            u32MaxLength--;
            pstMemberTemp = DLinkedList_Item__pstGetPreviousItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}

uint32_t DLinkedList__u32GetNItem(const DLinkedList_t* pstList, void** pvData, uint32_t u32Items, uint32_t u32MaxLength)
{
    DLinkedListItem_t *pstMember = (DLinkedListItem_t*) 0UL;
    DLinkedListItem_t *pstMemberTemp = (DLinkedListItem_t*) 0UL;
    void* pvDataMember = (void*)0UL;
    uint32_t u32SizeReg = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pvData ) && (0UL != u32MaxLength) && (0UL != u32Items))
    {
        pstMember = DLinkedList__pstGetHead(pstList);
        while(((uint32_t) 0UL != (uint32_t) pstMember) && (0UL != u32MaxLength) && (0UL != u32Items))
        {
            pvDataMember = DLinkedList_Item__pvGetData(pstMember);
            *pvData = pvDataMember;
            u32SizeReg++;
            pvData += 1U;
            u32MaxLength--;
            u32Items--;
            pstMemberTemp = DLinkedList_Item__pstGetNextItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}

uint32_t DLinkedList__u32GetNItem_Value(const DLinkedList_t* pstList, uint32_t* pu32ValueItem, uint32_t u32Items, uint32_t u32MaxLength)
{
    DLinkedListItem_t *pstMember = (DLinkedListItem_t*) 0UL;
    DLinkedListItem_t *pstMemberTemp = (DLinkedListItem_t*) 0UL;
    uint32_t pu32ValueItemMember = (uint32_t)0UL;
    uint32_t u32SizeReg = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pu32ValueItem ) && (0UL != u32MaxLength) && (0UL != u32Items))
    {
        pstMember = DLinkedList__pstGetHead(pstList);
        while(((uint32_t) 0UL != (uint32_t) pstMember) && (0UL != u32MaxLength) && (0UL != u32Items))
        {
            pu32ValueItemMember = DLinkedList_Item__u32GetValue(pstMember);
            *pu32ValueItem = pu32ValueItemMember;
            u32SizeReg++;
            pu32ValueItem += 1U;
            u32MaxLength--;
            u32Items--;
            pstMemberTemp = DLinkedList_Item__pstGetNextItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}

uint32_t DLinkedList__u32GetNItemBackward(const DLinkedList_t* pstList, void** pvData, uint32_t u32Items, uint32_t u32MaxLength)
{
    DLinkedListItem_t *pstMember = (DLinkedListItem_t*) 0UL;
    DLinkedListItem_t *pstMemberTemp = (DLinkedListItem_t*) 0UL;
    void* pvDataMember = (void*)0UL;
    uint32_t u32SizeReg = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pvData ) && (0UL != u32MaxLength) && (0UL != u32Items))
    {
        pstMember = DLinkedList__pstGetTail(pstList);
        while(((uint32_t) 0UL != (uint32_t) pstMember) && (0UL != u32MaxLength) && (0UL != u32Items))
        {
            pvDataMember = DLinkedList_Item__pvGetData(pstMember);
            *pvData = pvDataMember;
            u32SizeReg++;
            pvData += 1U;
            u32MaxLength--;
            u32Items--;
            pstMemberTemp = DLinkedList_Item__pstGetPreviousItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}

uint32_t DLinkedList__u32GetNItemBackward_Value(const DLinkedList_t* pstList, uint32_t* pu32ValueItem, uint32_t u32Items, uint32_t u32MaxLength)
{
    DLinkedListItem_t *pstMember = (DLinkedListItem_t*) 0UL;
    DLinkedListItem_t *pstMemberTemp = (DLinkedListItem_t*) 0UL;
    uint32_t pu32ValueItemMember = (uint32_t)0UL;
    uint32_t u32SizeReg = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pu32ValueItem ) && (0UL != u32MaxLength) && (0UL != u32Items))
    {
        pstMember = DLinkedList__pstGetTail(pstList);
        while(((uint32_t) 0UL != (uint32_t) pstMember) && (0UL != u32MaxLength) && (0UL != u32Items))
        {
            pu32ValueItemMember = DLinkedList_Item__u32GetValue(pstMember);
            *pu32ValueItem = pu32ValueItemMember;
            u32SizeReg++;
            pu32ValueItem += 1U;
            u32MaxLength--;
            u32Items--;
            pstMemberTemp = DLinkedList_Item__pstGetPreviousItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}

