
#pragma once


#include <assert.h>
#include <stdio.h>

#define MAX_SIZE 10
typedef int DataType;

typedef struct ShareStack
{
	DataType arr[MAX_SIZE];
	int Top1;//栈1用数组的偶数下标
	int Top2;//栈2用数组的奇数下标

}SStack, *PSStack;


void StackInit(PSStack s);
void StackPush(PSStack s, int flag, DataType data);
void StackPop(PSStack s, int flag);
int StackSize(PSStack s, int flag);
int StackEmpty(PSStack s, int flag);
DataType StackTop(PSStack s, int flag);



//面试题4
//一个数组实现两个栈(共享栈）
/////////////////////////////////////////////////////////////////////////////////////////////
//#pragma once
//
//
//#include <assert.h>
//#include <stdio.h>
//
//#define MAX_SIZE 10
//typedef int DataType;
//
//typedef struct Stack
//{
//	DataType arr[MAX_SIZE];
//	int Top;
//}Stack, *PStack;
//
//int StackIsLegal(int* arr, int size, int* arr2, int size2);



//面试题3
/////////////////////////////////////////////////////////////////////////////////////
//#pragma once
//
//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//
//
//typedef int DataType;
//
//typedef struct Node
//{
//	DataType _data;
//	struct Node* _pNext;
//}Node;
//
//typedef struct Queue
//{
//	Node* _pHead;
//	Node* _pTail;
//}Queue;
//
//typedef struct Stack
//{
//	Queue* q1;
//	Queue* q2;
//}Stack, *PStack;



////初始化栈
//void StackInit(PStack s);
////创建新节点
//Node* BuyNewNode(DataType data);
////入栈
//void StackPush(PStack s, DataType data);
////入队列
//void QueuePush(Queue* q, DataType data);
////出队列
//void QueuePop(Queue* q);
////队列判空
//int QueueEmpty(Queue* q);
////出栈
//void StackPop(PStack s);
////获取栈顶元素
//DataType StackTop(PStack s);



















//面试题3
////////////////////////////////////////////////////////////////////////////////////////////
//#pragma once
//
//#include <stdio.h>
//#include <assert.h>
//
//
//typedef int DataType;
//
//#define MAX_SIZE 3
//
//
//typedef struct Stack
//{
//	DataType _arr[MAX_SIZE];
//	int _size;
//}Stack;
//
//
//typedef struct Queue
//{
//	Stack s1;
//	Stack s2;
//}Queue, *PQueue;
//
//
//
////初始化队列
//void QueueInit(PQueue q);
////入栈
//void StackPush(Stack* s, DataType data);
////入队列,入到栈s1
//void QueuePush(PQueue q, DataType data);
////返回栈顶元素
//DataType StackTop(Stack* s);
////出栈
//void StackPop(Stack* s);
////出队列
//void QueuePop(PQueue q);
////获取队头元素
//DataType QueueFront(PQueue q);
////获取队尾元素
//DataType QueueBack(PQueue q);



















//面试题1方法2
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#pragma once
//
//
//#include <stdio.h>
//#include <assert.h>
//
//
//#define MAX_SIZE 100
//
//typedef int DataType;
//
////存放平常数据的栈
//typedef struct Stack1
//{
//	DataType _arr[MAX_SIZE];
//	int _size;
//}Stack1;
//
////存放最小数据的栈
//typedef struct Stack2
//{
//	DataType _arr[MAX_SIZE];
//	int _size;
//}Stack2;
//
////将两个栈封装为1个
//typedef struct Stack
//{
//	Stack1 s1;
//	Stack2 s2;
//
//}Stack, *PStack;
//
//
//
//
////初始化栈
//void InitStack(PStack s);
////入栈
//void StackPush(PStack s, DataType data);
////获取栈顶元素
//DataType StackTop(Stack2* s2);
////出栈
//void StackPop(PStack s);
////获取最小值
//DataType StackMindata(PStack s);











////////////////////////////////////////////////////////////////
//面试题1方法1
//#include <stdio.h>
//#include <assert.h>
//
//#define MAX_SIZE 100
////将本来的数据和最小值封装为一个结构体
//typedef struct NewData
//{
//	int data;
//	int Mindata;
//}Newdata;
//
//typedef struct Stack
//{
//	Newdata _arr[MAX_SIZE];//栈里面放的都是封装好的结构体
//	int _size;
//}Stack, *PStack;
//
////面试题1
//void Test1();
////初始化栈
//void InitStack(PStack s);
////给栈顶插入元素
//void StackPush(PStack s, int data);
//void StackPop(PStack s);//出栈
////返回栈最小元素
//int StackMindata(PStack s);