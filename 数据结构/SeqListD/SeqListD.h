#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct SeqListD
{
	DataType *arr;
	int capacity;//空间容量
	int size;//有效元素个数
}SeqListD, *PSeqListD;



void SeqListDInit(PSeqListD ps, int capacity);//初始化
void CheckCapacity(PSeqListD ps);// 对顺序表进行增容 
void SeqListDPushBack(PSeqListD ps, DataType data);//尾插
void SeqListDPopBack(PSeqListD ps);//尾删
void SeqListDInsert(PSeqListD ps, int pos, DataType data);//任意位置插入
void SeqListDErase(PSeqListD ps, int pos);//任意位置删除

int SeqListDSize(PSeqListD ps);// 获取元素个数 

int SeqListDCapacity(PSeqListD ps);// 获取顺序表的容量
int SeqListDEmpty(PSeqListD ps);//判空,为空返回0，

void SeqListDClear(PSeqListD ps);// 将顺序表中的元素清空 注意：不改变顺序表空间的大小 
void SeqListDDestroy(PSeqListD ps);//销毁顺序表

