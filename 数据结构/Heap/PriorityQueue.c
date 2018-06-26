#include "PriorityQueue.h"

//���г�ʼ��
void PriorityQueueInit(PQueue q)
{
	assert(q);

	HeapInit(&(q->_hp), Less);
}

//�����
void PriorityQueuePush(PQueue q, DataType data)
{
	assert(q);

	InsertHeap(&(q->_hp), data);
}

//������
void PriorityQueuePop(PQueue q)
{
	assert(q);
	DeleteHeap(&(q->_hp));
}

//�鿴��ͷԪ��
DataType PriorityQueueFront(PQueue q)
{
	assert(q);

	return HeapTop(&(q->_hp));

}

//�鿴��βԪ��
DataType PriorityQueueBack(PQueue q)
{
	assert(q);

	if (!EmptyHeap(&(q->_hp)))
		return q->_hp.arr[q->_hp._size - 1];

	return 0;
}

//�鿴Ԫ�ظ���
int PriorityQueueSize(PQueue q)
{
	assert(q);

	return HeapSize(&(q->_hp));
}

//�����п�
int PriorityQueueEmpty(PQueue q)
{
	assert(q);

	return EmptyHeap(&(q->_hp));
}

//���ٶ���
void PriorityQueueDestory(PQueue q)
{
	assert(q);

	DestoryHeap(&(q->_hp));
}