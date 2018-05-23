#include "BitMap.h"
#include "BloomFilter.h"
#include "comm.h"

//void TestBitMap()
//{
//	BMap bp;
//	BitMapInit(&bp, 28);
//	BitMapSet(&bp, 3);//which是从0开始
//	BitMapSet(&bp, 4);
//	BitMapSet(&bp, 1);
//	BitMapReSet(&bp, 1);
//
//	printf("第零位为:%d\n", BitMapTest(&bp, 0));
//	printf("第一位为:%d\n", BitMapTest(&bp, 1));
//
//	printf("位图中共有1:%d个\n", BitMapCount(&bp));
//	BitMapDestroy(&bp);
//}


void TestBloomFilter()
{
	BFilter bf;
	PSTI pSTI[] = { StrToInt1, StrToInt2, StrToInt3, StrToInt4, StrToInt5};
	BloomFilterInit(&bf, 5, pSTI, sizeof(pSTI)/sizeof(pSTI[0]));

	BloomFilterInseret(&bf, "阿花");
	BloomFilterInseret(&bf, "爸爸");
	BloomFilterInseret(&bf, "阿猫");
	BloomFilterInseret(&bf, "阿狗");

	if (BloomFilterIsIn(&bf, "阿花"))
		printf("阿花在!\n");
	else
		printf("阿花不在这!\n");
	
	if (BloomFilterIsIn(&bf, "爷爷"))
		printf("爷爷在!\n");

	else
		printf("爷爷不在这!\n");

	printf("Size = %d\n", BloomFilterSize(&bf));

	BloomFilterDestroy(&bf);
}

int main()
{
	//TestBitMap();
	TestBloomFilter();
}