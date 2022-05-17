/**
 *
 * @file SLinkedList_Item.c
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
 * @verbatim 7 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 7 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/DataStructure/LinkedList/SingleLinkedList/xHeader/SLinkedList_Item.h>

#include <xUtils/DataStructure/LinkedList/SingleLinkedList/Intrinsics/SLinkedList_Intrinsics.h>

SLinkedListItem_t*  SLinkedList__pstGetItemPos(const SLinkedList_t* pstList, uint32_t u32Position)
{
    SLinkedListItem_t* pstItem = (SLinkedListItem_t*) 0UL;
    uint32_t u32SizeList = 0UL;
    if((uint32_t) 0UL != (uint32_t) pstList)
    {
        u32SizeList = SLinkedList__u32GetSize(pstList);
        if(u32Position < u32SizeList)
        {
            if(0UL == u32Position)
            {
                pstItem = SLinkedList__pstGetHead(pstList);
            }
            else if((uint32_t) (u32SizeList -1UL) == (uint32_t) u32Position)
            {
                pstItem = SLinkedList__pstGetTail(pstList);
            }
            else
            {
                pstItem = SLinkedList__pstGetHead(pstList);
                while(0UL != u32Position)
                {
                    pstItem = SLinkedList_Item__pstGetNextItem(pstItem);
                    u32Position--;
                }
            }
        }
    }
    return (pstItem);
}

uint32_t SLinkedList__u32GetAllItem(const SLinkedList_t* pstList, void** pvData, uint32_t u32MaxLength)
{
    SLinkedListItem_t *pstMember = (SLinkedListItem_t*) 0UL;
    SLinkedListItem_t *pstMemberTemp = (SLinkedListItem_t*) 0UL;
    void* pvDataMember = (void*)0UL;
    uint32_t u32SizeReg = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pvData ) && (0UL != u32MaxLength))
    {
        pstMember = SLinkedList__pstGetHead(pstList);
        while(((uint32_t) 0UL != (uint32_t) pstMember) && (0UL != u32MaxLength))
        {
            pvDataMember = SLinkedList_Item__pvGetData(pstMember);
            *pvData = pvDataMember;
            u32SizeReg++;
            pvData += 1U;
            u32MaxLength--;
            pstMemberTemp = SLinkedList_Item__pstGetNextItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}

uint32_t SLinkedList__u32GetNItem(const SLinkedList_t* pstList, void** pvData, uint32_t u32Items, uint32_t u32MaxLength)
{
    SLinkedListItem_t *pstMember = (SLinkedListItem_t*) 0UL;
    SLinkedListItem_t *pstMemberTemp = (SLinkedListItem_t*) 0UL;
    void* pvDataMember = (void*)0UL;
    uint32_t u32SizeReg = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pvData ) && (0UL != u32MaxLength) && (0UL != u32Items))
    {
        pstMember = SLinkedList__pstGetHead(pstList);
        while(((uint32_t) 0UL != (uint32_t) pstMember) && (0UL != u32MaxLength) && (0UL != u32Items))
        {
            pvDataMember = SLinkedList_Item__pvGetData(pstMember);
            *pvData = pvDataMember;
            u32SizeReg++;
            pvData += 1U;
            u32MaxLength--;
            u32Items--;
            pstMemberTemp = SLinkedList_Item__pstGetNextItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}



uint32_t SLinkedList__u32GetAllItem_Value(const SLinkedList_t* pstList, uint32_t* pu32ValueItem, uint32_t u32MaxLength)
{
    SLinkedListItem_t *pstMember = (SLinkedListItem_t*) 0UL;
    SLinkedListItem_t *pstMemberTemp = (SLinkedListItem_t*) 0UL;
    uint32_t pu32ValueItemMember = (uint32_t)0UL;
    uint32_t u32SizeReg = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pu32ValueItem ) && (0UL != u32MaxLength))
    {
        pstMember = SLinkedList__pstGetHead(pstList);
        while(((uint32_t) 0UL != (uint32_t) pstMember) && (0UL != u32MaxLength))
        {
            pu32ValueItemMember = SLinkedList_Item__u32GetValue(pstMember);
            *pu32ValueItem = pu32ValueItemMember;
            u32SizeReg++;
            pu32ValueItem += 1U;
            u32MaxLength--;
            pstMemberTemp = SLinkedList_Item__pstGetNextItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}

uint32_t SLinkedList__u32GetNItem_Value(const SLinkedList_t* pstList, uint32_t* pu32ValueItem, uint32_t u32Items, uint32_t u32MaxLength)
{
    SLinkedListItem_t *pstMember = (SLinkedListItem_t*) 0UL;
    SLinkedListItem_t *pstMemberTemp = (SLinkedListItem_t*) 0UL;
    uint32_t pu32ValueItemMember = (uint32_t)0UL;
    uint32_t u32SizeReg = 0UL;

    if(((uint32_t) 0UL != (uint32_t) pstList) && ((uint32_t) 0UL != (uint32_t) pu32ValueItem ) && (0UL != u32MaxLength) && (0UL != u32Items))
    {
        pstMember = SLinkedList__pstGetHead(pstList);
        while(((uint32_t) 0UL != (uint32_t) pstMember) && (0UL != u32MaxLength) && (0UL != u32Items))
        {
            pu32ValueItemMember = SLinkedList_Item__u32GetValue(pstMember);
            *pu32ValueItem = pu32ValueItemMember;
            u32SizeReg++;
            pu32ValueItem += 1U;
            u32MaxLength--;
            u32Items--;
            pstMemberTemp = SLinkedList_Item__pstGetNextItem(pstMember);
            pstMember = pstMemberTemp;
        }
    }
    return (u32SizeReg);
}

