#include "Queue.h"



PListNode BuyNewQueue(DataType data)
{
	PListNode ptr = NULL;
	ptr = (PListNode)malloc(sizeof(ListNode));

	if (ptr == NULL)
	{
		printf("�ռ�����ʧ��!!!\n");
		return NULL;
	}

	ptr->data = data;
	ptr->_PNext = NULL;
	return ptr;
}

//���г�ʼ������ͷ���
void InitQueue(struct Queue* q)
{
	assert(q);//�ж϶����Ƿ����

	//����ͷ�ڵ�,ͷָ���βָ�붼ָ��ͷ�ڵ�
	q->_pTail = q->_pHead = BuyNewQueue(0);
}

//���в����½ڵ�
void QueuePush(struct Queue* q, DataType data)
{

	if (NULL == q)
		return;
	
	q->_pTail->_PNext = BuyNewQueue(data);
	q->_pTail = q->_pTail->_PNext;

}


//ɾ���ڵ�
void QueuePop(struct Queue* q)
{
	assert(q);
	PListNode pDelete = q->_pHead->_PNext;

	if (NULL == q->_pHead->_PNext)
	{
		printf("�����ѿգ�����ʧ��!!!\n");
		return;
	}

	//�Ӷ�ͷ������
	//���ֻʣһ���ڵ㣬����С����������_pHead��ָ��NULL����_pTail����ָ�����һ���ڵ�
	q->_pHead->_PNext = q->_pHead->_PNext->_PNext;
	if (pDelete->_PNext == NULL)
		q->_pTail = q->_pHead;
	free(pDelete);
}


//���ض�ͷ�ڵ�
DataType QueueFront(struct Queue* q)
{
	assert(q);

	if (NULL == q->_pHead->_PNext)
	{
		printf("�����ѿգ�����ʧ��!!!\n");
		return 0;
	}

	return q->_pHead->_PNext->data;
}

//���ض�β�ڵ�
DataType QueueBack(struct Queue* q)
{
	assert(q);

	PListNode ptr = q->_pHead->_PNext;

	if (NULL == ptr)
	{
		printf("�����ѿգ�����ʧ��!!!\n");
		return 0;
	}

	return q->_pTail->data;
}

//�п�
int QueueEmpty(struct Queue* q)
{
	assert(q);

	if (NULL == q->_pHead->_PNext)
		return 0;

	return 1;
}

//���ض��нڵ����
int QueueSize(struct Queue* q)
{
	assert(q);
	int size = 0;
	PListNode pCur = q->_pHead->_PNext;

	while (pCur)
	{
		pCur = pCur->_PNext;
		size++;
	}

	return size;
}