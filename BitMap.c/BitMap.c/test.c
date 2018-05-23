#include "BitMap.h"
#include "BloomFilter.h"


void TestBitMap()
{
	BMap bp;
	BitMapInit(&bp, 28);
	BitMapSet(&bp, 3);//which是从0开始
	BitMapSet(&bp, 4);
	BitMapSet(&bp, 1);
	BitMapReSet(&bp, 1);

	printf("第零位为:%d\n", BitMapTest(&bp, 0));
	printf("第一位为:%d\n", BitMapTest(&bp, 1));

	printf("位图中共有1:%d个\n", BitMapCount(&bp));
	BitMapDestroy(&bp);
}

int main()
{
	TestBitMap();
}