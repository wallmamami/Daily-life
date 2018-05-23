#pragma once


#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include "BitMap.h"

typedef char* DataType;
typedef unsigned(*PSTI)(DataType str);


typedef struct BloomFilter
{
	BMap _bp;
	int _size;  //有效数据的个数
	PSTI _STI[5]; //函数指针数组
}BFilter;

