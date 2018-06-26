#pragma once
#include <stdio.h>
#define MAX_SIZE 10 

typedef struct SeqList
{
	int arr[MAX_SIZE];
	int size; // 表示顺序表中有效元素的个数 
}SeqList, *PSeqList;




// 顺序表的初始化 
void SeqListInit(PSeqList ps);

// 顺序表的尾插 
void SeqListPushBack(PSeqList ps, int data);

// 顺序表的尾删 
void SeqListPopBack(PSeqList ps);

// 顺序表的头插 
void SeqListPushFront(PSeqList ps, int data);

// 顺序表的头删 
void SeqListPopFront(PSeqList ps);

// 顺序表pos位置插入元素data 
void SeqListInsert(PSeqList ps, int pos, int data);

// 删除顺序表pos位置元素 
void SeqListErase(PSeqList ps, int pos);

// 移除顺序表中第一个值为data的元素 
void Remove(PSeqList ps, int data);

// 移除顺序表中所有值为data的元素 
void RemoveAll(PSeqList ps, int data);

// 在顺序表中查找值为data的元素，找到返回该元素在顺序表中的位置，否则返回-1 
int SeqListFind(PSeqList ps, int data);

// 获取顺序表中元素的个数 
int SeqListSize(PSeqList ps);
//辅助操作 
// 打印顺序表 
void PrintSeqList(PSeqList ps);

// 使用冒泡排序对顺序表中的元素进行排序 
void BubbleSort(PSeqList ps);

//使用选择排序对顺序表中的元素进行排序 
void SelectSort(PSeqList ps);

