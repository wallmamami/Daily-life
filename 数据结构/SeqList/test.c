#include "SeqList.h"
#include <windows.h>

int main()
{
	SeqList A;
	PSeqList ps = &A;

	// 顺序表的初始化 
	SeqListInit(ps);
	// 顺序表的尾插 
	SeqListPushBack(ps, 0);
	SeqListPushBack(ps, 5);
	SeqListPushBack(ps, 3);
	SeqListPushBack(ps, 2);
	SeqListPushBack(ps, 7);
	SeqListPushBack(ps, 5);
	SeqListPushBack(ps, 5);
	SeqListPushBack(ps, 3);
	SeqListPushBack(ps, 1);
	//顺序表任意位置插入
	SeqListInsert(ps, 3, 2);

	// 删除顺序表pos位置元素 
	SeqListErase(ps, 2);

	// 移除顺序表中第一个值为data的元素 
	Remove(ps,5);

	// 移除顺序表中所有值为data的元素 
	RemoveAll(ps, 2);

	// 在顺序表中查找值为data的元素，找到返回该元素在顺序表中的位置，否则返回-1 
	SeqListFind(ps, 5);
	// 获取顺序表中元素的个数 
	SeqListSize(ps);

	// 使用冒泡排序对顺序表中的元素进行排序 
	BubbleSort(ps);

	//使用选择排序对顺序表中的元素进行排序 
	SelectSort(ps);

	PrintSeqList(ps);

	system("pause");
	return 0;
}