/**
 *
 * @file SLinkedList_ItemValue.c
 * @copyright
 * @verbatim InDeviceMex 2021 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 14 jul. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 14 jul. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xUtils/DataStructure/LinkedList/SingleLinkedList/Intrinsics/Item/xHeader/SLinkedList_ItemValue.h>

uint32_t SLinkedList_Item__u32GetValue(const SLinkedListItem_t* const pstItem)
{
    uint32_t u32ValueItemReg = 0UL;
    if(0UL != (uint32_t) pstItem)
    {
        u32ValueItemReg = pstItem->u32ValueItem;
    }
    return (u32ValueItemReg);
}

void SLinkedList_Item__vSetValue(SLinkedListItem_t* pstItem, uint32_t u32ValueItemArg)
{
    if(0UL != (uint32_t) pstItem)
    {
        pstItem->u32ValueItem = u32ValueItemArg;
    }
}
