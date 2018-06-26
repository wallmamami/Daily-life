#ifndef __BITMAP_H__
#define __BITMAP_H__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>


typedef struct BitMap
{
	int* _bmp;
	int _capacity; //位集合所占空间大小(有几个整形数据)
	int _size;    //比特位的有效个数(假如最大数为24，他的有效个数就为25,0到24有25个数)
}BMap;




void BitMapInit(BMap* bp, int bitcount);

void BitMapSet(BMap* bp, int which);

//将任意一位置零
void BitMapReSet(BMap* bp, int which);

//判断任意一位是0或1
int BitMapTest(BMap* bp, int which);

int BitMapSize(BMap* bp);

//比特位为1的总个数
int BitMapCount(BMap* bp);

//销毁位图
void BitMapDestroy(BMap* bp);




#endif