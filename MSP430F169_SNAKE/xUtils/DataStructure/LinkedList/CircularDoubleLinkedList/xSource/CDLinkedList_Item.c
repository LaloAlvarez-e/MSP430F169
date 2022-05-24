/**
 *
 * @file CDLinkedList_Item.c
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
#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/xHeader/CDLinkedList_Item.h>

#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/Intrinsics/CDLinkedList_Intrinsics.h>

CDLinkedListItem_t*  CDLinkedList__pstGetItemPos(const CDLinkedList_t* pstList, uint32_t u32Position)
{
    CDLinkedListItem_t* pstItem = (CDLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    uint32_t u32SizeForward = 0UL;
    uint32_t u32SizeBackward = 0UL;
    uint32_t u32SizeOptimum = 0UL;
    uint32_t u32Direction = 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        u32SizeList = CDLinkedList__u32GetSize(pstList);
        if(u32Position < u32SizeList)
        {
            if(0UL == u32Position)
            {
                pstItem = CDLinkedList__pstGetHead(pstList);
            }
            else if((uint32_t) u32Position == (uint32_t) (u32SizeList - 1UL))
            {
                pstItem = CDLinkedList__pstGetTail(pstList);
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
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = CDLinkedList_Item__pstGetNextItem(pstItem);
                        u32SizeOptimum--;
                    }
                }
                else /*Backward*/
                {
                    pstItem = CDLinkedList__pstGetTail(pstList);
                    while(0UL != u32SizeOptimum)
                    {
                        pstItem = CDLinkedList_Item__pstGetPreviousItem(pstItem);
                        u32SizeOptimum--;
                    }
                }
            }
        }
    }
    return (pstItem);
}

