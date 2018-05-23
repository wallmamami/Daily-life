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
	int _size;  //��Ч���ݵĸ���
	PSTI _STI[5]; //����ָ������
}BFilter;

