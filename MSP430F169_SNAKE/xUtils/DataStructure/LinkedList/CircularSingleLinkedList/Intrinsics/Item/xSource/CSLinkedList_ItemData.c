/**
 *
 * @file CSLinkedList_ItemData.c
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
#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/Intrinsics/Item/xHeader/CSLinkedList_ItemData.h>

void* CSLinkedList_Item__pvGetData(const CSLinkedListItem_t* const pstItem)
{
    void* pvDataReg = (void*) 0UL;
    if(0UL != (uint32_t) pstItem)
    {
        pvDataReg = pstItem->pvDataContainer;
    }
    return (pvDataReg);
}

void CSLinkedList_Item__vSetData(CSLinkedListItem_t* pstItem, void* pvDataArg)
{
    if(0UL != (uint32_t) pstItem)
    {
        pstItem->pvDataContainer = pvDataArg;
    }
}
