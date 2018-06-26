#include "SeqListD.h"


//1.参数检测
//2.边界判断
void SeqListDInit(PSeqListD ps, int capacity)
{
	if (NULL == ps)
		return;//说明结构体不存在

	ps->arr = (DataType *)malloc(sizeof(DataType)*capacity);
	if (ps->arr == NULL)
	{
		printf("空间申请失败!!!\n");
		return;
	}
	ps->capacity = capacity;
	ps->size = 0;
}

void CheckCapacity(PSeqListD ps)
{
	if (NULL == ps)
		return;
	//printf("Data = %d capa = %d\n", sizeof(DataType), ps->capacity);
	ps->arr = (DataType *)realloc(ps->arr, (sizeof(DataType) * (ps->capacity) * 2));

	if (NULL == ps->arr)
	{
		printf("空间申请失败!!\n");
		return;
	}
	ps->capacity = 2 * ps->capacity;//每次扩增为原空间两倍
}

void SeqListDPushBack(PSeqListD ps, DataType data)
{
	if (NULL == ps)
		return;

	if (ps->size == ps->capacity)//说明原空间已满
		CheckCapacity(ps);//空间扩容

	ps->arr[ps->size] = data;//插入成功
	ps->size++;
}

void SeqListDPopBack(PSeqListD ps)
{
	if (NULL == ps)
		return;
	if (ps->size == 0)
	{
		printf("表已空，删除失败!!!\n");
		return;
	}

	ps->size--;//删除成功
}

void SeqListDInsert(PSeqListD ps, int pos, DataType data)
{
	int i = 0;

	if (NULL == ps)
		return;
	if (!((pos >= 0) && (pos <= ps->size)))
	{
		printf("位置不合法\n");
		return;
	}

	for (i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];//将pos到size-1中的所有元素向后移位
	}

	ps->arr[pos] = data;
	ps->size++;//插入成功
}

void SeqListDErase(PSeqListD ps, int pos)
{
	int i = pos;
	if (NULL == ps)
		return;
	if (!((pos >= 0) && (pos <= ps->size - 1)))
	{
		printf("位置不合法!!!\n");
	}

	for (; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	
	ps->size--;//删除成功
}

int SeqListDSize(PSeqListD ps)
{
	if (NULL == ps)
	{
		assert(0);
		return 0;
	}
	return ps->size;
}

int SeqListDCapacity(PSeqListD ps)
{
	if (NULL == ps)
	{
		assert(0);
		return 0;
	}
	return ps->capacity;
}

int SeqListDEmpty(PSeqListD ps)
{
	if (NULL == ps)
	{
		assert(0);
		return -1;
	}

	if (ps->size == 0)
		return 0;
	return 1;
}

void SeqListDClear(PSeqListD ps)
{
	if (NULL == ps)
		return;

	ps->size = 0;
}

void SeqListDDestroy(PSeqListD ps)
{
	if (NULL == ps)
		return;

	ps->size = 0;
	ps->capacity = 0;
	free(ps->arr);//释放空间
	ps->arr = NULL;//指针赋空，防止野指针产生
}
