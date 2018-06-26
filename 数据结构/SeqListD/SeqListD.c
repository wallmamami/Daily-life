#include "SeqListD.h"


//1.�������
//2.�߽��ж�
void SeqListDInit(PSeqListD ps, int capacity)
{
	if (NULL == ps)
		return;//˵���ṹ�岻����

	ps->arr = (DataType *)malloc(sizeof(DataType)*capacity);
	if (ps->arr == NULL)
	{
		printf("�ռ�����ʧ��!!!\n");
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
		printf("�ռ�����ʧ��!!\n");
		return;
	}
	ps->capacity = 2 * ps->capacity;//ÿ������Ϊԭ�ռ�����
}

void SeqListDPushBack(PSeqListD ps, DataType data)
{
	if (NULL == ps)
		return;

	if (ps->size == ps->capacity)//˵��ԭ�ռ�����
		CheckCapacity(ps);//�ռ�����

	ps->arr[ps->size] = data;//����ɹ�
	ps->size++;
}

void SeqListDPopBack(PSeqListD ps)
{
	if (NULL == ps)
		return;
	if (ps->size == 0)
	{
		printf("���ѿգ�ɾ��ʧ��!!!\n");
		return;
	}

	ps->size--;//ɾ���ɹ�
}

void SeqListDInsert(PSeqListD ps, int pos, DataType data)
{
	int i = 0;

	if (NULL == ps)
		return;
	if (!((pos >= 0) && (pos <= ps->size)))
	{
		printf("λ�ò��Ϸ�\n");
		return;
	}

	for (i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];//��pos��size-1�е�����Ԫ�������λ
	}

	ps->arr[pos] = data;
	ps->size++;//����ɹ�
}

void SeqListDErase(PSeqListD ps, int pos)
{
	int i = pos;
	if (NULL == ps)
		return;
	if (!((pos >= 0) && (pos <= ps->size - 1)))
	{
		printf("λ�ò��Ϸ�!!!\n");
	}

	for (; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	
	ps->size--;//ɾ���ɹ�
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
	free(ps->arr);//�ͷſռ�
	ps->arr = NULL;//ָ�븳�գ���ֹҰָ�����
}
