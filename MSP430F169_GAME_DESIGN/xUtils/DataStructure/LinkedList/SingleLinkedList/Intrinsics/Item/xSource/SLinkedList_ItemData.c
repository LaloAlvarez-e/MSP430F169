/**
 *
 * @file SLinkedList_ItemData.c
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
 * @verbatim 6 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xUtils/DataStructure/LinkedList/SingleLinkedList/Intrinsics/Item/xHeader/SLinkedList_ItemData.h>

void* SLinkedList_Item__pvGetData(const SLinkedListItem_t* const pstItem)
{
    void* pvDataReg = (void*) 0UL;
    if(0UL != (uint32_t) pstItem)
    {
        pvDataReg = pstItem->pvDataContainer;
    }
    return (pvDataReg);
}

void SLinkedList_Item__vSetData(SLinkedListItem_t* pstItem, void* pvDataArg)
{
    if(0UL != (uint32_t) pstItem)
    {
        pstItem->pvDataContainer = pvDataArg;
    }
}
