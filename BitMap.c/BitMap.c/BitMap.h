#ifndef __BITMAP_H__
#define __BITMAP_H__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>


typedef struct BitMap
{
	int* _bmp;
	int _capacity; //λ������ռ�ռ��С(�м�����������)
	int _size;    //����λ����Ч����(���������Ϊ24��������Ч������Ϊ25,0��24��25����)
}BMap;




void BitMapInit(BMap* bp, int bitcount);

void BitMapSet(BMap* bp, int which);

//������һλ����
void BitMapReSet(BMap* bp, int which);

//�ж�����һλ��0��1
int BitMapTest(BMap* bp, int which);

int BitMapSize(BMap* bp);

//����λΪ1���ܸ���
int BitMapCount(BMap* bp);

//����λͼ
void BitMapDestroy(BMap* bp);




#endif