uint32_t CDLinkedList__u32GetAllItem(const CDLinkedList_t* pstList, const void** pvData, uint32_t u32MaxLength)
{
    CDLinkedListItem_t *pstMember = (CDLinkedListItem_t*) 0UL;
    CDLinkedListItem_t *pstMemberTemp = (CDLinkedListItem_t*) 0UL;
    void* pvDataMember = (void*)0UL;
    uint32_t u32SizeReg = 0UL;
    uint32_t u32SizeList = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pvData ) && (0UL != u32MaxLength))
    {
        pstMember = CDLinkedList__pstGetHead(pstList);
        u32SizeList = CDLinkedList__u32GetSize(pstList);
        while((0UL != u32MaxLength) && (u32SizeReg != u32SizeList))
        {
            pvDataMember = CDLinkedList_Item__pvGetData(pstMember);
            *pvData = pvDataMember;
            u32SizeReg++;
            pvData += 1U;
            u32MaxLength--;
            pstMemberTemp = CDLinkedList_Item__pstGetNextItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}

uint32_t CDLinkedList__u32GetAllItem_Value(const CDLinkedList_t* pstList, uint32_t* pu32ValueItem, uint32_t u32MaxLength)
{
    CDLinkedListItem_t *pstMember = (CDLinkedListItem_t*) 0UL;
    CDLinkedListItem_t *pstMemberTemp = (CDLinkedListItem_t*) 0UL;
    uint32_t pu32ValueItemMember = (uint32_t)0UL;
    uint32_t u32SizeReg = 0UL;
    uint32_t u32SizeList = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pu32ValueItem ) && (0UL != u32MaxLength))
    {
        pstMember = CDLinkedList__pstGetHead(pstList);
        u32SizeList = CDLinkedList__u32GetSize(pstList);
        while((0UL != u32MaxLength) && (u32SizeReg != u32SizeList))
        {
            pu32ValueItemMember = CDLinkedList_Item__u32GetValue(pstMember);
            *pu32ValueItem = pu32ValueItemMember;
            u32SizeReg++;
            pu32ValueItem += 1U;
            u32MaxLength--;
            pstMemberTemp = CDLinkedList_Item__pstGetNextItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}

uint32_t CDLinkedList__u32GetAllItemBackward(const CDLinkedList_t* pstList, void** pvData, uint32_t u32MaxLength)
{
    CDLinkedListItem_t *pstMember = (CDLinkedListItem_t*) 0UL;
    CDLinkedListItem_t *pstMemberTemp = (CDLinkedListItem_t*) 0UL;
    void* pvDataMember = (void*)0UL;
    uint32_t u32SizeReg = 0UL;
    uint32_t u32SizeList = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pvData ) && (0UL != u32MaxLength))
    {
        pstMember = CDLinkedList__pstGetTail(pstList);
        u32SizeList = CDLinkedList__u32GetSize(pstList);
        while((0UL != u32MaxLength) && (u32SizeReg != u32SizeList))
        {
            pvDataMember = CDLinkedList_Item__pvGetData(pstMember);
            *pvData = pvDataMember;
            u32SizeReg++;
            pvData += 1U;
            u32MaxLength--;
            pstMemberTemp = CDLinkedList_Item__pstGetPreviousItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}

uint32_t CDLinkedList__u32GetAllItemBackward_Value(const CDLinkedList_t* pstList, uint32_t* pu32ValueItem, uint32_t u32MaxLength)
{
    CDLinkedListItem_t *pstMember = (CDLinkedListItem_t*) 0UL;
    CDLinkedListItem_t *pstMemberTemp = (CDLinkedListItem_t*) 0UL;
    uint32_t pu32ValueItemMember = (uint32_t)0UL;
    uint32_t u32SizeReg = 0UL;
    uint32_t u32SizeList = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pu32ValueItem ) && (0UL != u32MaxLength))
    {
        pstMember = CDLinkedList__pstGetTail(pstList);
        u32SizeList = CDLinkedList__u32GetSize(pstList);
        while((0UL != u32MaxLength) && (u32SizeReg != u32SizeList))
        {
            pu32ValueItemMember = CDLinkedList_Item__u32GetValue(pstMember);
            *pu32ValueItem = pu32ValueItemMember;
            u32SizeReg++;
            pu32ValueItem += 1U;
            u32MaxLength--;
            pstMemberTemp = CDLinkedList_Item__pstGetPreviousItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}

uint32_t CDLinkedList__u32GetNItem(const CDLinkedList_t* pstList, void** pvData, uint32_t u32Items, uint32_t u32MaxLength)
{
    CDLinkedListItem_t *pstMember = (CDLinkedListItem_t*) 0UL;
    CDLinkedListItem_t *pstMemberTemp = (CDLinkedListItem_t*) 0UL;
    void* pvDataMember = (void*)0UL;
    uint32_t u32SizeReg = 0UL;
    uint32_t u32SizeList = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pvData ) && (0UL != u32MaxLength) && (0UL != u32Items))
    {
        pstMember = CDLinkedList__pstGetHead(pstList);
        u32SizeList = CDLinkedList__u32GetSize(pstList);
        while((0UL != u32MaxLength) && (u32SizeReg != u32SizeList) && (0UL != u32Items))
        {
            pvDataMember = CDLinkedList_Item__pvGetData(pstMember);
            *pvData = pvDataMember;
            u32SizeReg++;
            pvData += 1U;
            u32MaxLength--;
            u32Items--;
            pstMemberTemp = CDLinkedList_Item__pstGetNextItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}

uint32_t CDLinkedList__u32GetNItem_Value(const CDLinkedList_t* pstList, uint32_t* pu32ValueItem, uint32_t u32Items, uint32_t u32MaxLength)
{
    CDLinkedListItem_t *pstMember = (CDLinkedListItem_t*) 0UL;
    CDLinkedListItem_t *pstMemberTemp = (CDLinkedListItem_t*) 0UL;
    uint32_t pu32ValueItemMember = (uint32_t)0UL;
    uint32_t u32SizeReg = 0UL;
    uint32_t u32SizeList = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pu32ValueItem ) && (0UL != u32MaxLength) && (0UL != u32Items))
    {
        pstMember = CDLinkedList__pstGetHead(pstList);
        u32SizeList = CDLinkedList__u32GetSize(pstList);
        while((0UL != u32MaxLength) && (u32SizeReg != u32SizeList) && (0UL != u32Items))
        {
            pu32ValueItemMember = CDLinkedList_Item__u32GetValue(pstMember);
            *pu32ValueItem = pu32ValueItemMember;
            u32SizeReg++;
            pu32ValueItem += 1U;
            u32MaxLength--;
            u32Items--;
            pstMemberTemp = CDLinkedList_Item__pstGetNextItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}

uint32_t CDLinkedList__u32GetNItemBackward(const CDLinkedList_t* pstList, void** pvData, uint32_t u32Items, uint32_t u32MaxLength)
{
    CDLinkedListItem_t *pstMember = (CDLinkedListItem_t*) 0UL;
    CDLinkedListItem_t *pstMemberTemp = (CDLinkedListItem_t*) 0UL;
    void* pvDataMember = (void*)0UL;
    uint32_t u32SizeReg = 0UL;
    uint32_t u32SizeList = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pvData ) && (0UL != u32MaxLength) && (0UL != u32Items))
    {
        pstMember = CDLinkedList__pstGetTail(pstList);
        u32SizeList = CDLinkedList__u32GetSize(pstList);
        while((0UL != u32MaxLength) && (u32SizeReg != u32SizeList) && (0UL != u32Items))
        {
            pvDataMember = CDLinkedList_Item__pvGetData(pstMember);
            *pvData = pvDataMember;
            u32SizeReg++;
            pvData += 1U;
            u32MaxLength--;
            u32Items--;
            pstMemberTemp = CDLinkedList_Item__pstGetPreviousItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}

uint32_t CDLinkedList__u32GetNItemBackward_Value(const CDLinkedList_t* pstList, uint32_t* pu32ValueItem, uint32_t u32Items, uint32_t u32MaxLength)
{
    CDLinkedListItem_t *pstMember = (CDLinkedListItem_t*) 0UL;
    CDLinkedListItem_t *pstMemberTemp = (CDLinkedListItem_t*) 0UL;
    uint32_t pu32ValueItemMember = (uint32_t)0UL;
    uint32_t u32SizeReg = 0UL;
    uint32_t u32SizeList = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pu32ValueItem ) && (0UL != u32MaxLength) && (0UL != u32Items))
    {
        pstMember = CDLinkedList__pstGetTail(pstList);
        u32SizeList = CDLinkedList__u32GetSize(pstList);
        while((0UL != u32MaxLength) && (u32SizeReg != u32SizeList) && (0UL != u32Items))
        {
            pu32ValueItemMember = CDLinkedList_Item__u32GetValue(pstMember);
            *pu32ValueItem = pu32ValueItemMember;
            u32SizeReg++;
            pu32ValueItem += 1U;
            u32MaxLength--;
            u32Items--;
            pstMemberTemp = CDLinkedList_Item__pstGetPreviousItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}
