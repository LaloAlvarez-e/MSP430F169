/**
 *
 * @file CDLinkedList_Struct.h
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
#ifndef XUTILS_DATASTRUCTURE_CIRCULARDOUBLELINKEDLIST_INTRINSICS_XHEADER_CIRCULARDLINKEDLIST_STRUCT_H_
#define XUTILS_DATASTRUCTURE_CIRCULARDOUBLELINKEDLIST_INTRINSICS_XHEADER_CIRCULARDLINKEDLIST_STRUCT_H_

#include <xUtils/Standard/Standard.h>

typedef enum
{
    CDLinkedList_enSTATUS_OK,
    CDLinkedList_enSTATUS_ERROR
}CDLinkedList_nSTATUS;


typedef enum
{
    CDLinkedList_enSTATE_FALSE,
    CDLinkedList_enSTATE_TRUE,
}CDLinkedList_nSTATE;

typedef struct CDLinkedListItem
{
        void* pvDataContainer;
        void* pvOwnerList;
        uint32_t u32ValueItem;
        struct CDLinkedListItem *pstPreviousItem;
        struct CDLinkedListItem *pstNextItem;
}CDLinkedListItem_t;

typedef struct CDLinkedList
{
        uint32_t u32Size;
        uint32_t (*pfu32Match) (const void *pcvKey1, const void *pcvKey2);
        void (*pvfDestroyItemData) (void *DataContainer);
        void (*pvfDestroyItem) (void *Item);
        void (*pvfDestroy) (void* List);
        CDLinkedListItem_t *pstLastItemRead;
        CDLinkedListItem_t *pstHead;
        CDLinkedListItem_t *pstTail;
}CDLinkedList_t;




#endif /* XUTILS_DATASTRUCTURE_CIRCULARDOUBLELINKEDLIST_INTRINSICS_XHEADER_CIRCULARDLINKEDLIST_STRUCT_H_ */
