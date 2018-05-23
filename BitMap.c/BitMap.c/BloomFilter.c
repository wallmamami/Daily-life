#include "BloomFilter.h"
#include "BitMap.h"
#include "comm.h"

//��ʼ��
void BloomFilterInit(BFilter* bf, int capacity, PSTI* pSTI, int size)//size��ʾ����Ĵ�С
{
	int i = 0;
	assert(bf);
	BitMapInit(&bf->_bp, capacity * 5);//
	bf->_size = 0;

	for (; i < size; i++)
		bf->_STI[i] = pSTI[i];
}


//����Ԫ��
void BloomFilterInseret(BFilter* bf, DataType data)
{
	assert(bf);
	unsigned hashaddr = -1;

	hashaddr = bf->_STI[0](data) % bf->_bp._size;
	BitMapSet(&bf->_bp, hashaddr);

	hashaddr = bf->_STI[1](data) % bf->_bp._size;
	BitMapSet(&bf->_bp, hashaddr);

	hashaddr = bf->_STI[2](data) % bf->_bp._size;
	BitMapSet(&bf->_bp, hashaddr);

	hashaddr = bf->_STI[3](data) % bf->_bp._size;
	BitMapSet(&bf->_bp, hashaddr);

	hashaddr = bf->_STI[4](data) % bf->_bp._size;
	BitMapSet(&bf->_bp, hashaddr);

	bf->_size++;
}

//�ж������Ƿ��ڲ�¡��--ֻҪ�����һ�����ھͿ϶�����
int BloomFilterIsIn(BFilter* bf, DataType data)
{
	assert(bf);
	unsigned hashaddr = -1;

	hashaddr = bf->_STI[0](data) % bf->_bp._size;
	if (!BitMapTest(&bf->_bp, hashaddr))
		return 0;

	hashaddr = bf->_STI[1](data) % bf->_bp._size;
	if (!BitMapTest(&bf->_bp, hashaddr))
		return 0;

	hashaddr = bf->_STI[2](data) % bf->_bp._size;
	if (!BitMapTest(&bf->_bp, hashaddr))
		return 0;

	hashaddr = bf->_STI[3](data) % bf->_bp._size;
	if (!BitMapTest(&bf->_bp, hashaddr))
		return 0;

	hashaddr = bf->_STI[4](data) % bf->_bp._size;
	if (!BitMapTest(&bf->_bp, hashaddr))
		return 0;

	return 1;
}


int BloomFilterSize(BFilter* bf)
{
	assert(bf);

	return bf->_size;
}


void BloomFilterDestroy(BFilter* bf)
{
	assert(bf);

	BitMapDestroy(&bf->_bp);
	bf->_size = 0;
}