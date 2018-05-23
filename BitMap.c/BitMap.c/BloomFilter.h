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
	int _size;  //��Ч���ݵĸ���
	PSTI _STI[5]; //����ָ������
}BFilter;

//��ʼ��
void BloomFilterInit(BFilter* bf, int capacity, PSTI* pSTI, int size);//size��ʾ����Ĵ�С

//����Ԫ��
void BloomFilterInseret(BFilter* bf, DataType data);

//�ж������Ƿ��ڲ�¡��--ֻҪ�����һ�����ھͿ϶�����
int BloomFilterIsIn(BFilter* bf, DataType data);

int BloomFilterSize(BFilter* bf);

void BloomFilterDestroy(BFilter* bf);