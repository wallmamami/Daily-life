#include "PriorityQueue.h"

//队列初始化
void PriorityQueueInit(PQueue q)
{
	assert(q);

	HeapInit(&(q->_hp), Less);
}

//入队列
void PriorityQueuePush(PQueue q, DataType data)
{
	assert(q);

	InsertHeap(&(q->_hp), data);
}

//出队列
void PriorityQueuePop(PQueue q)
{
	assert(q);
	DeleteHeap(&(q->_hp));
}

//查看队头元素
DataType PriorityQueueFront(PQueue q)
{
	assert(q);

	return HeapTop(&(q->_hp));

}

//查看队尾元素
DataType PriorityQueueBack(PQueue q)
{
	assert(q);

	if (!EmptyHeap(&(q->_hp)))
		return q->_hp.arr[q->_hp._size - 1];

	return 0;
}

//查看元素个数
int PriorityQueueSize(PQueue q)
{
	assert(q);

	return HeapSize(&(q->_hp));
}

//队列判空
int PriorityQueueEmpty(PQueue q)
{
	assert(q);

	return EmptyHeap(&(q->_hp));
}

//销毁队列
void PriorityQueueDestory(PQueue q)
{
	assert(q);

	DestoryHeap(&(q->_hp));
}