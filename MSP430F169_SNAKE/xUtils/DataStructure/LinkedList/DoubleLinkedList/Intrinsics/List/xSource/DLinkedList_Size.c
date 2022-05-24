/**
 *
 * @file DLinkedList_Size.c
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
#include <xUtils/DataStructure/LinkedList/DoubleLinkedList/Intrinsics/List/xHeader/DLinkedList_Size.h>

uint32_t DLinkedList__u32GetSize(const DLinkedList_t* const pstList)
{
    uint32_t u32SizeReg = 0UL;
    if(0UL != (uint32_t) pstList)
    {
        u32SizeReg = pstList->u32Size;
    }
    return (u32SizeReg);

}

void DLinkedList__vSetSize(DLinkedList_t*  pstList, uint32_t u32SizeArg)
{
    if(0UL != (uint32_t) pstList)
    {
        pstList->u32Size = u32SizeArg;
    }
}

DLinkedList_nSTATUS DLinkedList__enIsEmpty(const DLinkedList_t*  pstList)
{
    DLinkedList_nSTATUS enStatus = DLinkedList_enSTATUS_ERROR;
    if(0UL  == pstList->u32Size)
    {
        enStatus = DLinkedList_enSTATUS_OK;
    }
    return (enStatus);
}
