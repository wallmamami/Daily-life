#include "SeqList.h"

void SeqListInit(PSeqList ps)
{
	if (NULL == ps)
		return;
	ps->size = 0;
}

void SeqListPushBack(PSeqList ps, int data)
{
	if (NULL == ps)
		return;

	if (ps->size == MAX_SIZE)
		printf("表已满，操作失败!!!\n");

	ps->arr[ps->size] = data;//插入成功
	ps->size++;
}

void SeqListPopBack(PSeqList ps)
{
	if (NULL == ps)
		return;

	if (ps->size == 0)
		printf("表已空，操作失败!!!\n");

	ps->size--;
}

void SeqListPushFront(PSeqList ps, int data)
{
	int i = 0;
	if (NULL == ps)
		return;

	if (ps->size == MAX_SIZE)
		printf("表已满，操作失败!!!\n");

	for (i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i -1];//元素移位
	}
	ps->arr[0] = data;//插入成功
	ps->size++;
}

void SeqListPopFront(PSeqList ps)
{
	int i = 0;
	if (NULL == ps)
		return;

	if (ps->size == 0)
		printf("表已空，操作失败!!!\n");

	for (; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;//删除成功
}

void SeqListInsert(PSeqList ps, int pos, int data)
{
	int i = 0;
	if (NULL == ps || !((pos >= 0) && (pos <= ps->size)))
		return;

	if (ps->size == MAX_SIZE)
		printf("表已满，操作失败!!!\n");

	for (i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->size++;
}

void SeqListErase(PSeqList ps, int pos)
{
	int i = pos;
	if (NULL == ps || !((pos >= 0) && (pos < ps->size)))
		return;

	if (ps->size == 0)
		printf("表已空，操作失败!!!\n");

	for (; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}

	ps->size--;
}

int SeqListFind(PSeqList ps, int data)
{
	int i = 0;
	for (; i < ps->size; i++)
	{
		if (ps->arr[i] == data)
			return i;
	}
	return -1;
}

void Remove(PSeqList ps, int data)
{
	if (NULL == ps)
		return;

	int pos = SeqListFind(ps, data);
	SeqListErase(ps, pos);

}

void RemoveAll(PSeqList ps, int data)
{
	//1.创建临时数组，将不是该数据的所有数据移到创建的临时数组中，然后再覆盖  时间O(n)  空间O(n)
	//2.找n-1躺， 每趟删除一个 空间复杂度O（1） 时间O（n^2）
	//3.
	int count = 0;
	int i = 0;
	
	for (; i < ps->size; i++)
	{
		if (ps->arr[i] == data)
			count++;
		else
			ps->arr[i - count] = ps->arr[i];//朝前搬移count位

	}
	ps->size -= count;

}

int SeqListSize(PSeqList ps)
{
	return ps->size;
}

void PrintSeqList(PSeqList ps)
{
	int i = 0;
	printf("size = %d\n", ps->size);
	
	for (; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
}

static void Swap(int *dest, int *src)
{
	*dest ^= *src;
	*src ^= *dest;
	*dest ^= *src;
}

void BubbleSort(PSeqList ps)
{
	int i = 0;
	for (; i < ps->size - 1; i++)
	{
		int j = 0;
		int flag = 0;
		for (; j < ps->size - 1 - i; j++)
		{
			if (ps->arr[j] > ps->arr[j + 1])//从小到大
			{
				Swap(&(ps->arr[j]), &(ps->arr[j+1]));
				flag = 1;
			}
			if (flag == 0)
			return;
		}
	}
}
//缺陷：1.已经有序不能退出
//      2.重复性操作太多
void SelectSort(PSeqList ps)
{
	int i = 0;
	for (; ps->size - 1; i++)
	{
		int maxPos = 0;
		int j = 0;
		for (j = 1; j < ps->size - i; j++)
		{
			if (ps->arr[j] > ps->arr[maxPos])
			{
				maxPos = j;
			}		
		}

		if (maxPos != p->size - i - j);
		Swap(&(ps->arr[maxPos]), &(ps->arr[j-1]));
	}
}