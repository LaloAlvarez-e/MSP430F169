/**
 *
 * @file CDLinkedList_Size.c
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
#include <xUtils/DataStructure/LinkedList/CircularDoubleLinkedList/Intrinsics/List/xHeader/CDLinkedList_Size.h>

uint32_t CDLinkedList__u32GetSize(const CDLinkedList_t* const pstList)
{
    uint32_t u32SizeReg = 0UL;
    if(0UL != (uint32_t) pstList)
    {
        u32SizeReg = pstList->u32Size;
    }
    return (u32SizeReg);

}

void CDLinkedList__vSetSize(CDLinkedList_t*  pstList, uint32_t u32SizeArg)
{
    if(0UL != (uint32_t) pstList)
    {
        pstList->u32Size = u32SizeArg;
    }
}

CDLinkedList_nSTATUS CDLinkedList__enIsEmpty(const CDLinkedList_t*  pstList)
{
    CDLinkedList_nSTATUS enStatus = CDLinkedList_enSTATUS_ERROR;
    if(0UL  == pstList->u32Size)
    {
        enStatus = CDLinkedList_enSTATUS_OK;
    }
    return (enStatus);
}
