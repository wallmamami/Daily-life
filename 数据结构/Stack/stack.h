#pragma once
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern  struct Position;
typedef struct Position DataType;

typedef struct Stack
{
	DataType *arr;//ָ��̬�ռ��ָ��
	int capacity;//�ռ�������
	int size;//��ЧԪ�ظ���
}Stack,* PStack;

// ջ�ĳ�ʼ�� 
void StackInit(PStack ps, int capacity);

// ��ջ 
void StackPush(PStack ps, DataType data);

// ��ջ 
void StackPop(PStack ps);

// ��ȡջ��Ԫ�� 
DataType StackTop(PStack ps);

// ��ȡջ��Ԫ�ظ��� 
int StackSize(PStack ps);

// ���ջ�Ƿ�Ϊ�� 
int StackEmpty(PStack ps);

void PrintStack(PStack ps);//��ӡջ

//����ƥ������
int IsBrackets(char *ptr);
void IsMach(char *a, PStack ps);

//�����沨�����ʽ
void Calculate(char *a, PStack ps);