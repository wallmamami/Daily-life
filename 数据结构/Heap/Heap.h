#ifndef __HEAP_H__
#define __HEAP_H__


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int DataType;
typedef int(*Compare)(DataType left, DataType right);//比较方法的函数指针

//堆的内容
typedef struct Heap
{
	DataType* arr;//连续的存储空间
	int _Capacity;//空间总容量
	int _size;//有效元素个数
	Compare com;
}Heap;


//初始化堆
void HeapInit(Heap* hp, Compare com);

//比较方法
//大堆
int Greater(DataType left, DataType right);
//小堆
int Less(DataType left, DataType right);
void _Swap(DataType* left, DataType* right);
//堆的创建
void CreateHeap(Heap* hp, DataType* arr, int size);

//插入元素
void InsertHeap(Heap* hp, DataType data);

//删除堆顶元素
void DeleteHeap(Heap* hp);

//查看堆顶元素
DataType HeapTop(Heap* hp);

//查看堆总元素个数
int HeapSize(Heap* hp);

//堆判空
int EmptyHeap(Heap* hp);

//销毁堆
void DestoryHeap(Heap* hp);

//堆排
void HeapSort(int* arr, int size);

#endif