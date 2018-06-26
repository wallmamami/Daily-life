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
PListNode BuyNewQueue(DataType data);//创建新节点
void InitQueue(struct Queue* q);//队列初始化
void QueuePush(struct Queue* q, DataType data);//队列插入新节点，链表的尾插
void QueuePop(struct Queue* q);//删除节点，链表的头删
DataType QueueFront(struct Queue* q);//返回对头节点
DataType QueueBack(struct Queue* q);//返回队尾节点
int QueueEmpty(struct Queue* q);//判空
int QueueSize(struct Queue* q);//返回队列节点个数

