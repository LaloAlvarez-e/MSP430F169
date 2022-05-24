/**
 *
 * @file CDLinkedList_Index.c
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
#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/Intrinsics/List/xHeader/CDLinkedList_Index.h>

CDLinkedListItem_t* CDLinkedList__pstGetLastItemRead(const CDLinkedList_t*  const pstList)
{
    CDLinkedListItem_t* pstLastItemReadReg = (CDLinkedListItem_t*) 0U;
    if(0UL != (uint32_t) pstList)
    {
        pstLastItemReadReg = pstList->pstLastItemRead;
    }
    return (pstLastItemReadReg);
}

void CDLinkedList__vSetLastItemRead(CDLinkedList_t* pstList, CDLinkedListItem_t* pstLastItemReadArg)
{
    if(0UL != (uint32_t) pstList)
    {
        pstList->pstLastItemRead = pstLastItemReadArg;
    }
}

CDLinkedList_nSTATUS CDLinkedList__enIsLastItemRead(const CDLinkedList_t* const pstList, const CDLinkedListItem_t* const pstItem)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    CDLinkedListItem_t* pstListLastItemRead = (CDLinkedListItem_t*)0UL;
    pstListLastItemRead= CDLinkedList__pstGetLastItemRead(pstList);
    if ((uint32_t) pstItem == (uint32_t) (pstListLastItemRead))
    {
        enStatus = CDLinkedList_enSTATUS_OK;
    }
    return (enStatus);
}
