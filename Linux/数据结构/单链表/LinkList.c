#include "LinkList.h"

//初始化
void LinkListInit(PNode* pHead)
{
    assert(pHead);

    *pHead = NULL;
}


PNode BuyNewNode(DataType data)
{
    PNode ptr = NULL;
    ptr = (PNode)malloc(sizeof(Node));
    if(ptr == NULL)
    {
        assert(0);
        return NULL;
    }

    ptr->data = data;
    ptr->_pNext = NULL;
}

//头插
void LinkLilstPushBack(PNode* pHead, DataType data)
{
    //判断链表是否存在
    assert(pHead);
    PNode pNewNode = BuyNewNode(data);

    pNewNode->_pNext = *pHead;
    *pHead = pNewNode;
}
