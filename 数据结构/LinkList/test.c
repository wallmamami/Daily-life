#include "SList.h"
#include <windows.h>

//找到链表最后一个节点并返回
PNode SListBack(PNode pHead)
{
	if (pHead == NULL)
		return NULL;

	while (pHead->_pNext)
		pHead = pHead->_pNext;

	return pHead;
}

void Test1(PNode *pHead)
{
	PNode ptr = *pHead;
	//构环
	SListBack(*pHead)->_pNext = *pHead;
	JosephCircle(pHead, 3);
	//解环
	(*pHead)->_pNext = NULL;


}



void Test2()
{
	PNode pHead1 = NULL;
	PNode pHead2 = NULL;
	SListPushBack(&pHead1, 1);//尾插
	SListPushBack(&pHead1, 3);
	SListPushBack(&pHead1, 5);
	SListPushBack(&pHead1, 7);//尾插
	SListPushBack(&pHead1, 9);
	PrintfList(pHead1);
	SListPushBack(&pHead2, 2);
	SListPushBack(&pHead2, 4);
	SListPushBack(&pHead2, 6);
	SListPushBack(&pHead2, 8);
	SListPushBack(&pHead2, 10);
	PrintfList(pHead2);
	PrintfList(MergeSList(pHead1, pHead2));
}

void Test3()
{
	PNode pHead1 = NULL;
	PNode pHead2 = NULL;
	SListPushBack(&pHead1, 1);//尾插
	SListPushBack(&pHead1, 3);
	SListPushBack(&pHead1, 5);
	SListPushBack(&pHead1, 7);//尾插
	SListPushBack(&pHead1, 9);
	SListPushBack(&pHead1, 6);
	SListPushBack(&pHead1, 8);
	SListPushBack(&pHead1, 10);
	PrintfList(pHead1);
	SListPushBack(&pHead2, 2);
	SListPushBack(&pHead2, 4);
	SListPushBack(&pHead2, 30);
	SListPushBack(&pHead2, 21);
	//让其相交
	SListBack(pHead2)->_pNext = pHead1->_pNext->_pNext;
	PrintfList(pHead2);
	PrintfList(GetCorssNode(pHead1, pHead2));


}

void Test4()
{
	//构造复杂链表
	PCSLNode PHead = NULL;
	PCSLNode pNewHead = NULL;
	PHead = BuyCSNewNode(1);
	PHead->_pNext = BuyCSNewNode(2);
	PHead->_pNext->_pNext = BuyCSNewNode(3);
	PHead->_pNext->_pNext->_pNext = BuyCSNewNode(4);
	PHead->_pRandom = PHead->_pNext->_pNext;//1随机指针域指向3
	PHead->_pNext->_pRandom = PHead;//2的随机指针域指向1
	PHead->_pNext->_pNext->_pRandom = PHead->_pNext->_pNext;//3的随机指针域指向他自己
	PHead->_pNext->_pNext->_pNext->_pRandom = NULL;//4的随机指针域指向NULL

	pNewHead = CopyComplexList(PHead);

}

int main()
{
	SNode SList;
	PNode pHead = &SList;
	SListInit(&pHead);// 链表的初始化
	//SListEmpty(pHead);// 判断链表是否为空 
	SListInsert(&pHead, pHead, 40);
	//PrintfList(pHead);
	//SListPushFront(&pHead, 0);
	//PrintfList(pHead);
	SListPushBack(&pHead, 5);//尾插
	SListPushBack(&pHead, 10);
	SListPushBack(&pHead, 3);
	//PrintfList(pHead);
	//SListPopBack(&pHead);//尾删
	//PrintfList(pHead);
	SListPushFront(&pHead, 0);//头插
	//PrintfList(pHead);
	//SListPopFront(&pHead);//头删
	//PrintfList(pHead);
	// 在链表中查找值为data的元素，找到后返回值为data的结点
	//SListFind(pHead, 3);
	//SListSize(pHead);// 获取链表中节点总数
	SListInsert(&pHead, pHead->_pNext->_pNext , 20);// 在pos位置插入值为data的结点 
	//PrintfList(pHead);
	//SListErase(&pHead, pHead->_pNext->_pNext);// 删除pos位置的结点
	//PrintfList(pHead);
	//PrintSListFromTail2Head(pHead);
	DeleteListNotTailNode(pHead->_pNext);
	InesrtPosFront(pHead->_pNext, 100);
	SListPushBack(&pHead, 9);

	DeleteLastKNode(&pHead, 7);
	//Test1(&pHead);//测试约瑟夫环
	//ReverseSList(&pHead);
	PrintfList(pHead);
	
	//PrintfList(ReverseSListOP(pHead));
	//printf("%d\n", FindLastKNode(pHead, 7)->data);
	//SListDestroy(&pHead);// 销毁链表
	//Test2();//测试合并俩有序链表
	Test3();//测试俩非环链表是否相交
	Test4();//测试复杂链表的复制
	system("pause");
	return 0;
}



