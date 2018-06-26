#include "BitMap.h"
#include "BloomFilter.h"
#include "comm.h"

//void TestBitMap()
//{
//	BMap bp;
//	BitMapInit(&bp, 28);
//	BitMapSet(&bp, 3);//which�Ǵ�0��ʼ
//	BitMapSet(&bp, 4);
//	BitMapSet(&bp, 1);
//	BitMapReSet(&bp, 1);
//
//	printf("����λΪ:%d\n", BitMapTest(&bp, 0));
//	printf("��һλΪ:%d\n", BitMapTest(&bp, 1));
//
//	printf("λͼ�й���1:%d��\n", BitMapCount(&bp));
//	BitMapDestroy(&bp);
//}


void TestBloomFilter()
{
	BFilter bf;
	PSTI pSTI[] = { StrToInt1, StrToInt2, StrToInt3, StrToInt4, StrToInt5};
	BloomFilterInit(&bf, 5, pSTI, sizeof(pSTI)/sizeof(pSTI[0]));

	BloomFilterInseret(&bf, "����");
	BloomFilterInseret(&bf, "�ְ�");
	BloomFilterInseret(&bf, "��è");
	BloomFilterInseret(&bf, "����");

	if (BloomFilterIsIn(&bf, "����"))
		printf("������!\n");
	else
		printf("����������!\n");
	
	if (BloomFilterIsIn(&bf, "үү"))
		printf("үү��!\n");

	else
		printf("үү������!\n");

	printf("Size = %d\n", BloomFilterSize(&bf));

	BloomFilterDestroy(&bf);
}

int main()
{
	//TestBitMap();
	TestBloomFilter();
}