#include "Queue.h"



PListNode BuyNewQueue(DataType data)
{
	PListNode ptr = NULL;
	ptr = (PListNode)malloc(sizeof(ListNode));

	if (ptr == NULL)
	{
		printf("空间申请失败!!!\n");
		return NULL;
	}

	ptr->data = data;
	ptr->_PNext = NULL;
	return ptr;
}

//队列初始化，带头结点
void InitQueue(struct Queue* q)
{
	assert(q);//判断队列是否存在

	//分配头节点,头指针和尾指针都指向头节点
	q->_pTail = q->_pHead = BuyNewQueue(0);
}

//队列插入新节点
void QueuePush(struct Queue* q, DataType data)
{

	if (NULL == q)
		return;
	
	q->_pTail->_PNext = BuyNewQueue(data);
	q->_pTail = q->_pTail->_PNext;

}


//删除节点
void QueuePop(struct Queue* q)
{
	assert(q);
	PListNode pDelete = q->_pHead->_PNext;

	if (NULL == q->_pHead->_PNext)
	{
		printf("队列已空，操作失败!!!\n");
		return;
	}

	//从队头出队列
	//如果只剩一个节点，按照小面这样做，_pHead就指向NULL，而_pTail还是指向最后一个节点
	q->_pHead->_PNext = q->_pHead->_PNext->_PNext;
	if (pDelete->_PNext == NULL)
		q->_pTail = q->_pHead;
	free(pDelete);
}


//返回队头节点
DataType QueueFront(struct Queue* q)
{
	assert(q);

	if (NULL == q->_pHead->_PNext)
	{
		printf("队列已空，操作失败!!!\n");
		return 0;
	}

	return q->_pHead->_PNext->data;
}

//返回队尾节点
DataType QueueBack(struct Queue* q)
{
	assert(q);

	PListNode ptr = q->_pHead->_PNext;

	if (NULL == ptr)
	{
		printf("队列已空，操作失败!!!\n");
		return 0;
	}

	return q->_pTail->data;
}

//判空
int QueueEmpty(struct Queue* q)
{
	assert(q);

	if (NULL == q->_pHead->_PNext)
		return 0;

	return 1;
}

//返回队列节点个数
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