#pragma once

#include "Heap.h"


//优先级队列就是封装堆
typedef struct PriorityQueue
{
	Heap _hp;

}PriorityQueue, *PQueue;


//队列初始化
void PriorityQueueInit(PQueue q);

//入队列
void PriorityQueuePush(PQueue q, DataType data);

//出队列
void PriorityQueuePop(PQueue q);

//查看队头元素
DataType PriorityQueueFront(PQueue q);

//查看队尾元素
DataType PriorityQueueBack(PQueue q);

//查看元素个数
int PriorityQueueSize(PQueue q);

//队列判空
int PriorityQueueFront(PQueue q);

//销毁队列
void PriorityQueueDestory(PQueue q);