#pragma once

#include "Heap.h"


//���ȼ����о��Ƿ�װ��
typedef struct PriorityQueue
{
	Heap _hp;

}PriorityQueue, *PQueue;


//���г�ʼ��
void PriorityQueueInit(PQueue q);

//�����
void PriorityQueuePush(PQueue q, DataType data);

//������
void PriorityQueuePop(PQueue q);

//�鿴��ͷԪ��
DataType PriorityQueueFront(PQueue q);

//�鿴��βԪ��
DataType PriorityQueueBack(PQueue q);

//�鿴Ԫ�ظ���
int PriorityQueueSize(PQueue q);

//�����п�
int PriorityQueueFront(PQueue q);

//���ٶ���
void PriorityQueueDestory(PQueue q);