#include "BitMap.h"

//��ʼ��
void BitMapInit(BMap* bp, int bitcount)//�ڶ�������Ϊ��Ҫ����λ�ĸ���
{
	assert(bp);
	bp->_capacity = bitcount / 32 + 1;

	//��Ϊ��Ҫÿһ������λ��ʼ����Ϊ0������������calloc
	bp->_bmp = (int*)calloc(bp->_capacity, sizeof(int));
	if (NULL == bp->_bmp)
	{
		assert(0);
		return;
	}

	bp->_size = bitcount;
}

//������һλ��1
void BitMapSet(BMap* bp, int which)//which��0��ʼ
{
	int index = 0;
	int pos = 0;

	assert(bp);
	if (which >= bp->_size)
		return;

	index = which / 32;//���������һ������������
	pos = which % 32;  //����������������һλ

	bp->_bmp[index] |= (1 << pos);
}

//������һλ����
void BitMapReSet(BMap* bp, int which)
{
	int index = 0;
	int pos = 0;
	assert(bp);

	if (which >= bp->_size)
		return;

	index = index = which / 32;
	pos = which % 32;  
	bp->_bmp[index] &= ~(1 << pos);
}

//�ж�����һλ��0��1
int BitMapTest(BMap* bp, int which)
{
	int index = 0;
	int pos = 0;
	assert(bp);

	if (which >= bp->_size)
	{
		printf("which������ʾ��Χ!\n");
		return 0;
	}

	index = which / 32;
	pos = which % 32;

	return bp->_bmp[index] & (1 << pos);
}

int BitMapSize(BMap* bp)
{
	assert(bp);

	return bp->_size;
}

//����λΪ1���ܸ���
int BitMapCount(BMap* bp)
{
	int i = 0;
	int count = 0;
	const char bitCount[] = "\0\1\1\2\1\2\2\3\1\2\2\3\2\3\3\4";//'\'�൱�ڶ��ţ���0-15һ�ĸ���ֱ��д�ڱ���
	
	for (; i < bp->_capacity; i++)
	{
		int tmp = bp->_bmp[i];
		int j = 0;

		//ÿһ��ѭ��ֻ����һ���ֽ��б���λ�ĸ���
		while (j < sizeof(bp->_bmp[0]))
		{
			char c = tmp;
			count += bitCount[c & 0x0f];//ÿ��ֻ�����ĸ�����λ��1�ĸ���

			c >>= 4;
			count += bitCount[c & 0x0f];


			tmp >>= 8;//��ڶ����ֽ�
			j++;
		}
	}

	return count;
}

//����λͼ
void BitMapDestroy(BMap* bp)
{
	assert(bp);
	free(bp->_bmp);
	bp->_bmp = NULL;
	bp->_capacity = 0;
	bp->_size = 0;
}