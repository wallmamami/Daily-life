
#pragma once


#include <assert.h>
#include <stdio.h>

#define MAX_SIZE 10
typedef int DataType;

typedef struct ShareStack
{
	DataType arr[MAX_SIZE];
	int Top1;//ջ1�������ż���±�
	int Top2;//ջ2������������±�

}SStack, *PSStack;


void StackInit(PSStack s);
void StackPush(PSStack s, int flag, DataType data);
void StackPop(PSStack s, int flag);
int StackSize(PSStack s, int flag);
int StackEmpty(PSStack s, int flag);
DataType StackTop(PSStack s, int flag);



//������4
//һ������ʵ������ջ(����ջ��
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



//������3
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



////��ʼ��ջ
//void StackInit(PStack s);
////�����½ڵ�
//Node* BuyNewNode(DataType data);
////��ջ
//void StackPush(PStack s, DataType data);
////�����
//void QueuePush(Queue* q, DataType data);
////������
//void QueuePop(Queue* q);
////�����п�
//int QueueEmpty(Queue* q);
////��ջ
//void StackPop(PStack s);
////��ȡջ��Ԫ��
//DataType StackTop(PStack s);



















//������3
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
////��ʼ������
//void QueueInit(PQueue q);
////��ջ
//void StackPush(Stack* s, DataType data);
////�����,�뵽ջs1
//void QueuePush(PQueue q, DataType data);
////����ջ��Ԫ��
//DataType StackTop(Stack* s);
////��ջ
//void StackPop(Stack* s);
////������
//void QueuePop(PQueue q);
////��ȡ��ͷԪ��
//DataType QueueFront(PQueue q);
////��ȡ��βԪ��
//DataType QueueBack(PQueue q);



















//������1����2
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
////���ƽ�����ݵ�ջ
//typedef struct Stack1
//{
//	DataType _arr[MAX_SIZE];
//	int _size;
//}Stack1;
//
////�����С���ݵ�ջ
//typedef struct Stack2
//{
//	DataType _arr[MAX_SIZE];
//	int _size;
//}Stack2;
//
////������ջ��װΪ1��
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
////��ʼ��ջ
//void InitStack(PStack s);
////��ջ
//void StackPush(PStack s, DataType data);
////��ȡջ��Ԫ��
//DataType StackTop(Stack2* s2);
////��ջ
//void StackPop(PStack s);
////��ȡ��Сֵ
//DataType StackMindata(PStack s);











////////////////////////////////////////////////////////////////
//������1����1
//#include <stdio.h>
//#include <assert.h>
//
//#define MAX_SIZE 100
////�����������ݺ���Сֵ��װΪһ���ṹ��
//typedef struct NewData
//{
//	int data;
//	int Mindata;
//}Newdata;
//
//typedef struct Stack
//{
//	Newdata _arr[MAX_SIZE];//ջ����ŵĶ��Ƿ�װ�õĽṹ��
//	int _size;
//}Stack, *PStack;
//
////������1
//void Test1();
////��ʼ��ջ
//void InitStack(PStack s);
////��ջ������Ԫ��
//void StackPush(PStack s, int data);
//void StackPop(PStack s);//��ջ
////����ջ��СԪ��
//int StackMindata(PStack s);