#pragma once


#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include "BitMap.h"
#include "comm.h"


typedef char* DataType;
typedef unsigned(*PSTI)(DataType str);


typedef struct BloomFilter
{
	BMap _bp;
	int _size;  //有效数据的个数
	PSTI _STI[5]; //函数指针数组
}BFilter;

//初始化
void BloomFilterInit(BFilter* bf, int capacity, PSTI* pSTI, int size);//size表示数组的大小

//插入元素
void BloomFilterInseret(BFilter* bf, DataType data);

//判断数据是否在布隆中--只要算出来一个不在就肯定不在
int BloomFilterIsIn(BFilter* bf, DataType data);

int BloomFilterSize(BFilter* bf);

void BloomFilterDestroy(BFilter* bf);