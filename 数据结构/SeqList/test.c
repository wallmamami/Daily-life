#include "SeqList.h"
#include <windows.h>

int main()
{
	SeqList A;
	PSeqList ps = &A;

	// ˳���ĳ�ʼ�� 
	SeqListInit(ps);
	// ˳����β�� 
	SeqListPushBack(ps, 0);
	SeqListPushBack(ps, 5);
	SeqListPushBack(ps, 3);
	SeqListPushBack(ps, 2);
	SeqListPushBack(ps, 7);
	SeqListPushBack(ps, 5);
	SeqListPushBack(ps, 5);
	SeqListPushBack(ps, 3);
	SeqListPushBack(ps, 1);
	//˳�������λ�ò���
	SeqListInsert(ps, 3, 2);

	// ɾ��˳���posλ��Ԫ�� 
	SeqListErase(ps, 2);

	// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
	Remove(ps,5);

	// �Ƴ�˳���������ֵΪdata��Ԫ�� 
	RemoveAll(ps, 2);

	// ��˳����в���ֵΪdata��Ԫ�أ��ҵ����ظ�Ԫ����˳����е�λ�ã����򷵻�-1 
	SeqListFind(ps, 5);
	// ��ȡ˳�����Ԫ�صĸ��� 
	SeqListSize(ps);

	// ʹ��ð�������˳����е�Ԫ�ؽ������� 
	BubbleSort(ps);

	//ʹ��ѡ�������˳����е�Ԫ�ؽ������� 
	SelectSort(ps);

	PrintSeqList(ps);

	system("pause");
	return 0;
}