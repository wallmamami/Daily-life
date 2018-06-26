#include "SList.h"
#include <windows.h>

//�ҵ��������һ���ڵ㲢����
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
	//����
	SListBack(*pHead)->_pNext = *pHead;
	JosephCircle(pHead, 3);
	//�⻷
	(*pHead)->_pNext = NULL;


}



void Test2()
{
	PNode pHead1 = NULL;
	PNode pHead2 = NULL;
	SListPushBack(&pHead1, 1);//β��
	SListPushBack(&pHead1, 3);
	SListPushBack(&pHead1, 5);
	SListPushBack(&pHead1, 7);//β��
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
	SListPushBack(&pHead1, 1);//β��
	SListPushBack(&pHead1, 3);
	SListPushBack(&pHead1, 5);
	SListPushBack(&pHead1, 7);//β��
	SListPushBack(&pHead1, 9);
	SListPushBack(&pHead1, 6);
	SListPushBack(&pHead1, 8);
	SListPushBack(&pHead1, 10);
	PrintfList(pHead1);
	SListPushBack(&pHead2, 2);
	SListPushBack(&pHead2, 4);
	SListPushBack(&pHead2, 30);
	SListPushBack(&pHead2, 21);
	//�����ཻ
	SListBack(pHead2)->_pNext = pHead1->_pNext->_pNext;
	PrintfList(pHead2);
	PrintfList(GetCorssNode(pHead1, pHead2));


}

void Test4()
{
	//���츴������
	PCSLNode PHead = NULL;
	PCSLNode pNewHead = NULL;
	PHead = BuyCSNewNode(1);
	PHead->_pNext = BuyCSNewNode(2);
	PHead->_pNext->_pNext = BuyCSNewNode(3);
	PHead->_pNext->_pNext->_pNext = BuyCSNewNode(4);
	PHead->_pRandom = PHead->_pNext->_pNext;//1���ָ����ָ��3
	PHead->_pNext->_pRandom = PHead;//2�����ָ����ָ��1
	PHead->_pNext->_pNext->_pRandom = PHead->_pNext->_pNext;//3�����ָ����ָ�����Լ�
	PHead->_pNext->_pNext->_pNext->_pRandom = NULL;//4�����ָ����ָ��NULL

	pNewHead = CopyComplexList(PHead);

}

int main()
{
	SNode SList;
	PNode pHead = &SList;
	SListInit(&pHead);// ����ĳ�ʼ��
	//SListEmpty(pHead);// �ж������Ƿ�Ϊ�� 
	SListInsert(&pHead, pHead, 40);
	//PrintfList(pHead);
	//SListPushFront(&pHead, 0);
	//PrintfList(pHead);
	SListPushBack(&pHead, 5);//β��
	SListPushBack(&pHead, 10);
	SListPushBack(&pHead, 3);
	//PrintfList(pHead);
	//SListPopBack(&pHead);//βɾ
	//PrintfList(pHead);
	SListPushFront(&pHead, 0);//ͷ��
	//PrintfList(pHead);
	//SListPopFront(&pHead);//ͷɾ
	//PrintfList(pHead);
	// �������в���ֵΪdata��Ԫ�أ��ҵ��󷵻�ֵΪdata�Ľ��
	//SListFind(pHead, 3);
	//SListSize(pHead);// ��ȡ�����нڵ�����
	SListInsert(&pHead, pHead->_pNext->_pNext , 20);// ��posλ�ò���ֵΪdata�Ľ�� 
	//PrintfList(pHead);
	//SListErase(&pHead, pHead->_pNext->_pNext);// ɾ��posλ�õĽ��
	//PrintfList(pHead);
	//PrintSListFromTail2Head(pHead);
	DeleteListNotTailNode(pHead->_pNext);
	InesrtPosFront(pHead->_pNext, 100);
	SListPushBack(&pHead, 9);

	DeleteLastKNode(&pHead, 7);
	//Test1(&pHead);//����Լɪ��
	//ReverseSList(&pHead);
	PrintfList(pHead);
	
	//PrintfList(ReverseSListOP(pHead));
	//printf("%d\n", FindLastKNode(pHead, 7)->data);
	//SListDestroy(&pHead);// ��������
	//Test2();//���Ժϲ�����������
	Test3();//�������ǻ������Ƿ��ཻ
	Test4();//���Ը�������ĸ���
	system("pause");
	return 0;
}



