#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <assert.h>



#define MAX_SIZE 10
typedef int DataType;


typedef struct SeqList
{
    DataType arr[MAX_SIZE];
    int size;
}SeqList, *PSqList;




//初始化
void SeqListInit(PSqList ps);

//尾插
void SeqListPushBack(PSqList ps, DataType data);

//尾删
void SeqListPopBack(PSqList ps);

//头插
void SeqListPushFront(PSqList ps, DataType data);

//头删
void SeqListPopFront(PSqList ps);

//任意位置插
void SeqListPushPos(PSqList ps, DataType data, int pos);

//任意位置删除
void SeqListPopPos(PSqList ps, int pos);

//删除值为data的元素
void RemoveData(PSqList ps, DataType data);

//查找data返回下标
int FindData(PSqList ps, DataType data);

//删除所有值为data的元素
void RemoveAllData(PSqList ps, DataType data);

//获取顺序表的元素
int SeqListSize(PSqList ps);

//判空
int SeqListEmpty(PSqList ps);




#endif
