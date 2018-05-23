#include "BitMap.h"
#include "BloomFilter.h"


void TestBitMap()
{
	BMap bp;
	BitMapInit(&bp, 28);
	BitMapSet(&bp, 3);//which�Ǵ�0��ʼ
	BitMapSet(&bp, 4);
	BitMapSet(&bp, 1);
	BitMapReSet(&bp, 1);

	printf("����λΪ:%d\n", BitMapTest(&bp, 0));
	printf("��һλΪ:%d\n", BitMapTest(&bp, 1));

	printf("λͼ�й���1:%d��\n", BitMapCount(&bp));
	BitMapDestroy(&bp);
}

int main()
{
	TestBitMap();
}