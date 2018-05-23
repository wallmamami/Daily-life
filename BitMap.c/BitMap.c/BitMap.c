#include "BitMap.h"

//初始化
void BitMapInit(BMap* bp, int bitcount)//第二个参数为需要比特位的个数
{
	assert(bp);
	bp->_capacity = bitcount / 32 + 1;

	//因为需要每一个比特位初始化都为0，所以这里用calloc
	bp->_bmp = (int*)calloc(bp->_capacity, sizeof(int));
	if (NULL == bp->_bmp)
	{
		assert(0);
		return;
	}

	bp->_size = bitcount;
}

//将任意一位置1
void BitMapSet(BMap* bp, int which)//which从0开始
{
	int index = 0;
	int pos = 0;

	assert(bp);
	if (which >= bp->_size)
		return;

	index = which / 32;//计算出在哪一个整形数据中
	pos = which % 32;  //计算出再这个数的哪一位

	bp->_bmp[index] |= (1 << pos);
}

//将任意一位置零
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

//判断任意一位是0或1
int BitMapTest(BMap* bp, int which)
{
	int index = 0;
	int pos = 0;
	assert(bp);

	if (which >= bp->_size)
	{
		printf("which超过表示范围!\n");
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

//比特位为1的总个数
int BitMapCount(BMap* bp)
{
	int i = 0;
	int count = 0;
	const char bitCount[] = "\0\1\1\2\1\2\2\3\1\2\2\3\2\3\3\4";//'\'相当于逗号，将0-15一的个数直接写在表中
	
	for (; i < bp->_capacity; i++)
	{
		int tmp = bp->_bmp[i];
		int j = 0;

		//每一次循环只能算一个字节中比特位的个数
		while (j < sizeof(bp->_bmp[0]))
		{
			char c = tmp;
			count += bitCount[c & 0x0f];//每次只能算四个比特位中1的个数

			c >>= 4;
			count += bitCount[c & 0x0f];


			tmp >>= 8;//算第二个字节
			j++;
		}
	}

	return count;
}

//销毁位图
void BitMapDestroy(BMap* bp)
{
	assert(bp);
	free(bp->_bmp);
	bp->_bmp = NULL;
	bp->_capacity = 0;
	bp->_size = 0;
}