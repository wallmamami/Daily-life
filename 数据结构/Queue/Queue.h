#pragma once

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


typedef int DataType;

typedef struct ListNode
{
	DataType data;
	struct ListNode* _PNext;

}ListNode, *PListNode;

struct Queue
{
	PListNode _pHead;
	PListNode _pTail;
};



void TestQueue();
PListNode BuyNewQueue(DataType data);//�����½ڵ�
void InitQueue(struct Queue* q);//���г�ʼ��
void QueuePush(struct Queue* q, DataType data);//���в����½ڵ㣬�����β��
void QueuePop(struct Queue* q);//ɾ���ڵ㣬�����ͷɾ
DataType QueueFront(struct Queue* q);//���ض�ͷ�ڵ�
DataType QueueBack(struct Queue* q);//���ض�β�ڵ�
int QueueEmpty(struct Queue* q);//�п�
int QueueSize(struct Queue* q);//���ض��нڵ����

