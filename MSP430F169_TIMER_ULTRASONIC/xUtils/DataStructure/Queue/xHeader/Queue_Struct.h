/**
 *
 * @file Queue_Struct.h
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
 * @verbatim 13 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 13 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#ifndef XUTILS_DATASTRUCTURE_QUEUE_XHEADER_QUEUE_STRUCT_H_
#define XUTILS_DATASTRUCTURE_QUEUE_XHEADER_QUEUE_STRUCT_H_

#include <xUtils/DataStructure/LinkedList/SingleLinkedList/Intrinsics/xHeader/SLinkedList_Struct.h>

typedef enum
{
    Queue_enSTATUS_OK,
    Queue_enSTATUS_ERROR,
    Queue_enSTATUS_FULL,
    Queue_enSTATUS_EMPTY,
}Queue_nSTATUS;

typedef SLinkedList_t Queue_t;

#endif /* XUTILS_DATASTRUCTURE_QUEUE_XHEADER_QUEUE_STRUCT_H_ */
