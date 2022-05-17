/**
 *
 * @file CSLinkedList_Item.c
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
 * @verbatim 10 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 10 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/xHeader/CSLinkedList_Item.h>

#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/Intrinsics/CSLinkedList_Intrinsics.h>

CSLinkedListItem_t*  CSLinkedList__pstGetItemPos(const CSLinkedList_t* pstList, uint32_t u32Position)
{
    CSLinkedListItem_t* pstItem = (CSLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        u32SizeList = CSLinkedList__u32GetSize(pstList);
        if(u32Position < u32SizeList)
        {
            if(0UL == u32Position)
            {
                pstItem = CSLinkedList__pstGetHead(pstList);
            }
            else if((uint32_t) (u32SizeList -1UL) == (uint32_t) u32Position)
            {
                pstItem = CSLinkedList__pstGetTail(pstList);
            }
            else
            {
                pstItem = CSLinkedList__pstGetHead(pstList);
                while(0UL != u32Position)
                {
                    pstItem = CSLinkedList_Item__pstGetNextItem(pstItem);
                    u32Position--;
                }
            }
        }
    }
    return (pstItem);
}

uint32_t CSLinkedList__u32GetAllItem(const CSLinkedList_t* pstList, void** pvData, uint32_t u32MaxLength)
{
    CSLinkedListItem_t *pstMember = (CSLinkedListItem_t*) 0UL;
    CSLinkedListItem_t *pstMemberTemp = (CSLinkedListItem_t*) 0UL;
    void* pvDataMember = (void*)0UL;
    uint32_t u32SizeReg = 0UL;
    uint32_t u32SizeList = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pvData ) && (0UL != u32MaxLength))
    {
        pstMember = CSLinkedList__pstGetHead(pstList);
        u32SizeList = CSLinkedList__u32GetSize(pstList);
        while((0UL != u32MaxLength) && (u32SizeReg != u32SizeList))
        {
            pvDataMember = CSLinkedList_Item__pvGetData(pstMember);
            *pvData = pvDataMember;
            u32SizeReg++;
            pvData += 1U;
            u32MaxLength--;
            pstMemberTemp = CSLinkedList_Item__pstGetNextItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}

uint32_t CSLinkedList__u32GetAllItem_Value(const CSLinkedList_t* pstList, uint32_t* pu32ValueItem, uint32_t u32MaxLength)
{
    CSLinkedListItem_t *pstMember = (CSLinkedListItem_t*) 0UL;
    CSLinkedListItem_t *pstMemberTemp = (CSLinkedListItem_t*) 0UL;
    uint32_t pu32ValueItemMember = (uint32_t)0UL;
    uint32_t u32SizeReg = 0UL;
    uint32_t u32SizeList = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pu32ValueItem ) && (0UL != u32MaxLength))
    {
        pstMember = CSLinkedList__pstGetHead(pstList);
        u32SizeList = CSLinkedList__u32GetSize(pstList);
        while((0UL != u32MaxLength) && (u32SizeReg != u32SizeList))
        {
            pu32ValueItemMember = CSLinkedList_Item__u32GetValue(pstMember);
            *pu32ValueItem = pu32ValueItemMember;
            u32SizeReg++;
            pu32ValueItem += 1U;
            u32MaxLength--;
            pstMemberTemp = CSLinkedList_Item__pstGetNextItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}

uint32_t CSLinkedList__u32GetNItem(const CSLinkedList_t* pstList, void** pvData, uint32_t u32Items, uint32_t u32MaxLength)
{
    CSLinkedListItem_t *pstMember = (CSLinkedListItem_t*) 0UL;
    CSLinkedListItem_t *pstMemberTemp = (CSLinkedListItem_t*) 0UL;
    void* pvDataMember = (void*)0UL;
    uint32_t u32SizeReg = 0UL;
    uint32_t u32SizeList = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pvData ) && (0UL != u32MaxLength) && (0UL != u32Items))
    {
        pstMember = CSLinkedList__pstGetHead(pstList);
        u32SizeList = CSLinkedList__u32GetSize(pstList);
        while((0UL != u32MaxLength) && (u32SizeReg != u32SizeList) && (0UL != u32Items))
        {
            pvDataMember = CSLinkedList_Item__pvGetData(pstMember);
            *pvData = pvDataMember;
            u32SizeReg++;
            pvData += 1U;
            u32MaxLength--;
            u32Items--;
            pstMemberTemp = CSLinkedList_Item__pstGetNextItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}

uint32_t CSLinkedList__u32GetNItem_Value(const CSLinkedList_t* pstList, uint32_t* pu32ValueItem, uint32_t u32Items, uint32_t u32MaxLength)
{
    CSLinkedListItem_t *pstMember = (CSLinkedListItem_t*) 0UL;
    CSLinkedListItem_t *pstMemberTemp = (CSLinkedListItem_t*) 0UL;
    uint32_t pu32ValueItemMember = (uint32_t)0UL;
    uint32_t u32SizeReg = 0UL;
    uint32_t u32SizeList = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pu32ValueItem ) && (0UL != u32MaxLength) && (0UL != u32Items))
    {
        pstMember = CSLinkedList__pstGetHead(pstList);
        u32SizeList = CSLinkedList__u32GetSize(pstList);
        while((0UL != u32MaxLength) && (u32SizeReg != u32SizeList) && (0UL != u32Items))
        {
            pu32ValueItemMember = CSLinkedList_Item__u32GetValue(pstMember);
            *pu32ValueItem = pu32ValueItemMember;
            u32SizeReg++;
            pu32ValueItem += 1U;
            u32MaxLength--;
            u32Items--;
            pstMemberTemp = CSLinkedList_Item__pstGetNextItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}
