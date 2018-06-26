#pragma once
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern  struct Position;
typedef struct Position DataType;

typedef struct Stack
{
	DataType *arr;//指向动态空间的指针
	int capacity;//空间总容量
	int size;//有效元素个数
}Stack,* PStack;

// 栈的初始化 
void StackInit(PStack ps, int capacity);

// 入栈 
void StackPush(PStack ps, DataType data);

// 出栈 
void StackPop(PStack ps);

// 获取栈顶元素 
DataType StackTop(PStack ps);

// 获取栈中元素个数 
int StackSize(PStack ps);

// 检测栈是否为空 
int StackEmpty(PStack ps);

void PrintStack(PStack ps);//打印栈

//括号匹配问题
int IsBrackets(char *ptr);
void IsMach(char *a, PStack ps);

//计算逆波兰表达式
void Calculate(char *a, PStack ps);