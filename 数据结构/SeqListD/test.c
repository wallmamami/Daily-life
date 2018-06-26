#include "SeqListD.h"
#include <Windows.h>

void print(PSeqListD ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

int main()
{
	int capacity = 10;
	int size = 0;
	SeqListD List;
	PSeqListD ps = &List;

	SeqListDInit(ps, capacity);//��ʼ��
	CheckCapacity(ps);// ��˳���������� 
	SeqListDPushBack(ps, 10);//β��
	SeqListDPushBack(ps, 20);
	SeqListDPushBack(ps, 10);
	//SeqListDPopBack(ps);//βɾ
	SeqListDInsert(ps, 2, 50);//����λ�ò���
	//SeqListDErase(ps, 2);//����λ��ɾ��
	size = SeqListDSize(ps);// ��ȡԪ�ظ��� 
	capacity = SeqListDCapacity(ps);// ��ȡ˳��������
	printf("size = %d\ncapacity = %d\n", size, capacity);
	
	//SeqListDEmpty(ps);//�п�,Ϊ�շ���0��

	//SeqListDClear(ps);// ��˳����е�Ԫ����� ע�⣺���ı�˳���ռ�Ĵ�С 
	//SeqListDDestroy(ps);//����˳���
	print(ps);//��ӡ˳���

	system("pause");
	return 0;
}