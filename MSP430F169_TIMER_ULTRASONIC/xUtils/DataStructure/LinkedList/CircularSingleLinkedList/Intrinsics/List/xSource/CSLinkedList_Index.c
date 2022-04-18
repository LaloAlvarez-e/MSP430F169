/**
 *
 * @file CSLinkedList_Index.c
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
#include <xUtils/DataStructure/LinkedList/CircularSingleLinkedList/Intrinsics/List/xHeader/CSLinkedList_Index.h>

CSLinkedListItem_t* CSLinkedList__pstGetLastItemRead(const CSLinkedList_t*  const pstList)
{
    CSLinkedListItem_t* pstLastItemReadReg = (CSLinkedListItem_t*) 0U;
    if(0UL != (uint32_t) pstList)
    {
        pstLastItemReadReg = pstList->pstLastItemRead;
    }
    return (pstLastItemReadReg);
}

void CSLinkedList__vSetLastItemRead(CSLinkedList_t* pstList, CSLinkedListItem_t* pstLastItemReadArg)
{
    if(0UL != (uint32_t) pstList)
    {
        pstList->pstLastItemRead = pstLastItemReadArg;
    }
}

CSLinkedList_nSTATUS CSLinkedList__enIsLastItemRead(const CSLinkedList_t* const pstList, const CSLinkedListItem_t* const pstItem)
{
    CSLinkedList_nSTATUS enStatus = CSLinkedList_enSTATUS_ERROR;
    CSLinkedListItem_t* pstListLastItemRead = (CSLinkedListItem_t*)0UL;
    pstListLastItemRead= CSLinkedList__pstGetLastItemRead(pstList);
    if ((uint32_t) pstItem == (uint32_t) (pstListLastItemRead))
    {
        enStatus = CSLinkedList_enSTATUS_OK;
    }
    return (enStatus);
}



